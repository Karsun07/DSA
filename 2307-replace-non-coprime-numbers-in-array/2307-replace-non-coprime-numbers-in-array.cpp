class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (1LL * a / gcd(a, b)) * b; 
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        queue<int> q;
        for (int x : nums) q.push(x);

        vector<int> ans;

        while (!q.empty()) {
            int a = q.front();
            q.pop();

            
            while (!q.empty()) {
                int b = q.front();

                if (gcd(a, b) > 1) {
                    
                    q.pop();
                    a = lcm(a, b);
                } 
                else {
                   
                    break;
                }
            }

            
            while (!ans.empty() && gcd(ans.back(), a) > 1) {
                a = lcm(ans.back(), a);
                ans.pop_back();
            }

            ans.push_back(a);
        }

        return ans;
    }
};
