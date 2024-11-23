// 1861. Rotating the Box

// You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

//     A stone '#'
//     A stationary obstacle '*'
//     Empty '.'

// The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

// It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

// Return an n x m matrix representing the box after the rotation described above.


#include<iostream>
#include<vector>

using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box){
    int row = box.size();
    int col = box[0].size();
    // why ??????????????????????
    vector<vector<char>> ans(col,vector<char>(row));
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            ans[i][j] = '.';
        }
    }

    for(int i=0,k=row-1;i<row;i++,k--){
        for(int j=0;j<col;j++){
            if(box[i][j] == '*'){
                ans[j][k] = box[i][j];
            }
            if(box[i][j] == '#'){
                ans[j][k] = box[i][j];
            }
        }
    }
    // used for debugging
    // for(auto it:ans){
    //     for(auto it1:it){
    //         cout<<it1<<" ";
    //     }
    //     cout<<endl;
    // }


    for(int j=0;j<row;j++){
        int countStones = 0;
        for(int i=0;i<col;i++){
            int temp = i;
            if(ans[i][j] == '#'){
                countStones++;
                ans[i][j] = '.';
            }
            if(ans[i][j] == '*'){
                while(countStones != 0){
                    ans[--temp][j] = '#';
                    countStones--;
                }
            }
            if((i+1) == col && countStones != 0){
                while(countStones != 0){
                    ans[temp--][j] = '#';
                    countStones--;
                }
            }
        }
    }
    return ans;
}


int main(){
    vector<vector<char>> box = {{'#','#','*','.','*','.'},
              {'#','#','#','*','.','.'},
              {'#','#','#','.','#','.'}};
    vector<vector<char>> ans = rotateTheBox(box);

    for(auto it:ans){
        for(auto it1:it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    return 0;
}