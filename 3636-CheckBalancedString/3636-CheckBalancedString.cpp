// Last updated: 8/31/2025, 10:48:10 AM
class Solution {
public:
    bool isBalanced(string num) {
        int odd=0;
        int even=0;
        for (int i=0;i<num.length();i++)
            {
                if (i%2==0) even+=(num[i]-'0');
                else odd+=(num[i]-'0');
            }
        if (even==odd) return true;
        return false;
    }
};