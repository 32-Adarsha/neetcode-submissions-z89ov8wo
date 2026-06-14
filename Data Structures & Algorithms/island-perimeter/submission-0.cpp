class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0 ; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
               if(grid[i][j] == 1) {
                 perimeter += getPerimeter({i , j}, grid);
               }
            }
        }

        return perimeter;
    }

    int getPerimeter(pair<int , int> position , vector<vector<int>>& grid){
        vector<pair<int , int>> RNP = {{0 ,1}, {0 , -1} , {1 , 0}, {-1 , 0}};
        int n = 0;
        for(auto [x , y] : RNP){
            x += position.first; 
            y += position.second;
            if(x < grid.size() && x >= 0 && y < grid[0].size() && y >= 0 && grid[x][y] == 1 ){
                n += 1;   
            }
        }

        return 4 - n;

    }



};