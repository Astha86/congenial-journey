
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        int maxi = 1;
        int x = -1;
        vector<int>ans;
        sort(nums.begin(), nums.end());
        vector<int>v(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(!(nums[i]%nums[j]) && v[i]<v[j]+1){
                    v[i]=v[j]+1;
                    if(maxi<v[i]){
                        maxi=v[i];
                    }
                }
            }
        }
        
        for(int i=n-1; i>=0; i--){
            if(maxi==v[i] && (x==-1 || !(x%nums[i]))){
                ans.push_back(nums[i]);
                maxi--;
                x=nums[i];
            }
        }
        return ans;
    }
};
