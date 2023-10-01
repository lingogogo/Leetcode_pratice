class Solution {
public:
    bool isValid(string s) {
        int count_size = s.size();
        int i = 0;
        stack<char> sc;

        for(char c:s)
        {
            if(c=='(' || c == '{' || c == '[')
            {
                sc.push(c);
            }
            else
            {
                if(sc.empty() || (c == ')' && sc.top() != '(')||
                (c == '}' && sc.top() != '{')||
                (c == ']' && sc.top() != '['))
                return false;
                sc.pop();
            }
        }
        return sc.empty();
    }
};
