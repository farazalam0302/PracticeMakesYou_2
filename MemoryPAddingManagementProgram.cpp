/*
 * we have two dataItemsTypes Large and Small of size 5 and 3 bytes ;
 * and memory is 4bytes addressable
 * if the stream is [s s s] ->
 */


#include <bits/stdc++.h>



#define LARGE_CHUNK 5
#define SMALL_CHUNK 3
#define BYTE_ADDRESS 4

using namespace std;


unsigned int chunk[2]{
	SMALL_CHUNK ,LARGE_CHUNK
};

int calculateMinimumPaddedMemory(vector<int>& a)
{int n = a.size();
	// segregation
	int tmp;
	int shift = 0 ;
	for (int i = 0; i < n; ++i) {
		if (a[i]==0) {
			swap(a[i],a[shift]);
			shift++;
		}
	}
	int size  = 0;
	for (int i = 0; i < n; ++i) {

	}
}


int main(int argc, char **argv) {
	vector<int> a {0,1,0};

	int r ;
	r= calculateMinimumPaddedMemory(a);

	return 0;
}
