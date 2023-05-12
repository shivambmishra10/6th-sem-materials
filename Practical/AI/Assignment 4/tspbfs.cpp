#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, graph[N][N], visited[1 << N][N], ans = INT_MAX;

struct node
{
  int mask, cur, cost;
};

void bfs()
{
  queue<node> q;
  q.push({1, 0, 0});
  visited[1][0] = 1;
  while (!q.empty())
  {
    node nd = q.front();
    q.pop();
    if (nd.mask == (1 << n) - 1 && graph[nd.cur][0])
    {
      ans = min(ans, nd.cost + graph[nd.cur][0]);
    }
    for (int i = 0; i < n; i++)
    {
      if (!visited[nd.mask | (1 << i)][i] && graph[nd.cur][i])
      {
        visited[nd.mask | (1 << i)][i] = 1;
        q.push({nd.mask | (1 << i), i, nd.cost + graph[nd.cur][i]});
      }
    }
  }
}

int main()
{
  cout << "Enter the number of nodes: ";
  cin >> n;
  cout << "Enter the adjacency matrix: \n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> graph[i][j];
    }
  }
  bfs();
  if (ans == INT_MAX)
  {
    cout << "No Hamiltonian cycle exists.\n";
  }
  else
  {
    cout << "Minimum cost of Hamiltonian cycle: " << ans << "\n";
  }
  return 0;
}