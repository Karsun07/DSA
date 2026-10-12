class BusBooking {
public:
    int m;
    vector<vector<int>> mat;
    int total;
    int booked;

    BusBooking(int n) {
        m = n;
        total = 0;
        booked = 0;
        mat = vector<vector<int>>(m, vector<int>(4, 0));
    }

    void toggle(string s) {
        int seat = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;

        if (mat[row][seat] != 0) {
            total -= mat[row][seat];
            mat[row][seat] = 0;
            booked--;
            return;
        }

        if (seat == 1 || seat == 2) {
            mat[row][seat] = 1;
            total += 1;
        }
        else {
            int adjacent = (seat == 0) ? 1 : 2;

            if (mat[row][adjacent] != 0) {
                mat[row][seat] = 3;
                total += 3;
            }
            else {
                mat[row][seat] = 1;
                total += 1;
            }
        }

        booked++;
    }

    int getTotalTime() {
        return total;
    }

    int getMinTime() {
        return booked;
    }
};