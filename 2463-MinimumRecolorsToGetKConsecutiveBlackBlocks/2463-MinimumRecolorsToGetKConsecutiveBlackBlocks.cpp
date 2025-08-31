// Last updated: 8/31/2025, 10:48:45 AM
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int b=0, w=0;
        for (int i=0;i<k;i++)
        {
            if (blocks[i]=='W') w++;
            else b++;
        }
        int maxi=INT_MIN;
        int n=blocks.length();
        for (int i=0;i<=n-k;i++)
        {
            maxi=max(maxi, b);
            if (blocks[i]=='W') w--;
            else b--;
            if (blocks[i+k]=='W') w++;
            else b++;
        }
        return k-maxi;
    }
};