// Last updated: 8/31/2025, 10:50:02 AM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        if (pow(2,(int)(log2(n)))==n) return true;
        else return false;
    }
};