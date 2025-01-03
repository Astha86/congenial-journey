class Solution {
public:

    vector<vector<int>>react;
    vector<int>v;
    
    int sides(vector<int>& r){
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }

    Solution(vector<vector<int>>& rects) {
        react = rects;
        
        int x = 0;
        for(auto r : react){
            x += sides(r);
            v.push_back(x);
        }
    }
    
    vector<int> pick() {
        int rnd = rand() % v.back();
        int idx = upper_bound(v.begin(),v.end(), rnd) - v.begin();
        auto r = react[idx];
        int x = rand() % (r[2] - r[0] +1) + r[0] ; 
        int y = rand() % (r[3] - r[1] + 1 ) + r[1]; 
        return {x, y};
    }
};
