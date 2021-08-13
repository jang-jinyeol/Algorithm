#include <vector>
#include <iostream>

#pragma warning(disable:4996);

using namespace std;

int main(){

	vector<vector<int>> arr(6, vector<int>(5, 0)); //초기화
	int serial = 0;
	for (int i = 0; i < 6; i++)

		for (int j = 0; j < 5; j++)

			arr[i][j] = serial++;
	//출력부분
	for (vector<int>vec : arr) { //6개의 행
		for (int n : vec) //열
			cout << n << " ";
		cout << "\n";
	}

	vector<vector<int>>::iterator row;
	vector<int>::iterator col;

	for (row = arr.begin(); row != arr.end(); row++) {
		for (col = row->begin(); col != row->end(); col++) {
			cout << *col << " ";
		}
		cout << '\n';
	}

	return 0;
}


