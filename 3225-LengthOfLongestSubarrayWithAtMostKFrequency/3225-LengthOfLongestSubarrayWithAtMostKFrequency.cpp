// Last updated: 8/31/2025, 10:48:32 AM
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int>hash;
        int longest=0, start=-1;
        for (int end=0;end<nums.size();end++)
        {
            hash[nums[end]]++;
            while (hash[nums[end]]>k)
            {
                start++;
                hash[nums[start]]--;
            }
            longest=max(longest,end-start);
        }
        return longest;
    }
};