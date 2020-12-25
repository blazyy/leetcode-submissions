class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cmap = {}
        start = longest = 0
        for i, ch in enumerate(s):
            if ch in cmap and cmap[ch] >= start:
                start = cmap[ch] + 1
            cmap[ch] = i
            longest = max(longest, i + 1 - start)
        return longest
