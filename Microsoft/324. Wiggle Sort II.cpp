class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>v(n);

        int j = n-1;
        int i = 1;
        while(i<n){ //filling all large no. at odd indices
            v[i] = nums[j];
            i = i+2;
            j--;
        }

        i = 0;
        while(i<n){ //filling all small no. at even indices
            v[i] = nums[j];
            i = i+2;
            j--;
        }

        for(int i=0; i<n; i++){
            nums[i] = v[i];
        }
        return;
    }
};
