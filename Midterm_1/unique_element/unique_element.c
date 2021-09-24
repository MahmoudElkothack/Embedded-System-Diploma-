/********
AUTHOR:Mahmoud ALI Elkot
*************/
#include <stdio.h>
int main() {
int i,size,a[100],unique=0;
printf("enter size");
scanf("%d",&size);
for(i=0;i<size;i++){
	scanf("%d",&a[i]);
}
for(i=0;i<size;i++){
	unique^=a[i];

}
printf("%d",unique);
   return 0;
}
