class Solution {
public:
//using queue
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       queue<int>q;
       int t=0;
       for(int i=0;i<tickets.size();i++){
        q.push(i);
       }
       
       while(!q.empty()){
         tickets[q.front()]--;
         t++;
         if(tickets[k]==0) break;
         else if(tickets[q.front()]>0) q.push(q.front());
         q.pop();


       }
       return t;
       
    }
};