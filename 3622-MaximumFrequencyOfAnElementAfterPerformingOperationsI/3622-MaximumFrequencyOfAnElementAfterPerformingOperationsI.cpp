// Last updated: 8/31/2025, 10:48:14 AM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int max_num=*max_element(nums.begin(), nums.end());
        int size=max_num+k+2;
        vector<int> freq(size,0);
        for (int num: nums) freq[num]++;
        vector<int> pre(size, 0);
        pre[0]=freq[0];
        for (int i=1;i<size;i++) pre[i]=pre[i-1]+freq[i];
        int result=0;
        for(int x=0;x<size;x++){
            if (freq[x]==0 && numOperations==0) continue;
            int l=max(0,x-k);
            int r=min(size-1, x+k);
            int total=pre[r]-(l>0?pre[l-1]:0);
            int adj=total-freq[x];
            int tot=freq[x]+min(numOperations, adj);
            result=max(result, tot);
        }
        return result;
    }
};