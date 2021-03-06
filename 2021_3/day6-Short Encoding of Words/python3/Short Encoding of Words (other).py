class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        indices = set(words)
        
        for word in words:
            for i in range(1,len(word)):
                indices.discard(word[i:])
              
        
        return sum(len(word)+1 for word in indices)