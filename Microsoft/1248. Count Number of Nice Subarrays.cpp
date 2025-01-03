class Solution {
public:

    int helper(vector<int>& nums, int k) {
        int n = nums.size();
        bool flag = 0;
        for (int i=0; i<n; i++){
            if (nums[i]%2 == 0) nums[i] = 0;
            else{
                nums[i] = 1;
                flag = true;
            }
        }

        int sum = 0, ans = 0;
        int x = 0, l=0;
        if (!flag) return 0; 
        while (x<n){
            sum += nums[x];
            while (sum>k){ 
                sum -= nums[l];
                l++;
            }
            if (sum <= k) ans += x - l + 1; 
            x++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
