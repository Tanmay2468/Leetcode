// Last updated: 8/31/2025, 10:49:18 AM
class Solution {
public:
    int maximum69Number (int num) {
        stack<int> st;
        while (num>0)
        {
            st.push(num%10);
            num/=10;
        }
        string str="";
        bool flag=true;
        while (!st.empty())
        {
            if (st.top()==6 && flag)
            {
                str+="9";
                flag=false;
                st.pop();
                continue;
            }
            str+=to_string(st.top());
            st.pop();
        }
        return stoi(str);
    }
};