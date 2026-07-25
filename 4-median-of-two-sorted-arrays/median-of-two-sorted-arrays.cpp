class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int m= nums1.size();
     int n = nums2.size();
      if ( m>n) {
        return findMedianSortedArrays (nums2,nums1); // swap kar diya cz hame pahle chote size ka array chahiye for bs
      }

      int l= 0; int r = m;  // bs chote array pe lagao nums1
      while( l<=r){ 
        int mid = l+ (r-l)/2;
          
        int px = mid;            // nums1 se kitne elements left me lenge
        int py = (m+n+1)/2 - px; // nums2 se remaining left elements

        //left  half vale 
        int x1 = ( px==0 ) ? INT_MIN : nums1[px-1] ;   //rightmost in upper left    && agar left half mai ek bhi nahi liye to left mai bachega  -infinity 
        int x2 = ( py ==0 ) ? INT_MIN : nums2[py-1];    //rightmost in lower left  &&  agar left half mai ek bhi nahi liye to left mai bachega  -infinity 

         //right half vale 

         int x3 = (px==m ) ? INT_MAX : nums1[px];      //leftmost in upper right    && gar right half mai ek bhi nahi liye to right mai bachega infinity 
         int x4 = (py==n ) ? INT_MAX : nums2[py];      // leftmost in lower right   &&  agar right half mai ek bhi nahi liye to right mai bachega infinity 
        
        // Perfect partition mil gaya
        if (x1<= x4 && x2<= x3){
            // Total elements odd hain
            if ((m+n)%2 ==1){ //odd hai
                return max(x1,x2); //median left side half mai  jo maximum tha x1 and x2 mai 
            }
            // Total elements even hain
            else{ 
                return (max(x1, x2)+ min(x3,x4))/2.0;
            }
        }

       // Partition ko left move karo
       if ( x1> x4){
         r= px-1; // mid = px shrink left side 
       }
       // Partition ko right move karo
       else{
        l = px+1;  // right side expand
       }
      } 
      return 0;
      
    }
};