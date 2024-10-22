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
#include "software_timer.h"
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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
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
const int MAX_LED = 4;
 int index_led = 0;
 void update7SEG (int index, int num) {
      switch ( index ) {
        case 0:
          // Display the first 7 SEG with led_buffer [0]
     	   HAL_GPIO_WritePin ( EN1_GPIO_Port , EN1_Pin, GPIO_PIN_SET);
     	   HAL_GPIO_WritePin ( EN2_GPIO_Port , EN2_Pin, GPIO_PIN_SET);
     	   HAL_GPIO_WritePin ( EN3_GPIO_Port , EN3_Pin, GPIO_PIN_SET);
     	   display7SEG(num);
     	   HAL_GPIO_WritePin ( EN0_GPIO_Port , EN0_Pin, GPIO_PIN_RESET);
          break ;
        case 1:
          // Display the second 7 SEG with led_buffer [1]
     	   HAL_GPIO_WritePin ( EN0_GPIO_Port , EN0_Pin, GPIO_PIN_SET);
     	   HAL_GPIO_WritePin ( EN2_GPIO_Port , EN2_Pin, GPIO_PIN_SET);
     	   HAL_GPIO_WritePin ( EN3_GPIO_Port , EN3_Pin, GPIO_PIN_SET);
       	   display7SEG(num);
        	   HAL_GPIO_WritePin ( EN1_GPIO_Port , EN1_Pin, GPIO_PIN_RESET);
          break ;
        case 2:
          // Display the third 7 SEG with led_buffer [2]
     	   HAL_GPIO_WritePin ( EN1_GPIO_Port , EN1_Pin, GPIO_PIN_SET);
        	   HAL_GPIO_WritePin ( EN0_GPIO_Port , EN0_Pin, GPIO_PIN_SET);
        	   HAL_GPIO_WritePin ( EN3_GPIO_Port , EN3_Pin, GPIO_PIN_SET);
        	   display7SEG(num);
        	   HAL_GPIO_WritePin ( EN2_GPIO_Port , EN2_Pin, GPIO_PIN_RESET);
          break ;
        case 3:
          // Display the forth 7 SEG with led_buffer [3]
     	   HAL_GPIO_WritePin ( EN1_GPIO_Port , EN1_Pin, GPIO_PIN_SET);
        	   HAL_GPIO_WritePin ( EN2_GPIO_Port , EN2_Pin, GPIO_PIN_SET);
        	   HAL_GPIO_WritePin ( EN0_GPIO_Port , EN0_Pin, GPIO_PIN_SET);
        	   display7SEG(num);
        	   HAL_GPIO_WritePin ( EN3_GPIO_Port , EN3_Pin, GPIO_PIN_RESET);
          break ;
        default :
          break ;
       }
  }
 int counter = 200;
 int cnt = 100;
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
  MX_GPIO_Init () ;
  MX_TIM2_Init () ;
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 ) ;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int hour = 15 , minute = 8 , second = 50;
  setTimer1(100);
  setTimer2(50);
  void updateClockBuffer (){
	  if(timer1_flag == 1){
		  setTimer1(100);
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		  index_led++;
		  if(index_led > 3){
			  index_led = 0;
		  }
	  }
	  switch (index_led){
	  case 0:
		  if(hour<10){
			  update7SEG (0, 0);
		  }
		  if(hour>=10){
			  update7SEG (0, hour/10);
		  }
		  break;
	  case 1:
		  update7SEG (1, hour%10);
		  break;
	  case 2:
		  if(minute<10){
			  update7SEG (2, 0);
		  }
		  if(minute>=10){
			  update7SEG (2, minute/10);
		  }
		  break;
	  case 3:
		  update7SEG (3, minute%10);
	      break;
	  default:
	      break;
	  }
   }
  while (1)
  {
	  if(timer2_flag == 1){
		  setTimer2(50);
	      second ++;
	  }
	  if ( second >= 60) {
		  second = 0;
	      minute ++;
	  }
	  if( minute >= 60) {
	      minute = 0;
	      hour ++;
	  }
	  if( hour >=24) {
	      hour = 0;
	  }
	  updateClockBuffer ();
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
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

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
  HAL_GPIO_WritePin(GPIOA, S7_Pin|ENM0_Pin|ENM1_Pin|DOT_Pin
                          |LED_RED_Pin|EN0_Pin|EN1_Pin|EN2_Pin
                          |EN3_Pin|ENM2_Pin|ENM3_Pin|ENM4_Pin
                          |ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, S0_Pin|S1_Pin|S2_Pin|L11_Pin
                          |L12_Pin|S11_Pin|S12_Pin|S13_Pin
                          |S3_Pin|S4_Pin|S5_Pin|S6_Pin
                          |L8_Pin|L9_Pin|L10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : S7_Pin ENM0_Pin ENM1_Pin DOT_Pin
                           LED_RED_Pin EN0_Pin EN1_Pin EN2_Pin
                           EN3_Pin ENM2_Pin ENM3_Pin ENM4_Pin
                           ENM5_Pin ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = S7_Pin|ENM0_Pin|ENM1_Pin|DOT_Pin
                          |LED_RED_Pin|EN0_Pin|EN1_Pin|EN2_Pin
                          |EN3_Pin|ENM2_Pin|ENM3_Pin|ENM4_Pin
                          |ENM5_Pin|ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : S0_Pin S1_Pin S2_Pin L11_Pin
                           L12_Pin S11_Pin S12_Pin S13_Pin
                           S3_Pin S4_Pin S5_Pin S6_Pin
                           L8_Pin L9_Pin L10_Pin */
  GPIO_InitStruct.Pin = S0_Pin|S1_Pin|S2_Pin|L11_Pin
                          |L12_Pin|S11_Pin|S12_Pin|S13_Pin
                          |S3_Pin|S4_Pin|S5_Pin|S6_Pin
                          |L8_Pin|L9_Pin|L10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
 {
   timerRun();
}
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
