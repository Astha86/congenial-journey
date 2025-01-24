class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int x = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            x += i*nums[i];
        }

        int ans = x;
        for(int i=n-1; i>=0; i--){
            x += sum-(nums[i]*n);
            ans = max(x,ans);
        }

        return ans;
    }
};
