// Last updated: 8/31/2025, 10:49:55 AM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<=0) return false;
        while (n%4==0) n/=4;
        if (n==1) return true;
        else return false;
    }
};