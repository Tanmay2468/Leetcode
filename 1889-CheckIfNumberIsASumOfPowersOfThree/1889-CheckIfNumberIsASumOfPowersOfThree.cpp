// Last updated: 8/31/2025, 10:49:05 AM
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int k=n;
        vector<int> power;
        while (k)
        {
            int bit=k%3;
            power.push_back(bit);
            k/=3;
        }
        int flag=1;
        for (auto it: power) if (it==2) flag=0;
        if (flag) return true;
        else return false;
    }
};