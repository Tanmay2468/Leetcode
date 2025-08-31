// Last updated: 8/31/2025, 10:50:06 AM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int freqS[127];
        int freqT[127];
        for (int i=0;i<s.length();i++)
        {
            if (freqS[s.at(i)]!=freqT[t.at(i)])
            {
                return false;
            }
            freqS[s.at(i)]=i+1;
            freqT[t.at(i)]=i+1;
        }
        return true;
    }
};