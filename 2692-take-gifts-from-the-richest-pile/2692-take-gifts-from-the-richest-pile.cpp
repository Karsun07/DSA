#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> p; 

        for (int g : gifts) {
            p.push(g);
        }

        while (k-- && !p.empty()) {
            int top = p.top(); p.pop();
            p.push((int) sqrt(top));
        }

        long long ans = 0;
        while (!p.empty()) {
            ans += p.top();
            p.pop();
        }

        return ans;
    }
};
