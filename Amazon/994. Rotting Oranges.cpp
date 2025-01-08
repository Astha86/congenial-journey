class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int,int>>q;

        int f = 0; // no. of fresh oranges
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1) f++;
                else if(grid[i][j]==2) q.push({i,j}); //multisource bfs
            }
        }

        q.push({-1,-1}); // 1 minute completed here

        int ans = 0; //calculating the minutes
        vector<vector<int> > dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr.first==-1){
                ans++;
                if(q.size()!=0) q.push(curr);
                else break;
            }

            else{ // means we have rotten orange
                int i = curr.first;
                int j = curr.second;
                for(int d=0; d<4; d++){
                    int row = i+dir[d][0];
                    int col = j+dir[d][1];

                    if(row>=0 && row<r && col>=0 && col<c){
                        if(grid[row][col]==1){ //means it is fresh orange
                            q.push({row,col});
                            grid[row][col] = 2; // mark as rotten
                            f--; // removing it from no. of fresh oranges
                        }
                    }
                }
            }
        }
        if(f==0) ans -= 1;
        else ans = -1;

        return ans;
    }
};
