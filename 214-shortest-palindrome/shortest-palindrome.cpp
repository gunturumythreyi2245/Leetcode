#include <string>
#include <vector>
#include <algorithm>
class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        int n=s.length();
        if (n<=1)return s;
        std::string rev=s;
        std::reverse(rev.begin(),rev.end());
        std::string temp=s +"#"+rev;
        int m=temp.length();
        std::vector<int>lps(m, 0);
        for(int i=1;i<m;++i) {
            int j=lps[i-1];
            while(j>0&&temp[i]!=temp[j]){
                j=lps[j-1];
            }
            if(temp[i]==temp[j]) {
                j++;
            }
            lps[i]=j;
        }
        int longest_palette_len=lps[m-1];
        std::string remaining=s.substr(longest_palette_len);
        std::reverse(remaining.begin(), remaining.end());
        return remaining + s;
    }
};
