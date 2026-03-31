class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        int xBound = grid[0].size() - 1;
        int yBound = grid.size() - 1 ;
        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0 ; j < grid[0].size() ; ++j){
                if(grid[i][j] == '1'){
                    islandCount++;
                }
                queue<pair<int , int>> q;
                q.push({i , j});
                while(!q.empty()){
                    pair<int , int> point = q.front();
                    q.pop();
                    if(grid[point.first][point.second] != '1') continue;

                    grid[point.first][point.second] = 'x';

                    // left 
                    q.push({point.first , max(0 , point.second - 1)});
                    // right 
                    q.push({point.first , min(xBound , point.second + 1)});
                    // top
                    q.push({max(0 , point.first - 1) , point.second});
                    // bottom
                    q.push({min(yBound , point.first + 1) , point.second});
                }

            }
        }


        return islandCount;
    }
};
