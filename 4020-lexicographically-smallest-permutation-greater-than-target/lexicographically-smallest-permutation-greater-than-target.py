class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        count = [0] * 26
        for ch in s:
            count[ord(ch) - ord('a')] += 1
        best = -1
        temp = count[:]
        for i in range(len(target)):
            current = ord(target[i]) - ord('a')
            for j in range(current + 1, 26):
                if temp[j] > 0:
                    best = i
                    break
            if temp[current] == 0:
                break
            temp[current] -= 1
        if best == -1:
            return ""
        ans = []
        for i in range(best):
            ans.append(target[i])
            count[ord(target[i]) - ord('a')] -= 1
        current = ord(target[best]) - ord('a')
        for j in range(current + 1, 26):
            if count[j] > 0:
                ans.append(chr(j + ord('a')))
                count[j] -= 1
                break
        for j in range(26):
            while count[j] > 0:
                ans.append(chr(j + ord('a')))
                count[j] -= 1

        return ''.join(ans)