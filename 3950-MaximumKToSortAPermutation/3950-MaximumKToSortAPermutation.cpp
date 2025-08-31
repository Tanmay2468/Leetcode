// Last updated: 8/31/2025, 10:47:46 AM
class Solution {
public:
    int so(vector<int> &nums, int sz){
        int ans=pow(2, 20)-1;
        for (int i=0;i<sz;i++){
            if (nums[i]!=i) ans&=nums[i];
        }
        return ans;
    }
    // Here we take AND of every element which is not on its place
    int sortPermutation(vector<int>& nums) {
        int sz=nums.size();
        bool flag=false;
        for (int i=0;i<sz;i++){
            if (nums[i]!=i) flag=true;
        }
        if (flag) return so(nums, sz);
        else return 0;
    }
};