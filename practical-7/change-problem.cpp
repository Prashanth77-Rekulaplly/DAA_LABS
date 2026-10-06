#include <iostream> #include <algorithm> using namespace std;
int main()
{
// Static coin denominations int coins[] = {1, 2, 5, 10};
int n = 4;
int amount = 12; int dp[100];
// Base case dp[0] = 0;

// Initialize DP array
for (int i = 1; i <= amount; i++) dp[i] = 9999;

// Dynamic Programming
for (int i = 1; i <= amount; i++)
{
for (int j = 0; j < n; j++)
{
if (coins[j] <= i)
{
dp[i] = min(dp[i],
1 + dp[i - coins[j]]);
}
}
}

cout << "Coins: 1 2 5 10" << endl;
cout << "Amount: " << amount << endl;

cout << "Minimum number of coins = "
<< dp[amount] << endl;
return 0;
}

