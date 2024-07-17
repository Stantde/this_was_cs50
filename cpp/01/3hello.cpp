/*
    g++ -o runProgram hello.cpp
    # creates runProgram
*/

#include <iostream>
//using namespace std;
void test();
int main(void){test();return 0;}
void test(){std::cout << "Hello World!\n"; return;}
