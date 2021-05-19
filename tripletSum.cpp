#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<int>> triplets(vector<int>& arr, int target) {
  vector<vector<int>> result;
  int n = arr.size();
  sort(arr.begin(), arr.end());

  for (int i = 0; i < n - 2; i++) {
    int j = i + 1, k = n - 1;

    while (j < k) {
      int currentSum = arr[i];
      currentSum += arr[j];
      currentSum += arr[k];

      if (currentSum == target) {
        result.push_back({ arr[i], arr[j], arr[k] });
        j++;
        k--;
      } else if (currentSum > target) {
        k--;
      } else if (currentSum < target) {
        j++;
      }
    }
  }

  return result;
}

int main() {
  vector<int> arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
  int target = 18;

  auto result = triplets(arr, target);

  for (auto v: result) {
    for (auto no: v) {
      cout << no << ", ";
    }
    cout << endl;
  }
}