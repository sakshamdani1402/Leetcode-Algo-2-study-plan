class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            //if found
            if(nums[mid]==target)   return mid;
            //check if left half is sorted
            else if(nums[low] <= nums[mid]){
                //now check if target lies in the left half
                if(nums[low] <=target && target < nums[mid])
                    high = mid-1;
                //this means it  doesnt lie in the left half
                else
                    low = mid+1;
            }
            //since the left half isnt sorted
            //we cant use binary search so we use it on right half
            //this also suggests that this portion is rotated forward
            else{
                //check if target lies in the right half
                if(target > nums[mid] && target<= nums[high])
                    low=mid+1;
                //since it doesnt lie here we go back to the
                //left half excluding mid
                else
                    high = mid-1;
            }
                    
            
        }
        //if nothing is found
        return -1;
    }
};