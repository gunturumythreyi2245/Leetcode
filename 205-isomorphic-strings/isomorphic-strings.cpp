class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Since we are dealing with standard ASCII characters, 
        // fixed-size arrays of size 256 act as incredibly fast lookup tables.
        int mapS[256] = {0};
        int mapT[256] = {0};
        // Both strings are guaranteed to be of equal length per constraints
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            // Get the ASCII values of the current characters
            unsigned char charS = s[i];
            unsigned char charT = t[i];
            // If their last recorded positions don't match, the mapping is broken
            if (mapS[charS] != mapT[charT]) {
                return false;
            }
            mapS[charS] = i + 1;
            mapT[charT] = i + 1;
        }
        return true;
    }
};
