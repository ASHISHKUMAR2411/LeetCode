class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        for i in range(len(s)):
            if s[i] in t:
                t = t.replace(s[i],"",1)
            else:
                return False
        if len(t) == 0:
            return True
        return False