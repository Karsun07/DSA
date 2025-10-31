class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        priority_queue<long long>p(target.begin(),target.end());
        long long maxele,remsum,element,sum=0;
        for(int i=0;i<n;i++){
            sum+=target[i];
        }
        while(p.top()!=1){
            maxele=p.top();
            p.pop();
            remsum=sum-maxele;
            if(remsum<=0 || remsum>=maxele) return 0;

            element=maxele%remsum;
            if(element==0){
                if(remsum!=1) return 0;
                else return 1;
            }
            p.push(element);
            sum=remsum+element;
        }
        return 1;


    }
};