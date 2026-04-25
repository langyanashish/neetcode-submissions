class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c]++;
        unordered_map<char, int> np;
        for(char c : t)
            np[c]++;
        if(mp == np)
            return true;
        return false;
   }
};