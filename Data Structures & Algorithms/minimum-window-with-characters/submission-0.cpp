class Solution {
public:
    string minWindow(string source, string target) {
        if(source.empty() || target.empty())
            return "";
        unordered_map<char, int> mp, window;
        vector<int> ans = {INT_MAX, 0, 0};
        for(char c : target)
            mp[c]++;
        int required = mp.size(), left = 0, formed = 0;
        for(int right = 0; right < source.size(); right++)
        {
            char c = source[right];
            window[c]++;
            if(mp[c] == window[c])
                formed++;
            while(left <= right && formed == required)
            {
                c = source[left];
                if(ans[0] > right-left)
                    ans = {right-left, left, right};
                window[c]--;
                if(mp[c] && window[c] < mp[c])
                    formed--;
                left++;
            }
        }
        return ans[0]==INT_MAX ? "" : source.substr(ans[1], ans[0]+1);
    }
};
