class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp[prices.size()][2];
        int last_buy = prices[0];
        //0為手上沒股票，1為手上有股票
        dp[0][0] = 0;
        dp[0][1] = -prices[0];  //購入成本
        
        
        for(int i=1;i<prices.size();i++) {
            //不買不賣 或是 賣出 找最大利潤
            dp[i][0] = max(dp[i-1][0], prices[i]+dp[i-1][1]-fee);
            //買入(扣成本) 或是 不買不賣 找最大利潤
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
        }
        
        return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
    }
};