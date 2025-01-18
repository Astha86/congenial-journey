class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(abs(nums[i]-nums[j])==k) {
                    v.push_back({nums[i],nums[j]});
                }
            }
        }
        v.erase(unique(v.begin(), v.end()), v.end());

        return v.size();
    }
};
