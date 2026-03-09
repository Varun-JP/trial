class Solution {
public:
    bool row[10][10];
    bool col[10][10];
    bool box[10][10];
    bool solve(vector<vector<char>> &board ){
        for(int r = 0; r< 9 ; r++){
            for(int c =0 ; c < 9 ; c++){
                if(board[r][c] == '.'){
                    int b = (r/3)*3 + (c/3);
                    for(int d =1 ; d<= 9 ;d++){
                        if(row[r][d] || col[c][d] || box[b][d])   continue;
                        board[r][c] = '0' + d ;
                        row[r][d] = 1; 
                        col[c][d] = 1;
                        box[b][d] =1;
                        if(solve(board)) return true;
                        row[r][d] = 0; 
                        col[c][d] = 0;
                        box[b][d] =0;
                        board[r][c] = '.' ;            
                    }
                    return false;
                }
            }
        }
        return true; 
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] != '.'){
                    int d = board[r][c] - '0';
                    int b = (r/3)*3 + (c/3);
                    row[r][d] = col[c][d] = box[b][d] = true;
                 }
            }
        }
        solve(board);
    }
};