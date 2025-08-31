// Last updated: 8/31/2025, 10:48:04 AM
class Solution {
public:

    // int gcd(int a, int b){
    //     if (b==0) return a;
    //     else return gcd(b, a%b);
    // }
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for (int i=0;i<n;i++){
            long long prod_=1;
            int _gcd=0;
            long long _lcm=1;
            for (int j=i;j<n;j++){
                if (prod_>LLONG_MAX/nums[j]) break;
                prod_*=nums[j];
                if (i==j) _gcd=nums[j];
                else _gcd=gcd(_gcd, nums[j]);
                if (i==j) _lcm=nums[j];
                else _lcm=(_lcm/gcd(_lcm, nums[j]))*nums[j];
                if (prod_==_gcd*_lcm) maxi=max(maxi, j-i+1);                
            }
        }
        return maxi;
    }
};