class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> bc;
        int all_size = 1<<k;
        if(s.length()<=k  || s.length()-k+1 < all_size)
            return false;
        
        for(int i=0; i<=s.length()-k;i++) {
            bc.insert(s.substr(i, k));
            if(bc.size() == all_size)
                return true;
        }
        return false;
    }
};