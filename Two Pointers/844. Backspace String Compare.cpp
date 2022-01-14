class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1,st2;
        for(char i:s){
            if(!st1.empty() && i=='#')
                st1.pop();
            else if(i!='#')
                st1.push(i);
        }
        for(char i:t){
            if(!st2.empty() && i=='#')
                st2.pop();
            else if(i!='#')
                st2.push(i);
        }
        return st1==st2;
    }
};