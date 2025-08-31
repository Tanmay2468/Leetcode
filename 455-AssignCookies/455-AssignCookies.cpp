// Last updated: 8/31/2025, 10:49:51 AM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0, j=0, ct=0;
        while (i<g.size() && j<s.size())
        {
            if (s[j]>=g[i])
            {
                ct++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return ct;
    }
};