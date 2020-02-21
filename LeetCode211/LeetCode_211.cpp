//LeetCode_211
#include<map>
#include<vector>

class WordDictionary 
{

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        dictionary[word.size()].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
        for (auto str : dictionary[word.size()])
        	if (isEqual(word, str))
        		return true;
        
        return false;
    }
    
private:
    
    unordered_map<int, vector<string>> dictionary;

    bool isEqual(string stringA, string stringB)
    {
        for (int i = 0; i < stringA.size(); i++)
        {
            if (stringA[i] == '.' || stringB[i] == '.')
            {
                continue;
            }
            
            if (stringA[i]  != stringB[i])
            {
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
