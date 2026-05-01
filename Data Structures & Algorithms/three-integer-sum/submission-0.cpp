class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3)
            return {};
        vector<vector<int>> ans;
        for(int start = 0; start < n - 1; start++)
        {
            if(start > 0 && nums[start] == nums[start-1])
                continue;
            int mid = start + 1;
            int end = n - 1;
            while(mid < end)
            {
                int sum = nums[start] + nums[mid] + nums[end];
                if(sum == 0)
                {
                    ans.push_back({nums[start], nums[mid], nums[end]});
                    while(mid < end && nums[mid] == nums[mid+1])
                        mid++;
                    while(mid < end && nums[end] == nums[end-1])
                        end--;
                    mid++;
                    end--;
                }
                else if(sum > 0)    
                    end--;
                else
                    mid++;
            }
        }
        return ans;
    }
};
