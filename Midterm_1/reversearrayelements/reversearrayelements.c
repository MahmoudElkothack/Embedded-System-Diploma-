/********
AUTHOR:Mahmoud ALI Elkot
*************/
#include <stdio.h>

void reverse_array(int arr[],int size){
	int i=0;
	for(i=size-1;i>=0;i--)
	{
		printf("%d ",arr[i]);

	}


}
int main() {
	int i,size,a[100];
	printf("enter size ");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	reverse_array(a,size);
   return 0;
}
