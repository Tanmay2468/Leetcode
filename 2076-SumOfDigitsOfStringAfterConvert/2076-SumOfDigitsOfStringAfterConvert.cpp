// Last updated: 8/31/2025, 10:49:02 AM
class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.length();
        int sum=0;
        for (int i=0;i<n;i++)
        {
            int temp=s[i]-96;
            sum+=(temp%10)+(temp/10);
        }
        k--;
        while (k > 0) {
        int newSum = 0;
        while (sum > 0) {
            newSum += sum % 10;
            sum /= 10;
        }
        sum = newSum;
        k--;
    }
        return sum;
    }
};