// Last updated: 8/31/2025, 10:47:59 AM
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k=nums.size()/3;
        long long sum=0;
        for (int i=nums.size()-2;i>k-1;i-=2){
            sum+=nums[i];
        }
        return sum;
    }
};