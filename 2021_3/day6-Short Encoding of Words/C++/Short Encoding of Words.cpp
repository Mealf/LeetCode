class Solution {
public:
    static bool cmp(string a, string b){
        return a.length() < b.length();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        if(words.empty())
            return 0;
        sort(words.begin(), words.end(), cmp);
        bool flag;
        int ans = 0;
        for(int i=0;i<words.size();i++) {
            flag = false;
            for(int j=i+1; j<words.size();j++) {
                if(words[i] == words[j].substr(words[j].size()-words[i].size())) {
                    flag = true;
                    break;
                }
            }
            if(!flag)
                ans+=words[i].length()+1;
        }
        
        return ans;
    }
};