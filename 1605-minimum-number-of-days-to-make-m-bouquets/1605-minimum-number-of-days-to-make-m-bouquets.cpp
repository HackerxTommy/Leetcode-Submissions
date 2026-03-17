class Solution {
private:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0, bouquets = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                cnt++;
                if(cnt == k){
                    bouquets++;
                    cnt = 0;
                }
            }
            else{
                cnt = 0;
            }
        }

        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long need = (long long)m * k;
        if(need > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            if(possible(bloomDay, mid, m, k))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};