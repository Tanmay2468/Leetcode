// Last updated: 8/31/2025, 10:48:33 AM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=0;
        int maxi=nums[0];
        for (int i=1;i<n;i++)
        {
            if (nums[i-1]>maxi) maxi=nums[i-1];
            prefix[i]=maxi;
        }
        vector<int> suffix(n);
        suffix[n-1]=0;
        maxi=nums[n-1];
        for (int i=n-2;i>=0;i--)
        {
            if (nums[i+1]>maxi) maxi=nums[i+1];
            suffix[i]=maxi;
        }
        long long triplet=INT_MIN;
        for (int i=0;i<n;i++)
        {
            long long temp=prefix[i]-nums[i];
            temp*=suffix[i];
            if (temp>triplet) triplet=temp;
        }
        return triplet;
    }
};