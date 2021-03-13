class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, int> m;
        int ans = 0, factor, modulo = 1e9+7, num;
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<arr.size();i++) {
            m[arr[i]] = 1;
            for(int j=0;j<i;j++) {
                factor = arr[j];
                num = arr[i];
                if(num % factor == 0 && m.count(num/factor)) { //加上m.count(num/factor)避免分配記憶體到無用的數字上
                    m[num] += ((long long)m[num/factor]*m[factor])%modulo;
                    m[num] %= modulo;
                }
            }
            ans += m[arr[i]];
            ans %= modulo;
        }
        
        return ans;
    }
};