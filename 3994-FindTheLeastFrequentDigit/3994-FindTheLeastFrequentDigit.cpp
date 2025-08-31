// Last updated: 8/31/2025, 10:47:36 AM
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int k=n;
        unordered_map<int, int> mpp;
        while (k>0){
            int bit=k%10;
            mpp[bit]++;
            k/=10;
        }
        int mini=INT_MAX;
        int ct=INT_MAX;
        for (auto it: mpp){
            if (it.second==ct){
                mini=min(mini, it.first);
            }
            else if (it.second<ct){
                mini=it.first;
                ct=it.second;
            }
        }
        return mini;
    }
};