// /home/falam/Dropbox/Placement_prep/leetcode/JewelsandStones.cpp

#include <bits/stdc++.h>
using namespace std ;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map <int,int> fmap ;
        for (auto i : nums1)
        {
            if (fmap.find(i)==fmap.end())
            {
                fmap[i]=1;
            }
            else
            	(fmap[i])++;


        }

        vector <int> retVec;
        for (auto i : nums2)
        {
            if (fmap.find(i)!=fmap.end())
            {
                if (fmap[i])
                {
                    retVec.push_back(i);
                    fmap[i]--;
                }
            }
            else ;

        }

        return retVec ;

    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    // while (getline(cin, line)) {
        int a[4]  = {1,2,2,1};
        int b[2] = {2,2};
        vector<int> nums1 (a,a+4);//stringToIntegerVector(line);
        // getline(cin, line);
        vector<int> nums2 (b,b+2); //stringToIntegerVector(line);

        vector<int> ret = Solution().intersect(nums1, nums2);

        string out = integerVectorToString(ret);
        cout << out << endl;
    // }
    return 0;
}

/*

int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

*/