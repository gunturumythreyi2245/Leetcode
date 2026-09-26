#include <string>
#include <vector>
#include <unordered_map>
class Solution {
public:
    std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge) {
        std::unordered_map<std::string, std::string> mp;
        for (const auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }
        std::string result = "";
        std::string current_key = "";
        bool in_bracket = false;
        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
                current_key = "";
            } else if (c == ')') {
                in_bracket = false;
                if (mp.count(current_key)) {
                    result += mp[current_key];
                } else {
                    result += '?';
                }
            } else {
                if (in_bracket) {
                    current_key += c;
                } else {
                    result += c;
                }
            }
        }
        return result;
    }
};