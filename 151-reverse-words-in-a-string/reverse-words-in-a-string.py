class Solution:
    def reverseWords(self, s: str) -> str:
        # Split automatically handles multiple spaces and strips extras
        words = s.split()
        
        # Reverse the list of words in-place
        words.reverse()
        
        # Join the reversed words with a single space
        return " ".join(words)
