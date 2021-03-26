class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> count(26), tmp(26);
        vector<string> result;
        for(auto &word: B) {
            tmp = vector<int>(26);
            for(auto &c: word) 
                ++tmp[c-'a'];
            
            for(int i=0;i<26;i++) 
                count[i] = max(count[i], tmp[i]);
        }
        
        for(auto &word: A) {
            bool fail = false;
            tmp = vector<int>(26);
            for(auto &c: word) {
                ++tmp[c-'a'];
            }
            
            for(int i=0;i<26;i++) {
                if(count[i]>tmp[i]) {
                    fail = true;
                    break;
                }
            }
            if(!fail)
                result.push_back(word);
        }
        
        return result;
    }
};