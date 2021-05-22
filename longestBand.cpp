#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int longestBand(vector<int>& arr) {
  int n = arr.size();
  unordered_set<int> s; 
  int largestBand = 1;

  for (int i: arr) {
    s.insert(i);
  }

  for (int i: arr) {
    int parent = i - 1;
    // if i - 1 does not exist
    // this is start of chain
    if (s.find(parent) == s.end()) {
      int next = i + 1, count = 1;

      while (s.find(next) != s.end()) {
        next++;
        count++;
      }

      largestBand = max(largestBand, count);
    }
  }

  return largestBand;
}

int main() {
  vector<int> arr {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};

  auto result = longestBand(arr);

  cout << result << endl;

  return 0;
}