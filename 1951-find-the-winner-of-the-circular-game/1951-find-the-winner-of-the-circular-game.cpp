class Solution {
public:
    int winner(vector<bool>& person, int n, int index, int person_left, int k) {
        if (person_left == 1) {
            for (int i = 0; i < n; i++) {
                if (person[i] == 0) {
                    return i;
                }
            }
        }

        int kill = (k - 1) % person_left;  

        
        while (kill > 0) {
            index = (index + 1) % n;
            if (person[index] == 0) {
                kill--;
            }
        }

        
        while (person[index] == 1) {
            index = (index + 1) % n;
        }

        person[index] = 1;  

        while(person[index]==1){
            index=(index+1)%n;

        }

        
        

        return winner(person, n, index, person_left - 1, k);
    }

    int findTheWinner(int n, int k) {
        vector<bool> person(n, 0);
        int person_left = n;
        return winner(person, n, 0, n, k) + 1;
    }
};