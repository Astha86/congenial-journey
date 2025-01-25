class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int st = 0;
        int e = 0;
        int sum = 0;

        while(e<n){
            sum += abs(s[e]-t[e++]);
            if(sum>maxCost) sum -= abs(s[st]-t[st++]);
        }
        int ans = e - st;
        
        return ans;
    }
};

// T.C: O(n)
// S.C: O(1)
