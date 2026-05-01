class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0, right = 1;
        int maxProfit = 0;
        while(right < n)
        {
            if(prices[right] < prices[left])
            {
                left = right;
                continue;
            }
            maxProfit = max(maxProfit, prices[right] - prices[left]);
            right++;
        }
        return maxProfit;
    }
};
