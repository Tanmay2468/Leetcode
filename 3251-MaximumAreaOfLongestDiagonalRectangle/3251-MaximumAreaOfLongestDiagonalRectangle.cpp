// Last updated: 8/31/2025, 10:48:29 AM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        double maxi=0;
        int area=0;
        for (int i=0;i<n;i++)
        {
            double diag=sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
            if (diag>maxi)
            {
                maxi=diag;
                area=dimensions[i][0]*dimensions[i][1];
            }
            else if (diag==maxi){
                maxi=diag;
                area=max(area, dimensions[i][0]*dimensions[i][1]);
            }
        }
        return area;
    }
};