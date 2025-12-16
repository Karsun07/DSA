class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxcount = 0;

        for(int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
            maxcount = max(maxcount, freq[tasks[i] - 'A']);
        }

        int ans = (maxcount - 1) * (n + 1);

        for(int i = 0; i < 26; i++) {
            if(freq[i] == maxcount)
                ans++;
        }

        return ans > tasks.size() ? ans : tasks.size();
    }
};
