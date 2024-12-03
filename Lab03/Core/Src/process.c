/*
 * process.c
 *
 *  Created on: Dec 1, 2024
 *      Author: ASUS
 */

#include "process.h"
#include "main.h"
#include "software_timer.h"

void display7SEG(int num) {
	int SMap[10] = { 0b00111111, // 0
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
	HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin,
			(segments & 0b00000001) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin,
			(segments & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin,
			(segments & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin,
			(segments & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin,
			(segments & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin,
			(segments & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin,
			(segments & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void display7SEG1(int num) {
	int SMap[10] = { 0b00111111, // 0
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
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin,
			(segments & 0b00000001) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin,
			(segments & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin,
			(segments & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin,
			(segments & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin,
			(segments & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin,
			(segments & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin,
			(segments & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void update7SEG(int x, int index, int num) {
	switch (index) {
	case 1:
		if (x) {
			HAL_GPIO_WritePin( EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			display7SEG(num < 10 ? num : num % 10);
		} else {
			HAL_GPIO_WritePin( EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			display7SEG(num < 10 ? 0 : num / 10);
		}
		break;
	case 2:
		if (x) {
			HAL_GPIO_WritePin( EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			display7SEG1(num < 10 ? num : num % 10);
		} else {
			HAL_GPIO_WritePin( EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			display7SEG1(num < 10 ? 0 : num / 10);
		}
		break;
	default:
		break;
	}
}

void SetLight1(int color){
	switch (color){
	//đỏ sáng
	case 1:
		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, SET);
		HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, RESET);
		HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, RESET);
		break;
	//xanh lá sáng
	case 2:
		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, RESET);
		HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, RESET);
		HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, SET);
		break;
		//vàng sáng
	case 3:
		HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, RESET);
		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, RESET);
		HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, SET);
		break;
	default:
		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, RESET);
		HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, RESET);
		HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, RESET);
		break;
	}
}
void SetLight2(int color){
	switch (color){
	//đỏ sáng
		case 1:
			HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, SET);
			HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, RESET);
			HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, RESET);
			break;
			//xanh lá sáng
		case 2:
			HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, RESET);
			HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, RESET);
			HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, SET);
			break;
			//vàng sáng
		case 3:
			HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, RESET);
			HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, RESET);
			HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, SET);
			break;
		default:
			HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, RESET);
			HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, RESET);
			HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, RESET);
			break;
	}
}

void Mode1(int Red, int Green, int Yellow) {
	// biến time1 cho cụm đèn 1, time2 cho cụm đèn 2
	static int time1 = 1, time2 = 1;
	// 2 biến light tương đương với trạng thái đèn đỏ, xanh, vàng của 2 cặp đèn giao thông
	static int light1 = 0, light2 = 0;
	//biến x quyết định đèn 7 đoạn nào sẽ sáng cho mỗi cặp led 7 đoạn
	static int x = 0;
	if(timer3_flag){
		x = 1 - x;
		setTimer3(500);
	}
	if (timer1_flag) {
		time1--;time2--;
		if (time1 == 0) {
			switch (light1) {
			case 1:
				light1 = 2;
				time1 = Green;
				break;
			case 2:
				light1 = 3;
				time1 = Yellow;
				break;
			case 3:
				light1 = 1;
				time1 = Red;
				break;
			default:
				time1 = Red;
				light1 = 1;
				break;
			}
		}
		if (time2 == 0) {
			switch (light2) {
			case 1:
				light2 = 2;
				time2 = Green;
				break;
			case 2:
				light2 = 3;
				time2 = Yellow;
				break;
			case 3:
				light2 = 1;
				time2 = Red;
				break;
			default:
				time2 = Green;
				light2 = 2;
				break;
			}

		}
		setTimer1(1000);
	}

	update7SEG(x, 1, time1);
	update7SEG(x, 2, time2);
	SetLight1(light1);
	SetLight2(light2);
}
//chỉnh đèn đỏ
//tất cả đèn đỏ nhấp nháy tần số 2Hz
//2 led 7 đoạn hiển thị số
//biến n để led 7 đoạn hiển thị
void Mode2(int Red) {
	static int x = 0;
	//tất cả đèn đỏ nhấp nháy
	HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, RESET);
	HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, RESET);
	HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, RESET);
	HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, RESET);
	if (timer2_flag) {
		HAL_GPIO_TogglePin(L4_GPIO_Port, L4_Pin);
		HAL_GPIO_TogglePin(L1_GPIO_Port, L1_Pin);
		x = 1 - x;
		setTimer2(500);
	}
	update7SEG(x, 1, 2);
	update7SEG(x, 2, Red);

}
//chỉnh đèn xanh lá
void Mode3(int Green) {
	//tất cả đèn xanh nhấp nháy
	static int x = 0;
	HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, RESET);
	HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, RESET);
	HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, RESET);
	HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, RESET);
	if (timer2_flag == 1) {
		HAL_GPIO_TogglePin(L3_GPIO_Port, L3_Pin);
		HAL_GPIO_TogglePin(L6_GPIO_Port, L6_Pin);
		x = 1 - x;
		setTimer2(500);
	}
	//2 đèn led hiển thị số 0 2
	//2 đèn led hiển thị số giây xanh lá
		update7SEG(x, 1, 3);
		update7SEG(x, 2, Green);

}
//chỉnh đèn vàng
void Mode4(int Yellow) {
	static int x = 0;
	HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, RESET);
	HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, RESET);
	HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, RESET);
	HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, RESET);
	if (timer2_flag == 1) {
		HAL_GPIO_TogglePin(L2_GPIO_Port, L2_Pin);
		HAL_GPIO_TogglePin(L5_GPIO_Port, L5_Pin);
		x = 1 - x;
		setTimer2(500);
	}
	//2 đèn led hiển thị số 0 2
	//2 đèn led hiển thị số giây vàng

	update7SEG(x, 1, 4);
	update7SEG(x, 2, Yellow);
}

