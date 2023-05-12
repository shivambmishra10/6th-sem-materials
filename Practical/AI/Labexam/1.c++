#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000

int graph[10][10] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int n = 4; 

struct State {
    int node;
    vector<int> visited;

    State(int n, const vector<int>& v) {
        node = n;
        visited = v;
    }
};

bool operator<(const State& s1, const State& s2) {
    int cost1 = 0, cost2 = 0;
    for (int i = 0; i < s1.visited.size(); i++) {
        cost1 += graph[s1.visited[i]][s1.visited[(i+1)%s1.visited.size()]];
    }
    for (int i = 0; i < s2.visited.size(); i++) {
        cost2 += graph[s2.visited[i]][s2.visited[(i+1)%s2.visited.size()]];
    }
    return cost1 > cost2;
}


int TSP_BFS() {
  
    vector<int> visited;
    visited.push_back(0);
    State start(0, visited);

 
    priority_queue<State> q;
    q.push(start);

    int best_cost = INF;

  
    while (!q.empty()) {
   
        State current = q.top();
        q.pop();

        
        if (current.visited.size() == n) {
            int cost = 0;
            for (int i = 0; i < n; i++) {
                cost += graph[current.visited[i]][current.visited[(i+1)%n]];
            }
            best_cost = min(best_cost, cost);
        }
        else {
            
            for (int i = 0; i < n; i++) {
                if (find(current.visited.begin(), current.visited.end(), i) == current.visited.end()) {
                    vector<int> visited = current.visited;
                    visited.push_back(i);
                    State next(i, visited);
                    q.push(next);
                }
            }
        }
    }

    return best_cost;
}

int main() {
    int shortest_path = TSP_BFS();
    cout << "Shortest path length using BFS: " << shortest_path << endl;
    return 0;
}
