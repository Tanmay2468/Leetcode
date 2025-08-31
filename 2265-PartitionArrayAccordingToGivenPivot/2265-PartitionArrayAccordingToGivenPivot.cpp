// Last updated: 8/31/2025, 10:48:52 AM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> low;
        vector<int> high;
        int ct=0;
        for (auto it: nums)
        {
            if (it<pivot) low.push_back(it);
            else if (it>pivot) high.push_back(it);
            else ct++;
        }
        vector<int> ans;
        for (auto it: low) ans.push_back(it);
        while (ct--) ans.push_back(pivot);
        for (auto it: high) ans.push_back(it);
        return ans;
    }
};