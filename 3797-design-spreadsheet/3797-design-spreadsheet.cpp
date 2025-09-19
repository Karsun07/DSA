class Spreadsheet {
public:
    int rows;
    vector<vector<int>>m;
    Spreadsheet(int rows) {
        m=vector<vector<int>>(rows,vector<int>(26,0));
        
    }
    
    void setCell(string cell, int value) {
        int c=cell[0]-'A';//A=>0 col
        string num_str="";
        for(int i=1;i<cell.size();i++){
            num_str+=cell[i];
        }
        int r=stoi(num_str)-1;//1 row=>0
        m[r][c]=value;//A1=>10

        

        
    }
    
    void resetCell(string cell) {
        int c=cell[0]-'A';//A=>0 col
        string num_str="";
        for(int i=1;i<cell.size();i++){
            num_str+=cell[i];
        }
        int r=stoi(num_str)-1;//1 row=>0
        m[r][c]=0;

    }
    int fun(string cell){
        int c=cell[0]-'A';//A=>0 col
        string num_str="";
        for(int i=1;i<cell.size();i++){
            num_str+=cell[i];
        }
        int r=stoi(num_str)-1;//1 row=>0
        return m[r][c];

    }
    bool isCell(string cell){
        if(isalpha(cell[0])) return 1;
        return 0;
    }
    int getValue(string formula) {
        int n=formula.size();
        int ans=0;
        int i=0;
        while(i<n){
            if(formula[i]=='='){
                i++;
                string temp="";
                while(formula[i]!='+'){
                    temp+=formula[i];
                    i++;
                }
                if(isCell(temp))
                    ans+=fun(temp);
                else{
                    int x=stoi(temp);
                    ans+=x;
                }

            }
            
            
            if(formula[i]=='+'){
                i++;
                string temp2="";
                while(i<n){
                    temp2+=formula[i];
                    i++;
                }
                if(isCell(temp2))
                   ans+=fun(temp2);
                else{
                    int y=stoi(temp2);
                    ans+=y;
                }

            }

        }
        return ans;

        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */