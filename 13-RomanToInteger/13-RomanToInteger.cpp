// Last updated: 8/31/2025, 10:50:34 AM
class Solution {
public:
    int romanToInt(string s) {
        s+="O";
        unordered_map<char, int> mpp={{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}, {'O', 0}};
        int ans=0;
        int n=s.length();
        for (int i=0;i<n-1;i++)
        {
            if (mpp[s[i]]<mpp[s[i+1]]) ans-=mpp[s[i]];
            else ans+=mpp[s[i]];
        }
        return ans;
    }
};