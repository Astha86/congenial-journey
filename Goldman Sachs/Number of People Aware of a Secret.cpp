class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> v(n, 0);
        int ans = 0;
        int mod = 1e9 + 7;
        v[0] = 1;

        for(int i=0; i<n; i++){
            for(int k=delay; k<forget && i+k<n; k++){
                v[i+k] = (v[i+k] + v[i]) % mod;
            }
            
            ans = (ans + v[i]) % mod;
            if(i >= forget){
                ans = (ans - v[i-forget] + mod) % mod;
            }
        }

        return ans;
    }
};
