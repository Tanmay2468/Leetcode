// Last updated: 8/31/2025, 10:48:15 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        for (int i=0;i<n;i++){
            if (nums[i]<k) return -1;
        }
        set<int> st;
        int flag_k=0;
        for (auto it: nums){
            if (it>k) st.insert(it);
            else if (it==k){
                flag_k=1;
                st.insert(it);
            }
        }
        if (flag_k) return st.size()-1;
        else return st.size();
    }
};