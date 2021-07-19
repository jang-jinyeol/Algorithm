#include <iostream>
#include <queue>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

//중앙값 구하기 알고리즘은 새로 들어오는 데이터가 기존 중앙값보다 작으면 최대힙, 크면 최소힙에 넣는다고 생각하면 이해하기 쉽다.

priority_queue<int>maxHeap;//default는 가장 큰 수가 top
priority_queue<int, vector<int>, greater<int>>minHeap; //greater는 가장 작은 수가 top


class Queue {

public:

	void insert(int n){
		if (maxHeap.size() == 0) { // 초기값을 maxheap에 할당

			maxHeap.push(n);
			return;
			
		}

		else if (maxHeap.size() > minHeap.size()) { //maxheap이 더 큰 경우
			if (n <= get()) {						//평균값과 비교하여 평균값보다 작으면
				maxHeap.push(n); //먼저 maxheap에 push해준다.
				minHeap.push(maxHeap.top()); //그다음 maxheap에 top부분을 minheap에 push해준다.
				maxHeap.pop();				//maxpheap top에 있는 수를 pop 한다.
				//최대힙이 더 많았다가 동등해졌다가 다시 최소힙이 많아지는걸 반복하는 알고리즘이다.
			}
			else {
				minHeap.push(n);

			}
		}

		else { //minheap이 더 큰 경우
			if (n <= get())
				maxHeap.push(n);
			else
				minHeap.push(n);
		}
	}

	double get() {

		if (maxHeap.size() == minHeap.size()) //최대힙과 최소힙이 같으면(짝수) 각각의 top부분을 더하여 나눠준다.
			return (maxHeap.top() + minHeap.top()) / 2;
		else if (maxHeap.size() > minHeap.size()) //최대힙이 더 크면 최대힙 top부분이 중앙값이다.
			return maxHeap.top();
		else //최소힙이 더 크면 최소힙 top부분이 중앙값이다.
			return minHeap.top();
	}
};

int main() {
	int n;
	Queue q;
	
	
	
	

		while (true) { //-1 입력 전까지 무한루프를 돌도록 구현 하였다.
			cout << "값을 입력하세요(종료를 원하면 -1입력): ";

			if (scanf("%d", &n) == 0) { //문자를 입력한경우 rewind 함수를 호출하여 표준입력버퍼를 초기화 한다.
				cout << "정수를 입력하세요." << endl;
				rewind(stdin);
			}
			else if (n== -1) { //-1 입력시 break
				cout << "프로그램을 종료합니다."<<endl;
				break;
			}
			else {
				q.insert(n); //insert함수 호출
				cout << n << "을 추가하셨습니다. 중앙값은 : " << q.get() << " 입니다." << endl;
			}
	

			
		}
	

}
