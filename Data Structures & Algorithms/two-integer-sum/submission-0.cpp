class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int i = 0;
        for(int n : nums)
        {
            if(mp.find(target - n) !=mp.end())
                return {mp[target - n], i};
            mp[n] = i++;
        }
        return {0,0};
    }
};
