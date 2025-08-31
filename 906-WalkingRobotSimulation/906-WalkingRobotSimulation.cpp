// Last updated: 8/31/2025, 10:49:35 AM
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // int n = commands.size();
        // int m = obstacles.size();
        // int x_curr = 0, y_curr = 0;
        // bool xp = false, xn = false, yp = true, yn = false;
        // int maxi = 0;
        // for (int i = 0; i < n; i++) {
        //     if (commands[i] == -1) {
        //         if (xp == true) {
        //             yn = true;
        //             xp = false;
        //         } else if (xn == true) {
        //             yp = true;
        //             xn = false;
        //         } else if (yp == true) {
        //             xp = true;
        //             yp = false;
        //         } else if (yn == true) {
        //             xn = true;
        //             yn = false;
        //         }
        //     } else if (commands[i] == -2) {
        //         if (xp == true) {
        //             yp = true;
        //             xp = false;
        //         } else if (xn == true) {
        //             yn = true;
        //             xn = false;
        //         } else if (yp == true) {
        //             xn = true;
        //             yp = false;
        //         } else if (yn == true) {
        //             xp = true;
        //             yn = false;
        //         }
        //     } else {
        //         if (xp == true) {
        //             int x_poss = x_curr + commands[i];
        //             for (int j = 0; j < m; j++) {
        //                 if (obstacles[j][0] > x_curr &&
        //                     obstacles[j][0] <= x_poss) {
        //                     x_curr = obstacles[j][0] - 1;
        //                     int temp = pow(x_curr, 2) + pow(y_curr, 2);
        //                     maxi = max(maxi, temp);
        //                 }
        //             }
        //         } else if (xn == true) {
        //             int x_poss = x_curr - commands[i];
        //             for (int j = 0; j < m; j++) {
        //                 if (obstacles[j][0] < x_curr &&
        //                     obstacles[j][0] >= x_poss) {
        //                     x_curr = obstacles[j][0] + 1;
        //                     int temp = pow(x_curr, 2) + pow(y_curr, 2);
        //                     maxi = max(maxi, temp);
        //                 }
        //             }
        //         } else if (yp == true) {
        //             int y_poss = y_curr + commands[i];
        //             for (int j = 0; j < m; j++) {
        //                 if (obstacles[j][1] > y_curr &&
        //                     obstacles[j][1] <= y_poss) {
        //                     y_curr = obstacles[j][1] - 1;
        //                     int temp = pow(x_curr, 2) + pow(y_curr, 2);
        //                     maxi = max(maxi, temp);
        //                 }
        //             }
        //         } else if (yn == true) {
        //             int y_poss = y_curr - commands[i];
        //             for (int j = 0; j < m; j++) {
        //                 if (obstacles[j][1] < y_curr &&
        //                     obstacles[j][1] >= y_poss) {
        //                     y_curr = obstacles[j][1] + 1;
        //                     int temp = pow(x_curr, 2) + pow(y_curr, 2);
        //                     maxi = max(maxi, temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return maxi;

        // Convert the obstacle positions to a set for quick lookup
        unordered_set<string> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," +
                               to_string(obstacle[1]));
        }

        int x_curr = 0, y_curr = 0; // Robot's current position
        int maxDist = 0;            // Maximum Euclidean distance squared
        int direction = 0;          // 0 = North, 1 = East, 2 = South, 3 = West
        vector<int> dx = {0, 1, 0, -1}; // x direction changes
        vector<int> dy = {1, 0, -1, 0}; // y direction changes

        for (int command : commands) {
            if (command == -1) {
                direction = (direction + 1) % 4; // Turn right
            } else if (command == -2) {
                direction = (direction + 3) % 4; // Turn left
            } else {
                for (int step = 0; step < command; ++step) {
                    int nx = x_curr + dx[direction];
                    int ny = y_curr + dy[direction];
                    string nextPos = to_string(nx) + "," + to_string(ny);
                    if (obstacleSet.find(nextPos) != obstacleSet.end()) {
                        break; // Stop before hitting the obstacle
                    }
                    x_curr = nx;
                    y_curr = ny;
                    maxDist = max(maxDist, x_curr * x_curr + y_curr * y_curr);
                }
            }
        }
        return maxDist;
    }
};