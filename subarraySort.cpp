#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> subarraySort(vector<int> a) {
  vector<int> b(a);
  sort(a.begin(), a.end());

  int n = a.size();
  int i = 0, j = n - 1;

  while (i < n && a[i] == b[i])
    i++;

  while (j >= 0 && a[j] == b[j])
    j--;

  if (i == n - 1) {
    return {-1, -1};
  }

  return {i, j};
}

int main() {
  vector<int> arr {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
  auto result = subarraySort(arr);
  cout << result[0] << ", " << result[1] << endl;
  return 0;
}