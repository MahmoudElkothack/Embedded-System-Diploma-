/*
Author Mahmoid Elkot
*/
#include <stdint.h>


static unsigned long  stack_top[256];


extern unsigned int  _E_data;
extern unsigned int  _S_data;
extern unsigned int  _S_bss;
extern unsigned int  _E_bss;
extern unsigned int  _E_text;
extern int main();
void Reset_handler();

void Default_handler(){
Reset_handler();

}

void NMI_Handler()__attribute__((weak,alias("Default_handler")));
void H_fault_handler()__attribute__((weak,alias("Default_handler")));
void MM_Fault_handler()__attribute__((weak,alias("Default_handler")));
void Bus_fAULT_handler()__attribute__((weak,alias("Default_handler")));


  void (* const g_p_fn_vectors[])()__attribute__((section(".vectors")))=
{

  (void (*)()) stack_top + sizeof(stack_top),
   &Reset_handler,
   &NMI_Handler,
   &H_fault_handler,
   &MM_Fault_handler,
   &Bus_fAULT_handler,


};

void Reset_handler(){
unsigned int Data_size = (unsigned int) &_S_data - _E_data ;
unsigned char* ptr_src = (unsigned char*)&_E_text;
unsigned char* ptr_dst = (unsigned char*)&_S_data;
for(int i=0; i<Data_size;i++){
  *((unsigned char*)ptr_dst++)=*((unsigned char*)ptr_src++); 
}
unsigned int bss_size = (unsigned int) &_E_bss - (unsigned int) &_S_bss;
ptr_dst = (unsigned char*) &_S_bss;
for(int i=0;i< bss_size;i++){
*((unsigned char*)ptr_dst++) = (unsigned char)0;
}


main();

}