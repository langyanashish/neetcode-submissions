class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0, mid = 1, right = n-1;
        int maxProfit = 0;
        while(mid <= right)
        {
            if(prices[mid] < prices[left])
            {
                left = mid;
                continue;
            }
            maxProfit = max(maxProfit, prices[mid] - prices[left]);
            mid++;
        }
        return maxProfit;
    }
};
