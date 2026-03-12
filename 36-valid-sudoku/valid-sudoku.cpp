class Solution {
public:

    bool row[9][10] = {};
    bool col[9][10] = {};
    bool box[9][10] = {};

    bool solve(vector<vector<char>>& board){

        for(int r = 0 ; r < 9 ; r++){
            for(int c = 0 ; c < 9 ; c++){
                if(board[r][c] != '.' ){
                    int b = (r/3)*3 + c/3;
                    int d = board[r][c] - '0';
                        if(row[r][d] || col[c][d] || box[b][d]){
                            return false;
                        }

                        row[r][d] = true;
                        col[c][d] = true;
                        box[b][d] = true;     
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
      
        return solve(board);
        
    }
};