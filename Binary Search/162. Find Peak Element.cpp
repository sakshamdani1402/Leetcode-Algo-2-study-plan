class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        //if we take low<=high then
        //there will we only 1 elem to check and we wouldnt be able to check
        //the mid+1 elem thus we end our search
        while(low<high){
            int  mid = low + (high-low)/2;
            //if current elem is less than its next
            //then slope is ascending so we need to search the right side
            //thus we set low to mid +1
            if(nums[mid] < nums[mid+1]) low = mid+1;
            //this means mid elem is higher or equal to next elem 
            //thus we search in left half including the mid elem
            else high=mid;
        }
        //here low==high as we are narrowing our 
        //search to 1 elem 
        //return either low or high
        return low;
    }
};