class Solution {
    int ans = INT_MAX;
    void solve(auto& coins, int amount, int nums, int idx)
    {
        if(idx < 0)
            return;
        if(amount == 0)
        {
            ans = min(ans, nums);
        }
        if(amount < coins[idx])
        {
            solve(coins, amount, nums, idx-1);
            return;
        }
        solve(coins, amount-coins[idx], nums+1, idx);
        solve(coins, amount, nums, idx-1);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        solve(coins, amount, 0, n-1);
        return ans == INT_MAX ? -1 : ans;
    }
};
