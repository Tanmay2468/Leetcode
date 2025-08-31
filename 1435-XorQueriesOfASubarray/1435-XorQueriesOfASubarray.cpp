// Last updated: 8/31/2025, 10:49:20 AM
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> pre;
        vector<int> post;
        long long total=0;
        for (int i=0;i<arr.size();i++)
        {
            total^=arr[i];
        }
        long long bfr=0, aftr=total;
        pre.push_back(0);
        for (int i=1;i<arr.size();i++)
        {
            bfr^=arr[i-1];
            pre.push_back(bfr);
        }
        for (int i=0;i<arr.size();i++)
        {
            aftr^=arr[i];
            post.push_back(aftr);
        }
        // cout<<total<<endl;
        // for (int i=0;i<arr.size();i++)
        // {
        //     cout<<pre[i]<<" "<<post[i]<<endl;
        // }
        for (int i=0;i<queries.size();i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            long long temp=pre[start]^post[end]^total;
            ans.push_back(temp);
        }
        return ans;
    }
};