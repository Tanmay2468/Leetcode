// Last updated: 8/31/2025, 10:47:47 AM
class Solution {
public:
    long long numOfSubsequences(string s) {
        int l=0, c=0, t=0;
        int n=s.length();
        for (int i=0;i<n;i++){
            if (s[i]=='L') l++;
            else if (s[i]=='C') c++;
            else if (s[i]=='T') t++;
        }
        int l1=l, c1=c, t1=t;
        long long sum=0;
        for (int i=0;i<n;i++){
            if (s[i]=='L') sum+=c1*t1;
            else if (s[i]=='C') c1--;
            else if (s[i]=='T') t1--;
        }
        long long sumL=sum+c*t;
        long long sumT=sum+l*c;
        long long extraC=0;
        l1=0, c1=0, t1=t;
        long long extra1C=0;
        // for (int i=0;i<n;i++){
        //     if (s[i]=='L') l1++;
        //     else if (s[i]=='T') t1--;
        //     extra1C=l1*t1;
        //     extraC=max(extraC, extra1C);
        // }
        // long long sumC=sum+extraC;
        // cout<<sumL<<" "<<sumC<<" "<<sumT;
        // return max(sumL, max(sumC, sumT));

        long long T=0, L=0, C=0, LC=0, CT=0, ans=0, maxi=0, Tpast=0;
        for (int i=0;i<n;i++){
            if (s[i]=='T') T++;
        }
        for (int i=0;i<n;i++){
            maxi=max(maxi, L*(T-Tpast));
            if (s[i]=='L') L++;
            else if (s[i]=='C'){
                C++;
                LC+=L;
            }
            else if (s[i]=='T'){
                Tpast++;
                CT+=C;
                ans+=LC;
            }
        }
        maxi=max(maxi, L*(T-Tpast));
        long long retur1=ans+max(0LL, max(LC, max(CT, maxi)));
        return retur1;
    }
};