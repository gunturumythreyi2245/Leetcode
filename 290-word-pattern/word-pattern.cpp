#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::vector<std::string> words;
        std::stringstream ss(s);
        std::string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        if (pattern.length() != words.size()) {
            return false;
        }
        
        std::unordered_map<char, std::string> charToWord;
        std::unordered_map<std::string, char> wordToChar;
        
        for (size_t i = 0; i < pattern.length(); ++i) {
            char ch = pattern[i];
            const std::string& w = words[i];
            
            if (charToWord.count(ch) && charToWord[ch] != w) {
                return false;
            }
            if (wordToChar.count(w) && wordToChar[w] != ch) {
                return false;
            }
            
            charToWord[ch] = w;
            wordToChar[w] = ch;
        }
        
        return true;
    }
};
