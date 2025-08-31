// Last updated: 8/31/2025, 10:48:09 AM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        map<int, int> mpp;
        vector<pair<int, int>> tv;
        for (int it: nums){
            mpp[it]++;
            tv.push_back({it-k, 1});
            tv.push_back({it+k+1, -1});
        }
        set<int>pts;
        for (auto it: tv) pts.insert(it.first);
        for (auto it: mpp) pts.insert(it.first);

        sort(tv.begin(), tv.end());

        int idx=0;
        int curr=0;
        int maxi=0;
        int ac=0;
        for (int it:pts){
            while (idx<tv.size() && tv[idx].first<=it){
                curr+=tv[idx].second;
                idx++;
            }
            ac=mpp.count(it)?mpp[it]:0;
            int possi=ac+min(numOperations, curr-ac);
            maxi=max(maxi, possi);
        }
        return maxi;
    }
};