// Last updated: 8/31/2025, 10:48:40 AM
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        long long sk=skill[0]+skill[n-1];
        long long sum=0;
        for (int i=0;i<n/2;i++)
        {
            if ((skill[i]+skill[n-i-1])!=sk) return -1;
            else sum+=skill[i]*skill[n-i-1];
        }
        return sum;
    }
};