class Solution {
public:
    //class variables so we dont have to pass them as params
    vector<vector<int>> res;
    vector<int> temp;
    int n;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();  //init n
        unordered_map<int,int> m;
        // we use map to iterate over unique elems 
        // to avoid duplicates
        for(int num:nums)   m[num]++;   //set counter for every elem
        backtrack(m);
        return res;
    }
    
    void backtrack(unordered_map<int,int>& m){
        // pusback the curr vector array
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }
        // iterate over the map
        for(auto [key,val]:m){
            // if the val of curr elem is 0 we cannot include it
            if(val==0) continue;
            temp.push_back(key);    //include this elem in temp
            m[key]--;               //reduce its val
            backtrack(m);           //backtrack it
            m[key]++;               //++ to turn map back to original
            temp.pop_back();        //pop from the temp to find next 
                                    //candidate
        }
    }
};