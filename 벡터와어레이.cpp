#include <vector>
#include <array>
#include <iostream>


using namespace std;

int main() {
	//1차원 벡터 fill함수로 초기화
	vector<int>arr3 = {1, 2, 3, 4, 5};
	fill(arr3.begin(), arr3.end(), 4);
	for (int n : arr3)
		cout << n<<" ";

	cout << "\n" << "\n";

	//vector 초기화
	vector<vector<int>> arr(6, vector<int>(5, 0));
	int serial = 0;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 5; j++)
			arr[i][j] = serial++;
	//범위기반 for문 vector 출력부분
	for (vector<int>vec : arr) { 
		for (int n : vec) 
			cout << n << " ";
		cout << "\n";
	}
	cout << "\n";

	//iterator
	vector<vector<int>>::iterator row;
	vector<int>::iterator col;

	//iterator로 vector 출력부분
	
	for (row = arr.begin(); row != arr.end(); row++) {
		for (col = row->begin(); col != row->end(); col++) {
			cout << *col << " ";
		}
		cout << '\n';
	}
	cout << '\n';

	int q = 0;
	
	//array 초기화
	array<array<int, 5>, 6>arr2 = { 0 };
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 5; j++)
			arr2[i][j] = q++;
	
	//array 선언
	array<array<int, 5>, 6>::iterator row2;
	array<int, 5>::iterator col2;

	//iterator로 array 출력부분
	
	for (row2 = arr2.begin(); row2 != arr2.end(); row2++) {
		for (col2 = (*row2).begin(); col2 != (*row2).end(); col2++) {
			cout << *col2 << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	int w = 0;

	for (array<int, 5> k : arr2) {
		for (int i : k)
			cout << i << " ";
		cout << '\n';
	}
	for (row2 = arr2.begin(); row2 != arr2.end(); row2++) {
		(*row2).fill(w++);
	}

	cout << '\n' << "after fill" << '\n' << '\n';

	for (array<int, 5> k : arr2) {
		for (int i : k)
			cout << i << " ";
		cout << '\n';
	}

	//fill(arr.begin(), arr.end(), 4); //2차원 vector 불가능
	
	cout << '\n';

	int n = 0;
	for (row2 = arr2.begin(); row2 != arr2.end(); row2++)
		row2->fill(n++);
	//범위기반 for문
	for (array<int, 5> k : arr2) {
		for (int n : k)
			cout << n << " ";
		cout << "\n";
	}
	cout << "\n";

	//2차원 array front로 출력
	cout << "value of arr[0][2]: ";
	cout << (arr2.front())[2] << '\n';
	cout << "\n";
	//2차원 array at으로 출력
	cout << "value of arr[1][3]: ";
	arr2[1][3] = 59;
	cout << (arr2.at(1)).at(3);

	return 0;
}


