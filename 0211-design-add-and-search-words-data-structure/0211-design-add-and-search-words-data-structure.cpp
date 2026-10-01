class WordDictionary {
public:
    unordered_map<int, vector<string>> mp;

    WordDictionary() {
        mp.clear();
    }
    
    void addWord(string word) {
        int len = word.size();
        mp[len].push_back(word);
    }
    
    bool search(string word) {
        int len = word.size();

        for (auto &s : mp[len]) {

            int i = 0, j = 0;

            while (i < len && j < len) {

                if (word[j] == '.' || s[i] == word[j]) {
                    i++;
                    j++;
                }
                else {
                    break;  
                }
            }

            if (i == len && j == len)
                return true;
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */