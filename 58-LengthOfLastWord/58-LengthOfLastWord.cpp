// Last updated: 8/31/2025, 10:50:27 AM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int end=s.length()-1;
        int len=0;
        while (s.at(end)==' ')
        {
            end--;
        }
        while (end>=0 && s.at(end)!=' ')
        {
            len++;
            end--;
        }
        return len;
    }
};