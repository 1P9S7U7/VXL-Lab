/*
 * button.c
 *
 *  Created on: Dec 1, 2024
 *      Author: ASUS
 */

#include "button.h"
#include "process.h"
#include "software_timer.h"
#include "main.h"

#define NUM_BUTTONS 3
uint8_t KeyReg0[NUM_BUTTONS];
uint8_t KeyReg1[NUM_BUTTONS];
uint8_t KeyReg2[NUM_BUTTONS];
uint8_t KeyReg3[NUM_BUTTONS];
uint16_t TimeForKeyPress[NUM_BUTTONS];

GPIO_TypeDef *ButtonPorts[NUM_BUTTONS] = { BUTTON_1_GPIO_Port,
		BUTTON_2_GPIO_Port, BUTTON_3_GPIO_Port };
uint16_t ButtonPins[NUM_BUTTONS] = { BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin };

int Red = 5;
int Yellow = 2;
int Green = 3;
static int BT_flag = 0;

void Process() {
	static int currentMode = 1;  // Mặc định là Mode 1
	static int timeRed = 5, timeGreen = 3, timeYellow = 2; // Thời gian ban đầu
	static int num = 1;
	// Kiểm tra giá trị của BT_flag và thực hiện các hành động
	switch (BT_flag) {
	case 1:  // Nút 1: Chuyển mode
		currentMode++;  // Chuyển mode
		if (currentMode > 4)
			currentMode = 1; // Nếu vượt quá Mode 4, quay lại Mode 1
		BT_flag = 0; // Reset BT_flag
		break;

	case 2:  // Nút 2: Tăng giá trị thời gian đèn
		num++;
		if (num > 99) {
			num = 1;
		}
		BT_flag = 0; // Reset BT_flag
		break;
	case 3:  // Nút 3: Xác nhận và quay lại Mode 1
		if (currentMode == 2) {
			if (num >= timeGreen + timeYellow) {
				timeRed = num;
				num = 1;
			}
		}
		if (currentMode == 3) {
			if (num <= timeRed + timeYellow) {
				timeGreen = num;
				num = 1;
			}
		}
		if (currentMode == 4) {
			if (num <= timeRed + timeGreen) {
				num = timeYellow;
				num = 1;
			}
		}
		currentMode = 1;// Quay lại Mode 1
		BT_flag = 0; // Reset BT_flag
		break;

	default:
		break;
	}

	// Chạy chế độ tương ứng với mode hiện tại
	switch (currentMode) {
	case 1: // Mode 1: Chế độ bình thường
		Mode1(timeRed, timeGreen, timeYellow);
		break;

	case 2: // Mode 2: Chỉnh thời gian đèn đỏ
		Mode2(num);
		break;

	case 3: // Mode 3: Chỉnh thời gian đèn xanh
		Mode3(num);
		break;

	case 4: // Mode 4: Chỉnh thời gian đèn vàng
		Mode4(num);
		break;

	default:
		break;
	}
}
void getKeyInput() {
	for (int i = 0; i < NUM_BUTTONS; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(ButtonPorts[i], ButtonPins[i]);
		if (KeyReg0[i] == KeyReg1[i] && KeyReg1[i] == KeyReg2[i]) {
			if (KeyReg3[i] != KeyReg2[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE) {
					BT_flag = i + 1;
					TimeForKeyPress[i] = 200;
				} else {
					TimeForKeyPress[i]--;
					if (TimeForKeyPress[i] == 0) {
						KeyReg3[i] = NORMAL_STATE;
					}
				}
			}
		}
	}
}

