// Last updated: 8/31/2025, 10:48:56 AM
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> ct;
        for (auto it:arr)
        {
            ct[it]++;
        }
        for (auto it:arr)
        {
            if (ct[it]==1)
            {
                k--;
                if (k==0)return it;
            }
        }
        return "";
    }
};