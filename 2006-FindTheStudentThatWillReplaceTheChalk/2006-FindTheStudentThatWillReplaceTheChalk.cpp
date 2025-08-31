// Last updated: 8/31/2025, 10:49:03 AM
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=0;
        int n=chalk.size();
        for (int i=0;i<n;i++)
        {
            sum+=chalk[i];
        }
        int remain=k%sum;
        int ans;
        for (int i=0;i<n;i++)
        {
            remain-=chalk[i];
            if (remain<0)
            {
                ans=i;
                break;
            }
            else if (remain==0)
            {
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};