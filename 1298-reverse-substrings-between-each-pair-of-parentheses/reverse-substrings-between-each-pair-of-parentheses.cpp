class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string result = "";
        for (int curr = 0, dir = 1; curr < n; curr += dir) {
            if (s[curr] == '(' || s[curr] == ')') {
                curr = pair[curr];
                dir = -dir;
            } else {
                result += s[curr];
            }
        }

        return result;
    }
};