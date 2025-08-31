// Last updated: 8/31/2025, 10:49:37 AM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int ct5=0,ct10=0;
        bool fail=false;
        for (int i=0;i<n;i++)
        {
            if (bills[i]==5)
            {
                ct5++;
            }
            else if (bills[i]==10)
            {
                if (ct5>=1)
                {
                    ct5--;
                    ct10++;
                }
                else
                {
                    fail=true;
                    break;
                }
            }
            else
            {
                if (ct10>=1 && ct5>=1)
                {
                    ct5--;
                    ct10--;
                }
                else if (ct5>=3)
                {
                    ct5-=3;
                }
                else
                {
                    fail=true;
                    break;
                }
            }
        }
        if (!fail) return true;
        return false;
    }
};