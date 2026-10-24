class Solution {
public:
    int countDaysTogether(string aA, string lA, string aB, string lB) {

        int Aam, Aad;
        int Alm, Ald;
        int Bam, Bad;
        int Blm, Bld;

        Aam = stoi(aA.substr(0, 2));
        Aad = stoi(aA.substr(3, 2));

        Alm = stoi(lA.substr(0, 2));
        Ald = stoi(lA.substr(3, 2));

        Bam = stoi(aB.substr(0, 2));
        Bad = stoi(aB.substr(3, 2));

        Blm = stoi(lB.substr(0, 2));
        Bld = stoi(lB.substr(3, 2));

        int arr[13] = {
            0, 31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int As = Aad;
        for(int i = 1; i < Aam; i++)
            As += arr[i];

        int Bs = Bad;
        for(int i = 1; i < Bam; i++)
            Bs += arr[i];

        int Ae = Ald;
        for(int i = 1; i < Alm; i++)
            Ae += arr[i];

        int Be = Bld;
        for(int i = 1; i < Blm; i++)
            Be += arr[i];

        int start = max(As, Bs);
        int end = min(Ae, Be);

        if(start > end)
            return 0;

        return end - start + 1;
    }
};