// Last updated: 8/31/2025, 10:48:11 AM
class Solution {
public:
    char mirrOfThisChar(char ch){
        return 'z'-(ch-'a');
    }
    
    long long calculateScore(string s) {
        int n=s.length();
        vector<bool>charIfMarked(n, false);
        unordered_map<char, vector<int>> ind;
        long long ans=0;
        for (int i=0;i<n;i++){
            char mirr=mirrOfThisChar(s[i]);
            if (ind[mirr].empty()) ind[s[i]].push_back(i);
            else {
                int j=ind[mirr].back();
                ind[mirr].pop_back();
                charIfMarked[i]=true;
                charIfMarked[j]=true;
                ans+=i-j;
            }
        }
        return ans;
    }
};