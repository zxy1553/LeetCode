#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {

private:
  const int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

  bool isValid(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

public:
  int orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    int fresh = 0;
    int step = 0;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          fresh++;
        } else if (grid[i][j] == 2) {
          q.emplace(i, j);
        }
      }
    }

    if (!fresh)
      return 0;

    while (!q.empty() && fresh) {
      int sz = q.size();
      for (int idx = 0; idx < sz; ++idx) {
        auto [x, y] = q.front();
        q.pop();
        for (const auto &dir : directions) {
          int nx = x + dir[0];
          int ny = y + dir[1];
          if (isValid(nx, ny, n, m)) {
            if (grid[nx][ny] == 1) {
              fresh--;
              grid[nx][ny] = 2;
              q.emplace(nx, ny);
            }
          }
        }
      }
      step++;
    }

    return fresh == 0 ? step : -1;
  }
};

int main() {
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  vector<vector<int>> grid1 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
  vector<vector<int>> grid2 = {{0, 2}};
  vector<vector<int>> grid3 = {
      {2, 0, 1, 2, 1, 1, 2, 2, 1, 2}, {0, 1, 1, 0, 0, 2, 1, 2, 0, 1},
      {2, 0, 1, 1, 1, 0, 1, 2, 0, 0}, {1, 0, 1, 2, 1, 0, 2, 0, 1, 2},
      {2, 2, 2, 0, 2, 1, 0, 1, 0, 1}, {1, 0, 2, 2, 0, 1, 2, 1, 1, 2},
      {1, 2, 2, 0, 1, 0, 2, 1, 2, 0}, {1, 0, 1, 0, 1, 0, 1, 0, 1, 2},
      {0, 2, 2, 2, 2, 1, 2, 0, 2, 2}, {1, 1, 2, 1, 1, 1, 2, 1, 1, 1}};

  Solution sol;
  cout << sol.orangesRotting(grid3);
}