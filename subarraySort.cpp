#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

bool outOfOrder(vector<int> arr, int i) {
  int x = arr[i];
  if (i == 0) {
    return x > arr[1];
  }

  if (i == arr.size() - 1) {
    return x < arr[i - 1];
  }

  return x > arr[i + 1] || x < arr[i - 1];
}

vector<int> subarraySort(vector<int> arr) {
  int smallest = INT_MAX;
  int largest = INT_MIN;

  for (int i = 0; i < arr.size(); i++) {
    if (outOfOrder(arr, i)) {
      smallest = min(smallest, arr[i]);
      largest = max(largest, arr[i]);
    }
  }

  if (smallest == INT_MAX) {
    return {-1, -1};
  }

  int left = 0, right = arr.size() - 1;
  while (smallest >= arr[left]) {
    left++;
  }

  while (largest <= arr[right]) {
    right--;
  }
  
  return {left, right};
}

int main() {
  vector<int> arr {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
  auto result = subarraySort(arr);
  cout << result[0] << ", " << result[1] << endl;
  return 0;
}