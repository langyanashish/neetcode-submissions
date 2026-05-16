class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minProd = nums[0], maxProd = nums[0], ans = nums[0];
        for(int i = 1; i < n; i++)
        {
            int x = nums[i];
            if(x < 0)
                swap(minProd, maxProd);
            maxProd = max(x, x*maxProd);
            minProd = min(x, x*minProd);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};
