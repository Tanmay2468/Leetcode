// Last updated: 8/31/2025, 10:50:38 AM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        vector<int> arr;
        for (auto it: nums1) arr.push_back(it);
        for (auto it: nums2) arr.push_back(it);
        sort(arr.begin(), arr.end());
        if ((m+n)%2==0)
        {
            int mid=(m+n)/2-1;
            return (arr[mid]+arr[mid+1])/2.0;
        }
        else
        {
            int mid=(m+n)/2;
            return arr[mid];
        }
    }
};