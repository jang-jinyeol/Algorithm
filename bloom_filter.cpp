#include <iostream>
#include <vector>
using namespace std;
//블룸필터 만들기
class bloom_filter
{
	vector<bool>data;
	int size;

public:

	bloom_filter(int n) : size(n) {//생성자 vector의 자료형은 bool

		data = vector<bool>(size, false);
	}

	void insert(int n) {  //3개의 hash 함수를 이용여 true 값을 저장한다.

		data[n % size] = true;
		data[(n / size) % 7] = true;
		data[(n % size) % 11] = true;
		cout << n << "을(를) 삽입: ";

		for (auto k : data)
			cout << k << " ";
		cout << endl;
	}

	void lookup(int n) { //and 연산을 이용하여 lookup을 진행한다.

		bool result = data[n % size] & data[(n / size) % 7] & data[(n % size) % 11];
		if (result)
			cout << n << ": 있을 수 있음" << endl;
		else
			cout << n << ": 절대 없음" << endl;

	}
};

int main() {

	bloom_filter bf(7);

	bf.insert(100);
	bf.insert(54);
	bf.insert(82);

	bf.lookup(5);
	bf.lookup(50);
	bf.lookup(20);
	bf.lookup(54);
}