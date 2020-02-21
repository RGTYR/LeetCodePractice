class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dictionary = {}
        
    def isEqual(self, stringA : str, stringB : str) -> bool:
        for i in range(len(stringA)):
            if stringA[i] == '.' or stringB[i] == '.':
                continue

            if stringA[i] != stringB[i]:
                print("Test", stringA[i], stringB[i])
                return False
        
        return True


    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        if (word == None):
            return False

        if self.dictionary.get(len(word), None) == None:
            self.dictionary[len(word)] = [word]
        else:
            self.dictionary[len(word)].append(word)
        
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        if (word == "a"):
            print(self.dictionary.items())

        if word == None:
            return False
        
        if self.dictionary.get(len(word), None) == None:
            return False
        
        for string in self.dictionary[len(word)]:
            if self.isEqual(string, word):
                return True

        return False

# wd = WordDictionary()
# wd.addWord("bad")
# print(wd.dictionary.items())
# print(wd.search("a"))        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)