#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//global
int addr5;
int addr6;

//functions
int foo()
{
    return -1;
}
void point_at(void *p);
void foo1();

//global arg
char g = 'g';

//function
void foo2();

//functions
int secondary(int x)
{
    int addr2;
    int addr3;
    char *yos = "ree";
    int *addr4 = (int *)(malloc(50));
	int iarray[3];
    float farray[3];
    double darray[3];
    char carray[3]; 
	int iarray2[] = {1,2,3};
    char carray2[] = {'a','b','c'};
    int* iarray2Ptr;
    char* carray2Ptr; 
    
	printf("- &addr2: %p\n", &addr2);
    printf("- &addr3: %p\n", &addr3);
    printf("- foo: %p\n", &foo);
    printf("- &addr5: %p\n", &addr5);
	printf("Print distances:\n");
    point_at(&addr5);

    printf("Print more addresses:\n");
    printf("- &addr6: %p\n", &addr6);
    printf("- yos: %p\n", yos);
    printf("- gg: %p\n", &g);
    printf("- addr4: %p\n", addr4);
    printf("- &addr4: %p\n", &addr4);

    printf("- &foo1: %p\n", &foo1);
    printf("- &foo1: %p\n", &foo2);
    
    printf("Print another distance:\n");
    printf("- &foo2 - &foo1: %ld\n", (long) (&foo2 - &foo1));

   
    printf("Arrays Mem Layout (T1b):\n");

    /* task 1 b here:*/

    printf("iarray: %p\n",iarray);
    printf("iarrayplus1: %p\n",iarray+1);
    printf("farray: %p\n",farray);
    printf("farrayplus1: %p\n",farray+1);
    printf("darray: %p\n",darray);
    printf("darrayplus1: %p\n",darray+1);
    printf("carray: %p\n",carray);
    printf("carrayplus1: %p\n",carray+1);

    printf("Pointers and arrays (T1d): \n");

    /* task 1 d here */
    iarray2Ptr = iarray2;
    carray2Ptr = carray2;
    printf("iarray: %d,%d,%d\n",*iarray2Ptr,*(iarray2Ptr+1),*(iarray2Ptr+2));
    printf("carray: %c,%c,%c\n",*carray2Ptr,*(carray2Ptr+1),*(carray2Ptr+2));
    int* localPtr;
    printf("uninitialized pointer local variable: %p\n",localPtr);

}

int main(int argc, char **argv)
{ 

    printf("Print function argument addresses:\n");

    printf("- &argc %p\n", &argc);
    printf("- argv %p\n", argv);
    printf("- &argv %p\n", &argv);
	
	secondary(0);
    
    printf("Command line arg addresses (T1e):\n");
    /* task 1 e here: */
    printf("argv: %p\n",argv); //wehre the ptr array of arguments start
    printf("agrv&: %p\n",&argv); //argv location
    printf("argv0: %s\n",argv[0]); 
    printf("agrv0&: %p\n",&argv[0]);
    printf("argv1: %s\n",argv[1]);
    printf("agrv1&: %p\n",&argv[1]);
    printf("argv2: %s\n",argv[2]);
    printf("agrv2&: %p\n",&argv[2]);

    printf("string adresses:\n");
    printf("argv0strAdr: %p\n",argv[0]);
    printf("argv1strAdr: %p\n",argv[1]);
    printf("argv2strAdr: %p\n",argv[2]);
    
    return 0;
}

void point_at(void *p)
{
    int local;
    static int addr0 = 2;
    static int addr1;

    long dist1 = (size_t)&addr6 - (size_t)p; //same section
    long dist2 = (size_t)&local - (size_t)p; //biggest distance since local var is in the stack(highest) and adr5 is global(lowest)
    long dist3 = (size_t)&foo - (size_t)p; //code - data distnce medim distance

    printf("- dist1: (size_t)&addr6 - (size_t)p: %ld\n", dist1);
    printf("- dist2: (size_t)&local - (size_t)p: %ld\n", dist2);
    printf("- dist3: (size_t)&foo - (size_t)p:  %ld\n", dist3);
    
    printf("Check long type mem size (T1a):\n");
    /* part of task 1 a here: */
    printf("size is: %d\n",sizeof(dist1));

    printf("- addr0: %p\n", &addr0);
    printf("- addr1: %p\n", &addr1);
}

void foo1()
{
    printf("foo1\n");
}

void foo2()
{
    printf("foo2\n");
}