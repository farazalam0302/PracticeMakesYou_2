/*
2 
Given a string , find if it contains duplicate parenthesis or not.
A set of parenthesis are duplicate if the same subexpression is surrounded by multiple parenthesis.

Examples:

Below strings have duplicate parenthesis -

((a+b)+((c+d)))
The subexpression "c+d" is surrounded by two
pairs of brackets.

(((a+(b)))+(c+d))
The subexpression "a+(b)" is surrounded by two
pairs of brackets.

(((a+(b))+c+d))
The whole expression is surrounded by two
pairs of brackets.

((a+(b))+(c+d))
(b) and ((a+(b)) is surrounded by two
pairs of brackets.

Below string don't have any duplicate parenthesis -

((a+b)+(c+d)
No subsexpression is surrounded by duplicate
brackets.




*/

#include <bits/stdc++.h >
using namespace std;
int main()
{
string in = "((a+b)+(c+d)";
 stack<char> brackets;
int sz = in.size();
for (int i = 0 ; i < sz ; i++) 
{
    if (in[i] == '(') 
	{ brackets.push(in[i]) ; }
	else if (in [i] == ')' && brackets.top() == '(' ) 
	{ brackets.pop() ;}
}
if (brackets.empty()) cout << "Yes, expression Is Balanced parantheses\n" << endl;
else   cout << "No, expression Is not Balanced parantheses\n" << endl;


 

return 0;
}

