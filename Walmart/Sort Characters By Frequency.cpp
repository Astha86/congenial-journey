class Solution {
public:
    string frequencySort(string st) {
        unordered_map<char,int> mp;
        for(char x: st){
            mp[x]++;
        }

        string ans = "";
        while(mp.size()>0){
            int cnt = 0;
            char ch;

            for(auto x : mp){
                if(x.second > cnt){
                    cnt = x.second;
                    ch = x.first;
                }
            }

            for(int i=0; i<cnt; i++){
                ans+=ch;
            }
            mp.erase(ch);
        }
        return ans;
    }
};
