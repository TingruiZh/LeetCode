class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
       vector<int> totalcost(n+1);
       totalcost[0]=0;
       totalcost[1]=0;
       
       for(int i=2;i<n+1;i++){
         totalcost[i]=min(totalcost[i-1]+cost[i-1],totalcost[i-2]+cost[i-2]);
       }
       return totalcost[n];

    }
};