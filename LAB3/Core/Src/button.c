/*
 * button.c
 *
 *  Created on: Nov 5, 2024
 *      Author: ASUS
 */
#include "button.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int TimeForKeyPress = 200;

void subKeyProcess(){

}

void getKeyInput(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	if(KeyReg0 == KeyReg1 && KeyReg1 == KeyReg2){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				subKeyProcess();
				TimeForKeyPress = 200;
			} else{
				TimeForKeyPress--;
				if(TimeForKeyPress == 0){
					KeyReg3 = NORMAL_STATE;
				}
			}
		}
	}
}

