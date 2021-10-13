#include <bits/stdc++.h>
//#include <crtdbg.h>
void* ImOnTheNextLevel(int* ProblemSolving) {
    void* FridayNight=malloc(sizeof(char)**ProblemSolving);
    strcpy((char*)FridayNight, "Hello World!");
    return FridayNight;
}

int main()
{
    int Size = sizeof("Hello World!");
    char* Ilikethis=(*(char*(*)(int&))ImOnTheNextLevel)(Size);
    printf("%s", Ilikethis);
    free(Ilikethis);
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  //_msize() 함수는 포인터 변수가 가리키는 메모리의 크기를 알려주는 함수이다. 하지만 g++에선 작동하지 않는다.
    return 0;
}//
