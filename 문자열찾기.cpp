#include <stdlib.h>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)



int main(void) {

	std::string word = "sweet new, sweet new";
	std::string str;

	std::cout << "found word: ";
	std::cin >> str;

	int pos = 0;
	int i = 0;

	//find() 함수는 특정 값을 찾지 못하면 string::npos를 반환한다.
	//찾을경우 해당문자열이 위치한 주솟값을 반환
	while (word.find(str, pos) != std::string::npos) {
		std::cout << "Found! " << ++i << '\n';
		pos += word.find(str, pos) + str.length();	// 찾은 후에 다음 탐색 시작 위치를 구하기 위해 찾은 '문자(열)의 위치 + 문자(열) 길이'를 구한다.
		cout << pos << '\n';
	}

	return 0;
}
