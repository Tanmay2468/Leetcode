// Last updated: 8/31/2025, 10:50:37 AM
class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        if (x<0) neg=true;
        string str=to_string(x);
        std::reverse(str.begin(), str.end());
        if (neg)
        {
            str.erase(str.length()-1, 1);
            str="-"+str;
        }
        long long it=stoll(str);
        if (it<INT_MIN || it>INT_MAX) return 0;
        else return (int)it;
    }
};