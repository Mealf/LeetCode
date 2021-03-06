class Solution {
public:
    struct Trie {
      Trie *next[26] = {nullptr};  
    };
    
    static bool cmp(string a, string b){
        return a.length() > b.length();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        Trie root;
        
        int ans = 0;
        sort(words.begin(), words.end(), cmp);
        for(auto& w : words) {
            bool createNode = false;
            Trie *p = &root;
            for(int i=w.length()-1; i>=0; i--) {
                if(p->next[w[i]-'a'] == nullptr) {
                    p->next[w[i]-'a'] = new Trie;
                    createNode = true;
                }
                
                p = p->next[w[i]-'a'];
            }
            if(createNode)
                ans += w.length()+1;
        }
        
        return ans;
    }
};