#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> pairSum(vector<int> arr, int sum) {
	unordered_set<int> s;
	vector<int> result;

	for(int i = 0; i < arr.size(); i++){
		int x = sum - arr[i];

		if(s.find(x) != s.end()){
			result.push_back(x);
			result.push_back(arr[i]);
			return result;
		}
    
		s.insert(arr[i]);
	}

	return {};
}

int main(){

	vector<int> arr { 10, 5, 2 , 3, -6, 9 , 11 };
	int S = 4;

	auto result = pairSum(arr,S);

	if(result.empty()){
		cout << "No such pair" << endl;
	} else{
		cout << result[0] << "," << result[1] << endl;
	}

	return 0;
}