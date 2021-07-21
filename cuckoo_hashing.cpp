#include <iostream>
#include <vector>
using namespace std;



class hash_map {

	size_t n;
	vector<int>data1;//먼저 선언하지 않으면 오류 발생
	vector<int>data2;

	auto hash_fnc(size_t key) {

		return key % n;  //첫번째 함수 모듈러 연산
	}
	auto hash_fnc2(size_t key) {

		return (key / n) % n; //두번째 함수 모듈러 연산
	}

	void Insert2(size_t key, int cnt, int table) {

		if (cnt >= n) { //cnt 수가 해시맵 크기만큼 반복되었다면 종료
		
			cout <<key<< " 삽입 시 사이클 발생! 재해싱이 필요합니다." << endl; //순환 발생
			return;
		}
		if (table == 1) { //테이블이 1일때 data1에 삽입
			int tmp1 = hash_fnc(key);
			if (data1[tmp1] == -1) {
				data1[tmp1] = key;
				cout << table << "번 테이블에 " << key << "삽입"<<endl<<endl;
			}
			else {
				auto old = data1[tmp1];
				data1[tmp1] = key;
				cout << table << "번 테이블에 " << key << " 삽입: 기존의 " << old << " 이동 ->";// <<table+1<<"번 테이블에 " <<old <<"삽입" << endl;
				return Insert2(old, cnt + 1, 2);
			}
		}
		else { //테이블이 2일때 data2에 삽입
			auto tmp2 = hash_fnc2(key);
			if (data2[tmp2] == -1) {
				data2[tmp2] = key;
				cout << table << "번 테이블에 " << key << "삽입" << endl<<endl;
			}
			else {
				auto old = data2[tmp2];
				data2[tmp2] = key;
				cout << table << "번 테이블에 " << key << "삽입: 기존의 " << old << " 이동 ->";// << table - 1 << "번 테이블에 " << old << "삽입" << endl;
				Insert2(old, cnt + 1, 1);
			}
		}
	}


	
public:
		//반환 값은 벡터 iterator(반복자)
	vector<int>::iterator lookup(size_t key) { //가장 중요한 부분
								//룩업 함수는 양쪽 해시 테이블에서 키를 검색하고, 해당 위치를 나타내는 반복자를 반환한다.(삭제 함수에서 쓰임)
								//원소를 찾지 못하였을 경우 자미막을 가리키는 반복자가 반환 됨. 룩업 함수는 O(1)의 시간복잡도를 가짐.
		auto v1 = hash_fnc(key);
		
		if(data1[v1]==key){
			cout << "1번 테이블에서" << key << "을(를) 찾았습니다." << endl;
			return data1.begin()+v1;
		}
		auto v2 = hash_fnc2(key);

		if (data2[v2] == key) {
			cout << "2번 테이블에서" << key << "을(를) 찾았습니다." << endl;
			return data2.begin() + v2;

		}

		return data2.end();

	}

	void erase(size_t key) {

		auto position = lookup(key);
	
		if (position != data2.end()) { //찾는 값이 없을경우 data2.end()를 반환 했으므로 position != data2.end()는 값을 찾았다는 뜻.

			*position = -1; //-1값을 넣어서 값을 지움
			cout << key << "에 해당하는 원소를 삭제했습니다." << endl;
		}
		else {
			cout << key << "키를 찾지 못했습니다." << endl;
		}
	}


	hash_map(int n) :n(n) {

		//vector<int>data1(n, -1); 처음에 이렇게 초기화 해서 계속 오류가 났다. 지역변수로 인식하는 것 같다
		data1 = vector<int>(n, -1);
		data2 = vector<int>(n, -1);
		//vector<int>data2(n, -1);
	}
	void Insert(size_t key) {

		Insert2(key, 0, 1); //먼저 1번테이블 부터 검사한다.
	}
	
	void Print() { 
		cout << endl;
		cout << "Index : ";
		for (int i = 0; i < n;i++) {
			cout << i << "\t";
		}
		cout << endl << "data1 : ";
		for (auto i : data1) {
			cout << i << "\t";
		}
		cout << endl << "data2 : ";
		for (auto i : data2) {
			cout << i << "\t";
		}
		cout << endl;
	}
};

int main() {

	hash_map map(7);
	map.Print(); //처음 테이블 화면
	map.Insert(10);
	map.Insert(20);
	map.Insert(30);
	map.Insert(104);
	map.Insert(2);
	map.Insert(70);
	map.Insert(9);
	map.Insert(90);
	map.Insert(2);
	map.Insert(7);
	map.Insert(14);
	map.Print();
	map.lookup(30);
	map.erase(99);
	map.erase(30);

}
