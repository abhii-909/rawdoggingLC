class Solution {
public:
    void BFS(vector<vector<char>>&grid,int i,int j){
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};

        queue<pair<int,int>>q;
        q.push({i,j});

        grid[i][j]='o';

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int x=r+dx[i];
                int y=c+dy[i];

                if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]=='O'){
                    grid[x][y]='o';
                    q.push({x,y});
                }
            }
        }
    }
    void solve(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]=='O'){
                BFS(grid,i,0);
            }
        }
        for(int i=0;i<grid.size();i++){

            if(grid[i][grid[0].size()-1]=='O'){
                BFS(grid,i,grid[0].size()-1);
            }
        }
        for(int i=0;i<grid[0].size();i++){

            if(grid[0][i]=='O'){
                BFS(grid,0,i);
            }
        }
        for(int i=0;i<grid[0].size();i++){

            if(grid[grid.size()-1][i]=='O'){
                BFS(grid,grid.size()-1,i);
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