class Solution {
public:
    int lengthOfLongestSubstring(string s) {
 int max_ = 0;

        for (int i = 0; i < s.size(); i++) {
            map<char, bool> mp;
            int c = 0;

            for (int j = i; j < s.size(); j++) {
                if (mp[s[j]]) {
                    break; 
                } else {
                    mp[s[j]] = true;
                    c++;
                    max_ = max(max_, c);
                }
            }
        }

        return max_;}
};