// Last updated: 8/31/2025, 10:48:20 AM
class Solution {
public:
    int countOfSubstrings(string word, int k) {
        unordered_set<char>v={'a','e','i','o','u'};
        int ans=0;
        int n=word.length();
        for (int i=0;i<n;i++)
        {
            unordered_map<char, bool> mpp;
            int con=0;
            for (int j=i;j<n;j++)
            {
                char ch=word[j];
                if (v.find(ch)!=v.end()) mpp[ch]=true;
                else con++;
                if (mpp.size()==5 && con==k) ans++;
                if (con>k) break;
            }
        }
        return ans;
        // map<char, int> vowel;
        // int conso = 0, res = 0, i = 0, vt = 0;
        // for (int j = 0; j < word.length(); j++) {
        //     if (isVowel(word[j])) {
        //         vowel[word[j]]++;
        //         if (vowel[word[j] == 1])
        //             vt++;
        //     } else
        //         conso++;
        //     while (conso > k) {
        //         if (isVowel(word[i])) {
        //             vowel[word[i]]--;
        //             if (vowel[word[i]] == 0)
        //                 vt--;
        //         } else
        //             conso--;
        //         i++;
        //     }
        //     if (vt == 5 && conso == k)
        //         res++;
        // }
        // return res;
    }
};