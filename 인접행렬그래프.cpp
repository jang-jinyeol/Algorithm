#include <iostream>
#include <vector>
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
struct graph{ //구조체 정의

	vector<vector<int>>data;
	vector<int>row;

	graph(int n) {
		data.reserve(n);//2차원 동적할당을 위해 n크기 만큼 예약
		vector<int>row(n);
		fill(row.begin(), row.end(), -1); //row vector를 -1로 초기화

		for (int i = 0; i < 6; i++) {
			data.push_back(row); //data vector를 2차원 배열처럼 사용 전부 -1로 초기화
		}
	}
		void addEdge(const city c1, const city c2, int dis) {
			
			cout << "에지 추가: " << c1 << "-" << c2 << "=" << dis << endl;

			auto n1 = static_cast<int>(c1); //static_cast를 이용하여 int로 형변환
			auto n2 = static_cast<int>(c2); //enum class에 정의된 숫자로 변환된다.
			data[n1][n2] = dis;
			data[n2][n1] = dis; //가중치 업데이트
		}

		void removeEdge(const city c1, const city c2) {
			

			cout << "에지 삭제" << c1 << "-" << c2 << endl;

			auto n1 = static_cast<int>(c1);
			auto n2 = static_cast<int>(c2); 
			data[n1][n2] = -1;
			data[n2][n1] = -1; //삭제시 -1로 업데이트
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