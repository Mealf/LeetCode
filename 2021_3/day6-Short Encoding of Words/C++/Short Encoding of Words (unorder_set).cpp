class Solution {
public:    
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        for(auto& w :dict) {
            for(int i=1; i<w.length(); i++) {
                dict.erase(w.substr(i));
            }
        }
        
        int ans = 0;
        for(auto& w:dict)
            ans += w.length()+1;
        return ans;
    }
};