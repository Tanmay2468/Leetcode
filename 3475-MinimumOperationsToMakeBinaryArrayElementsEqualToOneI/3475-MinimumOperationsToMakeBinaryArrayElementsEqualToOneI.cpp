// Last updated: 8/31/2025, 10:48:27 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ct=0;
        for (int i=0;i<n;i++)
        {
            if (nums[i]==0 && i<n-2)
            {
                nums[i]=1-nums[i];
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
                ct++;
            }
        }
        bool flag=true;
        for (auto it: nums)
        {
            if (it==0)
            {
                flag=false;
                break;
            }
        }
        if (flag) return ct;
        else return -1;
    }
};