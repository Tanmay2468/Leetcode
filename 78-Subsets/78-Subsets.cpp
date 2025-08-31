// Last updated: 8/31/2025, 10:50:21 AM
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subsets=1<<n;
        vector<vector<int>> ans;
        for (int i=0;i<subsets;i++)
        {
            vector<int> lst;
            for (int j=0;j<n;j++)
            {
                if (i&(1<<j)) lst.push_back(nums[j]);
            }
            ans.push_back(lst);
        }
        return ans;
    }
};