class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto i : s) {
            if(i == '(' or i == '[' or i == '{')
                st.push(i);
            else {
                if(st.empty()) return false;
                if(i == ')' && st.top() == '(')
                    st.pop();
                else if(i == '}' && st.top() == '{')
                    st.pop();
                else if(i == ']' && st.top() == '[')
                    st.pop();
                else return false;
            }
        }
        
        if(!st.empty()) return false;
        
        return true;
    }
};