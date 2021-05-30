#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumSwaps(vector<int> arr) {
  int n = arr.size();
  int count = 0;

  pair<int, int> ap[n];
  for (int i = 0; i < n; i++) {
    ap[i].first = arr[i];
    ap[i].second = i;
  }

  sort(ap, ap + n);

  vector<bool> visited(n, false);
  
  for (int i = 0; i < n; i++) {
    int oldPos = ap[i].second;
    if (visited[i] || oldPos == i) {
      continue;
    }

    int node = i, cycle = 0;
    while (!visited[node]) {
      visited[node] = true;
      int nextNode = ap[node].second;
      node = nextNode;
      cycle++;
    }

    count += cycle - 1;
  }

  return count;
}

int main() {
  vector<int> arr {5, 4, 3, 2, 1};
  cout << minimumSwaps(arr) << endl;
  return 0;
}