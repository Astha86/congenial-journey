class Solution {
public:
    static bool cmp(vector<int> &a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }

    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();

        sort(env.begin(), env.end(), cmp);
        vector<int> v;
        v.push_back(env[0][1]);

        for(int i=1; i<n; i++){
            if(v.back()<env[i][1]) v.push_back(env[i][1]);
            else{
                int idx=lower_bound(v.begin(),v.end(),env[i][1])-v.begin();
                v[idx]=env[i][1];
            }
        }
        return v.size();
    }
};
