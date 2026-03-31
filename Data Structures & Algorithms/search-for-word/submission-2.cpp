class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       for(int i = 0 ; i < board.size() ; i++) {
        for (int j = 0 ; j < board[0].size(); j++) {
            if(board[i][j] == word[0]) {
                cout<<"found"<<endl;
                if (searchword(board , word , 0 , {i , j})) return true;
            }
        }
       } 
       return false;
    }


    bool searchword(vector<vector<char>> board , string word , int word_index , pair<int , int> pos){
        // if the index is greater than word we are certain that we find the word
        if(word_index > word.length() - 1) return true;

        if(pos.first < 0 || pos.second < 0 || pos.first >= board.size() || pos.second >= board[0].size() || board[pos.first][pos.second] == '*' ) {
            return false;
        }

        if (board[pos.first][pos.second] != word[word_index]) return false;

        board[pos.first][pos.second] = '*';

        bool left = searchword(board , word  , word_index +1 , {pos.first - 1 , pos.second});
        bool right = searchword(board , word , word_index + 1 , {pos.first + 1 , pos. second});
        bool top = searchword(board , word , word_index + 1 , {pos.first , pos.second-1});
        bool bottom = searchword(board , word , word_index + 1 , {pos.first , pos.second + 1});

        return left || right || top || bottom;
        
    }


    
};
