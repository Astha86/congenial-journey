class ThroneInheritance {
public:

    unordered_map<string,vector<string>> mp;
    unordered_map<string,int> dead;
    string s; //king

    ThroneInheritance(string kingName) {
        this->s = kingName;
        mp[kingName];
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = 1;
    }

    void helper(string king, vector<string> &ans){
        for(auto i: mp[king]){
            if(dead.find(i) == dead.end()) ans.push_back(i);
            helper(i,ans);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        if(dead.find(s) == dead.end()) ans.push_back(s);
        helper(s,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
