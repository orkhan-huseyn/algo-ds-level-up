#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int waterTrap(vector<int>& arr) {
  int n = arr.size();

  vector<int> left(n, 0);
  left[0] = arr[0];

  vector<int> right(n, 0);
  right[n - 1] = arr[n - 1];

  for (int i = 1; i < n; i++) {
    left[i] = max(left[i - 1], arr[i]);
  }

  for (int i = n - 2; i >= 0; i--) {
    right[i] = max(right[i + 1], arr[i]);
  }

  int trappedWater = 0;
  for (int i = 0; i < n; i++) {
    trappedWater += (min(left[i], right[i]) - arr[i]);
  }

  return trappedWater;
}

int main() {
  vector<int> arr {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  int result = waterTrap(arr);
  cout << result << endl;
}