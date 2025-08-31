// Last updated: 8/31/2025, 10:47:49 AM
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        // sort(nums.begin(), nums.end(), greater<int>());
        // long long ans=0;
        if (nums.size()<=2000){
            long long ans=0;
            int n=nums.size();
            for (int i=0;i<n;i++){
                for (int j=i+1;j<n;j++){
                    if ((nums[i]&nums[j])==0){
                        ans=max(ans, 1LL*nums[i]*nums[j]);
                    }
                }
            }
            return ans;
        }
        int maxi=20;
        int posi=pow(2, 20)-1;
        vector<int> vec(posi+1, 0);
        for (auto it: nums){
            int mk=0;
            for (int i=0;i<20;i++){
                int bitti=pow(2, i);
                if ((it&bitti)!=0) mk|=bitti;
            }
            vec[mk]=max(vec[mk], it);
        }
        // for (int i=0;i<20;i++){
        //     int bitti=pow(2, i);
        //     if ((it&bitti)!=0) mk|=bitti;
        // }
        for (int i=0;i<20;i++){
            for (int j=0;j<posi+1;j++){
                int tmp=pow(2, i);
                if ((j&tmp)!=0) vec[j]=max(vec[j], vec[j^tmp]);
            }
        }
        long long ans=0;
        for (auto it: nums){
            int mk=0;
            for (int i=0;i<20;i++){
                int bitti=pow(2, i);
                if ((it&bitti)!=0) mk|=bitti;
            }
            int ret=vec[(~mk)&posi];
            if (ret>0){
                ans=max(ans, 1LL*it*ret);
            }
        }
        return ans;
    }
};