class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> list[str]:
        word_set = set(wordDict)
        memo = {}
        
        def dfs(start: int) -> list[str]:
            if start in memo:
                return memo[start]
                
            if start == len(s):
                return [""]
                
            res = []
            for end in range(start + 1, len(s) + 1):
                word = s[start:end]
                
                if word in word_set:
                    sub_sentences = dfs(end)
                    for sub in sub_sentences:
                        if sub == "":
                            res.append(word)
                        else:
                            res.append(word + " " + sub)
                            
            memo[start] = res
            return res
            
        return dfs(0)
