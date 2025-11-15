class Solution {
public:
    

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);

        
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        
        return dfs(source, destination, graph, vis);
    }

    bool dfs(int node, int dest, vector<vector<int>>& graph, vector<bool>& vis){
        if(node == dest) return true;
        vis[node] = true;

        for(int nei : graph[node]){
            if(!vis[nei]){
                if(dfs(nei, dest, graph, vis))
                    return true;
            }
        }
        return false;
    }
};
