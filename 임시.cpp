#include <iostream>
#include <vector>
using namespace std;



class hash_map {

	size_t n;
	vector<int>data1;//���� �������� ������ ���� �߻�
	vector<int>data2;

	auto hash_fnc(size_t key) {

		return key%n;
	}
	auto hash_fnc2(size_t key) {

		return (key/n)%n;
	}

	void Insert2(size_t key, int cnt, int table) {

		if (cnt >= n) { //cnt ���� �ؽø� ũ�⸸ŭ �ݺ��Ǿ��ٸ� ����

			cout << "���ؽ��� �ʿ��մϴ�." << endl;
			return;
		}
		if (table == 1) { //���̺��� 1�϶� data1�� ����
			auto tmp1=hash_fnc(key);
			if (data1[tmp1] == -1) {
				data1[tmp1] = key;
			}
			else {
				auto old = data1[tmp1];
				data1[tmp1] = key;
				return Insert2(key, cnt + 1, 2);
			}
		}
		else { //���̺��� 2�϶� data2�� ����
			auto tmp2 = hash_fnc2(key);
			if (data2[tmp2] == -1) {
				data2[tmp2] = key;
			}
			else {
				auto old = data2[tmp2];
				data1[tmp2] = key;
				Insert2(key, cnt + 1, 1);
			}
		}
	}
public:



	hash_map(int n) :n(n){

		vector<int>data1(n,-1);
		vector<int>data2(n,-1);
	}
	void Insert(size_t key) {

		Insert2(key,0,1);
	}
};

int main() {

	hash_map map(7);
	map.Insert(10);
	map.Insert(20);
	map.Insert(30);
	
}