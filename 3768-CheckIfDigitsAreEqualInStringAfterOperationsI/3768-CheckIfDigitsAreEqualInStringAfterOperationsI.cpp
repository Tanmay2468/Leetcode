// Last updated: 8/31/2025, 10:47:58 AM
class Solution {
public:
    bool hasSameDigits(string s) {
        string str=s;
        
        while (str.length()!=2){
            int n=str.length();
            string t="";
            for (int i=0;i<n-1;i++){
                int q=str[i]-'0';
                int w=str[i+1]-'0';
                // cout<<q<<" "<<w<<endl;
                int ne=(q+w)%10;
                t+=to_string(ne);
            }
            // cout<<t<<endl;
            str=t;
        }
        if (str[0]==str[1]) return true;
        else return false;
    }
};