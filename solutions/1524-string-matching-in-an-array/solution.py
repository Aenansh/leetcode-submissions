class Solution(object):
    def stringMatching(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        ans = []
        for word1 in words:
            match = word1
            for word2 in words:
                if word1 != word2 and word1 in word2:
                    if word1 not in ans:
                        ans.append(word1)
        return ans
        
