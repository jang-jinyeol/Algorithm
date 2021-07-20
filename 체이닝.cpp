#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
//해시 테이블에서 충돌을 피하기 위한 체이닝 기법
//벡터 안에 리스트
using uint = unsigned int; //unit으로 줄임

class hash_map {

	vector<list<int>>data;

public:
	hash_map(uint n) { //해시맵 생성자, 데이터 크기를 인자로 받는다

	
		data.resize(n); //n개를 기본값 0으로 할당
	}
	void Insert(uint value) { //매개변수를 벡터크기로 나눈 나머지값 인덱스에 저장
							//이전과 다르게 같은 배열이더라도 list로 push_back 할 수 있다.
		int n = data.size();
		data[value % n].push_back(value); 
		cout << value << "을(를) 삽입했습니다." << endl;
	}

	bool find(uint value) { 

		int n;
		n = data.size();

		auto& tmp = data[value % n]; //참조를 이용

		return std::find(tmp.begin(), tmp.end(), value) != tmp.end();//end는 마지막 다음을 가리켜서 find로 실제 값이 있으면 true를 return하는 것 같다.
	}//함수 이름과 같아서 std::를 붙임
	
	void erase(uint value) {

		int n = data.size();

		auto& tmp = data[value % n];

		auto iter = std::find(tmp.begin(), tmp.end(), value);//find함수가 이미 있어서 std붙임

		if (iter != tmp.end()) { //같지 않으면 실제 있는 값 이므로 삭제를 진행
			
			tmp.erase(iter);
			cout << value << "을(를) 삭제 했습니다.";
		}
	}

};

int main() {

	hash_map map(7); //크기를 7로 초기화 한다.

	auto Print = [&](uint value) { //내부 룩업 결과를 출력하는 람다함수

		if (map.find(value)) {
			cout << "해시 맵에서" << value << "을(를) 찾았습니다." << endl;
		}
		else {
			cout << "해시 맵에서" << value << "을(를) 찾지 못했습니다." << endl;
		}
	};
	map.Insert(2);//삽입
	map.Insert(25);
	map.Insert(10);
	map.Insert(100);
	map.Insert(55);
	Print(100);
	Print(2);//100,2 둘다 같은 배열에 있지만 체이닝 기법으로 collision이 발생하지 않음
	map.erase(2);

}