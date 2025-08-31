// Last updated: 8/31/2025, 10:49:50 AM
class Solution {
public:
    int findComplement(int num) {
        queue<int> q;
        while (num > 0) {
            int bit = num % 2;
            q.push(bit);
            num /= 2;
        }
        queue<int> qq;
        while (!q.empty()) {
            int temp = q.front();
            if (temp == 0)
                temp = 1;
            else
                temp = 0;
            qq.push(temp);
            q.pop();
        }
        int comp = 0;
        int p = 0;
        while (!qq.empty()) {
            int temp = qq.front();
            comp += temp * pow(2, p);
            p++;
            qq.pop();
        }
        return comp;
    }
};