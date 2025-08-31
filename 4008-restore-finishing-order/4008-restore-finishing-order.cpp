class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> answer;
        for (int o : order) {
            for (int f : friends) {
                if(o== f) {
                    answer.push_back(o);
                    break;
                }
            }
        }
        return answer;
        
    }
};