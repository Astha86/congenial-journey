class Solution {
public:

    int ans = 0;

    bool isPalindrome(string &s){
        int n = s.size();
        int i = 0;
        int j = n-1;

        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void helper(string &s1, string &s2, int idx, string &s){
        if(idx==s.size()){
            if(isPalindrome(s1) && isPalindrome(s2)){
                int temp = s1.size() * s2.size();
                ans = max(ans,temp);
            }
            return;
        }

        s1.push_back(s[idx]);
        helper(s1, s2, idx+1, s);
        s1.pop_back();

        s2.push_back(s[idx]);
        helper(s1, s2, idx+1, s);
        s2.pop_back();

        helper(s1, s2, idx+1, s);

        return;
    }

    int maxProduct(string &s) {
        string s1 = "";
        string s2 = "";
        helper(s1, s2, 0, s);
        return ans;
    }
};
