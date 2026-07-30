class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for (int i = 0; i < n - 1; i++) {
            int need = target - numbers[i];

            auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), need);

            if (it != numbers.end() && *it == need) {
                return {i + 1, (int)(it - numbers.begin()) + 1};
            }
        }

        return {};
    }
};