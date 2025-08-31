// Last updated: 8/31/2025, 10:49:17 AM
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> ct(3,0);
        int n=s.length();
        int left=0, ans=0;
        for (int i=0;i<n;i++)
        {
            ct[s[i]-'a']++;
            while (ct[0]>0 && ct[1]>0 && ct[2]>0)
            {
                ans+=n-i;
                ct[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};