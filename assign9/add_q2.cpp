#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;

    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], 0, 0});

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int cost = curr[0];
        int r = curr[1];
        int c = curr[2];

        if (r == m-1 && c == n-1) 
            return cost;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n) 
                continue;

            int newCost = cost + grid[nr][nc];
            if (newCost < dist[nr][nc]) {
                dist[nr][nc] = newCost;
                pq.push({newCost, nr, nc});
            }
        }
    }

    return dist[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << "Minimum cost = " << shortestPath(grid);
}
