class Solution {
public:
    int maxArea(vector<int>& heights) { 
        // using two pointer 
        //very easy  max_area / maximum amount of water store in rectangle is height * width
        // but width = (right -left) acc to two pointers  0 ->n
        // height  should be minimum because water will contain in less height from left to right pani chote height vale bar se decide hoga kitna contain hoga 
        int left =0, right = heights.size()-1, max_area=0;
        while( left <= right ){
             int area= min(heights[left], heights[right]) * (right-left); // area = min(height) * width
             max_area= max(area, max_area);

             // if  left bar chota hai to left pointer move else right
             if(heights[left]< heights[right]){
                left++;
             }
             else{
                right--;
             }

        }
        return max_area;
    }
};