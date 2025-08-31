// Last updated: 8/31/2025, 10:47:39 AM
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd=n*n;
        int even=n*(n+1);
        int gcd_2nos=__gcd(odd, even);
        return gcd_2nos;
    }
};