/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define S7_Pin GPIO_PIN_1
#define S7_GPIO_Port GPIOA
#define ENM0_Pin GPIO_PIN_2
#define ENM0_GPIO_Port GPIOA
#define ENM1_Pin GPIO_PIN_3
#define ENM1_GPIO_Port GPIOA
#define DOT_Pin GPIO_PIN_4
#define DOT_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_6
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_7
#define EN1_GPIO_Port GPIOA
#define S0_Pin GPIO_PIN_0
#define S0_GPIO_Port GPIOB
#define S1_Pin GPIO_PIN_1
#define S1_GPIO_Port GPIOB
#define S2_Pin GPIO_PIN_2
#define S2_GPIO_Port GPIOB
#define L11_Pin GPIO_PIN_10
#define L11_GPIO_Port GPIOB
#define L12_Pin GPIO_PIN_11
#define L12_GPIO_Port GPIOB
#define S11_Pin GPIO_PIN_13
#define S11_GPIO_Port GPIOB
#define S12_Pin GPIO_PIN_14
#define S12_GPIO_Port GPIOB
#define S13_Pin GPIO_PIN_15
#define S13_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_8
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_9
#define EN3_GPIO_Port GPIOA
#define ENM2_Pin GPIO_PIN_10
#define ENM2_GPIO_Port GPIOA
#define ENM3_Pin GPIO_PIN_11
#define ENM3_GPIO_Port GPIOA
#define ENM4_Pin GPIO_PIN_12
#define ENM4_GPIO_Port GPIOA
#define ENM5_Pin GPIO_PIN_13
#define ENM5_GPIO_Port GPIOA
#define ENM6_Pin GPIO_PIN_14
#define ENM6_GPIO_Port GPIOA
#define ENM7_Pin GPIO_PIN_15
#define ENM7_GPIO_Port GPIOA
#define S3_Pin GPIO_PIN_3
#define S3_GPIO_Port GPIOB
#define S4_Pin GPIO_PIN_4
#define S4_GPIO_Port GPIOB
#define S5_Pin GPIO_PIN_5
#define S5_GPIO_Port GPIOB
#define S6_Pin GPIO_PIN_6
#define S6_GPIO_Port GPIOB
#define L8_Pin GPIO_PIN_7
#define L8_GPIO_Port GPIOB
#define L9_Pin GPIO_PIN_8
#define L9_GPIO_Port GPIOB
#define L10_Pin GPIO_PIN_9
#define L10_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
