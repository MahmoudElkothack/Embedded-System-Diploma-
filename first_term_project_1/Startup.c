/*
Author Mahmoid Elkot
*/
#include <stdint.h>
//#define Stack_start  _stack_top
extern unsigned int  _E_data;
extern unsigned int  _S_data;
extern unsigned int  _stack_top;
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


uint32_t vectors[] __attribute__((section(".vectors")))= {

  (uint32_t) &_stack_top,
  (uint32_t) &Reset_handler,
  (uint32_t) &NMI_Handler,
  (uint32_t) &H_fault_handler,
  (uint32_t) &MM_Fault_handler,
  (uint32_t) &Bus_fAULT_handler,

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