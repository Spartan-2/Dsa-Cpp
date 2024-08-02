#include<iostream>
#include<vector>
#include<limits>
#include<queue>
#include<set>
using namespace std;

bool checkVisited(int r,int c,set<pair<int,int>> visited){
    auto it = visited.find({r,c});
    if (it != visited.end()){
        return false;
    }else{
        return true;
    }
}

void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 1;
        int inf = std::numeric_limits<int>::max();
        
        queue<pair<int,int>> q;
        vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
        set<pair<int,int>> visited;

        for (int i =0;i<r;i++){
            for(int j=0;j<c;j++){
                if (grid[i][j] == 0){
                    q.push({i,j});
                    visited.insert({i,j});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            for (int i =0;i<size;i++){
                pair<int,int> front = q.front();
                int row = front.first;
                int col = front.second;
                q.pop();

                for (auto it : direction){
                    int dr = row + it.first;
                    int dc = col + it.second;

                    if((dr < r) && (dr >= 0) && (dc < c) && (dc >= 0) &&
                     (grid[dr][dc] == inf) && (checkVisited(dr,dc,visited))){
                    
                        grid[dr][dc] = count;
                        visited.insert({dr,dc});
                        q.push({dr,dc});

                    }
                }
            }
            count++;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
}

int main(){
    vector<vector<int>> grid = {
  {2147483647,-1,0,2147483647},
  {2147483647,2147483647,2147483647,-1},
  {2147483647,-1,2147483647,-1},
  {0,-1,2147483647,2147483647}
    };
    islandsAndTreasure(grid);
    return 0;
}