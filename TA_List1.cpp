#include<iostream>
#include<list>
using namespace std;


int main() {

	double myDoubles[] = { 12.15, 2.72, 73.0, 12.77, 3.14,
12.77, 73.35, 72.25, 15.3, 72.25 };
	//일반 배열을 list로
	list<double>myList(myDoubles, myDoubles + 10);
	list<double>::iterator it;

	cout << ">> nodes of myList: ";

	for (it = myList.begin(); it != myList.end(); ++it)
		cout << *it << " ";
	cout << '\n';

	cout << "<< myList.push_front(1.4);" << '\n';
	
	myList.push_front(1.4);
	
	cout << "<< myList.push_back(1.4);" << '\n';
	
	myList.push_back(1.4);
	
	cout << ">> nodes of myList: ";
	
	for (it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << '\n';

	cout << "<< myList.sort();" << endl;
	
	myList.sort(); //default 오름차순

	for (it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}

	cout << '\n';
	//중복원소 제거
	myList.unique();

	cout << ">> nodes of myList: ";
	for (it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}

