
_main:

;MAIN.c,78 :: 		void main()
;MAIN.c,80 :: 		while(TRUE)
L_main0:
;MAIN.c,82 :: 		ConfigMCU   ();
	CALL        _ConfigMCU+0, 0
;MAIN.c,85 :: 		Screen_Main ();
	CALL        _Screen_Main+0, 0
;MAIN.c,87 :: 		}//END FUNCTION
	GOTO        L_main0
;MAIN.c,88 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
