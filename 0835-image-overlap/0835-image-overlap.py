class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n=len(img1)
        ans=float('-inf')
        for roff in range(-n+1,n,1):
            for coff in range(-n+1,n,1):
                temp=0
                for i in range(n):
                    for j in range(n):
                        if (i+roff)<n and (j+coff)<n and i+roff>=0 and j+coff>=0:
                            temp+=img1[i+roff][j+coff]*img2[i][j]
                  
                ans=max(ans,temp)
        
        return ans
        




                        