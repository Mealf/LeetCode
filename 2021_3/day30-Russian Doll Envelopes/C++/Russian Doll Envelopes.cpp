class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> len(envelopes.size(), 1);
        int result = 1;
        
        for(int i=0;i<envelopes.size();i++) {   //最長遞增子序列
            int max_len = 1;
            for(int j=0;j<i;j++) {
                if(envelopes[j][0]>envelopes[i][0] && envelopes[j][1]>envelopes[i][1]) {
                    max_len = max(max_len, len[j]+1);
                }
            }
            len[i] = max_len;
            result = max(result, len[i]);
        }
        return result;
    }
    
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] == b[0])
            return a[1]>b[1];
        return a[0]>b[0];
    }
};