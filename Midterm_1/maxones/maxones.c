/*int getMaxOnes(char n) {
   int setBit = 1;
   int prev = 0;
   int i;
   for (i = 1; i < sizeof(int) * 8; ++i) {
      ++prev;
      if ((n & setBit) == 0) {
         setBit = setBit << 1;
         break;
      }
      setBit = setBit << 1;
   }
   int maxZeros =-1;
   int cur = prev;
   for (int j = i + 1; j <= sizeof(int) * 8; ++j) {
      ++cur;
      if ((n & setBit) == 0) {
         if (maxZeros < (cur - prev - 1)) {
            maxZeros = cur - prev - 1; prev = cur;
         }
      }
      setBit = setBit << 1;
   }
   return maxZeros;
}
char max_ones(int num){
	int count=0;
	while(num!=0){

		num=(num&(num<<1));
	count++;
	}
	return count;
}
*/
int main() {
	int num;
/*  printf("enter num");
  scanf("%d",&num);
  printf("Max num of one's%d\n",max_ones(num));
  printf("Max num of one's%d\n",getMaxOnes(num));
  */
	int a=10;
	void* p=&a;
	printf("%d\n",p);
	p++;
	printf("%d\n",p);
   return 0;
}
