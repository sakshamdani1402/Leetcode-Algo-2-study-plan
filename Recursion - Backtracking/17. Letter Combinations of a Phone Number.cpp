class Solution {
public:
    vector<string> res;
    string ans="";
    //mapping of digits to letters
    //since mapping starts with 2 we have left 1st two empty
    vector<string> letters ={
        "", "", "abc", "def", "ghi", "jkl",
                "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if(digits=="") return res;
        backtrack(digits,ans,0);
        return res;
    }
    
    void backtrack(string digits,string ans, int curr){
        if(ans.size()==digits.size()){
            res.push_back(ans);
            return;
        }
        // eg : digits="23"
        // curr is current index in digits [let curr =0]
        // digits[curr] gives us the digit  [digits[0] is '2']
        // since digit is a string we convert it to int by
        // subtracting '0' as letters is a zero indexed array   ['2' - '0' = 2]
        // noe we would have access to letters[2] i.e "abc"
        // auto c : "abc" would iterate and add 1 letter at a time 
        for(auto c:letters[digits[curr]-'0']){
            backtrack(digits,ans+c,curr+1);
        }
    }
};