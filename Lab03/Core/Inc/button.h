/*
 * button.h
 *
 *  Created on: Dec 1, 2024
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

// Định nghĩa enum trạng thái


// Biến trạng thái toàn cục (extern)

int Red, Green, Yellow;

void Process() ;
void getKeyInput();

#endif /* INC_BUTTON_H_ */
