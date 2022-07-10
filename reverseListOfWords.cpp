#include <bits/stdc++.h>
using namespace std;
void reverseWordlistinString(string  input)

{
	char* s = &input[0];
	stack<char*> stk;
	char * token  = strtok(s," ");
	while (token != NULL)
	{
		stk.push(token);
		token = strtok(NULL," ");
	}

	while (! stk.empty()){
		cout << stk.top() << " ";
		stk.pop();
	}

	cout<<"\n\n\n"  << endl;
}

int main(int argc, char **argv) {
	string inp = "I am back Hurray!!";
    reverseWordlistinString(inp);
	return 0;
}
