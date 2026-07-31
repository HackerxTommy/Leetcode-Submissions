class Solution {
public:
    int trap(vector<int>& height) {
          
          int n= height.size();
          int left=0, right= height.size()-1;
          int lmax=0, rmax=0, water=0;
          while( left<right){
            if ( height[left]<= height[right]){
                lmax= max( lmax, height[left]);
                water += lmax- height[left];
                left++;
          }
          else{
            rmax= max( rmax, height[right]);
            water += rmax- height[right];
            right--;

          }
         


          } return water;

       

    }
};