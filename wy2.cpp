#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int rows[] = {-1, 1, 0, 0};
int cols[] = {0, 0, -1, 1};

int n, m;

bool inArea(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

int bfs(vector<vector<char>>& board, int sx, int sy, char target) {
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>> q;
    q.push({sx, sy});
    dist[sy][sx] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (board[y][x] == target) {
            return dist[y][x];
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + cols[d];
            int ny = y + rows[d];
            if (inArea(nx, ny) && board[ny][nx] != '#' && dist[ny][nx] == INT_MAX) {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1; // 无法到达
}

int main() {
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    int sx = 0, sy = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'S') {
                sy = i;
                sx = j;
            }
        }
    }

    int totalSteps = 0;
    int x = sx, y = sy;

    for (char target = '1'; target <= '5'; target++) {
        int steps = bfs(board, x, y, target);
        if (steps == -1) {
            cout << -1 << endl; // 有目标到不了
            return 0;
        }
        totalSteps += steps;

        // 更新起点
        // 找到目标的位置，作为下次 BFS 起点
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == target) {
                    y = i;
                    x = j;
                }
            }
        }
    }

    cout << totalSteps << endl;
    return 0;
}
