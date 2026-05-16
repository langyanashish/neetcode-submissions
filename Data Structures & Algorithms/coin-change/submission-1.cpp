class Solution {
    vector<int> dp;
    int solve(auto& coins, int amount)
    {
        if(amount == 0)
            return 0;
        if(amount < 0)
            return INT_MAX;
        if(dp[amount] != -1)
            return dp[amount];
        int ans = INT_MAX;
        for(int coin : coins)
        {
            int res = solve(coins, amount-coin);
            if(res != INT_MAX)
                ans = min(ans, res+1);
        }
        return dp[amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1, -1);
        int ans = solve(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
