class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int ans = 0;
        sort(ages.begin(), ages.end());

        for (int i=0; i<n; i++) {
            int x = (ages[i]/2)+7;
            for (int j=i-1; j>=0; j--) {
                if(ages[j] <= x) break;
                if(ages[i] == ages[j]) ans++;
                ans++;
            }
        }

        return ans;
    }
};
