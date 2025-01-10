class Solution {
public:

    bool valid(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        set<int> s;
        for(int i=sr; i<=er; i++) {
            for(int j=sc; j<=ec; j++) {
                if(board[i][j] != '.'){
                    int ch = board[i][j];
                    if(s.find(ch) != s.end()) return false;
                    s.insert(ch);
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        // check for all rows
        for(int i=0; i<9; i++){
            set<int> s;
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int ch = board[i][j];
                    if(s.find(ch) != s.end()) return false;
                    s.insert(ch);
                }
            }
        }

        // check for all columns
        for(int i=0; i<9; i++){
            set<int> s;
            for(int j=0; j<9; j++){
                if(board[j][i] != '.'){
                    int ch = board[j][i];
                    if(s.find(ch) != s.end()) return false;
                    s.insert(ch);
                }
            }
        }

        // check for each boxes
        for(int sr=0; sr<9; sr+=3) {
            int er = sr+2;
            for(int sc=0; sc<9; sc+=3) {
                int ec = sc+2;
                if(!valid(board, sr, er, sc, ec)) return false;
            }
        }

        return true;
    }
};
