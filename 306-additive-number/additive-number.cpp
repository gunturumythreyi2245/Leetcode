class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n / 2; ++i) {
            if (num[0] == '0' && i > 1) break;
            string s1 = num.substr(0, i);
            for (int j = 1; n - i - j >= max(i, j); ++j) {
                if (num[i] == '0' && j > 1) break;
                string s2 = num.substr(i, j);
                if (isValid(s1, s2, i + j, num)) return true;
            }
        }
        return false;
    }

private:
    bool isValid(string s1, string s2, int idx, const string& num) {
        if (idx == num.size()) return true;
        string sum = addStrings(s1, s2);
        if (num.compare(idx, sum.size(), sum) != 0) return false;
        return isValid(s2, sum, idx + sum.size(), num);
    }

    string addStrings(const string& a, const string& b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};