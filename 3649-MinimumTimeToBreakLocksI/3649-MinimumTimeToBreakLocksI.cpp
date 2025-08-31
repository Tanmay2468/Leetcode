// Last updated: 8/31/2025, 10:48:08 AM
class Solution {
public:
    long long demo[1<<8][100];
    vector<int> vv;
    int n;
    int incr;
    vector<int> str;
    long long dp(int ksam, int X){
        if (ksam==(1<<n)-1) return 0;
        if (demo[ksam][X]!=-1) return demo[ksam][X];
        long long res=LONG_LONG_MAX;
        for (int i=0;i<n;i++){
            if (!(ksam & (1<<i))) {
                long long t=(long long)ceil((double)str[i]/X);
                int itr=X+incr;
                long long tot=t+dp(ksam | (1<<i), itr);
                res=min(res,tot);
            }
        }
        return demo[ksam][X]=res;
    }

    int findMinimumTime(vector<int>& strength, int K) {
        str=strength;
        incr=K;
        n=strength.size();
        vv=strength;
        for (int i=0;i<(1<<n);i++){
            for (int j=0;j<100;j++){
                demo[i][j]=-1;
            }
        }
        long long ans=dp(0,1);
        if (ans<=1e12) return ans;
        else return -1;
    }
};