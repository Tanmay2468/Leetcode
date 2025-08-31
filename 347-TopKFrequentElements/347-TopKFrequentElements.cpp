// Last updated: 8/31/2025, 10:49:54 AM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (auto it: nums) mpp[it]++;
        vector<pair<int, int>> vec(mpp.begin(), mpp.end());
        sort (vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.second>b.second;
        });
        // for (auto it: vec) cout<<it.first<<" "<<it.second<<endl;
        vector<int> ans;
        for (int i=0;i<k;i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};