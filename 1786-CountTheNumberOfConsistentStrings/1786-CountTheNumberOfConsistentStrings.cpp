// Last updated: 8/31/2025, 10:49:09 AM
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char, int>mpp;
        for (int i=0;i<allowed.length();i++)
        {
            mpp[allowed[i]]++;
        }
        int ans=0;
        for (int i=0;i<words.size();i++)
        {
            map<char, int>m;
            string temp=words[i];
            for (int j=0;j<words[i].length();j++)
            {
                m[temp[j]]++;
            }
            int ct=0;
            for (auto it: m)
            {
                for (auto i:mpp)
                {
                    if (it.first==i.first) ct++;
                }
            }
            if (ct==m.size()) ans++;
        }
        return ans;
    }
};