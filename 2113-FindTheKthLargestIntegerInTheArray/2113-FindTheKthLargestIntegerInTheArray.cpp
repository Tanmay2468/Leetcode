// Last updated: 8/31/2025, 10:49:00 AM
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort (nums.begin(), nums.end(), [&](string a, string b){
            if (a.length()!=b.length()) return a.length()<b.length();
            return a<b;
        });
        return nums[nums.size()-k];
    }
};