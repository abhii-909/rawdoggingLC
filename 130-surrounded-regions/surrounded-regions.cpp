class Solution {
public:
    void DFS(vector<vector<char>>&grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!='O'){
            return;
        }
        grid[i][j]='o';
        DFS(grid,i+1,j);
        DFS(grid,i-1,j);
        DFS(grid,i,j+1);
        DFS(grid,i,j-1);
    }

    void solve(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){

            if(grid[i][0]=='O'){
                DFS(grid,i,0);
            }
        }
        for(int i=0;i<grid.size();i++){

            if(grid[i][grid[0].size()-1]=='O'){
                DFS(grid,i,grid[0].size()-1);
            }
        }
        for(int i=0;i<grid[0].size();i++){

            if(grid[0][i]=='O'){
                DFS(grid,0,i);
            }
        }
        for(int i=0;i<grid[0].size();i++){

            if(grid[grid.size()-1][i]=='O'){
                DFS(grid,grid.size()-1,i);
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
                if(grid[i][j]=='o'){
                    grid[i][j]='O';
                }
            }
        }
    }
};