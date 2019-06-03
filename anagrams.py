class Solution:
    # @param A : tuple of strings
    # @return a list of list of integers
    def anagrams(self, A):
        N = len(A)
        anagrams_store = {}
        for index in range(N):
            word = " "
            word = word.join(sorted(A[index]))
            if word in anagrams_store:
                anagrams_store[word].append(index+1)
            else:
                anagrams_store[word] = [index+1]
        result = list(anagrams_store.values())
        result.sort()
        return result
                
        
