class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int x = n/2;
        int ans = 0;
        sort(nums.begin(), nums.end());

        vector<int>v(n);
        for(int i=0; i<n; i++){
            v[i] = abs(nums[i]-nums[x]);
            ans += v[i];
        }

        return ans;
    }
};
