#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int r = grid.size();
    int c = grid[0].size();
    int fresh = 0;
    int time = 0;
    queue<pair<int, int>> q;
    vector<pair<int, int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};

    // Initialize the queue with all rotten oranges and count fresh oranges
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } 
            if (grid[i][j] == 1) {
                fresh++;
            }
        }  
    }

    // BFS to spread the rotting process
    while(!q.empty() && fresh > 0) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            pair<int, int> front = q.front();
            int row = front.first;
            int col = front.second;
            q.pop();

            for(auto dir: direction) {
                int dr = row + dir.first;
                int dc = col + dir.second;

                if (dr >= 0 && dr < r && dc >= 0 && dc < c && grid[dr][dc] == 1) {
                    grid[dr][dc] = 2;
                    fresh--;
                    q.push({dr, dc});
                }
            }
        }
        time++;
    }

    // If there are still fresh oranges left, return -1, otherwise return the time
    if (fresh == 0) {
        cout << time;
    } else {
        cout << -1;
    }

    return 0;
}
