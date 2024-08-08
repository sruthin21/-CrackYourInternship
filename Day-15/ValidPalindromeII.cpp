class Solution {
public:
    bool check(string s, int lo, int hi){
        while(lo<=hi){
            if(s[lo]!=s[hi])return false;
            lo++; hi--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int count = 0;
        int n = s.size();
        int lo = 0, hi = n-1;
        while(lo<=hi){
            if(s[lo]==s[hi]){
                lo++; hi--;
            }
            else{
                return (check(s, lo+1, hi) || check(s, lo, hi-1));
            }
        }
        return true;
    }
};