// Last updated: 8/31/2025, 10:47:55 AM
class Solution {
public:
    bool isPali(const string &str){
        int l=0, r=str.length()-1;
        while (l<r){
            if (str[l]!=str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int maxi=0;
        int n=s.length(), m=t.length();
        for (int i=0;i<=n;i++){
            for (int j=i;j<=n;j++){
                string sub_s=s.substr(i, j-i);
                for (int k=0;k<=m;k++){
                    for (int l=k;l<=m;l++){
                        string sub_t=t.substr(k, l-k);
                        string merged1=sub_s+sub_t;
                        // string merged2=sub_t+sub_s;
                        if (isPali(merged1)) maxi=max(maxi, (int)merged1.length());
                        // if (isPali(merged2)) maxi=max(maxi, (int)merged2.length());
                    }
                }
            }
        }
        return maxi;
        // int n=s.length(), m=t.length();
        // int len=0;
        // for (int i=0;i<n;i++){
        //     int q=i;
        //     int ct=0;
        //     for (int j=m-1;j>=0;j--){
        //         if (s[q]==t[j]){
        //             ct++;
        //             q++;
        //         }
        //         else{
        //             len=max(len, ct);
        //             ct=0;
        //             q=i;
        //         }
        //     }
        // }
        // for (int i=0;i<n;i++){
        //     int q=i, w=n-1;
        //     int ct=0;
        //     while (q<=w){
        //         if (s[q]==s[w]){
        //             ct++;
        //             w--;
        //             q++;
        //         }
        //         else{
        //             len=max(len, ct);
        //             ct=0;
        //             q=i;
        //         }
        //     }
        // }
        // for (int i=0;i<m;i++){
        //     int q=i, w=m-1;
        //     int ct=0;
        //     while (q<=w){
        //         if (t[q]==t[w]){
        //             ct++;
        //             w--;
        //             q++;
        //         }
        //         else{
        //             len=max(len, ct);
        //             ct=0;
        //             q=i;
        //         }
        //     }
        // }
        // return len*2+1;
    }
};