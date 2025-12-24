class Solution {
public:
    static bool cmp(int &a,int &b){
        return a>b;
    }
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=0;
        for(int i=0;i<apple.size();i++){
            total+=apple[i];
        }
        sort(capacity.begin(),capacity.end(),cmp);
        int ans=0;
        int i=0;
        while(i<capacity.size()&&total>0){
            total-=capacity[i];
            i++;
            ans++;
        }
        return ans;
    }
};