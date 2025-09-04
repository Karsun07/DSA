class Solution {
public:
    int findClosest(int x, int y, int z) {
        x=abs(z-x);
        y=abs(z-y);
        if(x<y) return 1;
        if(x>y) return 2;
        return 0;
    }
};