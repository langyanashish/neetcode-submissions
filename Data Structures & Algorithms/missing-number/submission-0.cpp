class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int exor = 0, max_n;
        for(int n : nums)
            exor = exor ^ n;
        for(int i = 1; i <= nums.size(); i++)
            exor = exor ^ i;
        return exor;
    }
};
