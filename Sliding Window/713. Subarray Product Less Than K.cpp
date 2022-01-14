class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // since all nums are +ve the product cannot be zero
        // also if k is 1 the product must be less than k which is zero
        // which isnt allowed so if k<=1 return 0 
        if(k<=1) return 0;
        int p=1,left=0,res=0;
        // init right ptr which will find product
        for(int right=0;right<nums.size();right++){
            p *= nums[right];
            // now for every right ptr moved we must move the left ptr
            // we will move left when p>=k so that we can reduce it
            // by reducing the no of elem in the window
            while(p>=k){
            // divide the current product with the elem at left
            // this will reduce the product by the current left elem
                p /= nums[left];
            // move left ptr to reduce the window size
            // we do this untill product becomes less than k
                left++;
            }
            // the no of subarrays will be the no of elem in the window
            // since individual elem also contributes to the product and acts
            // as a subarray of size 1
            res+= (right-left)+1;
        }
        return res;
    }
};