#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

int highestMountain(vector<int>& arr) {
  int n = arr.size(), largest = INT_MIN;
  int i = 1;
  
  while (i < n - 1) {
    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
      int count = 1;
      int j = i;
      // count backwards
      while (j >= 1 && arr[j] > arr[j - 1]) {
        count++;
        j--;
      }
      // count forwards
      while (i < n - 1 && arr[i] > arr[i + 1]) {
        count++;
        i++;
      }

      largest = max(count, largest);
    } else {
      i++;
    }

  }

  return largest;
}

int main() {
  vector<int> arr {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};

  auto result = highestMountain(arr);

  cout << result << endl;

  return 0;
}