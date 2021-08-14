#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector<int> v(3);
    vector<int>::iterator it;

    cout << "size of v: " << v.size() << '\n';
    cout << "capacity of v: " << v.capacity() << '\n';
    cout << "elements of v: ";
    for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
    cout << '\n'<< '\n';

    for (int i = 0; i < v.size(); ++i) v[i] = i + 1;
    for (int i = 10; i < 15; ++i) v.push_back(i);

    cout << "--- After push_back ---" << '\n';
    cout << "size of v: " << v.size() <<'\n';
    cout << "capacity of v: " << v.capacity() <<'\n';
    cout << "elements of v: ";
    for (it = v.begin(); it != v.end(); ++it) cout << *it <<" ";
    cout << '\n' << '\n';

    v.pop_back();
    v.pop_back();

    cout << "--- After pop_back ---" << '\n';
    cout << "size of v: " << v.size() << '\n';
    cout << "capacity of v: " << v.capacity() << '\n';
    cout << "elements of v: ";
    for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
    cout << '\n';


    return 0;

}
