// Last updated: 8/31/2025, 10:48:34 AM
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int ct=0;
        for (int i=0;i<n;i++)
        {
            if ((details[i][11]=='6' && details[i][12]>'0') || (details[i][11]>'6'))
            {
                ct++;
            }
        }
        return ct;
    }
};