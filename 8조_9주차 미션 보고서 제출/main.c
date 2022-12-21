#include "stm32f10x.h"
#include "core_cm3.h"
#include "misc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_adc.h"
#include "lcd.h"
#include "touch.h"
#include <stdio.h>
#include <stdlib.h>
uint16_t pos_x,pos_y;
uint16_t pix_x,pix_y;
uint16_t jodo;


int color[12] =
{WHITE,CYAN,BLUE,RED,MAGENTA,LGRAY,GREEN,YELLOW,BROWN,BRRED,GRAY};


void RCC_Configure(void);
void GPIO_Configure(void);
void USART1_Init(void);
void NVIC_Configure(void);

void USART1_IRQHandler(void);
void USART2_IRQHandler(void);

void Delay(void);

void sendDataUART1(uint16_t data);
void sendDataUART2(uint16_t data);


//---------------------------------------------------------------------------------------------------

void RCC_Configure(void)
{
   // TODO: Enable the APB2 peripheral clock using the function 'RCC_APB2PeriphClockCmd'
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);    // interrupt
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);     // RCC GPIO E
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);     // RCC GPIO B
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);     // RCC GPIO C
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);     // RCC GPIO D
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);    // ADC1
}

void GPIO_Configure(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

   // TODO: Initialize the GPIO pins using the structure 'GPIO_InitTypeDef' and the function 'GPIO_Init'
   
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
}

void ADC_Configure(void) {
   ADC_InitTypeDef ADC_InitStructure;
   ADC_DeInit(ADC1);
   ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
   ADC_InitStructure.ADC_ScanConvMode = ENABLE;
   ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
   ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
   ADC_InitStructure.ADC_NbrOfChannel = 1;
   ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_239Cycles5);
   ADC_Init(ADC1, &ADC_InitStructure);
}

void NVIC_Configure(void) {

    NVIC_InitTypeDef NVIC_InitStructure;
    
    // TODO: fill the arg you want

   // TODO: Initialize the NVIC using the structure 'NVIC_InitTypeDef' and the function 'NVIC_Init'
   
    // UART1
   // 'NVIC_EnableIRQ' is only required for USART setting
    
    NVIC_InitStructure.NVIC_IRQChannel = ADC1_2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);
    ADC_Cmd(ADC1, ENABLE);
}

void ADC_start(void) {
   ADC_ResetCalibration(ADC1);
   while(ADC_GetResetCalibrationStatus(ADC1));
   ADC_StartCalibration(ADC1);
   while(ADC_GetCalibrationStatus(ADC1));
   ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}


void ADC1_2_IRQHandler(void) {
   uint16_t input;
   u8 str[10];
   double result;
//
////   while(ADC_GetFlagStatus(ADC1, 0x2)==RESET);
   if (ADC_GetITStatus(ADC1, ADC_IT_EOC) != RESET) {
     input = ADC_GetConversionValue(ADC1);
     result = (double)input;
     jodo = result;
     ADC_ClearITPendingBit(ADC1,ADC_IT_EOC);
   }
   //   LCD_DrawRectangle(pix_x, pix_y, pix_x+10, pix_y+10);
}


void Delay(void) {
   int i;

   for (i = 0; i < 100000; i++) {}
}

void sendDataUART1(uint16_t data) {
   while ((USART1->SR & USART_SR_TXE) == 0);
   USART_SendData(USART1, data);
}

void sendDataUART2(uint16_t data) {
   while ((USART2->SR & USART_SR_TXE) == 0);
   USART_SendData(USART2, data);
}



int main() {
  // LCD 관련 설정은 LCD_Init에 구현되어 있으므로 여기서 할 필요 없음
  SystemInit();
  RCC_Configure();
  GPIO_Configure();
  ADC_Configure();
  NVIC_Configure();
  // ------------------------------------
  
  int prevCircleX = -1, prevCircleY = -1;
  char str[10];


  LCD_Init();
  Touch_Configuration();
  Touch_Adjust();
  LCD_Clear(WHITE);
  ADC_start();
  while(1){
    LCD_ShowString(25, 100, "TUE_Team08", BLACK, WHITE);
    Touch_GetXY(&pix_x, &pix_y, 0);
    
    Convert_Pos(pix_x, pix_y, &pix_x, &pix_y);
    
    if(T_INT == 0) {
            LCD_ShowNum(65, 160, jodo, 4, BLACK, WHITE);
            LCD_DrawCircle(pix_x, pix_y, 10);

            sprintf(str, "%3d", pix_x);
            LCD_ShowNum(75, 120, pix_x, 10, BLACK, WHITE);
            sprintf(str, "%3d", pix_y);
            LCD_ShowNum(75, 140, pix_y, 10, BLACK, WHITE);
            Delay();
    }
  }
}