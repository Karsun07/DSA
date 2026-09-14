class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:

        r1x1, r1y1, r1x2, r1y2 = rec1
        r2x1, r2y1, r2x2, r2y2 = rec2

        if r1x1 < r2x1:
            # rec1  on  left
            if r1x2 <= r2x1:
                return False

            if r1y1 >= r2y2:
                return False

            if r2y1 >= r1y2:
                return False

        elif r1x1 > r2x1:
            # rec1  on  right
            if r1x1 >= r2x2:
                return False

            if r2y1 >= r1y2:
                return False

            if r1y1 >= r2y2:
                return False

        else:
            # Same x1
            if r1y1 >= r2y2 or r2y1 >= r1y2:
                return False

        return True