
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n;
int bestCost = INT_MAX;
vector<int> bestPath;
void tsp(vector<vector<int>>& cost,
vector<bool>& visited,
 int current, int count, int currentCost,
 vector<int>& path) {
 if (count == n) {
 if (cost[current][0] != 0) {
 int totalCost = currentCost +
cost[current][0];
 if (totalCost < bestCost) {
 bestCost = totalCost;
 bestPath = path;
 bestPath.push_back(0);
 }
 }
 return;
 }
 for (int next = 0; next < n; next++) {
 if (!visited[next] && cost[current][next]
!= 0) {
 visited[next] = true;
 path.push_back(next);
 tsp(cost, visited, next, count + 1,
 currentCost + cost[current][next],
path);
 visited[next] = false;
 path.pop_back();
 }
 }
}
int main() {
 cout << "Enter number of cities: ";
 cin >> n;
 vector<vector<int>> cost(n,
vector<int>(n));
 cout << "Enter cost matrix:\n";
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 cin >> cost[i][j];
 }
 }

vector<bool> visited(n, false);
 vector<int> path;
 visited[0] = true;
 path.push_back(0);
 tsp(cost, visited, 0, 1, 0, path);
 if (bestCost == INT_MAX) {
 cout << "No complete tour exists.\n";
 } else {
 cout << "\nMinimum cost: " <<
bestCost;
 cout << "\nOptimal path: ";
 for (int city : bestPath) {
 cout << city << " ";
 }
 cout << endl;
 }
 return 0;