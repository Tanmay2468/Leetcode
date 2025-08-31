// Last updated: 8/31/2025, 10:48:39 AM
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        for (int n=max(2, left);n<=right;n++)
        {
            int ct = 0;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0)
                {
                    ct++;
                    break;
                }
            }
            if (ct==0) prime.push_back(n);
        }
        int mini=INT_MAX;
        vector<int> ans(2, -1);
        int n=prime.size();
        for (int i=0;i<n-1;i++)
        {
            int m=prime[i+1]-prime[i];
            if (m<mini)
            {
                ans[0]=prime[i];
                ans[1]=prime[i+1];
                mini=m;
            }
        }
        return ans;
    }
};