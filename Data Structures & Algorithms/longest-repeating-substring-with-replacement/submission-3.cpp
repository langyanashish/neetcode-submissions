class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        int ans = 0, maxFreq = 0;
        while(right < n)
        {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);
            while((right-left+1) - maxFreq > k)
                mp[s[left++]]--;
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};
