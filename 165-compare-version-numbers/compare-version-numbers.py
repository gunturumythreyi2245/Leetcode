class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        # Split version strings by the dot character
        v1_revisions = version1.split('.')
        v2_revisions = version2.split('.')
        
        len1 = len(v1_revisions)
        len2 = len(v2_revisions)
        
        # Iterate through the longest version array length
        for i in range(max(len1, len2)):
            # Convert string to int if it exists, otherwise use 0
            rev1 = int(v1_revisions[i]) if i < len1 else 0
            rev2 = int(v2_revisions[i]) if i < len2 else 0
            
            # Compare the revision integers
            if rev1 < rev2:
                return -1
            if rev1 > rev2:
                return 1
                
        # Both versions are perfectly equal
        return 0
