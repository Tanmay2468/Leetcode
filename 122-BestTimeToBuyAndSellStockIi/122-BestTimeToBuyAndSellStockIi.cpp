// Last updated: 8/31/2025, 10:50:13 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int prev=prices[0];
        int sum=0;
        int n=prices.size();
        bool hold=true;
        for (int i=0;i<n;i++)
        {
            if (prices[i]<prev && hold==true)
            {
                sum+=prev-mini;
                hold=false;
            }
            else if (prices[i]>prev)
            {
                if (hold==false) mini=prev;
                hold=true;
            }
            prev=prices[i];
        }
        if (hold==true) sum+=prev-mini;
        return sum;
    }
};