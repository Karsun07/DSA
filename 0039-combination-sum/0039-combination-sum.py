class Solution:
    def fun(self, i, target, temp, candidates, ans):
        
        if target == 0:
            ans.append(temp.copy())
            return
        
        if i == len(candidates) or target < 0:
            return
        
        self.fun(i+1, target, temp, candidates, ans)

        temp.append(candidates[i])
        self.fun(i, target-candidates[i], temp, candidates, ans)
        temp.pop()


    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        temp = []

        self.fun(0, target, temp, candidates, ans)

        return ans