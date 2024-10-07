def fibonacci (n):
    if (n < 0) :
        print ("incorrect input")
        exit(-1)
    elif (n == 0):
        # print(str(0)+", ")
        return 0
    elif n==1 or n==2 :
        # print(str(1)+", ")
        return 1
    else:
        a=fibonacci(n-1) + fibonacci(n-2)
        print(str(a)+", ")
        return a;


def fibonacci_loop(n):
    a=0
    b=1;
    nxt_num=b;
    count =1;
    print(a,end = " ");
    print(b,end = " ");

    while (count <= n) :
        print(nxt_num,end = " ");
        count+=1
        a,b = b,nxt_num;
        nxt_num=a+b;





## DRIVER PROGRAM
n = int(input("Enter a number? "))

print(fibonacci_loop(n))