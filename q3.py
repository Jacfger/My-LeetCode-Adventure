from collections import defaultdict


class Solution:
    def isRepeated(self, c, i):
        return c in self.characterSet[i]

    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        symbolIndex = defaultdict(lambda: -1)
        start_index = 0
        maxLength = 1
        for i, c in enumerate(s):
            if symbolIndex[c] >= start_index:
                start_index = symbolIndex[c] + 1
            maxLength = max(maxLength, i - start_index + 1)
            symbolIndex[c] = i

        return maxLength


sol = Solution()
print(sol.lengthOfLongestSubstring("abcabcbb"))
