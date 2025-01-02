class Solution {
public:

    int helper(vector<vector<int>>& v, int i, int j, int r, int c){
        int up = max(0, i-1);
        int dwn = min(r, i+2);
        int lft = max(0, j-1);
        int rgt = min(c, j+2);

        int sum = 0;
        int cnt = 0;

        for(int row=up; row<dwn; row++){
            for(int col=lft; col<rgt; col++){
                sum += v[row][col];
                cnt++;
            }
        }
        return sum/cnt;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size();
        int c = img[0].size();

        vector<vector<int>> ans(r, vector<int>(c,0));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans[i][j] = helper(img, i, j, r, c);
            }
        }

        return ans;
    }
};
