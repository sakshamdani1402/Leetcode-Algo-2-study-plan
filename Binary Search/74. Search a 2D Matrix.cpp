class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low =0, r = matrix.size(), c=matrix[0].size(), high = r*c-1;
        //since there are row*col elems
        //array index would be r*c-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[mid/c][mid%c] == target) return true;
            else if(matrix[mid/c][mid%c] > target)  high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};
