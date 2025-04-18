/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <system_stm32f4xx.h>
#include <stdint.h>
#include <timer.h>
#include <ucglib.h>

static ucg_t ucg;


int main(void)
{
		SystemCoreClockUpdate();        // cấp clock
	    TimerInit();                    // để khởi tạo chức năng timer.

	    // Khởi tạo LCD
	    Ucglib4WireSWSPI_begin(&ucg, UCG_FONT_MODE_SOLID);
	    ucg_ClearScreen(&ucg);

	    ucg_SetFont(&ucg, ucg_font_helvR08_hr);         // lựa chọn font chữ và cỡ chữ
	    ucg_SetColor(&ucg, 0, 0, 255, 0);           // chọn màu chữ là màu trắng
	    ucg_SetColor(&ucg, 1, 0, 0, 0);                 // màu background là màu đen
	    ucg_SetRotate180(&ucg);      // quay màn hình lại 180 độ

	    int screen_width = ucg_GetWidth(&ucg);  // Đảm bảo rằng ucg đã được khởi tạo
	    int screen_height = ucg_GetHeight(&ucg);

	    int x1 = screen_width - ucg_GetStrWidth(&ucg, "Nhom 6-TTCS");
	    int y1 = screen_height;

	    ucg_DrawString(&ucg, x1, y1, 0, "Nhom 6-TTCS");

	    /* Loop forever */
	    while(1)
	    {
	        processTimerScheduler();
	    }
	}

