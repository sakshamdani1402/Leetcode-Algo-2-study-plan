class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.size() <= 1) return s;
        
        int n=s.size(),start=0,maxLen=1;
        for(int i=0;i<n;i++){
            expand(s,i,i,maxLen,start);
            expand(s,i,i+1,maxLen,start);
        }
        
        return s.substr(start,maxLen);
    }
    
    void expand(string& s,int left,int right,int& maxLen,int& start){
        while(left>=0 && right<s.size() && s[left]==s[right] ){
            left--;
            right++;
        }
        if(maxLen < right-left-1){
            maxLen = right-left-1;
            start =  left+1;
        }
    }
};