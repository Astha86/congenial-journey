class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,int> mp;

        long long sum = 0;
        for(int i=0; i<n; i++){ // Including right element
            mp[nums[i]]++;
            sum += nums[i];

            
            if(i>=k){ // Excluding left element
                sum -= nums[i-k];
                mp[nums[i-k]]--;
                if(mp[nums[i-k]]==0) mp.erase(nums[i-k]);
            }

            if(i>=k-1 && mp.size()==k) ans = max(ans, sum);
        }
        return ans;
    }
};
