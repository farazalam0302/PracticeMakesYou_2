//#include <stdio.h>
//
//struct GreetApi{
//	int (*say_hello)(char* name);
//	int (*say_good_bye) (void);
//};
//
//int sayHelloFunction(char * name){
//
//	printf("Hello %s\n", name);
//
//	return 0;
//}
//
//
//int sayGoodByeFunction( void){
//
//	printf("GoodBye \n");
//
//	return 0;
//}
//
//struct GreetApi GreetAPI= {
//		.say_hello = sayHelloFunction,
//		.say_good_bye = sayGoodByeFunction
//};
//
//
//int main(int argc, char **argv) {
//	GreetAPI.say_hello(argv[1]);
//	GreetAPI.say_good_bye();
//	printf("%p, %p, %p\n", GreetAPI.say_hello, sayHelloFunction, &sayHelloFunction);
//
//	return 0;
//}
/*
 *  result = findMissingPositiveNumber(A+shift,N-shift);
 */
#include <stdio.h>



int main(int argc, char **argv) {
//	char* s = "Hello, World\n";
//	s[5] = '.';
//	printf("%s\n",s);

	unsigned int x =0;
	if((x++) || (x+=3))
	{
		x=4;
	}
	else{
		x++;
	}

	printf("x=%d\n" , x);
	return 0;
}
