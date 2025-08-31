// Last updated: 8/31/2025, 10:48:22 AM
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int c1=(int)(coordinate1[0])+coordinate1[1];
        int c2=(int)(coordinate2[0])+coordinate2[1];
        bool black_c1=false, black_c2=false;
        if (c1%2==0)
        {
            black_c1=true;
        }
        if (c2%2==0)
        {
            black_c2=true;
        }
        if (black_c1==black_c2) return true;
        else return false;
    }
};