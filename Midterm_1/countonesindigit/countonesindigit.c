/********
AUTHOR:Mahmoud ALI Elkot
*************/
#include <stdio.h>
void countones(int num){
	int bit,count=0;
	for(bit=0;bit<32;bit++){
		if((num & 1<<bit))count++;

	}
	printf("%d ",count);

}
int main() {
int num;
  printf("enter num ");
 scanf("%d",&num);
countones(num);
   return 0;
}
