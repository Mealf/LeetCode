class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int len = stamp.length();
        string final_t = string(target.length(),'?'), mask=string(len,'?');
        vector<int> result;
        
        for(int i=0;i<len;i++) {
            for(int j=0;j<=target.length()-stamp.length();j++) {
                if(equal_n(stamp, target, j, i)) {
                    result.push_back(j);
                    target.replace(j, len, mask);
                    j=-1;
                }
            }
        }
        
        if(target != final_t)
            return {};
        reverse(result.begin(), result.end());
        return result;
    }
    
    static bool equal_n(string s, string t,int t_start, int mark) {
        int n=0;
        for(int i=0;i<s.length() && n<=mark;i++) {
            if(t[t_start+i]=='?')
                n++;
            else if(s[i]!=t[t_start+i])
                return false;
        }
        if(n<=mark)
            return true;
        return false;
    }
};