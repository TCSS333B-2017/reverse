#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse1(char *a);
void reverse2(char *a);
void reverse3(void *a, int typeSize, int nElements);
int main(){
 int b[]={1,2,3,4,5};
 char a[]="Hello World";
 reverse3((void*)b,sizeof(int),sizeof(b)/sizeof(int));
 for(int i=0;i<5;i++){
  printf("%d\n",b[i]);
 }
 return 0;
}

void reverse1(char *a){
 int left=0, right=strlen(a)-1;
 char temp;
 while(left < right){	
  temp=a[right];
  a[right]=a[left];
  a[left]=temp;
  left++;
  right--;
 }
}

void reverse2(char *a){
 char *left=a, *right=a+strlen(a)-1;
 char temp;
 while(left < right){	
  temp=*right;
  *right=*left;
  *left=temp;
  left++;
  right--;
 }
}
void reverse3(void *a,int typeSize, int nElements){
 char *left=(char*) a, *right=(char*)a+(nElements-1)*typeSize;
 char temp[typeSize];
 while(left < right){	
  memcpy(temp,right,typeSize);
  memmove(right,left,typeSize);
  memcpy(left,temp,typeSize);
  left+=typeSize;
  right-=typeSize;
 }
}

