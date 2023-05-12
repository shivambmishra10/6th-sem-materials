#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

int main()
{
  int n = 10;
  vector<vector<pi>> graph(n);
  graph[0] = {{1, 6}, {5, 3}};
  graph[1] = {{0, 6}, {2, 3}, {3, 4}};
  graph[2] = {{1, 3}, {3, 1}, {4, 5}};
  graph[3] = {{1, 2}, {2, 1}, {4, 8}};
  graph[4] = {{2, 5}, {3, 8}, {8, 5}, {9, 5}};
  graph[5] = {{0, 3}, {6, 1}, {7, 7}};
  graph[6] = {{5, 1}, {8, 3}};
  graph[7] = {{5, 7}, {8, 2}};
  graph[8] = {{4, 5}, {9, 3}, {6, 3}, {7, 2}};
  graph[9] = {{4, 5}, {8, 3}};
  vector<int> heuristic = {10, 8, 5, 7, 3, 6, 5, 3, 1, 0};
  vector<int> cost(n, INT_MAX);
  vector<bool> visited(n, false);
  cost[0] = 0;

  vector<int> parent = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push({heuristic[0], 0});
  while (!pq.empty())
  {
    pi temp;
    int node, f_func;
    temp = pq.top();
    node = temp.second;
    f_func = temp.first;
    pq.pop();
    if (visited[node])
    {
      continue;
    }
    visited[node] = true;
    int size = graph[node].size();
    for (int i = 0; i < size; i++)
    {
      int tempnode = graph[node][i].first;
      int ch = graph[node][i].second;
      if (visited[tempnode])
      {
        continue;
      }
      if (cost[tempnode] > cost[node] + ch)
      {
        cost[tempnode] = cost[node] + ch;
        pq.push({cost[tempnode] + heuristic[tempnode], tempnode});
        parent[tempnode] = node;
      }
    }
  }

  cout << cost[9] << endl;
  // Path
  vector<int> ans;

  ans.push_back(9);
  int i = 9;
  while (parent[i])
  {
    i = parent[i];
    ans.push_back(i);
    // i = parent[i];
  }
  ans.push_back(0);

  for (int i = ans.size() - 1; i > 0; i--)
  {
    char ch = 'A' + ans[i];
    cout << ch << " -> ";
  }
  char ch = 'A' + ans[0];
  cout << ch << endl;
}
