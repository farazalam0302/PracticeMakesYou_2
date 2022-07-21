/*
 *
 * int ptr* = &(base+offset*2);
 *
 *
 *
 *

 void foo(int base, int offset)
{
int ptr* = &(base+offset*2);
}


 1. Preprocessing

 2. Lexical & Scanning  -> gettingTokens

 3. Syntax Analysis

 4. Semantic Analysis  // int a = 10/0;

 5. Static optimizations // constant folding  ; -O# 3 / 2 /1 // loop unrolling

 6. Independent IR generation





 last stage :  Assembly - Binary

 */

/*
 * impolement sizeof(int)
 * uint sizeof( int)
 * {
 *     //create of contg buffer of dtype (int) of size 2
 *      int buffer[2] = {0};
 *
 *      return (abs(&buffer[1] - &buffer[0]));
 * }
 *
 *
 *
 * string str = "Hello World";
 *
 *
 * c
 *
 * output : olleH dlroW
 */

//  string reverse(string &s){
//	  char tmp;
//	  int ln = sizeof(s);
//	  int front = 0 ;
//	  int back = ln-1;
//	  while(front < back)
//	  {
//
//	  }
//
//  }
//
//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//	string a = "12345";
//	cout << size(a) <<endl;
//}
//
//
//string str = "Hello World";
//string str("Hello World");
//






