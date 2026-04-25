class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int n : nums)
        {
            if(mp[n])
                return true;
            mp[n] = true;
        }
        return false;
    }
};