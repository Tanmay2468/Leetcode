// Last updated: 8/31/2025, 10:50:14 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int prof=0;
        for (auto it: prices)
        {
            mini=min(mini, it);
            prof=max(prof, it-mini);
        }
        return prof;
    }
};