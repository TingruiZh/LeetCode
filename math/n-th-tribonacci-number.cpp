class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int>T(n+1);
        T[0]=0;
        T[1]=1;
        T[2]=1;
        for(int i =3; i<n+1; i++){
            T[i]=T[i-1]+T[i-2]+T[i-3];
        }
        return T[n];
    }
};