class Solution {
public:
    int findMin(vector<int>& nums) {
        //since the array is sorted but rotated there is a point where
        //the next elem becomes smaller than the curr mid elem
        //this is the inflection point
        //we need to find this point
        int low=0,high=nums.size()-1;
        
        //high > low signifies the arr is fully sorted and isnt rotated
        // '=' signifies there is only one elem 
        //in both cases just return the elem at lowest index
        if(nums[high] >=nums[low])
            return nums[low];
        
        while(low<=high){
            int mid = low + (high-low)/2;
            //inflection point can occur if mid elem > mid+1 elem
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            //or mid elem < mid-1 elem
            if(nums[mid]<nums[mid-1])   return nums[mid];
            //if left half is sorted we search right half
            if(nums[mid] > nums[low])   low = mid+1;
            //else we search the left half
            else    high = mid-1;
                
        }
        //not needed really but since we need to return something..
        return -1;
    }
};