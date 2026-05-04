class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = nums[0];
        for(int i = 0; i < n; i++)
        {
            if(maxReach < i)
                return false;
            if(i + nums[i] > maxReach)
                maxReach = i + nums[i];
        }
        return true;
    }
};
// i = 2, nums[i] = 3
//3, 4, 5
