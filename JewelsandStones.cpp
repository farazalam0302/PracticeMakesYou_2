#include <bits/stdc++.h>
using namespace std ;


// Jewels and Stones
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int Cmap [53] = {0};
        for (auto i:Cmap)
        {
            i=0;
        }
        for (auto ch : J)
        {
            if (ch >= 'A' && ch <= 'Z')
                Cmap [ch - 'A'] = 1;
            else if (ch >= 'a' && ch <= 'z')
                Cmap [ch - 'a' + 26 ] = 1;
            else
                ;
        }
        int count =0;
        for (auto Sch : S)
        {
            if (Sch >= 'A' && Sch <= 'Z' && Cmap [Sch - 'A'] == 1)
                count++;
            else if (Sch >= 'a' && Sch <= 'z' && Cmap [Sch - 'a' + 26] == 1)
                count++;
            else
                ;
        }
        return count ;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
     // while (getline(cin, line)) {
        string J = "z";  //stringToString(line);
        // getline(cin, line);
        string S = "ZZ" ; //stringToString(line);

        int ret = Solution().numJewelsInStones(J, S);

        string out = to_string(ret);
        cout << out << endl;
    // }
    return 0;
}