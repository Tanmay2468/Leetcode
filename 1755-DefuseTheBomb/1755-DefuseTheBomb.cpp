// Last updated: 8/31/2025, 10:49:10 AM
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> defu(n,0);
        if (k>0)
        {
            int sum = 0;
            for (int i = 1; i <= k; ++i) {
                sum += code[i % n];
            }
            for (int i = 0; i < n; ++i) {
                defu[i] = sum;
                sum -= code[(i + 1) % n];
                sum += code[(i + 1 + k) % n];
            }
        }
        else if (k<0)
        {
            // int sum=0;
            // int j=n-k;
            // for (int i=n-1;i>=n-k;i--)
            // {
            //     sum+=code[i];
            // }
            // for (int i=0;i<n;i++)
            // {
            //     defu[i]=sum;
            //     if (j!=n-1) j++;
            //     else j=0;
            //     sum+=code[i];
            //     sum-=code[j];
            // }
            k = -k;
            int sum = 0;
            for (int i = 1; i <= k; ++i) {
                sum += code[(n - i) % n];
            }
            for (int i = 0; i < n; ++i) {
                defu[i] = sum;
                sum -= code[(n + i - k) % n];
                sum += code[i % n];
            }
        }
        // Not required as already vector is initialized to 0

        // else if (k==0)
        // {
        //     for (int i=0;i<n;i++)
        //     {
        //         defu[i]=0;
        //     }
        // }
        return defu;
    }
};