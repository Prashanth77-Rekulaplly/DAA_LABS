#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000;
int main() {
 int n;
 cout << "Enter number of vertices: ";
 cin >> n;
 vector<vector<int>> dist(n,
vector<int>(n));
 cout << "Enter adjacency matrix (use
999 for infinity):\n";
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 int x;
 cin >> x;
 if (x == 999)
 dist[i][j] = INF;
 else
 dist[i][j] = x;
 }
 }
 // Floyd-Warshall Algorthim
 for (int k = 0; k < n; k++) {
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 if (dist[i][k] != INF &&
 dist[k][j] != INF) {
 dist[i][j] = min(
 dist[i][j],
 dist[i][k] + dist[k][j]
 );
 
 }
 }
 }
 cout << "\nShortest Distance
Matrix:\n";
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 if (dist[i][j] == INF)
 cout << "INF ";
 else

 cout << dist[i][j] << " ";
 }
 cout << endl;
 }
 return 0;
}