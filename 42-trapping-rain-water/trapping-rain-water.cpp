class Solution {
public:
    int trap(vector<int>& height) {
          
        
          int left=0, right= height.size()-1;
          int lmax=0, rmax=0, water=0; // track the left max and right max bcz water contains between left max bar and right max bar 
          while( left<right){
            if ( height[left]<= height[right]){ // then height of water trapped only depends upon lmax
                lmax= max( lmax, height[left]); // If height[left] >= leftMax, update leftMax.
                water += lmax- height[left]; // Else, add leftMax - height[left].
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