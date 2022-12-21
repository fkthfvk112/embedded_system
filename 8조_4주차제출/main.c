#include "stm32f10x.h"

#define RCC_APB2ENR (*(volatile unsigned int *)0x40021018)
#define GPIOE_CRL (*(volatile unsigned *)0x40011800) //configration pin low
#define GPIOE_BSRR (*(volatile unsigned *)0x40011810)//bit set reset
#define GPIOE_ODR (*(volatile unsigned *)0x4001180C)//output data register
#define GPIOC_CRL (*(volatile unsigned *)0x40011000)
#define GPIOC_IDR (*(volatile unsigned *)0x40011008)//input data register

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
    RCC_APB2ENR |= 0x40; // GPIO E Ȱ��ȭ

    GPIOE_CRL &= 0xFFFFFFF0;
    GPIOE_CRL |= 0x00000003;
    GPIOC_CRL &= 0xFF0FF0FF;
    GPIOC_CRL |= 0x00800800;

  while(1) {

    if (check_bit(GPIOC_IDR, 2) == 0) { // DOWN
      GPIOE_BSRR |= 0x00010000;
    }
    if (check_bit(GPIOC_IDR, 5) == 0) { // UP
      GPIOE_BSRR |= 0x00000001;
    }
  }
}
