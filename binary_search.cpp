#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;


bool linear_search(int n, vector<int>& vec) {

	for (auto i : vec) {

		if (i == n)

			return true;
	}

	return false;
}

bool binary_search(int n, vector<int>& vec) {

	auto S = vec.begin();
	auto L = vec.end();

	while (true) { //인덱스 위치에 조심해야한다
		auto dis = distance(S, L);//시작 끝의 거리 즉 모든 원소의 개수
		auto mid_index = floor(dis / 2); //floor를 이용하여 반내림
		auto mid_element = *(S + mid_index); //mid_index가 double형인데 S를 더하여 묵시적 형변환이 일어나는 것 같다.

		if (mid_element == n)
			return true;//값을 찾면 true를 리턴
		else if (mid_element > n)
			advance(L, -mid_index); //advance를 인덱스를 가운데로 위치시킨다.
		if (mid_element < n)
			advance(S, mid_index);

		if (dis == 1) //거리가 1이면 더이상 찾을것이 없으므로 false 리턴
			return false;
	}
}

void run_small_search_test()
{
	auto N = 2;
	std::vector<int> S{ 1, 3, 2, 4, 5, 7, 9, 8, 6 };

	std::sort(S.begin(), S.end()); //정렬

	if (linear_search(N, S))
		std::cout << "선형 검색으로 원소를 찾았습니다!" << std::endl;
	else
		std::cout << "선형 검색으로 원소를 찾지 못했습니다." << std::endl;

	if (binary_search(N, S))
		std::cout << "이진 검색으로 원소를 찾았습니다!" << std::endl;
	else
		std::cout << "이진 검색으로 원소를 찾지 못했습니다." << std::endl;
}
//아래 함수는 복붙
void run_large_search_test(int size, int N)
{
	std::vector<int> S;
	std::random_device rd;
	std::mt19937 rand(rd());

	// [1, size] 범위에서 정수 난수 발생
	std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, size);

	// S에 난수 추가
	for (auto i = 0; i < size; i++)
		S.push_back(uniform_dist(rand));

	std::sort(S.begin(), S.end());

	// 검색 시간 측정 시작
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	bool search_result = binary_search(N, S);

	// 검색 시간 측정 종료
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "이진 검색 수행 시간: " << diff.count() << std::endl;

	if (search_result)
		std::cout << "원소를 찾았습니다." << std::endl;
	else
		std::cout << "원소를 찾지 못했습니다." << std::endl;
}




int main() {
	run_small_search_test();
	run_large_search_test(100000, 36543);
	run_large_search_test(1000000, 36543);
	run_large_search_test(10000000, 36543);
	//디버거 모드를 끄고 Release x64 모드로 빌드하여 실행하면 속도가 확연히 차이가 난다
	//입력 벡터 크기가 크게 증가했음에도 수행 시간이 거의 바뀌지 않았다.


}