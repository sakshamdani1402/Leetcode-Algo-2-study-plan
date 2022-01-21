class Solution {
public:
    //keep dividing no and adding squares of digits
    //if the number reaches a no already present in the set
    //there is a cycle present and cannot be a happy no
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && seen.find(n) == seen.end()){
            seen.insert(n);
            n = getNext(n);
        }
        
        return n == 1;
    }
    
    int getNext(int n){
        int total =0;
        while(n>0){
            total += ((n%10)*(n%10));
            n/=10;

        }
        return total;
    }
};