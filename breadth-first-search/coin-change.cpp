class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = 凑齐金额 i 所需的最少硬币数
        // 初始化时设为 amount+1（相当于无穷大）
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;  // 凑齐 0 元需要 0 枚硬币

        // 自底向上枚举所有金额
        for (int i = 1; i <= amount; ++i) {
            for (int c : coins) {
                if (i - c >= 0) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        // 如果仍然是「无穷大」，说明无法凑齐
        return dp[amount] > amount ? -1 : dp[amount];
    }
};