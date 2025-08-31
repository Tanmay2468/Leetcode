// Last updated: 8/31/2025, 10:48:58 AM
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        int m=rolls.size();
        for (auto it: rolls)
        {
            sum+=it;
        }
        int total=(n+m)*mean;
        int remain=total-sum;
        float each=remain/float(n);
        if (each>6.0 || remain<=0 || remain<n) return {};
        int eq=remain/n;
        int rem=remain%n;
        vector<int> ans(n,eq);
        int i=0;
        while (rem--)
        {
            ans[i]++;
            i++;
        }
        return ans;
    }
};