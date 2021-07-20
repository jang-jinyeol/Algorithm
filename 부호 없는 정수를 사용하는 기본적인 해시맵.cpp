#include <iostream>
#include <vector>
using namespace std;
//부호 없는 정수를 사용하는 기본적인 해시맵 구현
using uint = unsigned int; //unit으로 줄임

class hash_map {
	
	vector<int>data;

public:
	hash_map(int n) { //해시맵 생성자, 데이터 크기를 인자로 받는다

		data = vector<int>(n, -1); //n개 원소를 -1로 초기화
	}
	void Insert(uint value) { //매개변수를 벡터크기로 나눈 나머지값 인덱스에 저장
							//단순히 덮어쓰는 것이기 때문에 중복이 발생하면 collision 발생
		int n = data.size();
		data[value % n] = value;
		cout << value << "을(를) 삽입했습니다." << endl;
	}

	bool find(uint value) { //해당 값 위치에 저장된 값이 value와 같으면 true return

		int n;
		n = data.size();
		return data[value % n] == value;
	}
	void erase(uint value) {

		int n = data.size();

		if (data[value % n] == value) { //저장되어 있는 값과 일치하는지 확인
			data[value % n] = -1; //지우려는 위치에 -1 삽입
			cout << value << "을(를) 삭제했습니다." << endl;
		}
	}

};

int main() {

	hash_map map(7); //크기를 7로 초기화 한다.
	map.Insert(2);//삽입
	map.Insert(10);
	map.Insert(25);
	
	auto Print = [&](uint value) { //내부 룩업 결과를 출력하는 람다함수

		if (map.find(value)) {
			cout << "해시 맵에서" << value << "을(를) 찾았습니다."<<endl;
		}
		else {
			cout << "해시 맵에서" << value << "을(를) 찾지 못했습니다." << endl;
		}
	};
	Print(25);
	map.Insert(100);
	Print(100);
	Print(2);
	map.erase(25);

}