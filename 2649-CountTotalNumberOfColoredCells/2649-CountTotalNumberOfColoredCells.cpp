// Last updated: 8/31/2025, 10:48:37 AM
class Solution {
public:
    long long coloredCells(int n) {
        long long t1=pow(n, 2);
        long long t2=pow(n-1, 2);
        long long ans=t1+t2;
        return ans;
    }
};