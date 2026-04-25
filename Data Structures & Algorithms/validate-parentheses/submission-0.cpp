class Solution {
    bool IsOpenBracket(char c)
    {
        if(c == '{' || c == '(' || c == '[')
            return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s)
        {
            if(st.empty() || IsOpenBracket(ch))
            {
                st.push(ch);
                continue;
            }
            switch(ch)
            {
                case ')':
                    if(st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if(st.top() != '{')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if(st.top() != '[')
                        return false;
                    st.pop();
                    break;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
