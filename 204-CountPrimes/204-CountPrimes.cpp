// Last updated: 8/31/2025, 10:50:07 AM
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1, true);
        for (int i=2;i*i<=n;i++)
        {
            if (prime[i]==true)
            {
                for (int j=2*i;j<=n;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        int ct=0;
        for (int i=2;i<n;i++)
        {
            if (prime[i]==true) ct++;
        }
        return ct;
    }
};