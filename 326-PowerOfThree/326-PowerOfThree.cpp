// Last updated: 8/31/2025, 10:49:56 AM
class Solution {
public:
    bool isPowerOfThree(int n) {
        // if (n<=0) return false;
        // return (pow(3, int(log(n)/log(3.0)))==n) ? true : false;
        int maxPowerOf3 = 1162261467;
        return n > 0 && maxPowerOf3 % n == 0;
    }
};