// Last updated: 8/31/2025, 10:48:12 AM
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> arrival(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        arrival[0][0] = 0;
        pq.push({0, 0, 0});
        vector<pair<int, int>> dungeon123 = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!pq.empty()) {
            auto head = pq.top();
            pq.pop();
            int i = head[0];
            int j = head[1];
            int k = head[2];
            if (i > arrival[j][k]) continue;
    
            for (auto it : dungeon123) {
                int row = j + it.first;
                int col = k + it.second;
    
                if (row >= 0 && row < n && col >= 0 && col < m) {
                    int time1 = max(i, moveTime[row][col]) + 1;
    
                    if (time1 < arrival[row][col]) {
                        arrival[row][col] = time1;
                        pq.push({time1, row, col});
                    }
                }
            }
        }
        return arrival[n - 1][m - 1];
    }
};