class Solution {
    bool IsNotValidChar(char c)
    {
        if((c >= 'a' && c <= 'z')
        || (c >='A' && c <= 'Z')
        || (c >= '0' && c <= '9'))
            return false;
        return true;
    }
    bool IsNotEqual(char a, char b)
    {
        if(a == b)
            return false;
        if(a >= 'a')
            a = 'A' + (a - 'a');
        if(b >= 'a')
            b = 'A' + (b - 'a');
        return !(a == b);
    }
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int start = 0, end = n-1;
        while(start < end)
        {
            while(IsNotValidChar(s[start]))
                start++;
            while(IsNotValidChar(s[end]))
                end--;
            if(start >= end)
                break;
            if(IsNotEqual(s[start], s[end]))
                return false;
            start++;
            end--;
        }
        return true;
    }
};
