class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        int n=cardPoints.size();
        for (int i=0;i<k;i++){ //add first k elements and calculate their sum from front
            total = total+cardPoints[i];
        }
        int max_total=total; //store the max answer current
        
        //remove 1 card  from the front ie. move the window from front to back k times
         for (int i=0;i<k;i++){
            total = total -cardPoints[k-1-i];
         
         //add 1 card from the end
         
            total = total + cardPoints[n-1-i];
         
         
           max_total = max(max_total,total); //update the max_sum
         }



        return max_total;
        
        
    }
};