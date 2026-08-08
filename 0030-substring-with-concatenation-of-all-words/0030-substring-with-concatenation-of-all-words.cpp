class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string,int> map;
        int length = words[0].size();

        map.clear();
        for (string & word : words)
            map[word]++;

        for (int offset = 0; offset < length; ++offset) {
            int size = 0;
            unordered_map<string,int> seen;
            for (int i = offset; i + length <= s.size(); i += length) {
                string sub = s.substr(i, length);

                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                ++seen[sub];
                ++size;
                while (seen[sub] > itr->second) {
                    string first = s.substr(i - (size - 1) * length, length);
                    --seen[first];
                    --size;
                }
                
                if (size == words.size())
                    result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }
};