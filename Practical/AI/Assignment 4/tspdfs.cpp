#include <bits/stdc++.h>
using namespace std;

vector<int> path;
vector<int> min_path;
int min_tsp = INT_MAX - 1;
void dfs(vector<vector<int>> &adj, int node, int cnt, vector<bool> visited, int cost)
{
  if (cnt == adj.size() && adj[node][0] > 0)
  {
    if (min_tsp > cost + adj[node][0])
    {
      min_tsp = cost + adj[node][0];
      min_path = path;
    }
    return;
  }
  for (int i = 0; i < adj.size(); i++)
  {
    if (adj[node][i] <= 0 || visited[i])
      continue;
    visited[i] = true;
    path.push_back(i);
    dfs(adj, i, cnt + 1, visited, cost + adj[node][i]);
    path.pop_back();
    visited[i] = false;
  }
}
int main()
{
  cout << "\n----TRAVELLING SALESMAN PROBLEM USING DEPTH FIRST SEARCH----\n";
  int n = 7;
  vector<vector<int>> adj(n, vector<int>(n, -1));
  cout << "\nEnter the adjacency matrix\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> adj[i][j];
  }
  cout << "\n";
  vector<bool> visited(n, false);
  visited[0] = true;
  path.push_back(0);
  dfs(adj, 0, 1, visited, 0);
  cout << "Minimum cost path: ";
  for (int i = 0; i < min_path.size(); i++)
  {
    cout << min_path[i] << " -> ";
  }
  cout << 0 << endl;
  cout << "\n";
  cout << "Minimum Cost: " << min_tsp << endl;
  cout << "\n";
}