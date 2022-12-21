#include "stm32f10x.h"

#define GPIOD_IDR (*(volatile unsigned *)0x40011408)

int check_bit(int bit_32num, int bit_index) { // 16������ �Է¹޾�  n��°(0���� ����) bit�� 0���� 1���� �Ǻ��ϴ� �Լ�. (0�� ��� 0, 1�� ��� 1�� ��ȯ)
  bit_32num = bit_32num >> bit_index;
  
  if ((0x00000001 & bit_32num) == 0) {
    return 0;
  }
  else {
    return 1;
  }
}


void SysInit(void) {
    /* Set HSION bit */
    /* Internal Clock Enable */
    RCC->CR |= (uint32_t)0x00000001; //HSION

    /* Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits */
    RCC->CFGR &= (uint32_t)0xF0FF0000;

    /* Reset HSEON, CSSON and PLLON bits */
    RCC->CR &= (uint32_t)0xFEF6FFFF;

    /* Reset HSEBYP bit */
    RCC->CR &= (uint32_t)0xFFFBFFFF;

    /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
    RCC->CFGR &= (uint32_t)0xFF80FFFF;

    /* Reset PLL2ON and PLL3ON bits */
    RCC->CR &= (uint32_t)0xEBFFFFFF;

    /* Disable all interrupts and clear pending bits  */
    RCC->CIR = 0x00FF0000;

    /* Reset CFGR2 register */
    RCC->CFGR2 = 0x00000000;
}

void SetSysClock(void) {
    volatile uint32_t StartUpCounter = 0, HSEStatus = 0;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable HSE */
    RCC->CR |= ((uint32_t)RCC_CR_HSEON);
    /* Wait till HSE is ready and if Time out is reached exit */
    do {
        HSEStatus = RCC->CR & RCC_CR_HSERDY;
        StartUpCounter++;
    } while ((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSERDY) != RESET) {
        HSEStatus = (uint32_t)0x01;
    }
    else {
        HSEStatus = (uint32_t)0x00;
    }

    if (HSEStatus == (uint32_t)0x01) {
        /* Enable Prefetch Buffer */
        FLASH->ACR |= FLASH_ACR_PRFTBE;
        /* Flash 0 wait state */
        FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
        FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_0;

//@TODO - 1 Set the clock, (//) �ּ� ǥ�ø� ���ְ� Ʋ�� ���� �ִٸ� ����� �� ������ �����Ͻÿ�  �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
        /* HCLK = SYSCLK */
        RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
        /* PCLK2 = HCLK / ?, use PPRE2 */
        RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV2; // PCLK2 = SYSCLK / 2
        /* PCLK1 = HCLK */
        RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV1;

        /* Configure PLLs ------------------------------------------------------*/
        RCC->CFGR &= (uint32_t)~( RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
        RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_PREDIV1 | RCC_CFGR_PLLMULL4);

        RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL | RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
        RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL13 | RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV5);
        // 25 / 5(PREDIV2_DIV5) * 13(PLL2MUL13) -> �Ʒ� ���� -> / 5(PREDIV1_DIV5) * 4(PLLMULL4) = 52
//@End of TODO - 1 �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�

        /* Enable PLL2 */
        RCC->CR |= RCC_CR_PLL2ON;
        /* Wait till PLL2 is ready */
        while ((RCC->CR & RCC_CR_PLL2RDY) == 0)
        {
        }
        /* Enable PLL */
        RCC->CR |= RCC_CR_PLLON;
        /* Wait till PLL is ready */
        while ((RCC->CR & RCC_CR_PLLRDY) == 0)
        {
        }
        /* Select PLL as system clock source */
        RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
        RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;
        /* Wait till PLL is used as system clock source */
        while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
        {
        }
        /* Select System Clock as output of MCO */
//@TODO - 2 Set the MCO port for system clock output �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
        RCC->CFGR &= ~(uint32_t)RCC_CFGR_MCO;
        RCC->CFGR |= (uint32_t)RCC_CFGR_MCO_SYSCLK; // MCO�� SYSCLK ���� ����Ѵ� (SYSCLK ���� ������ ���� 52Mhz �� �������ִ�)
//@End of TODO - 2 �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    }
    else {
        /* If HSE fails to start-up, the application will have wrong clock
        configuration. User can add here some code to deal with this error */
    }
}

void RCC_Enable(void) {
//@TODO - 3 RCC Setting �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    /*---------------------------- RCC Configuration -----------------------------*/
    /* GPIO RCC Enable  */
    /* UART Tx, Rx, MCO port */
    RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPDEN); // GPIOA, D Ȱ��ȭ, Alternative function enable
    /* USART RCC Enable */
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // USART1  enable
}

