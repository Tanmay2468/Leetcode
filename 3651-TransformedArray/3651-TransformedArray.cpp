// Last updated: 8/31/2025, 10:48:06 AM
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        for (int i=0;i<n;i++){
            int steps=nums[i];
            if (steps==0) res[i]=nums[i];
            else if (steps>0){
                int idx=(i+steps)%n;
                res[i]=nums[idx];
            }
            else{
                int idx=abs(steps)%n;
                if (i>=idx) idx=i-idx;
                else idx=n-(idx-i);
                res[i]=nums[idx];
            }
        }
        return res;
    }
};