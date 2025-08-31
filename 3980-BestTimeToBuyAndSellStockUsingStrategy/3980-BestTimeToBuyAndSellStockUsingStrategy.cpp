// Last updated: 8/31/2025, 10:47:38 AM
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        long long beg=0;
        for (int i=0;i<n;i++){
            if (strategy[i]==-1) beg-=prices[i];
            else if (strategy[i]==1) beg+=prices[i];
        }
        int str=k/2;
        int i=0, j=k-1, last_i=str-1, first_j=str;
        long long curr=0;
        for (int it=i;it<=j;it++){
            if (strategy[it]==-1) curr-=prices[it];
            else if (strategy[it]==1) curr+=prices[it];
        }
        long long modi=0;
        for (int it=first_j;it<=j;it++){
            modi+=prices[it];
        }
        long long maxi=0;
        while (j<n){
            long long temp=modi-curr;
            if (temp>0 && temp>maxi){
                maxi=temp;
            }
            curr-=strategy[i]*prices[i];
            if (j!=n-1) curr+=strategy[j+1]*prices[j+1];
            modi-=prices[first_j];
            if (j!=n-1) modi+=prices[j+1];
            i++;
            last_i++;
            first_j++;
            j++;
        }
        return beg+maxi;
    }
};