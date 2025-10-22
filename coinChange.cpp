class Solution {
public:
    // int solveMem(vector<int>& coins, int amount,vector<int>& dp){
    //     if(amount<=0) return 0;
    //     if(dp[amount]!=-1) return dp[amount];

    //      int minCoinAns=INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //           int coin=coins[i];
    //           if(coin<=amount){
    //             int res=solveMem(coins,amount-coin,dp);
    //             if(res!=INT_MAX){
    //                 int coinsUsed=1+res;
    //                 minCoinAns=min(minCoinAns,coinsUsed);
    //             }
    //           }
    //           dp[amount]=minCoinAns;
    //     }
    //     return dp[amount];
    // }

    int solveTab(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int amt = 1; amt <= amount; amt++) {
            int minCoinAns = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                int coin = coins[i];
                if (coin <= amt) {
                    int res = dp[amt - coin];
                    if (res != INT_MAX) {
                        int coinsUsed = 1 + res;
                        minCoinAns = min(minCoinAns, coinsUsed);
                    }
                }
            }
            dp[amt] = minCoinAns;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount+1,-1);
        // int ans=solveMem(coins,amount,dp);
        int ans = solveTab(coins, amount);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
