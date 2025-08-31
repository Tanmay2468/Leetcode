// Last updated: 8/31/2025, 10:48:38 AM
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=0, p=0;
        for (auto it: nums){
            if (it<0) n++;
            else if (it>0) p++;
        }
        return max(n,p);
    }
};