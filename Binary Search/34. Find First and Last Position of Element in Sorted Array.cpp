class Solution {
public:
    //this can also be solved using vector :: upper_bound
    //and lower_bound methods
    vector<int> searchRange(vector<int>& a, int target) {
	int start = 0, end = a.size()-1;
	vector<int> ans(2, -1);
	//first occurrence
        while(start <= end){
            int mid = start + (end-start)/2;
            if(a[mid] < target)
                    start = mid+1;
            else if(a[mid] > target)
                    end = mid-1;
            //here we know a[mid] == target 
            else{
                //check if mid is 1st elem or,
                //prev elem is not a[mid]
                if(mid==start || a[mid] != a[mid-1]){
                    ans[0] = mid;
                    break;
                }
                //this means prev elem == a[mid]
                //so we search in left space
                else{
                    end=mid-1;
                    //this is totally optional 
                    //its just that we store a temporary res
                    //to ensure a result
                    ans[0]=mid-1;
                }
                    
            }
        }
        
	//last occurrence
        start = 0;
        end = a.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(a[mid] < target)
                    start = mid+1;
            else if(a[mid] > target)
                    end = mid-1;
            else{
                //check if this is the last elem or,
                //a[mid] != next elem
                if(mid==end || a[mid] != a[mid+1]){
                    ans[1] = mid;
                    break;
                }
                else{
                    start=mid+1;
                    ans[1] = mid+1;
                }
                    
            }
        }
        
        return ans;
    }
};