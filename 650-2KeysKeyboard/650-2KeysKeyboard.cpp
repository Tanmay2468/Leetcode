// Last updated: 8/31/2025, 10:49:44 AM
class Solution {
public:
    int minSteps(int n) {
        if (n==1) return 0;
        int steps=0;
        int factor=2;
        while (n>1)
        {
            while (n%factor==0)
            {
                steps+=factor;
                n/=factor;
            }
            factor++;
        }
        return steps;
        // int ct=0;
        // if (n==1) return 0;
        // else if (n%2==1) return n;
        // else
        // {
        //     int power=0;
        //     while (n!=0)
        //     {
        //         if (n%2==0)
        //         {
        //             power++;
        //             n/=2;
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        //     return n+
        // }
    }
};