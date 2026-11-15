class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftRem = 0, rightRem = 0;
        for (char c : s) {
            if (c == '(') {
                leftRem++;
            } else if (c == ')') {
                if (leftRem > 0) {
                    leftRem--;
                } else {
                    rightRem++;
                }
            }
        }

        vector<string> res;
        dfs(s, 0, leftRem, rightRem, res);
        return res;
    }

private:
    void dfs(string s, int start, int leftRem, int rightRem, vector<string>& res) {
        if (leftRem == 0 && rightRem == 0) {
            if (isValid(s)) {
                res.push_back(s);
            }
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (i != start && s[i] == s[i - 1]) continue;

            if (s[i] == '(' && leftRem > 0) {
                dfs(s.substr(0, i) + s.substr(i + 1), i, leftRem - 1, rightRem, res);
            } else if (s[i] == ')' && rightRem > 0) {
                dfs(s.substr(0, i) + s.substr(i + 1), i, leftRem, rightRem - 1, res);
            }
        }
    }

    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }
};
