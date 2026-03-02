class Solution {
    // ek point ke baad sab true ho jate hain monotonic property aur ismai hamesha binary search lagta hai
    
    private:
    int counthours(vector<int>&piles, int h,int k){ //
        long long hours=0;
        for (int pile:piles){
             hours+= (pile+k-1)/k; //ceil division 
        }
        if (hours>h){ // if hours jayda ho gaye to nahi chalega
            return false;
        }
        return true;
    }
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j= *max_element(piles.begin(),piles.end()); // 0 -> max(piles)
        int ans=j;
        while(i<=j){
            int mid=i+(j-i)/2;
            if (counthours(piles,h,mid)){
                ans=mid; 
                j=mid-1; // hours esse chote hain ya ismai hi hain
            
            }
            else{
                i=mid+1; //hours badhane padenge
            }
        }
    return ans;
        
    }
};