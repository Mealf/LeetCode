class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coin_num(amount+1, INT_MAX);
        coin_num[0] = 0;
        
        for(int i=1;i<=amount;i++) {
            for(auto coin: coins) {
                if(i>=coin && coin_num[i-coin]!=INT_MAX)
                    coin_num[i] = min(coin_num[i], coin_num[i-coin]+1);
            }
        }
        return (coin_num[amount]==INT_MAX? -1: coin_num[amount]);
    }
};