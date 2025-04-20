class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        // 1) 统计每个答案出现的次数
        for (int x : answers) {
            mp[x]++;
        }
        
        int answer = 0;
        // 2) 对于每种答案 k，算需要多少组，每组有 k+1 只兔子
        for (auto &p : mp) {
            int k   = p.first;   // “它前面看到 k 只同色兔子”
            int cnt = p.second;  // 一共有 cnt 个人给了这个答案
            
            int groupSize = k + 1;
            // 需要的组数 = ceil(cnt / (k+1))  
            // 用整数运算写成 (cnt + groupSize - 1) / groupSize
            int groups = (cnt + groupSize - 1) / groupSize;
            
            answer += groups * groupSize;
        }
        
        return answer;
    }
};