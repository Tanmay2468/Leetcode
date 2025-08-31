// Last updated: 8/31/2025, 10:49:22 AM
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0;
        for (auto it: candies) sum+=it;
        if (k>sum) return 0;
        long long left = 1, right = sum / k, ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            for (int candy : candies) {
                count += candy / mid;
                if (count >= k) break;
            }
            if (count >= k) { 
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};