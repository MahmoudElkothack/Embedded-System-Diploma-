/********
AUTHOR:Mahmoud ALI Elkot
*************/
#include <stdio.h>
void printreverse(int num){
	while(num>0){
		printf("%d",num%10);
		num/=10;

	}

}
int main() {
	int num;
  printf("enter num");
 scanf("%d",&num);
 printreverse(num);
   return 0;
}
