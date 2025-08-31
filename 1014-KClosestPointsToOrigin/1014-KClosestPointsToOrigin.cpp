// Last updated: 8/31/2025, 10:49:30 AM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, pair<int, int>>> vec;
        for (auto it: points)
        {
            vec.push_back({sqrt(pow(it[0], 2)+pow(it[1], 2)), {it[0], it[1]}});
        }
        sort(vec.begin(), vec.end());
        // for (auto it: vec) cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        vector<vector<int>> ans;
        for (int i=0;i<k;i++)
        {
            ans.push_back({vec[i].second.first, vec[i].second.second});
        }
        return ans;
    }
};