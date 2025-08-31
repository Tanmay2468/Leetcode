// Last updated: 8/31/2025, 10:48:43 AM
class Solution {
public:
    long long mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int t=n;
        vector<int> powers;
        while (t>0)
        {
            int po=pow(2, (int)log2(t));
            powers.push_back(po);
            t-=po;
        }
        reverse(powers.begin(), powers.end());
        vector<int> answers;
        for (auto it: queries)
        {
            long long ans=1;
            for (int i=it[0];i<=it[1];i++)
            {
                ans=(ans*powers[i])%mod;
            }
            answers.push_back(ans);
        }
        return answers;
    }
};