// Last updated: 8/31/2025, 10:49:12 AM
class Solution {
public:
    int maxDepth(string s) {
        int d=0, ans=0;
        for (int i=0;i<s.length();i++)
        {
            if (s.at(i)=='(')
            {
                d++;
                ans=max(ans,d);
            }
            else if (s.at(i)==')')
            {
                d--;
            }
        }
        return ans;
    }
};