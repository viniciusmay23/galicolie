
_Screen_App:

;SCREEN_APP.C,1 :: 		void Screen_App()
;SCREEN_APP.C,5 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;SCREEN_APP.C,6 :: 		lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;SCREEN_APP.C,8 :: 		for(ucX=0; ucX<1; ucX++)
	CLRF        Screen_App_ucX_L0+0 
L_Screen_App0:
	MOVLW       1
	SUBWF       Screen_App_ucX_L0+0, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_Screen_App1
;SCREEN_APP.C,10 :: 		Lcd_Out(2,4,"Body Health BR");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       4
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_SCREEN_APP+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_SCREEN_APP+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;SCREEN_APP.C,11 :: 		delay_ms(800);
	MOVLW       21
	MOVWF       R11, 0
	MOVLW       75
	MOVWF       R12, 0
	MOVLW       190
	MOVWF       R13, 0
L_Screen_App3:
	DECFSZ      R13, 1, 1
	BRA         L_Screen_App3
	DECFSZ      R12, 1, 1
	BRA         L_Screen_App3
	DECFSZ      R11, 1, 1
	BRA         L_Screen_App3
	NOP
;SCREEN_APP.C,12 :: 		Lcd_Cmd(_LCD_TURN_OFF);
	MOVLW       8
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;SCREEN_APP.C,13 :: 		delay_ms(800);
	MOVLW       21
	MOVWF       R11, 0
	MOVLW       75
	MOVWF       R12, 0
	MOVLW       190
	MOVWF       R13, 0
L_Screen_App4:
	DECFSZ      R13, 1, 1
	BRA         L_Screen_App4
	DECFSZ      R12, 1, 1
	BRA         L_Screen_App4
	DECFSZ      R11, 1, 1
	BRA         L_Screen_App4
	NOP
;SCREEN_APP.C,14 :: 		Lcd_Cmd(_LCD_TURN_ON);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;SCREEN_APP.C,8 :: 		for(ucX=0; ucX<1; ucX++)
	INCF        Screen_App_ucX_L0+0, 1 
;SCREEN_APP.C,15 :: 		}
	GOTO        L_Screen_App0
L_Screen_App1:
;SCREEN_APP.C,16 :: 		delay_ms(1200);
	MOVLW       31
	MOVWF       R11, 0
	MOVLW       113
	MOVWF       R12, 0
	MOVLW       30
	MOVWF       R13, 0
L_Screen_App5:
	DECFSZ      R13, 1, 1
	BRA         L_Screen_App5
	DECFSZ      R12, 1, 1
	BRA         L_Screen_App5
	DECFSZ      R11, 1, 1
	BRA         L_Screen_App5
	NOP
;SCREEN_APP.C,29 :: 		Lcd_CMD(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;SCREEN_APP.C,30 :: 		Lcd_CMD(_LCD_RETURN_HOME);
	MOVLW       2
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;SCREEN_APP.C,31 :: 		Lcd_Out(1,4,"Body Health BR");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       4
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_SCREEN_APP+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_SCREEN_APP+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;SCREEN_APP.C,32 :: 		Lcd_Out(2,4,"BHS-156 Tester");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       4
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr3_SCREEN_APP+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr3_SCREEN_APP+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;SCREEN_APP.C,33 :: 		Lcd_Out(4,7,"v2017.1.8");
	MOVLW       4
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       7
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr4_SCREEN_APP+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr4_SCREEN_APP+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;SCREEN_APP.C,34 :: 		delay_ms(2500);
	MOVLW       64
	MOVWF       R11, 0
	MOVLW       106
	MOVWF       R12, 0
	MOVLW       151
	MOVWF       R13, 0
L_Screen_App6:
	DECFSZ      R13, 1, 1
	BRA         L_Screen_App6
	DECFSZ      R12, 1, 1
	BRA         L_Screen_App6
	DECFSZ      R11, 1, 1
	BRA         L_Screen_App6
	NOP
	NOP
;SCREEN_APP.C,42 :: 		}
L_end_Screen_App:
	RETURN      0
; end of _Screen_App
