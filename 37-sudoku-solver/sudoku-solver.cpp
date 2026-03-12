class Solution {
public:
    vector<vector<bool>> row, col, box;
    vector<pair<int,int>> empty;

    bool dfs(vector<vector<char>>& board, int idx){
        if(idx == empty.size()) return true;

        int best = idx;
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

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.')
                    empty.push_back({r,c});
                else{
                    int d = board[r][c] - '0';
                    int b = (r/3)*3 + c/3;
                    row[r][d] = col[c][d] = box[b][d] = true;
                }
            }
        }

        dfs(board,0);
    }
};