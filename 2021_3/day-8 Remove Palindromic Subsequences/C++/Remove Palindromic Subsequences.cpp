class Solution {
public:
    int removePalindromeSub(string s) {
        string rs(s.rbegin(), s.rend());
        if(s == "")
            return 0;
        else if(s == rs)
            return 1;
        else
            return 2;
    }
};