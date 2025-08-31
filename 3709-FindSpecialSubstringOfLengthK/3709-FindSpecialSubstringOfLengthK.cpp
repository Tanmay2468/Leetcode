// Last updated: 8/31/2025, 10:48:03 AM
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n=s.length();
        int flag=1;
        for (int i=0;i<n-k+1;i++){
            flag=1;
            for (int j=i;j<i+k;j++){
                if (j==i && i!=0){
                    if (s[j]==s[j-1]){
                        flag=0;
                        break;
                    }
                }
                else if (i==j) flag=1;

                if (s[i]!=s[j]){
                    flag=0;
                    break;
                }
                
                if (j==i+k-1 && i!=n-k){
                    if(s[j]==s[j+1]){
                        flag=0;
                        break;
                    }
                }
                else if (j==i+k-1) flag=1;
            }
            if (flag==1) break;
            // if (s[i]==s[i+1] && s[i+1]==s[i+2]){
            //     if (k==n) flag=1;
            //     else if (i==0 && s[i+2]!=s[i+3]) flag=1;
            //     else if (i==n-3 && s[i]!=s[i-1]) flag=1;
            //     else if (s[i+2]!=s[i+3] && s[i]!=s[i-1]) flag=1;
            // }
        }
        if (flag==1) return true;
        else return false;
    }
};