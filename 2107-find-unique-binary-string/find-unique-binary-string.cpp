class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
      //cantor diagonalization trick question or cantor proof question 
    //  context of this question is real numbers are uncountable
    //ismai hume har index pe value dekhni hai aur use flip kar dena hai like
   // 0 ->1 and 1->0 like ['01','11'] then check num[0][0]=0 flip to 1 and num[1][1]=1 then flip to 0 then 10 is not in this string

        int n = nums.size();
        string ans = "";

        for(int i = 0; i < n; i++) {
            if(nums[i][i] == '0')
                ans += '1';
            else
                ans += '0';
        }

        return ans;
    }
};