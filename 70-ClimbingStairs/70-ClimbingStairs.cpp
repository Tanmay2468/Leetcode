// Last updated: 8/31/2025, 10:50:22 AM
class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) return n;
        int curr, prev1=2, prev2=1;
        for (int i=3;i<=n;i++)
        {
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};