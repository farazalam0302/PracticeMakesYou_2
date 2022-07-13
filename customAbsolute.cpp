#include <bits/stdc++.h>
using namespace std;

int customAbsolute(int a)
{
//	if (a == 0 ) return 0;
	int signBit = (a >> 31 ) & 1 ;
//	cout << "signBit =" << signBit << endl;
	int result  = a ^ ((-1) * signBit);
	result = result +1*signBit ;
	return result;

}


int main(int argc, char **argv) {

	int a = -2000;
//	unsigned long int ap = (unsigned long int)( (*(&a))^ (int)(-1) );
//     ap = ap+1;
//	cout  <<  "a = " << a << endl;
//	cout  << "ap = " << ap << endl;

	for (int i = -4; i <=4; ++i) {
		cout << customAbsolute(i) << "\n";

	}

	return 0;
}
