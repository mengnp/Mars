/**
 *
 */

class Solution {
    public:
        bool isValid(string s) {
            if (s.empty())
                return true;
            stack<char> ss;
            int n = s.size();
            for(int i = 0; i < n; i++) {
                if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                    ss.push(s[i]);
                else
                {
                    if (ss.empty())
                        return false;
                    else if (ss.top() == '(' && s[i] == ')')
                        ss.pop();
                    else if (ss.top() == '(' && s[i] == ')')
                        ss.pop();
                    else if (ss.top() == '(' && s[i] == ')')
                        ss.pop();
                    else 
                        return false;
                }
            } 
        }
        if (ss.empty())
            return true;
        else
            return false;
};
