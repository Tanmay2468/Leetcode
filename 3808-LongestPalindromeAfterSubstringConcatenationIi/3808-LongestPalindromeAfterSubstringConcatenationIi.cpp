// Last updated: 8/31/2025, 10:47:53 AM
class Solution {
public:
    bool isPali(const string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        string str_ = s;
        
        int n = s.size(), m = t.size();
        
        vector<int> vec_S(n, 0);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (isPali(s, i, j))
                    cnt = max(cnt, j - i + 1);
            }
            vec_S[i] = cnt;
        }
        
        int maxPali_S = 0;
        for (int i = 0; i < n; i++) {
            maxPali_S = max(maxPali_S, vec_S[i]);
        }
        
        vector<int> vec_T(m, 0);
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = i; j < m; j++) {
                if (isPali(t, i, j))
                    cnt = max(cnt, j - i + 1);
            }
            vec_T[i] = cnt;
        }
        int maxiPali = 0;
        for (int i = 0; i < m; i++) {
            maxiPali = max(maxiPali, vec_T[i]);
        }
        
        vector<int> vec_end(m, 0);
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j <= i; j++) {
                if (isPali(t, j, i))
                    cnt = max(cnt, i - j + 1);
            }
            vec_end[i] = cnt;
        }
        
        int ans = max(maxPali_S, maxiPali); 
        
        string r = t;
        reverse(r.begin(), r.end());
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == r[j]) {
                    dp[i][j] = (i > 0 && j > 0) ? dp[i-1][j-1] + 1 : 1;
                    int L = dp[i][j]; 
                    int posi_S = i - L + 1;  
                    int cand1 = 2 * L;
                    if (posi_S + L < n)
                        cand1 = 2 * L + vec_S[posi_S + L];
                    
                    int posi_T = m - j - 1;  
                    int cand2 = 2 * L;
                    if (posi_T > 0)
                        cand2 = 2 * L + vec_end[posi_T - 1];
                    
                    int candidate = max({2 * L, cand1, cand2});
                    ans = max(ans, candidate);
                }
            }
        }
        return ans;
    }
};