class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        map<int, bool> v;
        for(int n : nums)
            v[n] = true;
        int res = 0, cur = 1;
        for(auto i : v)
        {
            if(v[i.first - 1])
                cur++;
            else
            {
                res = max(res, cur);
                cur = 1;
            }
        }
        res = max(res, cur);
        return res;
    }
};
