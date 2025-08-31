// Last updated: 8/31/2025, 10:50:12 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for (auto it: nums)
        {
            ans^=it;
        }
        return ans;
    }
};