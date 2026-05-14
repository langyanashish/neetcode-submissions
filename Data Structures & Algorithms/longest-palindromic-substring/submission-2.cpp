class Solution {
public:
    string longestPalindrome(string s) {
        int resIdx = 0, resLen = 0;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            //odd length
            int low = i, high = i;
            while(low >= 0 && high < n && s[low] == s[high])
            {
                if((high-low+1) > resLen)
                {
                    resLen = high-low+1;
                    resIdx = low;
                }
                low--;
                high++;
            }
            //even length
            low = i, high = i+1;
            while(low >= 0 && high < n && s[low] == s[high])
            {
                if((high-low+1) > resLen)
                {
                    resLen = high-low+1;
                    resIdx = low;
                }
                low--;
                high++;
            }
        }
        return s.substr(resIdx, resLen);
    }
};
