// Last updated: 8/31/2025, 10:48:55 AM
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        for (int i=0;i<tickets.size();i++)
        {
            if (tickets[i]>=tickets[k] && i<=k)
            {
                time+=tickets[k];
            }
            else if (tickets[i]>=tickets[k])
            {
                time+=tickets[k]-1;
            }
            else
            {
                time+=tickets[i];
            }
        }
        return time;
    }
};