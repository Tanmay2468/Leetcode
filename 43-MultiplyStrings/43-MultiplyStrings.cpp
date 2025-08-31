// Last updated: 8/31/2025, 10:50:28 AM
class Solution {
public:
    string add(string bfr, string temp)
    {
        if (bfr.length()<temp.length())
        {
            int len=temp.length()-bfr.length();
            while (len--) bfr="0"+bfr;
        }
        else if (bfr.length()>temp.length())
        {
            int len=bfr.length()-temp.length();
            while (len--) temp="0"+temp;
        }
        int carry=0;
        string ans="";
        for (int i=bfr.length()-1;i>=0;i--)
        {
            int tp=(temp[i]-'0')+(bfr[i]-'0')+carry;
            ans=to_string(tp%10)+ans;
            carry=tp/10;
        }
        if (carry!=0) ans=to_string(carry)+ans;
        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0") return "0";
        int n1=num1.size(), n2=num2.size();
        int ct_zero=0;
        string bfr="";
        for (int i=n2-1;i>=0;i--)
        {
            string temp="";
            if (ct_zero!=0)
            {
                for (int k=0;k<ct_zero;k++)
                {
                    temp+="0";
                }
            }
            int carry=0;
            for (int j=n1-1;j>=0;j--)
            {
                int it=(num1[j]-'0')*(num2[i]-'0')+carry;
                temp=to_string(it%10)+temp;
                carry=it/10;
            }
            if (carry!=0)
            {
                temp=to_string(carry)+temp;
            }
            if (bfr=="") bfr=temp;
            else bfr=add(bfr, temp);
            ct_zero++;
        }
        return bfr;
    }
};