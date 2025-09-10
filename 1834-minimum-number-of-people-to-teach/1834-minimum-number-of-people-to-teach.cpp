class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // i am using the idea that i will find the most spoken language among
        // the people who are in "bad friendships" (i.e., pairs that cannot communicate),
        // and then teach that language to the remaining people in that set.

        int m = languages.size(); // number of people

        // build a set of known languages for each person for O(1) membership checks
        vector<unordered_set<int>> knows(m);
        for (int i = 0; i < m; ++i) {
            for (int lang : languages[i]) knows[i].insert(lang);
        }

        // find all people who are in friendships where they cannot currently communicate
        unordered_set<int> needTeach; // 0-based indices of people who might need teaching
        for (auto &f : friendships) {
            int u = f[0] - 1;
            int v = f[1] - 1;
            bool canCommunicate = false;
            // check if they share any language
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) { 
                    canCommunicate = true; 
                    break; }
            }
            if (!canCommunicate) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }

        // if no one is in a bad friendship, no one needs to be taught
        if (needTeach.empty()) return 0;

        // count how many people in needTeach already know each language
        vector<int> countKnown(n + 1, 0); // languages are 1-indexed
        for (int person : needTeach) {
            for (int lang : knows[person]) {
                countKnown[lang]++;
            }
        }

        // choose the language that maximizes known count among needTeach
        int best = INT_MAX;
        int needSize = (int)needTeach.size();
        for (int lang = 1; lang <= n; ++lang) {
            // number to teach if we pick `lang` = people in needTeach who DON'T know lang
            int toTeach = needSize - countKnown[lang];
            best = min(best, toTeach);
        }

        return best;
    }
};
