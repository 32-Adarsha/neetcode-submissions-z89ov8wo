
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {

    int x = matrix[0][0];
    int y = matrix[0][0];

    // NOTE: First Pass :- Set Edge Col or Row Zero ( 0th)
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        if (i != 0 && j != 0 && matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        } else {
          if (matrix[i][j] == 0 && i == 0) {
            y = 0;
          } else if (matrix[i][j] == 0){
            x = 0;
          }
        }
      }
    }

    // NOTE: Second Pass Not Including Id Oth Row and Col
    for (int i = 1; i < matrix.size(); ++i) {
      for (int j = 1; j < matrix[0].size(); ++j) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    cout<<x<<endl;
    cout<<y<<endl;

    for (int i = 1; i < matrix.size(); ++i) {
      matrix[i][0] = (x == 0) ? 0 : matrix[i][0];
    }

    for (int i = 1; i < matrix[0].size(); ++i) {
      matrix[0][i] = (y == 0) ? 0 : matrix[0][i];
    }

    matrix[0][0] = (x == 0 || y == 0) ? 0 : matrix[0][0];
  }
};