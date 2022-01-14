class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.size(),m = p.size();
        // we need to find anagrams of p in s, so if len of s in smaller
        // than len of p, we just return empty vec
        if(m>n) return res;
        // set up 2 hashes for chars
        vector<int> phash(26,0);
        vector<int> shash(26,0);
        // populate phash with its elem
        for(char c:p){
            phash[c - 'a']++;
        }
            
        int left=0,right=0;
        // until right reaches the end of s
        while(right < n){
            // add the right elem in the shash
            shash[s[right]-'a']++;
            // continue incrementing right untill we reach the size of p
            if(right-left+1 < m)
                right++;
            // we got a substring of len p now we check if the hashes are equal
            else if(right-left+1==m){
                // they are equal so we just append the left ptr in res vector
                if(shash==phash)
                    res.push_back(left);
                // remove the 1st elem in the hash and prepare to add another                       elem
                shash[s[left]-'a']--;
                // slide the window
                right++;
                left++;
            }            
        }
        return res;
    }
};