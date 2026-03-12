class Solution {
public:
    vector<vector<bool>> row, col, box;
    vector<pair<int,int>> empty;

    bool dfs(vector<vector<char>>& board, int idx){
        if(idx == empty.size()) return true;

        int best = 0;
        int minOptions = 10;

        for(int i = idx; i < empty.size(); i++){
            int r = empty[i].first;
            int c = empty[i].second;

            int options = 0;
            for(int d = 1; d <= 9; d++){
                int b= (r/3)*3 + c/3;
                if(!row[r][d] && !col[c][d] && !box[b][d])
                    options++;
            }
            if(options < minOptions){
                minOptions = options;
                best = i;
            }
        }

        swap(empty[idx], empty[best]);

        int r = empty[idx].first;
        int c = empty[idx].second;

        for(int d = 1; d <= 9; d++){
            int b = (r/3)*3 + c/3;

            if(row[r][d] || col[c][d] || box[b][d]) continue;

            board[r][c] = d + '0';
            row[r][d] = col[c][d] = box[b][d] = true;

            if(dfs(board, idx + 1)) return true;

            board[r][c] = '.';
            row[r][d] = col[c][d] = box[b][d] = false;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        row.assign(9, vector<bool>(10,false));
        col.assign(9, vector<bool>(10,false));
        box.assign(9, vector<bool>(10,false));
//creates [false,false,false,false,false,false,false,false,false,false] 

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.')
                    empty.push_back({r,c}); //empty = [(0,2),(0,3),(1,1),(1,2)]
                else{
                    int d = board[r][c] - '0';
                    int b = (r/3)*3 + c/3;
                    row[r][d] = col[c][d] = box[b][d] = true;
                }
            }
        }
//this entire thing is basically preprocessing for faster lookups from the function
        dfs(board,0);
    }
};

//back tracking but no dfs
/*class Solution {
public:
    bool row[9][10]; 
    // since d is from 1-9 we have to have 10 available rows for that  aceess
    bool col[9][10]; 
    bool box[9][10];
    bool solve(vector<vector<char>> &board ){
        for(int r = 0; r< 9 ; r++){
            for(int c =0 ; c < 9 ; c++){
                if(board[r][c] == '.'){
                    int b = (r/3)*3 + (c/3); //index = row * width + col
                    for(int d =1 ; d<= 9 ;d++){
                        if(row[r][d] || col[c][d] || box[b][d])   continue;
                        board[r][c] = '0' + d ; 
                        // row[r][d] → true if digit d is used in row r.
                        row[r][d] = 1, col[c][d] = 1 , box[b][d] =1;
                        if(solve(board)) return true; //since sudoku only has 1 path
                        row[r][d] = 0, col[c][d] = 0 , box[b][d] =0;
                        board[r][c] = '.' ;            
                    }
                    return false; //all digits failed for the curr return , backtrack
                }
            }
        }
        return true; //no empty cell left , board is filled
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] != '.'){
                    int d = board[r][c] - '0';
                    int b = (r/3)*3 + (c/3);
                    row[r][d] = col[c][d] = box[b][d] = 1;
                 }
            }
        }
        solve(board);
    }
};
*/