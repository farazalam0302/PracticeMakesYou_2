
int main(){
//m x n
int m ; int n ;

int* a = (int *) malloc( sizeof (int) * (m*n) );/// 
int ** b  = (int **) malloc (sizeof(int*) * m);
for (int i = 0 ; i < m ; i++)
{
	int *tmp = (int*) malloc(sizeof(int)*n);
	for (int j = 0 ; j < n ; j++)
	{
		tmp[j] = j;
	}		
	b[i]=tmp;// -> *(b+i)
	i[b]  // -> *(i+b)
}
int* c

return 0;
}

struct DLLNode{
	int data;
	DLLNode*  next;
	DLLNode*  prev;
}

