#include <bits/stdc++.h> 
using namespace std;

vector<vector<vector<int>>> dp1;
vector<vector<int>> dp2;

int solve2(int i,int j,vector<int>& coins){
    if(i > j) return 0;
    
    if(dp2[i][j] != -1) return dp2[i][j];
    
    int way1 = coins[i] + min( solve2(i+2,j,coins), solve2(i+1,j-1,coins) );
    int way2 = coins[j] + min( solve2(i,j-2,coins), solve2(i+1,j-1,coins) );
    
    return dp2[i][j] = max(way1,way2);
}


int solve1(int i,int j,vector<int>& coins,int flag){
    if(i > j) return 0;

    if(dp1[i][j][flag] != -1) return dp1[i][j][flag];
    if(flag == 0){
        int way1 = coins[i] + solve1(i+1,j,coins,1);
        int way2 = coins[j] + solve1(i,j-1,coins,1);
        dp1[i][j][flag] = max(way1,way2);
    }
    else{
        int way1 = solve1(i + 1, j, coins, 0);
        int way2 = solve1(i, j - 1, coins, 0);
        dp1[i][j][flag] = min(way1,way2);
    }

    return dp1[i][j][flag];
}


int optimalStrategyOfGame(vector<int> coins, int n)
{
    dp1.resize(n,vector<vector<int>>(n,vector<int>(2,-1)));
    dp2.resize(n,vector<int>(n,-1));
    //return solve1(0,n-1,coins,0); // way1
    return solve2(0,n-1,coins); // way2
}


int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int result = optimalStrategyOfGame(coins, n);

    cout << result << endl;

    return 0;
}