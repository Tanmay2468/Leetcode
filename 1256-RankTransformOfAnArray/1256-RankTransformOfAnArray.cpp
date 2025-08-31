// Last updated: 8/31/2025, 10:49:26 AM
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> a=arr;
        sort(a.begin(), a.end());
        map<int, int> mpp;
        int r=1;
        for (auto num: a)
        {
            if (mpp.find(num)==mpp.end())
            {
                mpp[num]=r++;
            }
        }
        vector<int> rank;
        for (int num: arr)
        {
            rank.push_back(mpp[num]);
        }
        return rank;
    }
};