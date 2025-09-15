class Solution {
public:
    bool found(string word, unordered_set<char> se) {
        for (int i = 0; i < word.size(); i++) {
            if (se.count(word[i])) return true;
        }
        return false;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> m;  
        unordered_set<char> se(brokenLetters.begin(), brokenLetters.end());
        int n = text.size();

        for (int i = 0; i < n; i++) {
            string s = "";
            while (i < n && text[i] != ' ') { 
                s += text[i];
                i++;
            }
            m.push_back(s);
        }

        int ans = m.size();
        for (int i = 0; i < m.size(); i++) {
            if (found(m[i], se)) ans--;
        }
        return ans;
    }
};
