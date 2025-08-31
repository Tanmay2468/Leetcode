// Last updated: 8/31/2025, 10:50:35 AM
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mpp={{4, "IV"}, {40, "XL"}, {400, "CD"}, {9, "IX"}, {90, "XC"}, {900, "CM"}, {5, "V"}, {50, "L"}, {500, "D"}, {1, "I"}, {10, "X"}, {100, "C"}, {1000, "M"}};
        int exp=log(num);
        string s="";
        while (num>0)
        {
            int bit=num/pow(10, exp);
            if (bit==4 || bit==9 || bit==5)
            {
                int vari=bit*pow(10, exp);
                s+=mpp[vari];
            }
            else if (bit==1 || bit==2 || bit==3)
            {
                int vari=pow(10, exp);
                for (int i=0;i<bit;i++)
                {
                    s+=mpp[vari];
                }
            }
            else if (bit==6 || bit==7 || bit==8)
            {
                int vari=5*pow(10, exp);
                s+=mpp[vari];
                vari=bit*pow(10, exp)-vari;
                int bitti=vari/pow(10, exp);
                vari=pow(10, exp);
                for (int i=0;i<bitti;i++)
                {
                    s+=mpp[vari];
                }
            }
            num%=int(pow(10, exp));
            exp--;
        }
        return s;
    }
};