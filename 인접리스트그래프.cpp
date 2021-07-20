#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


enum class city : int { //enum클래스를 이용하여 도시 이름을 저장한다.

	MOSCOW,
	LONDON,
	SEOUL,
	SEATTLE,
	DUBAI,
	SYDNEY
};

ostream& operator<<(ostream& os, const city c) { //city enum에 대해 연산자를 정의

	switch (c)
	{
	case city::LONDON:
		os << "런던";
		return os;
	case city::MOSCOW:
		os << "모스크바";
		return os;
	case city::SEOUL:
		os << "서울";
		return os;
	case city::SEATTLE:
		os << "시애틀";
		return os;
	case city::DUBAI:
		os << "두바이";
		return os;
	case city::SYDNEY:
		os << "시드니";
		return os;
	default:
		return os;

	}
}
struct graph { //구조체 정의

	vector<vector<pair<int, int>>>data;


	graph(int n) {//2차원 벡터를 사용하지만 행렬그래프와 다르게 모든 행은 비어 있는 형태로 초기화

		data = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());

	}
	void addEdge(const city c1, const city c2, int dis) {

		cout << "에지 추가: " << c1 << "-" << c2 << "=" << dis << endl;

		auto n1 = static_cast<int>(c1); //static_cast를 이용하여 int로 형변환
		auto n2 = static_cast<int>(c2); //enum class에 정의된 숫자로 변환된다.
		data[n1].push_back({ n2,dis });
		data[n2].push_back({ n1,dis }); //가중치와 연결된 곳을 업데이트
	}

	void removeEdge(const city c1, const city c2) {


		cout << "에지 삭제: " << c1 << "-" << c2 << endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair) { //remove_if로 n1행의 모든열을 람다식으로 탐색해서 [n2]을 찾으면 제거

			return pair.first == n2;
		});
		remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair) {//remove_if로 n2행의 모든열을 람다식으로 탐색해서 [n1]을 찾으면 제거

			return pair.first == n1;
		});
	}
};
int main() {
	
	
	
	graph g(6);
	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);

	g.addEdge(city::SEATTLE, city::LONDON, 8000);
	g.removeEdge(city::SEATTLE, city::LONDON);

	
}

