// 2d arrays
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv) {

    int m ;
    int n ;

    int **a = (int**) malloc(m*sizeof(int*));
    for (int i = 0; i < m; ++i) {
	a[i] =  (int*) malloc(n*sizeof(int));
    }
    /////////
    /*
     *
     * a
     * [.]->[ - - - n ]
     * [.]->[ - - - n ]
     * [.]->[ - - - n ]
     * m [.]->[ - - - n ]
     */

    // free

    for (int i = 0; i < m; ++i) {
    	free (a[i]);
        }

    free (a);




    return 0;
}
