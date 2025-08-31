// Last updated: 8/31/2025, 10:47:44 AM
class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int sz=value.size();
        // Keepig track of indices [0, 1, 2, ..., n-1]
        vector<int> vec(sz);
        int t=0;
        for (int i=0;i<sz;i++){
            vec[i]=t;
            t++;
        }
        // Sorting using lambda function
        sort(vec.begin(), vec.end(), [&](int i, int j){
            if (limit[i]!=limit[j]) return limit[i]<limit[j];
            else return value[i]>value[j];
        });
        // Main code
        multiset<int>actv;
        long long sum=0;
        int told=0;
        for (int it: vec){
            if (limit[it]<=told) continue;
            if (actv.size()<limit[it]){
                sum+=value[it];
                actv.insert(limit[it]);
                int p=actv.size();
                told=max(told, p);
                while (!actv.empty() && *actv.begin()<=told) actv.erase(actv.begin());
            }
        }
        return sum;
    }
};