class Solution {
    bool issafe(int row,int col,vector<int> & leftrow,vector<int> & upperdiagonal,vector<int> & lowerdiagonal,int n){
        if(leftrow[row]==0 && upperdiagonal[n-1+(col-row)]==0 &&  lowerdiagonal[row+col]==0) return true;
        return false ;
    }
    void NQueen(int n,vector<string> & board,int col,vector<vector<string>> & ans,vector<int> & leftrow,vector<int> & upperdiagonal,vector<int> & lowerdiagonal){
        if(col==n){
          ans.push_back(board);
          return ;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,leftrow,upperdiagonal,lowerdiagonal,n)){
              board[row][col]='Q';
              leftrow[row]=upperdiagonal[n-1+(col-row)]=lowerdiagonal[row+col]=1;
               NQueen(n,board,col+1,ans,leftrow,upperdiagonal,lowerdiagonal);
                 board[row][col]='.';
              leftrow[row]=upperdiagonal[n-1+(col-row)]=lowerdiagonal[row+col]=0; 
            }
        }

     }
public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>ans;
      vector<string>board(n,string(n,'.')) ;
      vector<int>leftrow(n,0);
      vector<int>upperdiagonal(2*n-1,0);
      vector<int>lowerdiagonal(2*n-1,0);
      NQueen(n,board,0,ans,leftrow,upperdiagonal,lowerdiagonal); 
      return ans; 
    }
};
