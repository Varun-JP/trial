class Solution {
public:
    int row;
    vector<vector<string>> ans;
    vector<int> col , diag1 , diag2;
    vector<string> board;
    void solve(int n , int row ){
        
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int c = 0 ;c< n ; c++){ 
            if(col[c] || diag1[row+c] || diag2[row-c+n-1]) {
                continue;
            }
            col[c] = 1; //blocking
            diag1[row+c] = 1;
            diag2[row-c+n-1] = 1;
            board[row][c] = 'Q'; 
            solve(n , row+1);      
            board[row][c] = '.'; //reverting
            col[c] = 0; //unblocking
            diag1[row+c] = 0;
            diag2[row-c+n-1] = 0;
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        col = vector<int>(n,0);
        diag1 = vector<int> (2*n , 0); //for any n*n space , the D is row + col
        diag2 = vector<int> (2*n, 0); 
        //it's (2*n)-1 but we just approx it for clear code
        board = vector<string>( n , string(n , '.'));
        //mapping . map before and then we add in Q everywhere
        solve( n , 0);
        return ans;
    }
};