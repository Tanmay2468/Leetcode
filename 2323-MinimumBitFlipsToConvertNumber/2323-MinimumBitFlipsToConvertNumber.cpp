// Last updated: 8/31/2025, 10:48:50 AM
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // vector<int> s(32, 0);
        // int ct=0;
        // while (start>0)
        // {
        //     int bit=start%2;
        //     s[ct]=bit;
        //     start>>=1;
        //     ct++;
        // }
        // vector<int> g(32, 0);
        // ct=0;
        // while (goal>0)
        // {
        //     int bit=goal%2;
        //     g[ct]=bit;
        //     goal>>=1;
        //     ct++;
        // }
        // int ans=0;
        // for (int i=0;i<32;i++)
        // {
        //     if (s[i]!=g[i]) ans++;
        // }
        // return ans;

        int ans=start^goal;
        int ct=0;
        while (ans>0)
        {
            int bit=ans%2;
            if (bit==1) ct++;
            ans/=2;
        }
        return ct;
    }
};