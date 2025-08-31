// Last updated: 8/31/2025, 10:48:18 AM
class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        int op=log2(k)+1;
        while (op--)
        {
            string temp="";
            for (int i=0;i<s.length();i++)
            {
                if (s[i]=='z') temp+="a";
                else temp+=char(s[i]+1);
            }
            s+=temp;
        }
        return s[k-1];
    }
};