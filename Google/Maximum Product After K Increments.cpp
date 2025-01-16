class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0; i<n; i++){
            q.push(nums[i]);
        }
        
        for(int i=0; i<k; i++){
            int x = q.top();
            q.pop();
            q.push(x+1);
        }

        long long mod = 1e9+7;
        long long ans = 1;
        while(!q.empty()){
            int x = q.top();
            q.pop();
            ans = (ans*x)%mod;
        }
        return ans;
    }
};
