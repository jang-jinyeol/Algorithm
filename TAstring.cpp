#include <iostream>
using namespace std;


int main(){
    string str1 = "Hello World!";
    cout << "str1: " << str1 << '\n';

    string::reverse_iterator rit;
    cout << "str1 (reverse): ";
    for (rit = str1.rbegin(); rit != str1.rend(); rit++)
        cout << *rit;
        cout << '\n' << '\n';
        string str2 = "Bonjour!";
        cout << "str2: " << str2 << '\n' << '\n';
        str1.swap(str2);
        cout << "--- After swap ---" << '\n';
        cout << "str1: "<< str1 << '\n';
        cout << "str2: "<< str2 << '\n';
    return 0;

}
