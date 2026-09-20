class Solution {
public:
    int reverseDegree(string s) {
        int totalSum = 0;
        for (int i = 0; i < s.length(); ++i) {
            int revAlphabetIndex = 26 - (s[i] - 'a');
            int stringIndex = i + 1;
            totalSum += revAlphabetIndex * stringIndex;
        }
        return totalSum;
    }
};