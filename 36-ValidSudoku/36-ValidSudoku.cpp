// Last updated: 8/31/2025, 10:50:29 AM
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag=true;
        for (int i=0;i<9;i++)
        {
            vector<int> vec(9,0);
            for (int j=0;j<9;j++)
            {
                if (isdigit(board[i][j])) vec[board[i][j]-'1']++;
            }
            for (auto it: vec)
            {
                if (it>1)
                {
                    flag=false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (!flag) return false;
        for (int i=0;i<9;i++)
        {
            vector<int> vec(9, 0);
            for (int j=0;j<9;j++)
            {
                if (isdigit(board[j][i])) vec[board[j][i]-'1']++;
            }
            for (auto it: vec)
            {
                if (it>1)
                {
                    flag=false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (!flag) return false;
        for (int i=0;i<9;i+=3)
        {
            for (int j=0;j<9;j+=3)
            {
                vector<int> vec(9, 0);
                for (int k=i;k<i+3;k++)
                {
                    for (int l=j;l<j+3;l++)
                    {
                        if (isdigit(board[k][l])) vec[board[k][l]-'1']++;
                    }
                }
                for (auto it: vec)
                {
                    if (it>1)
                    {
                        flag=false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (!flag) break;
        }
        if (!flag) return false;
        return true;
    }
};