void PortConfiguration(void) {
//@TODO - 4 GPIO Configuration �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    /* Reset(Clear) Port A CRH - MCO, USART1 TX,RX*/
    GPIOA->CRH &= ~(
	    (GPIO_CRH_CNF8 | GPIO_CRH_MODE8) |
	    (GPIO_CRH_CNF9 | GPIO_CRH_MODE9) |
	    (GPIO_CRH_CNF10 | GPIO_CRH_MODE10)
	);
    /* MCO Pin Configuration */
    GPIOA->CRH |= (GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8); // MCO Pin�� CNF�� MODE�� 1011 �� �����. (OUTPUT, Alternative pull in - pull down)
    /* USART Pin Configuration */
    GPIOA->CRH |= (
                   (GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9) | // USART Tx �� Rx �� CNF�� MODE �� �����Ѵ� (1011, 1000)
                   (GPIO_CRH_CNF10_1));
                     
    /* Reset(Clear) Port D CRH - User S1 Button */
    GPIOD->CRH &= ~(GPIO_CRH_CNF11 | GPIO_CRH_MODE11);
    /* User S1 Button Configuration */
    GPIOD->CRH |= GPIO_CRH_CNF11_1; // S1 ����ġ�� input mode�� �����Ѵ�
}

void UartInit(void) {
    /*---------------------------- USART CR1 Configuration -----------------------*/
    /* Clear M, PCE, PS, TE and RE bits */
    USART1->CR1 &= ~(uint32_t)(USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | USART_CR1_TE | USART_CR1_RE);
    /* Configure the USART Word Length, Parity and mode ----------------------- */
    /* Set the M bits according to USART_WordLength value */
//@TODO - 6: WordLength : 8bit �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    /* Set PCE and PS bits according to USART_Parity value */
    // PCE�� PS�� disable �̹Ƿ� ���� �ʿ� X (�ʱⰪ 0)
//@TODO - 7: Parity : None �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    /* Set TE and RE bits according to USART_Mode value */
    // ���� �ʿ� X
//@TODO - 8: Enable Tx and Rx �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    USART1->CR1 |= (USART_CR1_TE | USART_CR1_RE); // Tx�� Rx�� enable �Ѵ�. [reference USART_CR1 ����]

    /*---------------------------- USART CR2 Configuration -----------------------*/
    /* Clear STOP[13:12] bits */
    USART1->CR2 &= ~(uint32_t)(USART_CR2_STOP);
    /* Configure the USART Stop Bits, Clock, CPOL, CPHA and LastBit ------------*/
    USART1->CR2 &= ~(uint32_t)(USART_CR2_CPHA | USART_CR2_CPOL | USART_CR2_CLKEN);
    /* Set STOP[13:12] bits according to USART_StopBits value */
//@TODO - 9: Stop bit : 1bit �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    // �̹� �������־ ���� �ʿ� X [reference USART_CR2 ����]
    

    /*---------------------------- USART CR3 Configuration -----------------------*/
    /* Clear CTSE and RTSE bits */
    USART1->CR3 &= ~(uint32_t)(USART_CR3_CTSE | USART_CR3_RTSE);
    /* Configure the USART HFC -------------------------------------------------*/
    /* Set CTSE and RTSE bits according to USART_HardwareFlowControl value */
//@TODO - 10: CTS, RTS : disable �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    // PCE�� PS�� disable �̹Ƿ� ���� �ʿ� X (�ʱⰪ 0)

    /*---------------------------- USART BRR Configuration -----------------------*/
    /* Configure the USART Baud Rate -------------------------------------------*/
    /* Determine the integer part */
    /* Determine the fractional part */
//@TODO - 11: Calculate & configure BRR �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    USART1->BRR |= 0xA94; // 26000000/(16*9600) �ؼ� ���� ������ ��ģ �� ���Ѱ�.

    /*---------------------------- USART Enable ----------------------------------*/
    /* USART Enable Configuration */
//@TODO - 12: Enable UART (UE) �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    USART1->CR1 |= USART_CR1_UE; // UE�� Ȱ��ȭ�Ѵ�.
}

void delay(void){
    int i = 0;
    for(i=0;i<1000000;i++);
}

void SendData(uint16_t data) {
    /* Transmit Data */
	USART1->DR = data;

	/* Wait till TC is set */
	while ((USART1->SR & USART_SR_TC) == 0);
}

int main() {
	int i;
	char msg[] = "Hello Team08\r\n";
        
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    
	
    SysInit();
    SetSysClock();
    RCC_Enable();
    PortConfiguration();
    UartInit();
    
    // if you need, init pin values here
    
    
    while (1) {
		//@TODO - 13: Send the message when button is pressed �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
      
      if (check_bit(GPIOD_IDR, 11) == 0) { // GPIOD_IDR �� 1���� 0���� �ٲ������ Ȯ�� �� �ٲ���ٸ� �޼��� ����
        for(int i = 0; i < 14; i++) {
          SendData(msg[i]);
        }
      }
    }

}// end main