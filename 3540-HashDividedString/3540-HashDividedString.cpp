// Last updated: 8/31/2025, 10:48:23 AM
class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        int i = 0;
        string ret = "";
        while (i < n)
        {
            int j = i;
            long long int ct = 0;
            while (j < (k + i))
            {
                int temp = s[j] - 97;
                ct += temp;
                j++;
            }
            int mod = ct % 26;
            char ch = 'a' + mod;
            ret += ch;
            i = j;
        }
        return ret;
    }
};