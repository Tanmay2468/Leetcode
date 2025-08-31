// Last updated: 8/31/2025, 10:47:52 AM
class Solution {
public:
    // void dfs(const vector<vector<int>>& adj_mat, vector<bool>& visited, int node) {
    //     visited[node] = true;
    //     for (int neighbour : adj_mat[node]) {
    //         if (!visited[neighbour]) {
    //             dfs(adj_mat, visited, neighbour);
    //         }
    //     }
    // }
    // int countComponents(int n, vector<vector<int>>& edges) {
    //     vector<vector<int>> adj_mat(n);
    //     vector<bool> visited(n, false);
    //     for (const auto& edge : edges) {
    //         adj_mat[edge[0]].push_back(edge[1]);
    //         adj_mat[edge[1]].push_back(edge[0]);
    //     }
    //     int res = 0;
    //     for (int node = 0; node < n; ++node) {
    //         if (!visited[node]) {
    //             dfs(adj_mat, visited, node);
    //             res++;
    //         }
    //     }
    //     return res;
    // }
    // int intersect(vector<int>a, vector<int>b){
    //     unordered_set<int> st1;
    //     unordered_set<int> st2;
    //     for (auto it: a) st1.insert(it);
    //     for (auto it: b) st2.insert(it);
    //     int ct=0;
    //     for (auto it: st1){
    //         if (st2.find(it)!=st2.end()) ct++;
    //     }
    //     return ct;
    // }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        // vector<vector<int>> edges;
        vector<unordered_set<int>> neigh(n);
        vector<int> papa(n);
        int i=0;
        while (i<n){
            neigh[i]=unordered_set<int>(properties[i].begin(), properties[i].end());
            papa[i]=i;
            i++;
        }
        function<int(int)>find=[&](int x){
            while (papa[x]!=x){
                papa[x]=papa[papa[x]];
                x=papa[x];
            }
            return x;
        };
        auto mrge=[&](int x, int y){
            int R_x=find(x), R_y=find(y);
            if (R_x!=R_y) papa[R_y]=R_x;
        };
        i=0;
        while (i<n){
            int j=i+1;
            while (j<n){
                int same=0;
                for (int it:neigh[i]){
                    if (neigh[j].count(it)){
                        same++;
                        if (same>=k){
                            mrge(i,j);
                            break;
                        }
                    }
                }
                j++;
            }
            i++;
        }
        unordered_set<int> uqi;
        i=0;
        while (i<n){
            uqi.insert(find(i));
            i++;
        }
        return uqi.size();
        // for (int i=0;i<n-1;i++){
        //     for (int j=i+1;j<n;j++){
        //         int ct=intersect(properties[i], properties[j]);
        //         if (ct>=k){
        //             edges.push_back({i, j});
        //         }
        //     }
        // }
        // int ans=countComponents(n, edges);
        // return ans;
    }
};