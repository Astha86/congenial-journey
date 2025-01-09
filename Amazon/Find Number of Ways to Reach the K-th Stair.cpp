class Solution {
public:
    unordered_map<string, int> mp;

    int solve(int i, int jump, bool back, int k){
        if(i>k+1) return 0;
        int ans = 0;

        string key = to_string(i) + "_" + to_string(jump) + "_" + to_string(back);

        if(mp.find(key) != mp.end()) return mp[key];

        if(i==k) ans++;
        if(back) ans += solve(i-1, jump, 0, k);
        ans += solve(i+pow(2,jump), jump+1, 1, k);

        return mp[key] = ans;
    }

    int waysToReachStair(int k) {
       int ans = solve(1, 0, 1, k);
       return ans; 
    }
};

//Approach (Recursion + Memo)
//T.C : O(log k)
//S.C : O(log k)
