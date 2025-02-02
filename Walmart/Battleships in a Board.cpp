// cpy pstd

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int r = board.size();
        int c = board[0].size();
        
        int ans = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j]=='X'){ 
                    if(i==0 && j==0) ans++; 
                    
                    else if(i==0){          
                        if(board[i][j-1]!='X') ans++;
                    }
                     
                    else if(j==0){           
                        if(board[i-1][j]!='X') ans++;
                    }

                    else if(board[i-1][j]=='.' && board[i][j-1]=='.') ans++;
                }
            }
        }
        
        return ans;
    }
};
