#include "stm32f10x.h"

#define RCC_APB2ENR (*(volatile unsigned int *)0x40021018)
#define GPIOD_CRL (*(volatile unsigned *)0x40011400)
#define GPIOD_BSRR (*(volatile unsigned *)0x40011410)
#define GPIOD_ODR (*(volatile unsigned *)0x4001140C)
#define GPIOC_CRL (*(volatile unsigned *)0x40011000)
#define GPIOC_IDR (*(volatile unsigned *)0x40011008)
#define GPIOB_CRL (*(volatile unsigned *)0x40010C00)
#define GPIOB_IDR (*(volatile unsigned *)0x40010C08)

int check_bit(int bit_32num, int bit_index) { // 16������ �Է¹޾�  n��°(0���� ����) bit�� 0���� 1���� �Ǻ��ϴ� �Լ�. (0�� ��� 0, 1�� ��� 1�� ��ȯ)
  bit_32num = bit_32num >> bit_index;
  
  if ((0x00000001 & bit_32num) == 0) {
    return 0;
  }
  else {
    return 1;
  }
}

int main(void) {
    RCC_APB2ENR |= 0x20; // GPIO D Ȱ��ȭ
    RCC_APB2ENR |= 0x10; // GPIO C Ȱ��ȭ
    RCC_APB2ENR |= 0x8; // GPIO B Ȱ��ȭ
    
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
    } // 1001110 (PD 2,3,4,7) ���� ���� ���� �ִ� LED (GPIOD_ODR) �� ���� �Ѿ� �� LED�� ���� ��, ���� �ִ� �� ����(Reset), ���� �ִ°� Ų��.
  }
}