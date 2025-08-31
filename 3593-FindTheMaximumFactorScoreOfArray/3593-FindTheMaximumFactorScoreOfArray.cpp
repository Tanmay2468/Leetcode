// Last updated: 8/31/2025, 10:48:19 AM
class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
    long long maxScore(vector<int>& nums) {
        // int n = nums.size();
        // long long gcd1 = nums[0];
        // long long lcm1 = nums[0];
        // for (int i = 1; i < n; i++) {
        //     gcd1 = gcd(gcd1, nums[i]);
        //     lcm1 = lcm(lcm1, nums[i]);
        // }
        // long long gcd3 = gcd1;
        // long long lcm3 = lcm1;
        // for (int i = 0; i < n; i++) {
        //     long long gcd2 = 0;
        //     long long lcm2 = 1;
        //     for (int j = 0; j < n; j++) {
        //         if (i != j) {
        //             gcd2 = gcd(gcd2, nums[j]);
        //             lcm2 = lcm(lcm2, nums[j]);
        //         }
        //     }
        //     gcd3 = max(gcd3, gcd2);
        //     lcm3 = max(lcm3, lcm2);
        // }
        // return gcd3 * lcm3;

        int n = nums.size();
        if (n == 1)
            return static_cast<long long>(nums[0]) * nums[0];
        long long totalGCD = nums[0], totalLCM = nums[0];
        for (int i = 1; i < n; i++) {
            totalGCD = gcd(totalGCD, nums[i]);
            totalLCM = lcm(totalLCM, nums[i]);
        }
        long long maxScore = totalGCD * totalLCM;
        for (int i = 0; i < n; i++) {
            long long gcdWithout = 0, lcmWithout = 1;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                gcdWithout = gcd(gcdWithout, nums[j]);
                lcmWithout = lcm(lcmWithout, nums[j]);
            }
            maxScore = max(maxScore, gcdWithout * lcmWithout);
        }
        return maxScore;
    }
};