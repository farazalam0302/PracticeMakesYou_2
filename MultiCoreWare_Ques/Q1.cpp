/*
 * I AM ON THE THE TOP OF THE WORLD
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

void caseFoldingtoUpper(string &a)
{
	cout << "No Case Folded a = "<<a<< endl;

	for (int c= 0; c < (int)a.size(); ++c) {


		if (a[c]>='a' &&a[c]<='z')
		{
			a[c]=a[c]-'a'+'A'; // to lowerCase
		}

	}
	cout << "Upper Case Folded a = "<<a<< endl;
	return;

}

void removeRedundantWords(string &a) {
	caseFoldingtoUpper(a);

	char *Ach = &a[0];
	vector<char*> buff;

	char *token = strtok(Ach, " ");
	while (token) {
		buff.push_back(token);
		token = strtok(NULL, " ");
	}


	string result = "";
	result = result + buff[0];
	int i;
	for (i = 1; i < (int)buff.size(); ++i) {
		if (strcmp(buff[i - 1], buff[i]) == 0)
			continue;
		result = result + " " + (buff[i]);
	}
	cout << endl;
	cout << result << endl;

}

int main(int argc, char **argv) {
	string a = "i am on the the the top of the the the world";
	removeRedundantWords(a);
	return 0;
}
