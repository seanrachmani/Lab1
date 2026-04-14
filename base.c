#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
//task 2a
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  for(int i=0;i<array_length;i++){
    mapped_array[i]=f(array[i]);
  }
  return mapped_array;
}
 //should the function that calls map free location? 


//task2b:
/* Ignores c, reads and returns a character from stdin using fgetc. */
char my_get(char c){
  return fgetc(stdin);
}


/* If c is a number between 0x20 and 0x7E, cxprt prints the character of ASCII value c, otherwise, the dot ('.') character.
This is followed by a space character, and then the value of c in a hexadecimal. 
Finally, a new line character is printed. After printing, cprt returns the value of c unchanged. */
char cxprt(char c){
  if(c>=0x20 && c<=0x7E){
    printf("%c ",c);
  }
  else{
    printf(". ");
  }
  //the idea for how to print hex is from stackoverflow:
  printf("%02x\n",(unsigned char)c); //02x used to print in hex
  //end of inspired code
  return c;

}


/* Gets a char c and returns its encrypted form by adding 1 to its value. If c is 0x7F this wraps around and 0x20 is returned.
If c is not between 0x20 and 0x7F it is returned unchanged */
char encrypt(char c){
  if(c>=0x20 && c<0x7F){
    return(c+1);
  }
  if(c==0x7F){
    return 0x20;
  }
  return c;
}



/* Gets a char c and returns its decrypted form by reducing 1 from its value. 
If c is 0x20 this wraps around and 0x7F is returned. If c is not between 0x20 and 0x7F it is returned unchanged: */
char decrypt(char c){
   if(c>0x20 && c<=0x7F){
    return(c-1);
  }
  if(c==0x20){
    return 0x7F;
  }
  return c;
}



/* dprt prints the value of c in a decimal representation followed by a new line, and returns c unchanged: */
char dprt(char c){
  printf("%d \n",c);
  return c;
}




/*========================part3======================================*/

struct fun_desc {
char *name;
char index;
char (*fun)(char);
};

struct fun_desc menu1[] = { { "<m>y_get", 'm', my_get}, { "<c>xprt", 'c',cxprt }, { "<e>ncrypt", 'e',encrypt }, { "<d>ecrypt", 'd',decrypt },  { "<p>dprt", 'p',dprt },{ NULL, 0, NULL } };
void menu(){
  char* carray = (char*)(malloc(5));
  //init to empty string:
  carray[0]='\0'; //null charachter 
    while(feof(stdin)==0){//we have more 
      fprintf(stdout,"Select operation from the following menu by index:\n");
      int idx=0;
      while(menu1[idx].fun!=NULL){
          printf("%s\n",menu1[idx].name);
          idx++;
      }
      
      //code taken from tutorialsPoint:
      char buffer[50]; //array of chars
      fgets(buffer, sizeof(buffer), stdin);
      //end of taken code
      int isError = 1;
      for(int i=0;menu1[i].fun!=NULL;i++){
        if(buffer[0]==menu1[i].index){
          char* tmp =  map(carray,5,menu1[i].fun);
          free(carray);
          carray= tmp;
          isError = 0;
        }
      }
      if(isError==1){
        printf("function not supported\n");
      }   
    }      
  exit(0);
  free(carray);
}




/*
A user should be able to terminate the program when asked for a choice, by signaling EOF using 'Ctrl+D' on an empty line.

For example, the menu structure initialized as the menu[]
 above should be printed (exact format not very important, that TA may ask you to change it, regardless):
<h>ello
<b>ye


*/



int main(int argc, char **argv){
  /*
  int base_len = 5;
  char arr1[base_len];
  char* arr2 = map(arr1, base_len, my_get);
  char* arr3 = map(arr2, base_len, dprt);
  char* arr4 = map(arr3, base_len, cxprt);
  free(arr2);
  free(arr3);
  free(arr4);
  */
  menu();
}

