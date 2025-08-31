// Last updated: 8/31/2025, 10:49:14 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return 0;
        bool flag=true; // starts with 1
        if (nums[0]==0) flag=false;
        vector<pair<int, int>> ans;
        int ct=0;
        for (int i=0;i<n-1;i++)
        {
            if (nums[i]==nums[i+1]) ct++;
            else
            {
                ct++;
                if (flag) ans.push_back({ct, 1});
                else ans.push_back({ct, 0});
                flag=!flag;
                ct=0;
            }
        }
        if (nums[n-2]==nums[n-1])
        {
            ct++;
            if (flag) ans.push_back({ct, 1});
            else ans.push_back({ct, 0});
            flag=!flag;
        }
        else
        {
            ct++;
            if (flag) ans.push_back({ct, 1});
            else ans.push_back({ct, 0});
            flag=!flag;
        }
        int maxi=0;
        int m=ans.size();
        // for (auto it: ans) cout<<it.first<<" "<<it.second<<endl;
        for (int i=0;i<m;i++)
        {
            if (ans[i].second==1) maxi=max(maxi, ans[i].first);
        }
        for (int i=0;i<m;i++)
        {
            if (ans[i].first==1 && ans[i].second==0)
            {
                if (i!=0 && i!=m-1) maxi=max(maxi, ans[i-1].first+ans[i+1].first);
            }
        }
        if (m==1 && ans[0].second==1) return ans[0].first-1;
        return maxi;
    }
};