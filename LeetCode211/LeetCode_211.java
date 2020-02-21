import java.util.*;

class WordDictionary {

    private Map map = new HashMap<Integer, Vector<String>>();

    private boolean isEqual(String stringA, String stringB)
    {
        for (int i = 0; i < stringA.length(); i++)
        {
            if (stringA.charAt(i) == '.' || stringB.charAt(i) == '.')
                continue;
            if (stringA.charAt(i) != stringB.charAt(i))
                return false;
        }
        return true;
    }

    /** Initialize your data structure here. */
    public WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        
        if (map.get(word.length()) == null)
        {
            map.put(word.length(), new Vector<String>());
        }

        Vector vector = (Vector) map.get(word.length());
        vector.add(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) 
    {
        if (map.get(word.length()) != null)
            for (var str : (Vector) map.get(word.length()))
            {
                if (isEqual(word, (String) str))
                    return true;
            }

        return false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */