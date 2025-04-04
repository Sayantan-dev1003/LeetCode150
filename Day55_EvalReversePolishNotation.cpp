class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = 0;
                if (token == "+")
                    res = a + b;
                else if (token == "-")
                    res = a - b;
                else if (token == "*")
                    res = a * b;
                else if (token == "/")
                    res = a / b;
                st.push(res);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
