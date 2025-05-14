#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<long long int> numlist;
string input;

vector<long long int> moveright(vector<long long int> originvec){
	vector<int> result;
	result.push_back(originvec[originvec.size()-1]);
	for (int i = 0; i < originvec.size()-1; i++){
		result.push_back(originvec[i]);
	}
	return result;
}

long long int F(vector<int> argu){
	if (argu.size() == 1){
		return 0;
	}
	long long result = 0;
	for (int i = 0; i < argu.size(); i++){
		result += i * argu[i]; 
	}
	return result;
}

int main(){
	cin >> input;
	for (int j = 0; j < input.size(); j++){
		if (input[j] - '0' >= 0 && input[j] - '0' <= 9){
			numlist.push_back(input[j] - '0');
		}
	}
	
	// Now the numlist should be successfully collected!
	vector<long long int> result_set;
	for (int k = 0; k < numlist.size(); k++){
		vector<long long int> numlist_copy = numlist;
		// then for each permutation of these vectors
		long long int temp_result = 0;
		for (int m = 0; m < numlist.size(); m++){
			temp_result += F(numlist_copy);
			vector<long long int> numlist_copy = moveright(numlist_copy);
		}
		result_set.push_back(temp_result);
	}
	return max_element(result_set.begin(), result_set.end());
}
