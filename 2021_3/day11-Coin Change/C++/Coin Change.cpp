class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        
        int ans = 0;
        int coin_num[amount+1];
        memset(coin_num,-1,sizeof(coin_num));
        coin_num[0] = 0;
        
        for(int i=0;i<=amount;i++) {
            for(auto coin: coins) {
                if(coin<=amount-i && coin_num[i]!=-1 && (coin_num[i+coin]==-1||coin_num[i+coin]>coin_num[i]+1))
                    coin_num[i+coin] = coin_num[i]+1;
            }
        }
        return coin_num[amount];
    }
};