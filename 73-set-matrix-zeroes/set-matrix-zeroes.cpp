class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        bool FRZ = false , FCZ = false;
        int n  = matrix.size() , i=0 , j = 0 , m = matrix[0].size();

        while(j< m ){ //first row zero FRZ
            if(matrix[0][j] == 0) FRZ = true; // row is fixed we parse col
            j++;
        }
        
        while(i< n ){
            if(matrix[i][0] == 0) FCZ = true; //col is fixed we parse rows
            i++;
        }
        for(int i = 1 ; i< n ; i++){
            for(int j = 1 ; j< m ; j++){
                if(matrix[i][j] == 0){
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                 }
            }
        }
        for(int i = 1 ; i< n ; i++){
            if(matrix[i][0] == 0 ){
                for(int j = 1 ; j< m ; j++){
                     matrix[i][j]=0;
                }
            }
        }
       for(int j = 1 ; j< m ; j++) {
            if( matrix[0][j]==0){
                for(int i = 1 ; i< n ; i++){
                        matrix[i][j]=0;
                }
            }
       }
        if(FRZ)
            for(int j=0 ; j < m ; j++){
                matrix[0][j] = 0;
            }    
        if(FCZ)
            for(int i=0 ; i < n ; i++){
                matrix[i][0] = 0;
            }
    }
};