#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestBand(vector<int>& arr) {
  sort(arr.begin(), arr.end());

  int band = 1, maxBand = 0;
  
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i + 1] - arr[i] == 1) {
      band++;
    } else {
      maxBand = max(band, maxBand);
      band = 1;
    }
  }

  return maxBand;
}

int main() {
  vector<int> arr {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};

  auto result = longestBand(arr);

  cout << result << endl;

  return 0;
}