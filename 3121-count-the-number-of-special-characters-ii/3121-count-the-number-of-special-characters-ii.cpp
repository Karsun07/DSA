class Solution {
public:
    int numberOfSpecialChars(string word) {
        int small_lastocc[26], bigfirstocc[26];

        for(int i = 0; i < 26; i++) {
            small_lastocc[i] = -1;
            bigfirstocc[i] = -1;
        }

        for(int i = 0; i < word.size(); i++) {

            if(word[i] == tolower(word[i])) {
                small_lastocc[word[i] - 'a'] = i;
            }
            else {
                if(bigfirstocc[word[i] - 'A'] == -1)
                    bigfirstocc[word[i] - 'A'] = i;
            }
        }

        int count = 0;

        for(int i = 0; i < 26; i++) {
            if(small_lastocc[i] != -1 && bigfirstocc[i] != -1) {

                if(small_lastocc[i] < bigfirstocc[i]) {
                    count++;
                }
            }
        }

        return count;
    }
};