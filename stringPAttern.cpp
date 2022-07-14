/*
 * Given a string and a pattern, find the starting indices of all occurrences of
 * the pattern in the string. For example, given the string "abracadabra" and
 * the pattern "abr", you should return [0, 7].

 *
 */

#include <bits/stdc++.h>
#include <cstring>
using namespace std;
vector<int> substringPositions(char* a, char* p)
{
	int n = strlen(a);
	int pn= strlen(p);
	if (pn>n) exit(-100);

	char* a1=a;
	char* p1 =p ;
	char* cr;
	vector<int> r ;

	while(true){
		cr = strstr(a1,p1);
		a1=cr+pn;
		if (cr == NULL) break;
		r.push_back((cr-a));

	}

	for (auto i : r ) {
		cout << i << ", ";
	}
	cout << endl;
	return r;
}

int main(int argc, char **argv) {
	char * a = "aaabbbaaabbbaaabbabababaabbabbxx";
	char*  pattern = "abb";
//    cout << "a= " << a << endl;
	for (int i = 0; i < strlen(a); ++i) {
		cout << i << " -> " << a[i] << endl;
	}
    cout << "pattern= " << pattern << endl;
	vector<int> r;
	r= substringPositions(a,pattern);

	return 0;
}
