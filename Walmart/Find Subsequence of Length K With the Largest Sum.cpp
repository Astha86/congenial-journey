class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(),v.end()); // sorting the numbers
        vector<pair<int, int>> v2;
        int i=n-1;
        int count = 0;
        while(count!=k){
            count++;
            v2.push_back({v[i].second,v[i].first});
            i--;
        }

        sort(v2.begin(),v2.end()); // sorting the idices
        vector<int>ans;
        for(int i=0; i<v2.size(); i++){
            ans.push_back(nums[v2[i].first]);
        }
        return ans;
    }
};
