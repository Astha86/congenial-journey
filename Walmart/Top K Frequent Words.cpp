class Solution {
public:

    static bool cmp(pair<int,string>&a,pair<int,string>&b){
        if(a.first==b.first) return a.second < b.second;
        else return a.first > b.first;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int> mp;
        for(auto x: words){
            mp[x]++;
        }

        vector<pair<int,string>> v;
        for(auto x: mp){
            v.push_back({x.second,x.first});
        }

        sort(v.begin(),v.end(),cmp);
        vector<string> ans;
        int i = 1;
        for(auto x: v){
            if(i>k) break;
            ans.push_back(x.second);
            i++;
        }
        return ans;
    }
};
