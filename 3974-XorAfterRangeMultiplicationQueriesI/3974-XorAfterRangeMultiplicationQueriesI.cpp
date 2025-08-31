// Last updated: 8/31/2025, 10:47:40 AM
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int modi=1e9+7;
        vector<int> vec=nums;
        for (auto it: queries){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int v=it[3];
            for (int i=l;i<=r;i+=k){
                vec[i]=((long long)vec[i]*v)%modi;
            }
        }
        int ans=0;
        for (auto it: vec) ans^=it;
        return ans;
    }
};