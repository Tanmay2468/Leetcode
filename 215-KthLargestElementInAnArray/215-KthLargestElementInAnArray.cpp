// Last updated: 8/31/2025, 10:50:03 AM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort (nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};