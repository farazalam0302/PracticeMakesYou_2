/*
 * Print all possible strings of length k that can be formed from a set of n characters

 Difficulty Level : Medium
 Last Updated : 28 May, 2022
 Given a set of characters and a positive integer k, print all possible strings of length k that can be formed from the given set.

 Examples:

 Input:
 set[] = {'a', 'b'}, k = 3

 Output:
 aaa
 aab
 aba
 abb
 baa
 bab
 bba
 bbb


 Input:
 set[] = {'a', 'b', 'c', 'd'}, k = 1
 Output:
 a
 b
 c
 d
 */

#include <bits/stdc++.h>
using namespace std;
void recPrintPermutations(string &a, string prefix, int k) {
	if (k == 0) {
		cout << prefix << endl;
		return;

	}

	for (unsigned int i = 0; i < (unsigned int) a.size(); ++i) {
		string newPrefix;
		newPrefix = prefix + a[i];
		recPrintPermutations(a, newPrefix, k - 1);
	}

}

void printKlengthPermutation(string &a, int k) {
	recPrintPermutations(a, "", k);
}

int main(int argc, char **argv) {
	string a = "abcd";
	int k = 4;

	printKlengthPermutation(a, k);

	return 0;
}

