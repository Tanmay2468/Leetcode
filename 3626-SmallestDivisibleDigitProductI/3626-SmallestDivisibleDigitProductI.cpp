// Last updated: 8/31/2025, 10:48:13 AM
class Solution {
public:
    int smallestNumber(int n, int t) {
        int k=n;
        while (true){
            int l=k;
            int prod=1;
            while (l>0){
                int digi=l%10;
                prod*=digi;
                l/=10;
            }
            if (prod%t==0) return k;
            k++;
        }
    }
};