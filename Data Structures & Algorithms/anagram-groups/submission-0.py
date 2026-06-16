class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash = {}
        for word in strs:
          sortedWord = ''.join(sorted(word))
          if sortedWord not in hash:
            hash[sortedWord] = [word]
          else:
            hash[sortedWord].append(word)
        
        return list(hash.values())

