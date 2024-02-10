#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(int parent,vector<int>&vis,vector<int>*adj,vector<int>&ans){
        ans.push_back(parent);
        vis[parent] = 1;
        for(auto nbr :adj[parent]){
            if(!vis[nbr]){
                DFS(nbr, vis, adj, ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans, vis(V + 1, 0);
        DFS(0, vis, adj, ans);
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
