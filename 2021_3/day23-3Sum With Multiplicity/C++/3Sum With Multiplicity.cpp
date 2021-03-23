class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<int, int> m;
        int result = 0, MOD = 1e9+7;
        for(int i=0;i<arr.size();i++) {
            if(m.count(target-arr[i]))  //m[target-arr[i]] 為arr[i]+arr[j]的排列組合數量
                result = (result + m[target-arr[i]])%MOD;
            
            for(int j=0;j<i;j++) {
                m[arr[i]+arr[j]]++;
            }
        }
        return result;
    }
};