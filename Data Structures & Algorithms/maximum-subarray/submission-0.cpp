class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            curSum += nums[i];
            if(nums[i] > curSum)
                curSum = nums[i];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
