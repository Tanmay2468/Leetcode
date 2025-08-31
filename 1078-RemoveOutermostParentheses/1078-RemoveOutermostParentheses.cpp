// Last updated: 8/31/2025, 10:49:29 AM
#include <bits/stdc++.h>
class Solution {
public:
    string removeOuterParentheses(string s) {
        int ctleft=0,ctright=0;
        int i=0;
        for (int j=0;j<s.length();j++)
        {
            if (s.at(j)=='(') ctleft++;
            else ctright++;
            if (ctleft==ctright)
            {
                s.erase(s.begin()+i);
                s.erase(s.begin()+j-1);
                i=j-1;
                j=j-2;
            }
        }
        return s;
    }
};