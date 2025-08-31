// Last updated: 8/31/2025, 10:48:21 AM
class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        vector<int>vec;
        while (num1>0 || num2>0 || num3>0)
        {
            int d1=num1%10;
            int d2=num2%10;
            int d3=num3%10;
            int temp=min(d1, min(d2,d3));
            vec.push_back(temp);
            num1/=10;
            num2/=10;
            num3/=10;
        }
        int ans=0;
        for (int i=0;i<vec.size();i++)
        {
            ans+=vec[i]*pow(10,i);
        }
        return ans;
    }
};