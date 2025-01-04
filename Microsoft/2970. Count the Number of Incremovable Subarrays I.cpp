class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int l = -1;
                bool flag = false;
                for(int k=0; k<n; k++){
                    if(k>=i && k<=j) continue;
                    else if(l >= nums[k]){
                        flag = true; 
                        break; 
                    }
                    l = nums[k];
                }
                if(!flag) ans++;
            }
        }
        return ans;
    }
};
