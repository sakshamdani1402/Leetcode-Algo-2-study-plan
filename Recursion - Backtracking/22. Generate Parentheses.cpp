class Solution {
public:
    //class variables
    vector<string> res;
    string ans="";
    //only add '(' when open < n
    // only add ')' when close < open
    // only add to res when open == close ==n
    vector<string> generateParenthesis(int n) {
        if(n==0) return res;
        generate(n,0,0,ans);
        return res;
    }
    
    void generate(int n, int open, int close, string ans){
        // here we have balanced parenthesis 
        if(open==n && close==n){
            res.push_back(ans);
            return;
        }
        // we can still add '(' if open<n
        if(open<n)
            generate(n,open+1,close,ans+'(');
        // we can add ) only when close<open
        if(close<open)
            generate(n,open,close+1,ans+')');
    }
};