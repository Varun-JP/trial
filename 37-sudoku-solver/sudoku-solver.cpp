class Solution {
public:
    int row[9] = {0};
    int col[9] = {0};
    int box[9] = {0};
    vector<pair<int,int>> empty;

    bool solve(vector<vector<char>>& board, int idx){

        if(idx == empty.size()) return true;

        auto [r,c] = empty[idx];
        int b = (r/3)*3 + c/3;

        int mask = ~(row[r] | col[c] | box[b]) & 0x1FF;

        while(mask){

            int pick = mask & -mask;
            mask -= pick;

            int d = __builtin_ctz(pick);

            board[r][c] = '1' + d;

            row[r] |= pick;
            col[c] |= pick;
            box[b] |= pick;

            if(solve(board, idx+1)) return true;

            row[r] ^= pick;
            col[c] ^= pick;
            box[b] ^= pick;

            board[r][c] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){

                if(board[r][c]=='.'){
                    empty.push_back({r,c});
                }
                else{
                    int d = board[r][c]-'1';
                    int b = (r/3)*3 + c/3;

                    int bit = 1<<d;

                    row[r] |= bit;
                    col[c] |= bit;
                    box[b] |= bit;
                }
            }
        }

        solve(board,0);
    }
};