// Last updated: 8/31/2025, 10:47:35 AM
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if (n%k!=0) return false;
        unordered_map<int, int> mpp;
        for (int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int maxi=n/k;
        for (auto it: mpp){
            if (it.second>maxi) return false;
        }
        return true;
    }
};