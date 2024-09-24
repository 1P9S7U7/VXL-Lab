/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void  display7SEG(int num){
	int SMap[10] = {
	        0b00111111, // 0
	        0b00000110, // 1
	        0b01011011, // 2
	        0b01001111, // 3
	        0b01100110, // 4
	        0b01101101, // 5
	        0b01111101, // 6
	        0b00000111, // 7
	        0b01111111, // 8
	        0b01101111  // 9
	    };
	    if (num < 0 || num > 9) {
	        return;
	    }
	    int segments = SMap[num];
	    HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, (segments & 0b00000001) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, (segments & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, (segments & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, (segments & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, (segments & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, (segments & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, (segments & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	}
void  display7SEG1(int num){
	int SMap[10] = {
	        0b00111111, // 0
	        0b00000110, // 1
	        0b01011011, // 2
	        0b01001111, // 3
	        0b01100110, // 4
	        0b01101101, // 5
	        0b01111101, // 6
	        0b00000111, // 7
	        0b01111111, // 8
	        0b01101111  // 9
	    };
	    if (num < 0 || num > 9) {
	        return;
	    }
	    int segments = SMap[num];
	    HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, (segments & 0b00000001) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S8_GPIO_Port, S8_Pin, (segments & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S9_GPIO_Port, S9_Pin, (segments & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S10_GPIO_Port, S10_Pin, (segments & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S11_GPIO_Port, S11_Pin, (segments & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S12_GPIO_Port, S12_Pin, (segments & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	    HAL_GPIO_WritePin(S13_GPIO_Port, S13_Pin, (segments & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	}
void clearAllClock(){
	HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, GPIO_PIN_RESET);
    }
void  setNumberOnClock(int num){
	switch (num){
	case 0:
		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
				break;
	case 3:
		HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
				break;
	case 4:
		HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_SET);
				break;
	case 5:
		HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_SET);
				break;
	case 6:
		HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
				break;
	case 7:
		HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_SET);
				break;
	case 8:
		HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_SET);
				break;
	case 9:
		HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_SET);
				break;
	case 10:
		HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_SET);
				break;
	case 11:
		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
				break;
	}
}
void clearNumberOnClock(int num){
	switch (num){
		case 0:
			HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
					break;
		case 2:
			HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
					break;
		case 3:
			HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
					break;
		case 4:
			HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
					break;
		case 5:
			HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
					break;
		case 6:
			HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_RESET);
					break;
		case 7:
			HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_RESET);
					break;
		case 8:
			HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_RESET);
					break;
		case 9:
			HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_RESET);
					break;
		case 10:
			HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_RESET);
					break;
		case 11:
			HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
					break;
        }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  int state = 0;
  int lastTime = HAL_GetTick();
  int cnt = 0;
  int cnt1 = 0;
  while (1)
  {
      int curTime = HAL_GetTick();
      int Time = curTime - lastTime;

      switch (state)
      {
          case 0: // Đèn đỏ sáng 5 giây
              HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, GPIO_PIN_RESET);
              cnt = (5000 - Time) / 1000;
              cnt1 = (3000 - Time)/1000;
              display7SEG(cnt+1);
              display7SEG(cnt1+1);
              if (Time >= 3000)
              {
                  state = 1;
                  lastTime = curTime;
              }
              break;
          case 1: // đỏ sáng, xanh tắt, vàng sáng
        	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, GPIO_PIN_RESET);
        	  cnt = (2000 - Time) / 1000;
        	  cnt1 = (2000- Time)/ 100;
        	  display7SEG(cnt+1);
        	  if (Time >= 2000)
        	  {
        	     state = 2;
        	     lastTime = curTime;
        	   }
        	   break;
          case 2: // ĐỎ TẮT, XANH SÁNG, ĐỎ SÁNG
              HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, GPIO_PIN_RESET);
              cnt = (3000 - Time) / 1000;
              display7SEG(cnt+1);
              if (Time >= 3000)
              {
                  state = 3;
                  lastTime = curTime;
              }
              break;

          case 3: // ĐỎ TẮT, XANH TẮT, VÀNG SÁNG, ĐỎ BẬT
              HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_SET);
              HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, GPIO_PIN_SET);
              cnt = (2000 - Time) / 1000;
              display7SEG(cnt+1);
              if (Time >= 2000)
              {
                  state = 0;
                  lastTime = curTime;
              }
              break;
      }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|S0_Pin
                          |S1_Pin|S2_Pin|S3_Pin|S4_Pin
                          |S5_Pin|S6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, L1_Pin|L2_Pin|L3_Pin|L11_Pin
                          |L12_Pin|L4_Pin|L5_Pin|L6_Pin
                          |L7_Pin|L8_Pin|L9_Pin|L10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin S0_Pin
                           S1_Pin S2_Pin S3_Pin S4_Pin
                           S5_Pin S6_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|S0_Pin
                          |S1_Pin|S2_Pin|S3_Pin|S4_Pin
                          |S5_Pin|S6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : L1_Pin L2_Pin L3_Pin L11_Pin
                           L12_Pin L4_Pin L5_Pin L6_Pin
                           L7_Pin L8_Pin L9_Pin L10_Pin */
  GPIO_InitStruct.Pin = L1_Pin|L2_Pin|L3_Pin|L11_Pin
                          |L12_Pin|L4_Pin|L5_Pin|L6_Pin
                          |L7_Pin|L8_Pin|L9_Pin|L10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
