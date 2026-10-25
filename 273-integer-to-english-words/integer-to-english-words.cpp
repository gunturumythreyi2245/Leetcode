#include <string>
#include <vector>

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num);
    }

private:
    const vector<string> belowTwenty = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
    };
    
    const vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string helper(int num) {
        if (num < 20) {
            return belowTwenty[num];
        } else if (num < 100) {
            return tens[num / 10] + (num % 10 != 0 ? " " + belowTwenty[num % 10] : "");
        } else if (num < 1000) {
            return belowTwenty[num / 100] + " Hundred" + (num % 100 != 0 ? " " + helper(num % 100) : "");
        } else if (num < 1000000) {
            return helper(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + helper(num % 1000) : "");
        } else if (num < 1000000000) {
            return helper(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + helper(num % 1000000) : "");
        } else {
            return helper(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + helper(num % 1000000000) : "");
        }
    }
};
