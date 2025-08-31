// Last updated: 8/31/2025, 10:48:48 AM
class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        int pointer=2;
        int maxi=-1;
        while (pointer<n)
        {
            if (num[pointer-2]==num[pointer-1] && num[pointer-2]==num[pointer])
            {
                maxi=max(num[pointer]-'0', maxi);
            }
            pointer++;
        }
        if (maxi==-1) return "";
        return to_string(maxi)+to_string(maxi)+to_string(maxi);
    }
};