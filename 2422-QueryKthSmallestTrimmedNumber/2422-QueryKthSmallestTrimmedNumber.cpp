// Last updated: 8/31/2025, 10:48:47 AM
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto it: queries)
        {
            int k=it[0];
            int trim=it[1];
            vector<pair<string, int>> vec;
            for (int idx = 0; idx < nums.size(); idx++) {
                int n = nums[idx].size();
                vec.push_back({nums[idx].substr(n - trim), idx});
            }
            
            sort(vec.begin(), vec.end(), [&](auto &a, auto &b) {
                if (a.first == b.first) return a.second < b.second; // tie-breaker
                return a.first < b.first; // lexicographical compare
            });
            
            ans.push_back(vec[k - 1].second);
        }
        return ans;
        //     vector<pair<string, int>> vec;
        //     int ct=0;
        //     for (auto i: dupli) vec.push_back({i, ct++});
        //     sort(vec.begin(), vec.end(), [&](pair<string, int>a ,pair<string, int>b){
        //         if (a.first==b.first) return a.second<b.second;
        //         else if (a.first.length()==b.first.length()) return a.first<b.first;
        //         return a.first.length()<b.first.length();
        //     });
        //     ans.push_back(vec[k-1].second);
        // }
        // return ans;
    }
};