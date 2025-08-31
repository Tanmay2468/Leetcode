// Last updated: 8/31/2025, 10:47:51 AM
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int cells=n*n;
        int possi=maxWeight/w;
        if (possi>cells) return cells;
        else return possi;
    }
};