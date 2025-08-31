// Last updated: 8/31/2025, 10:47:56 AM
class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());
        int n=pizzas.size();
        int days=n/4;
        int od=ceil(days/2.0);
        int ev=days/2;
        long long w=0;
        int i=n-1;
        while (od--){
            w+=pizzas[i];
            i--;
        }
        i--;
        while (ev--){
            w+=pizzas[i];
            i=i-2;
        }
        return w;
    }
};