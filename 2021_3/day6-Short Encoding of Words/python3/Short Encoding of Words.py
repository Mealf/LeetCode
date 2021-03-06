class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        indices = set(words)
        
        for word in words:
            for i in range(1,len(word)):
                indices.discard(word[i:])
              
        ans = 0
        for word in indices:
            ans += len(word) + 1
        return ans