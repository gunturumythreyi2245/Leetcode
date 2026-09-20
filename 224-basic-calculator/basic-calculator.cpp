#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        long num = 0; // Use long to prevent integer overflow during parsing
        int sign = 1;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                result += sign * num;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                int prevSign = st.top(); st.pop();
                int prevResult = st.top(); st.pop();
                
                result = prevResult + prevSign * result;
            }
        }

        return result;
    }
};