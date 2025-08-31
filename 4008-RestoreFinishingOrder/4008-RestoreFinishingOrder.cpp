// Last updated: 8/31/2025, 10:47:34 AM
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> vec;
        set<int> st;
        int n=friends.size();
        for (int i=0;i<n;i++){
            st.insert(friends[i]);
        }
        int m=order.size();
        for (int i=0;i<m;i++){
            if (st.find(order[i])!=st.end()) vec.push_back(order[i]);
        }
        return vec;
    }
};