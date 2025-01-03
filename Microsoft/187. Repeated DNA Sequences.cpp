class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;

        if(n < 10) return ans;

        unordered_map<string, int> mp;
        for(int i=0; i<=n-10; i++){
            string x = s.substr(i, 10);
            mp[x]++;
        }

        for(auto i : mp){
            if(i.second >1) ans.push_back(i.first);
        }

        return ans;
    }
};
