// Last updated: 8/31/2025, 10:49:57 AM
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> arr=nums;
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int i=n/2-1, j=n-1;
        if (n%2==1) i++;
        for (int it=0;it<n;it++)
        {
            if (it%2==0) nums[it]=arr[i--];
            else nums[it]=arr[j--];
        }
    }
};