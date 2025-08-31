// Last updated: 8/31/2025, 10:49:39 AM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        unordered_map<int, int> mpp;
        for (int i=0;i<n;i++)
        {
            mpp[s[i]-'a']++;
        }
        unordered_set<int> st;
        vector<int> vec;
        int ct=0;
        // for (auto it: mpp) cout<<it.first<<" "<<it.second<<endl;
        for (int i=0;i<n;i++)
        {
            ct++;
            mpp[s[i]-'a']--;
            if (mpp[s[i]-'a']!=0)
            {
                st.insert(s[i]-'a');
            }
            else
            {
                st.erase(s[i]-'a');
                if (st.empty())
                {
                    vec.push_back(ct);
                    ct=0;
                }
            }
        }
        return vec;
    }
};