class Solution {
public:
    int MOD = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        vector<long> dp(n, 1);
        
        sort(arr.begin(), arr.end());
        
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j]; // another child, arr[j] is one child
                    if (pos.count(right)) {
                        dp[i] += dp[j] * dp[pos[right]];
                        dp[i] %= MOD;
                    }
                }
            }
        }
        
        int ans = 0;
        for (long d : dp) {
            ans += d;
            ans %= MOD;
        }
        
        return ans;
    }
};