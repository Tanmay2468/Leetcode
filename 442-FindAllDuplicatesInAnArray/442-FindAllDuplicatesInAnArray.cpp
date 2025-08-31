// Last updated: 8/31/2025, 10:49:52 AM
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            int index=abs(nums[i]);
            if (nums[index-1]<0)
            {
                ans.push_back(abs(nums[i]));
            }
            nums[index-1]*=-1;
        }
        return ans;
    }
};