# 임베디드 시스템 설계 및 실험

2022년 2학기 부산대학교 임베디드 시스템 설계 및 실험 과목의 결과입니다.

+ 설명
  + 임베디드 시스템 설계 및 실험 과목의 제출 결과물 및 수업 내용입니다.

+ 각 폴더(8조_3주차제출 ...)는 실험 제출 결과물입니다.
+ 강의 자료와 미션지는 별개의 폴더(강의자료 및 미션지)로 분리되어있습니다.
+ Temp Project폴더에는 텀프로젝트의 결과물이 들어있습니다.

------------------------
# 파일 구조
```
📦Total_result
 ┣ 📂8조_10주차제출
 ┃ ┣ 📜8조_10주차_동작_동영상.mp4
 ┃ ┣ 📜8조_10주차_실험_보고서.docx
 ┃ ┣ 📜main.c
 ┃ ┗ 📜~WRL2945.tmp
 ┣ 📂8조_11주차제출
 ┃ ┣ 📜8조_11주차_실험_보고서.docx
 ┃ ┣ 📜8조_11주차_실험동영상.mp4
 ┃ ┗ 📜main.c
 ┣ 📂8조_3주차제출
 ┃ ┣ 📜8조_3주차보고서.pdf
 ┃ ┣ 📜8조_실행 동영상.mp4
 ┃ ┗ 📜main.c
 ┣ 📂8조_4주차제출
 ┃ ┣ 📜4주차_8조_실행동영상.mp4
 ┃ ┣ 📜4주차_8조_실험 보고서.pdf
 ┃ ┗ 📜main.c
 ┣ 📂8조_5주차 미션 보고서 제출
 ┃ ┣ 📜5주차_8조_동작 동영상 (1).mp4
 ┃ ┣ 📜5주차_8조_동작 동영상 (2).mp4
 ┃ ┣ 📜5주차_8조_실험 보고서.pdf
 ┃ ┗ 📜main.c
 ┣ 📂8조_6주차 미션 보고서 제출
 ┃ ┣ 📜8조_6주차_동작_동영상1.mp4
 ┃ ┣ 📜8조_6주차_동작_동영상2.mp4
 ┃ ┣ 📜8조_6주차_실험_보고서.docx
 ┃ ┗ 📜main.c
 ┣ 📂8조_7주차 미션 보고서 제출
 ┃ ┣ 📜8조_7주차_동작_동영상.mp4
 ┃ ┣ 📜8조_7주차_실험_보고서.docx
 ┃ ┗ 📜main.c
 ┣ 📂8조_9주차 미션 보고서 제출
 ┃ ┣ 📜8조_9주차_동작_동영상.mp4
 ┃ ┣ 📜8조_9주차_실험_보고서.docx
 ┃ ┗ 📜main.c
 ┣ 📂TempProject
 ┃ ┣ 📂IAR_projects
 ┃ ┃ ┣ 📂CoreSupport
 ┃ ┃ ┃ ┣ 📜core_cm3.c
 ┃ ┃ ┃ ┗ 📜core_cm3.h
 ┃ ┃ ┣ 📂Debug
 ┃ ┃ ┃ ┣ 📂BrowseInfo
 ┃ ┃ ┃ ┃ ┣ 📂libraries
 ┃ ┃ ┃ ┃ ┃ ┣ 📂CMSIS
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂DeviceSupport
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜system_stm32f10x.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜system_stm32f10x.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜system_stm32f10x.xcl
 ┃ ┃ ┃ ┃ ┃ ┣ 📂DeviceSupport
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜system_stm32f10x.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜system_stm32f10x.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜system_stm32f10x.xcl
 ┃ ┃ ┃ ┃ ┃ ┣ 📂LCD
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜touch.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜touch.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜touch.xcl
 ┃ ┃ ┃ ┃ ┃ ┗ 📂STM32F10x_StdPeriph_Driver_v3.5
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂src
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜misc.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜misc.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜misc.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_adc.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_adc.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_adc.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_bkp.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_bkp.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_bkp.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_can.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_can.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_can.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_cec.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_cec.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_cec.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_crc.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_crc.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_crc.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dac.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dac.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dac.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dbgmcu.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dbgmcu.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dbgmcu.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dma.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dma.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dma.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_exti.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_exti.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_exti.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_flash.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_flash.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_flash.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_fsmc.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_fsmc.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_fsmc.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_gpio.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_gpio.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_gpio.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_i2c.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_i2c.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_i2c.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_iwdg.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_iwdg.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_iwdg.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_pwr.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_pwr.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_pwr.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rcc.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rcc.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rcc.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rtc.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rtc.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rtc.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_sdio.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_sdio.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_sdio.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_spi.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_spi.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_spi.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_tim.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_tim.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_tim.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_usart.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_usart.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_usart.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_wwdg.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_wwdg.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_wwdg.xcl
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜touch.pbi
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜touch.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜touch.xcl
 ┃ ┃ ┃ ┃ ┣ 📂user
 ┃ ┃ ┃ ┃ ┃ ┣ 📜DS3231_BUZZER.pbi
 ┃ ┃ ┃ ┃ ┃ ┣ 📜DS3231_BUZZER.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┣ 📜DS3231_BUZZER.xcl
 ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.pbi
 ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.xcl
 ┃ ┃ ┃ ┃ ┃ ┣ 📜main.pbi
 ┃ ┃ ┃ ┃ ┃ ┣ 📜main.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┣ 📜main.xcl
 ┃ ┃ ┃ ┃ ┃ ┣ 📜moveWheel.pbi
 ┃ ┃ ┃ ┃ ┃ ┣ 📜moveWheel.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┣ 📜moveWheel.xcl
 ┃ ┃ ┃ ┃ ┃ ┣ 📜pir.pbi
 ┃ ┃ ┃ ┃ ┃ ┣ 📜pir.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┣ 📜pir.xcl
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_it.pbi
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_it.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_it.xcl
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stop_button.pbi
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stop_button.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stop_button.xcl
 ┃ ┃ ┃ ┃ ┃ ┣ 📜touch.pbi
 ┃ ┃ ┃ ┃ ┃ ┣ 📜touch.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┣ 📜touch.xcl
 ┃ ┃ ┃ ┃ ┃ ┣ 📜ultrasonic.pbi
 ┃ ┃ ┃ ┃ ┃ ┣ 📜ultrasonic.pbi.dep
 ┃ ┃ ┃ ┃ ┃ ┗ 📜ultrasonic.xcl
 ┃ ┃ ┃ ┃ ┣ 📜.ninja_deps
 ┃ ┃ ┃ ┃ ┣ 📜.ninja_log
 ┃ ┃ ┃ ┃ ┣ 📜build.ninja
 ┃ ┃ ┃ ┃ ┣ 📜tempProject.pbd
 ┃ ┃ ┃ ┃ ┣ 📜tempProject.pbd.browse
 ┃ ┃ ┃ ┃ ┣ 📜tempProject.pbw
 ┃ ┃ ┃ ┃ ┣ 📜tempProject_part0.pbi
 ┃ ┃ ┃ ┃ ┣ 📜tempProject_part1.pbi
 ┃ ┃ ┃ ┃ ┣ 📜tempProject_part2.pbi
 ┃ ┃ ┃ ┃ ┣ 📜tempProject_part3.pbi
 ┃ ┃ ┃ ┃ ┣ 📜tempProject_part4.pbi
 ┃ ┃ ┃ ┃ ┗ 📜tempProject_part5.pbi
 ┃ ┃ ┃ ┣ 📂Exe
 ┃ ┃ ┃ ┃ ┣ 📜tempProject.bin
 ┃ ┃ ┃ ┃ ┣ 📜tempProject.out
 ┃ ┃ ┃ ┃ ┗ 📜tempProject.sim
 ┃ ┃ ┃ ┣ 📂List
 ┃ ┃ ┃ ┃ ┣ 📂libraries
 ┃ ┃ ┃ ┃ ┃ ┣ 📂CMSIS
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂DeviceSupport
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📂Startup
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜system_stm32f10x.lst
 ┃ ┃ ┃ ┃ ┃ ┣ 📂DeviceSupport
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂Startup
 ┃ ┃ ┃ ┃ ┃ ┣ 📂LCD
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜touch.lst
 ┃ ┃ ┃ ┃ ┃ ┗ 📂STM32F10x_StdPeriph_Driver_v3.5
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📂inc
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂src
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜misc.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_adc.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_bkp.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_can.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_cec.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_crc.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dac.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dbgmcu.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dma.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_exti.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_flash.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_fsmc.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_gpio.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_i2c.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_iwdg.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_pwr.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rcc.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rtc.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_sdio.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_spi.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_tim.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_usart.lst
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜stm32f10x_wwdg.lst
 ┃ ┃ ┃ ┃ ┣ 📂user
 ┃ ┃ ┃ ┃ ┃ ┣ 📂inc
 ┃ ┃ ┃ ┃ ┃ ┣ 📜DS3231_BUZZER.lst
 ┃ ┃ ┃ ┃ ┃ ┣ 📜main.lst
 ┃ ┃ ┃ ┃ ┃ ┣ 📜moveWheel.lst
 ┃ ┃ ┃ ┃ ┃ ┣ 📜pir.lst
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_it.lst
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stop_button.lst
 ┃ ┃ ┃ ┃ ┃ ┗ 📜ultrasonic.lst
 ┃ ┃ ┃ ┃ ┣ 📜tempProject.log
 ┃ ┃ ┃ ┃ ┗ 📜tempProject.map
 ┃ ┃ ┃ ┣ 📂Obj
 ┃ ┃ ┃ ┃ ┣ 📂libraries
 ┃ ┃ ┃ ┃ ┃ ┣ 📂CMSIS
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂DeviceSupport
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📂Startup
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜startup_stm32f10x_cl.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜system_stm32f10x.o
 ┃ ┃ ┃ ┃ ┃ ┣ 📂DeviceSupport
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂Startup
 ┃ ┃ ┃ ┃ ┃ ┣ 📂LCD
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜lcd.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜touch.o
 ┃ ┃ ┃ ┃ ┃ ┗ 📂STM32F10x_StdPeriph_Driver_v3.5
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📂inc
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂src
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜misc.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_adc.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_bkp.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_can.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_cec.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_crc.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dac.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dbgmcu.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dma.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_exti.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_flash.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_fsmc.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_gpio.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_i2c.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_iwdg.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_pwr.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rcc.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rtc.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_sdio.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_spi.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_tim.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_usart.o
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜stm32f10x_wwdg.o
 ┃ ┃ ┃ ┃ ┗ 📂user
 ┃ ┃ ┃ ┃ ┃ ┣ 📂inc
 ┃ ┃ ┃ ┃ ┃ ┣ 📜DS3231_BUZZER.o
 ┃ ┃ ┃ ┃ ┃ ┣ 📜main.o
 ┃ ┃ ┃ ┃ ┃ ┣ 📜moveWheel.o
 ┃ ┃ ┃ ┃ ┃ ┣ 📜pir.o
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_it.o
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stop_button.o
 ┃ ┃ ┃ ┃ ┃ ┗ 📜ultrasonic.o
 ┃ ┃ ┃ ┣ 📜.ninja_deps
 ┃ ┃ ┃ ┗ 📜.ninja_log
 ┃ ┃ ┣ 📂Libraries
 ┃ ┃ ┃ ┣ 📂CMSIS
 ┃ ┃ ┃ ┃ ┗ 📂DeviceSupport
 ┃ ┃ ┃ ┃ ┃ ┣ 📂Startup
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜startup_stm32f10x_cl.s
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜system_stm32f10x.c
 ┃ ┃ ┃ ┃ ┃ ┗ 📜system_stm32f10x.h
 ┃ ┃ ┃ ┣ 📂LCD
 ┃ ┃ ┃ ┃ ┣ 📜font.h
 ┃ ┃ ┃ ┃ ┣ 📜lcd.c
 ┃ ┃ ┃ ┃ ┣ 📜lcd.h
 ┃ ┃ ┃ ┃ ┣ 📜touch.c
 ┃ ┃ ┃ ┃ ┗ 📜touch.h
 ┃ ┃ ┃ ┗ 📂STM32F10x_StdPeriph_Driver_v3.5
 ┃ ┃ ┃ ┃ ┣ 📂inc
 ┃ ┃ ┃ ┃ ┃ ┣ 📜misc.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_adc.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_bkp.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_can.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_cec.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_crc.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dac.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dbgmcu.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dma.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_exti.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_flash.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_fsmc.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_gpio.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_i2c.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_iwdg.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_pwr.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rcc.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rtc.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_sdio.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_spi.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_tim.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_usart.h
 ┃ ┃ ┃ ┃ ┃ ┗ 📜stm32f10x_wwdg.h
 ┃ ┃ ┃ ┃ ┗ 📂src
 ┃ ┃ ┃ ┃ ┃ ┣ 📜misc.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_adc.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_bkp.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_can.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_cec.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_crc.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dac.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dbgmcu.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dma.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_exti.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_flash.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_fsmc.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_gpio.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_i2c.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_iwdg.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_pwr.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rcc.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rtc.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_sdio.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_spi.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_tim.c
 ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_usart.c
 ┃ ┃ ┃ ┃ ┃ ┗ 📜stm32f10x_wwdg.c
 ┃ ┃ ┣ 📂PSU_DB
 ┃ ┃ ┃ ┣ 📂Boards
 ┃ ┃ ┃ ┃ ┗ 📂PSU
 ┃ ┃ ┃ ┃ ┃ ┗ 📂STM32F107VCT6
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜dtsl_config_script.py
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜flash.xml
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜project_types.xml
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜STM32F107VCT6.rvc
 ┃ ┃ ┃ ┣ 📂Flash
 ┃ ┃ ┃ ┃ ┣ 📂Algorithms
 ┃ ┃ ┃ ┃ ┃ ┣ 📜STM32F10x_CL.FLM
 ┃ ┃ ┃ ┃ ┃ ┗ 📜STM32F10x_OPT.FLM
 ┃ ┃ ┃ ┃ ┣ 📜keil_flash.py
 ┃ ┃ ┃ ┃ ┣ 📜STM32F107VCT6_flash.py
 ┃ ┃ ┃ ┃ ┗ 📜stm32_setup.py
 ┃ ┃ ┃ ┗ 📜STM32F107VCT6.rvc
 ┃ ┃ ┣ 📂settings
 ┃ ┃ ┃ ┣ 📜Running_Alarm.wsdt
 ┃ ┃ ┃ ┣ 📜tempProject.crun
 ┃ ┃ ┃ ┣ 📜tempProject.dbgdt
 ┃ ┃ ┃ ┣ 📜tempProject.Debug.cspy.bat
 ┃ ┃ ┃ ┣ 📜tempProject.Debug.cspy.ps1
 ┃ ┃ ┃ ┣ 📜tempProject.Debug.driver.xcl
 ┃ ┃ ┃ ┣ 📜tempProject.Debug.general.xcl
 ┃ ┃ ┃ ┣ 📜tempProject.dnx
 ┃ ┃ ┃ ┣ 📜tempProject_Debug.jlink
 ┃ ┃ ┃ ┗ 📜test1.wsdt
 ┃ ┃ ┣ 📂user
 ┃ ┃ ┃ ┣ 📂inc
 ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_conf.h
 ┃ ┃ ┃ ┃ ┗ 📜stm32f10x_it.h
 ┃ ┃ ┃ ┣ 📜bluetooth.h
 ┃ ┃ ┃ ┣ 📜DS3231_BUZZER.c
 ┃ ┃ ┃ ┣ 📜DS3231_BUZZER.h
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜MFC45741B7A.tmp
 ┃ ┃ ┃ ┣ 📜moveWheel.c
 ┃ ┃ ┃ ┣ 📜moveWheel.h
 ┃ ┃ ┃ ┣ 📜pir.c
 ┃ ┃ ┃ ┣ 📜pir.h
 ┃ ┃ ┃ ┣ 📜stm32f10x_it.c
 ┃ ┃ ┃ ┣ 📜stop_button.c
 ┃ ┃ ┃ ┣ 📜stop_button.h
 ┃ ┃ ┃ ┣ 📜ultrasonic.c
 ┃ ┃ ┃ ┗ 📜ultrasonic.h
 ┃ ┃ ┣ 📜finalCode.zip
 ┃ ┃ ┣ 📜Running_Alarm.eww
 ┃ ┃ ┣ 📜tempProject.dep
 ┃ ┃ ┣ 📜tempProject.ewd
 ┃ ┃ ┣ 📜tempProject.ewp
 ┃ ┃ ┗ 📜tempProject.ewt
 ┃ ┣ 📂동작 및 완성 모습
 ┃ ┃ ┣ 📜1.jpg
 ┃ ┃ ┣ 📜2.jpg
 ┃ ┃ ┣ 📜3.jpg
 ┃ ┃ ┣ 📜4.jpg
 ┃ ┃ ┣ 📜Alarm Off.mp4
 ┃ ┃ ┣ 📜Alarm On.mp4
 ┃ ┃ ┗ 📜Alarm Set.mp4
 ┃ ┣ 📜README.md
 ┃ ┣ 📜팀프로젝트 제안서.pdf
 ┃ ┗ 📜팀프로젝트_완료보고서_8조.pdf
 ┣ 📂강의자료 및 미션지
 ┃ ┣ 📂10주차 강의자료
 ┃ ┃ ┣ 📜10주차 강의 자료.pdf
 ┃ ┃ ┣ 📜10주차 화요일 분반 미션지.docx
 ┃ ┃ ┗ 📜clock tree.png
 ┃ ┣ 📂11주차 강의자료
 ┃ ┃ ┣ 📜11주차 강의자료.pdf
 ┃ ┃ ┗ 📜11주차 화요일 분반 미션지.docx
 ┃ ┣ 📂3주차 강의자료
 ┃ ┃ ┣ 📂실험제공자료
 ┃ ┃ ┃ ┣ 📂코드파일
 ┃ ┃ ┃ ┃ ┣ 📂CoreSupport
 ┃ ┃ ┃ ┃ ┃ ┣ 📜core_cm3.c
 ┃ ┃ ┃ ┃ ┃ ┗ 📜core_cm3.h
 ┃ ┃ ┃ ┃ ┣ 📂Libraries
 ┃ ┃ ┃ ┃ ┃ ┣ 📂CMSIS
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂DeviceSupport
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📂Startup
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜startup_stm32f10x_cl.s
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜system_stm32f10x.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜system_stm32f10x.h
 ┃ ┃ ┃ ┃ ┃ ┗ 📂STM32F10x_StdPeriph_Driver_v3.5
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📂inc
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜misc.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_adc.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_bkp.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_can.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_cec.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_crc.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dac.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dbgmcu.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dma.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_exti.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_flash.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_fsmc.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_gpio.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_i2c.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_iwdg.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_pwr.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rcc.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rtc.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_sdio.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_spi.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_tim.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_usart.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜stm32f10x_wwdg.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂src
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜misc.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_adc.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_bkp.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_can.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_cec.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_crc.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dac.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dbgmcu.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_dma.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_exti.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_flash.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_fsmc.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_gpio.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_i2c.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_iwdg.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_pwr.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rcc.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_rtc.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_sdio.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_spi.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_tim.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_usart.c
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜stm32f10x_wwdg.c
 ┃ ┃ ┃ ┃ ┣ 📂PSU_DB
 ┃ ┃ ┃ ┃ ┃ ┣ 📂Boards
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂PSU
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📂STM32F107VCT6
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜dtsl_config_script.py
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜flash.xml
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜project_types.xml
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜STM32F107VCT6.rvc
 ┃ ┃ ┃ ┃ ┃ ┣ 📂Flash
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📂Algorithms
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜STM32F10x_CL.FLM
 ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜STM32F10x_OPT.FLM
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜keil_flash.py
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜STM32F107VCT6_flash.py
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜stm32_setup.py
 ┃ ┃ ┃ ┃ ┃ ┗ 📜STM32F107VCT6.rvc
 ┃ ┃ ┃ ┃ ┗ 📂user
 ┃ ┃ ┃ ┃ ┃ ┣ 📂inc
 ┃ ┃ ┃ ┃ ┃ ┃ ┣ 📜stm32f10x_conf.h
 ┃ ┃ ┃ ┃ ┃ ┃ ┗ 📜stm32f10x_it.h
 ┃ ┃ ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┃ ┃ ┗ 📜stm32f10x_it.c
 ┃ ┃ ┃ ┣ 📜STM32F107VCT6_schematic.pdf
 ┃ ┃ ┃ ┣ 📜stm32_Datasheet.pdf
 ┃ ┃ ┃ ┗ 📜stm32_ReferenceManual.pdf
 ┃ ┃ ┗ 📜3주차 수업 자료.pdf
 ┃ ┣ 📂4주차 강의자료
 ┃ ┃ ┣ 📜4주차 수업 자료.pdf
 ┃ ┃ ┣ 📜4주차 실험 미션지.docx
 ┃ ┃ ┗ 📜myicf.icf
 ┃ ┣ 📂5주차 강의자료
 ┃ ┃ ┣ 📜5주차 강의 자료.pdf
 ┃ ┃ ┣ 📜5주차 미션_화요일분반.docx
 ┃ ┃ ┣ 📜clock tree.png
 ┃ ┃ ┗ 📜tue_week05_template.c
 ┃ ┣ 📂6주차 강의자료
 ┃ ┃ ┣ 📜6주차 강의자료.pdf
 ┃ ┃ ┣ 📜6주차 미션_화요일분반.docx
 ┃ ┃ ┗ 📜week6_template.c
 ┃ ┣ 📂7주차 강의자료
 ┃ ┃ ┣ 📂FB755AC manual
 ┃ ┃ ┃ ┣ 📜AppendixA_Kor.pdf
 ┃ ┃ ┃ ┣ 📜AppendixB_Kor.pdf
 ┃ ┃ ┃ ┣ 📜AppendixC_Kor.pdf
 ┃ ┃ ┃ ┗ 📜FB755_UserGuide_Kor.pdf
 ┃ ┃ ┣ 📜7주차 강의 자료.pdf
 ┃ ┃ ┗ 📜7주차 미션_화요일분반.docx
 ┃ ┗ 📂9주차 강의자료
 ┃ ┃ ┣ 📜9주차 강의 자료.pdf
 ┃ ┃ ┣ 📜9주차 미션지.docx
 ┃ ┃ ┗ 📜LCD_Timing_Diagram.PNG
 ┗ 📜README.md
 ```
