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
int t1 = 1, t2 = 1;
int buttonOn = 1;
int clickable = 1;
int led1 = 0;
int led2 = 0;
int moter_counter = 0;
int moter_adder = 1;
int moter_purse[9]= {1400, 1475, 1400, 1475, 1550, 1475, 1550};

void RCC_Configure(void);
void GPIO_Configure(void);
void NVIC_Configure(void);

void init_Timer2(void);
void init_Timer3(void);

void TIM2_IRQHandler(void);

void Delay(void);
void change(uint16_t per);

//---------------------------------------------------------------------------------------------------

void RCC_Configure(void)
{
  // TODO: Enable the APB2 peripheral clock using the function 'RCC_APB2PeriphClockCmd'
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);    // interrupt
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);     // RCC GPIO E
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);     // RCC GPIO B
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);     // RCC GPIO B
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);     // RCC GPIO C
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);     // RCC GPIO D

   /* TIM2 Clock Enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
}

void GPIO_Configure(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;

  // TODO: Initialize the GPIO pins using the structure 'GPIO_InitTypeDef' and the function 'GPIO_Init'
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);  
}

void NVIC_Configure(void) {

  NVIC_InitTypeDef NVIC_InitStructure;
    
  // TODO: fill the arg you want

  // TODO: Initialize the NVIC using the structure 'NVIC_InitTypeDef' and the function 'NVIC_Init'
   
  // UART1
  // 'NVIC_EnableIRQ' is only required for USART setting
    
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); // interrupt enable
  
}

void init_Timer2(void) {
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; // timerbase...
  TIM_OCInitTypeDef TIM_OCInitStructure;
  
  /* TIM2 Initialize */
  uint16_t prescale = (uint16_t) (SystemCoreClock / 1200);
  TIM_TimeBaseStructure.TIM_Period = 1200 - 1;
  TIM_TimeBaseStructure.TIM_Prescaler = prescale;
  //계산방법 : 1/72Mhz * 1200 * 60000
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
  
  /* TIM2 Enale */
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
  TIM_ARRPreloadConfig(TIM2, ENABLE);
  TIM_Cmd(TIM2, ENABLE);
}

void init_Timer3(void) {
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; // timerbase...
  TIM_OCInitTypeDef TIM_OCInitStructure;
  
  /* TIM3 Initialize */
  uint16_t prescale = (uint16_t) (SystemCoreClock / 1000000);
  TIM_TimeBaseStructure.TIM_Period = 20000 - 1;
  TIM_TimeBaseStructure.TIM_Prescaler = prescale;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
  
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = moter_purse[0];
  TIM_OC3Init(TIM3, &TIM_OCInitStructure);
  
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Disable);
  TIM_ARRPreloadConfig(TIM3, ENABLE);
  TIM_Cmd(TIM3, ENABLE);
}

void TIM2_IRQHandler(void) {

  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
    t1++;
    t2++;
    clickable = 1;
    
    change(moter_purse[moter_counter]);
    moter_counter = (moter_counter + moter_adder) % 9;
    if (moter_counter == 0) {
      moter_adder = -moter_adder;
    }
  }
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  //Clears the TIMx's interrupt pending bits.
}


void change(uint16_t per) {
    uint16_t pwm_pulse;
    pwm_pulse = per;
    
    TIM_OCInitTypeDef TIM_OCInitStructure;
    
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = pwm_pulse;
    TIM_OC3Init(TIM3, &TIM_OCInitStructure);
}

void Delay(void) {
   int i;

   for (i = 0; i < 1000; i++) {}
}

void button() {
  buttonOn = !buttonOn;
  if (buttonOn == 0) {
    LCD_ShowString(25, 120, "OFF", RED, WHITE);
  }
  else if (buttonOn == 1) {
    LCD_ShowString(25, 120, "ON  ", RED, WHITE);
    t1 = 0;
    t2 = 0;
  }

  clickable = 0;   
}

void led1Toggle(void) {
  if (t1 >= 1) {
    t1 = 0;
    if (led1 == 1) {
     GPIO_ResetBits(GPIOD, GPIO_Pin_2);
     led1 = 0;
   }
   else {
     GPIO_SetBits(GPIOD, GPIO_Pin_2);
     led1 = 1;
  }
 }
}

void led2Toggle(void) {
  if (t2 >= 5) {
    t2 = 0;
    if (led2 == 1) {
     GPIO_ResetBits(GPIOD, GPIO_Pin_3);
     led2 = 0;
   }
   else {
     GPIO_SetBits(GPIOD, GPIO_Pin_3);
     led2 = 1;
  }
 }
}

int main() {
  // LCD 관련 설정은 LCD_Init에 구현되어 있으므로 여기서 할 필요 없음
  SystemInit();
  RCC_Configure();
  GPIO_Configure();
  NVIC_Configure();
  
  init_Timer2();
  init_Timer3();
  // ------------------------------------

  LCD_Init();
  Touch_Configuration();
  Touch_Adjust();
  
  LCD_Clear(WHITE);
  LCD_ShowString(25, 100, "TUE_Team08", BLACK, WHITE);
  LCD_DrawRectangle(40, 140, 100, 200);
  LCD_ShowString(50, 150, "BUT", RED, WHITE);
  LCD_ShowString(25, 120, "ON  ", RED, WHITE);
  
  while(1){
    Touch_GetXY(&pos_x, &pos_y, 0);
    Convert_Pos(pos_x, pos_y, &pos_x, &pos_y);
    
    if(T_INT == 0) {
       if (pos_x > 40 && pos_x < 100 && pos_y > 140 && pos_y < 200 && clickable)
        button();
    }
    if (buttonOn == 1) {
      led1Toggle();
      led2Toggle();
    }
  }
}