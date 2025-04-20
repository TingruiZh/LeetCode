class Solution {
public:
   int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // 注意：当循环结束时，left/right 指向的不再是回文内的边界
        // 实际回文长度 = right - left - 1
        return right - left - 1;
    }
    
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            // 以 s[i] 为中心（奇数长度）
            int len1 = expandAroundCenter(s, i, i);
            // 以 s[i] 和 s[i+1] 中间为中心（偶数长度）
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            
            // 如果找到更长的回文，就更新 start/end
            if (len > end - start + 1) {
                // 新回文的左右边界
                start = i - (len - 1) / 2;
                end   = i + len / 2;
            }
        }
        // substr(pos, count)
        return s.substr(start, end - start + 1);
    }
};