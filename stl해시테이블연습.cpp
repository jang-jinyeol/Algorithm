#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print(unordered_set<int>& container) {//참조에 의한 매개변수를 출력한다.

	///unordered_set<int>::iterator iter;
	
	for (auto& tmp : container) {

		cout << tmp << " ";
	}
	cout << endl;
	
}

void print(unordered_map<int,int>& container) {

	
	for (auto& tmp : container) {

		cout << tmp.first << " -> " << tmp.second << ", ";
	}
	cout << endl;
}

void find(unordered_set<int>& container,int element) {


	if (container.find(element) == container.end()) //찾는 값이 없는 경우 자주 쓰는표현이니 암기
		cout << element << " 검색: 실패" << endl;
	else
		cout << element << " 검색: 성공" << endl;

}

void find(unordered_map<int, int>& container, int element) {

	auto it = container.find(element);
	
	
	if (it == container.end())
		cout << element << " 검색: 실패" << endl;
	else
		cout << element << " 검색: 성공, 값 = "<< it->second << endl;

}

int main() {
	cout << "***std::unordered_set 예제***" << endl;

	unordered_set<int>set1 = { 1,2,3,4,5 };

	cout << "set1 초깃값: ";
	print(set1);
	set1.insert(2);
	cout << "2 삽입: ";print(set1);
	set1.insert(10);
	set1.insert(300);
	cout << "10, 300 삽입: ";print(set1);

	find(set1, 4);
	find(set1, 100);
	set1.erase(2);
	cout << "2 삭제: "; print(set1);
	find(set1, 2);
	cout << "***std::unordered_map 예제***" << endl;
	unordered_map<int, int> squareMap;

	squareMap.insert({ 2,4 });

	squareMap[3]=9;
	cout << "2, 3의 제곱 삽입: "; print(squareMap);
	squareMap[20] = 400;
	squareMap[30] = 900;
	cout << "20, 30의 제곱 삽입: "; print(squareMap);
	find(squareMap, 10);
	find(squareMap, 20);
	cout << "squareMap[3] = " << squareMap[3] << endl; //들어있는 값 출력
	cout << "squareMap[100] = " << squareMap[100] << endl;//100번째에는 값이 없다.
	print(squareMap);//미리 만든 함수로 값 전부 출력	
}