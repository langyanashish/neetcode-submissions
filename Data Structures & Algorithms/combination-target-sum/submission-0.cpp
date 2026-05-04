class Solution {
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int target, int idx, int sum, vector<int>& cur)
    {
        if(idx >= nums.size() || sum > target)
            return;
        if(sum == target)
        {
            ans.push_back(cur);
            return;
        }

        sum += nums[idx];
        cur.push_back(nums[idx]);
        solve(nums, target, idx, sum, cur);
        sum -= nums[idx];
        cur.pop_back();
        
       solve(nums, target, idx+1, sum, cur);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        solve(nums, target, 0, 0, cur);
        return ans;
    }
};
