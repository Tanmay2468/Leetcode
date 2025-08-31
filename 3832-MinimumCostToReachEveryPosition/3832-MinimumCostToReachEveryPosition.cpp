// Last updated: 8/31/2025, 10:47:50 AM
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n=cost.size();
        vector<int> ans(n);
        int mini=cost[0];
        for (int i=0;i<n;i++){
            if (cost[i]<mini){
                mini=cost[i];
            }
            ans[i]=mini;
        }
        return ans;
    }
};