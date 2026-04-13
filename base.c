#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  for(int i=0;i<array_length;i++){
    mapped_array[i]=f(array[i]);
  }
  return mapped_array;
}
 //should the function that calls map free location? 
 
int main(int argc, char **argv){
  /* TODO: Test your code */
}
