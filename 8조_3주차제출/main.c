#include "stm32f10x.h"

#define RCC_APB2ENR (*(volatile unsigned int *)0x40021018)
#define GPIOD_CRL (*(volatile unsigned *)0x40011400)
#define GPIOD_BSRR (*(volatile unsigned *)0x40011410)
#define GPIOD_ODR (*(volatile unsigned *)0x4001140C)
#define GPIOC_CRL (*(volatile unsigned *)0x40011000)
#define GPIOC_IDR (*(volatile unsigned *)0x40011008)
#define GPIOB_CRL (*(volatile unsigned *)0x40010C00)
#define GPIOB_IDR (*(volatile unsigned *)0x40010C08)

int check_bit(int bit_32num, int bit_index) { // 16진수를 입력받아  n번째(0부터 시작) bit가 0인지 1인지 판별하는 함수. (0일 경우 0, 1일 경우 1을 반환)
  bit_32num = bit_32num >> bit_index;
  
  if ((0x00000001 & bit_32num) == 0) {
    return 0;
  }
  else {
    return 1;
  }
}

int main(void) {
    RCC_APB2ENR |= 0x20; // GPIO D 활성화
    RCC_APB2ENR |= 0x10; // GPIO C 활성화
    RCC_APB2ENR |= 0x8; // GPIO B 활성화
    
    GPIOD_CRL &= 0x0FF000FF;
    GPIOD_CRL |= 0x30033300;
    GPIOC_CRL &= 0xFF0000FF;
    GPIOC_CRL |= 0x00888800;
    GPIOB_CRL &= 0x0FFFFFFF;
    GPIOB_CRL |= 0x80000000;
  
  while(1) {
    
    if (check_bit(GPIOC_IDR, 2) == 0) { // DOWN
      GPIOD_BSRR |= 0x00900000;
    }
    if (check_bit(GPIOC_IDR, 3) == 0) { // LEFT
      GPIOD_BSRR |= 0xC;
    }
    if (check_bit(GPIOC_IDR, 4) == 0) { // RIGHT
      GPIOD_BSRR |= 0x000C0000;
    }
    if (check_bit(GPIOC_IDR, 5) == 0) { // UP
      GPIOD_BSRR |= 0x90;
    }
    if (check_bit(GPIOB_IDR, 8) == 0) { // Selection
      int carry = 0x9C;
      carry = carry - GPIOD_ODR;
      GPIOD_BSRR |= GPIOD_ODR << 16;
      GPIOD_BSRR |= carry;
    } // 1001110 (PD 2,3,4,7) 에서 현재 켜져 있는 LED (GPIOD_ODR) 를 빼서 켜야 할 LED를 구한 뒤, 켜져 있는 건 끄고(Reset), 꺼져 있는건 킨다.
  }
}