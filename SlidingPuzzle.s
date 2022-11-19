		.syntax		unified
		.cpu		cortex-m4
		.text
		.global		CopyCell
		.thumb_func
		.align
          // void CopyCell(uint32_t *dst, uint32_t *src);
CopyCell:	
          	MOV		R2,0			// R2 = 0
NextRow1:	
		cmp		R2,60 	  		// compare
	        BGE		EndRows1  		// skip if greater than or equal
		LDR 		R3,=0     		// R3 = 0
NextCol1:	
          	cmp		R3,240			// compare R3 and 240
		BGE		EndCol1			// skip if greater thanor equal
		LDR		R12,[R1,R3]		// R12 = R1[R3]
		STR		R12,[R0,R3]		// R0[R3] = R12
		ADD 		R3,R3,4			// R3 = R3 + 1
		B		NextCol1		// go back to NextCol1
EndCol1:	
		ADD		R0,R0,960		// R0 = R0 + 960
		ADD		R1,R1,960		// R1 = R1 + 960
		ADD		R2,R2,1			// R2 = R2 + 1
		B		NextRow1		// go back to NextRow1
EndRows1:	
		BX		LR

		.global		FillCell
		.thumb_func
		.align 
		// void FillCell(uint32_t *dst, uint32_t color);
FillCel2:	
          	MOV		R2,0			// R2 = 0
NextRow2:	
          	cmp		R2,60			// compare R2 and 60
		BGE		EndRows2		// skip if greater than or equal
		LDR 		R3,=0			// R3 = 0
NextCol2:	
          	cmp		R3,240			// compare R3 and 240
		BGE		EndCol2			// skip if greater than or equal
		STR		R1,[R0,R3]		// R1 = R0[R3]
		ADD 		R3,R3,4			// R3 = R3 + 1
		B		NextCol2		// go back to NextCol2
EndCol2:	
          	ADD		R0,R0,960		// R0 = R0 + 960
		ADD		R2,R2,1			// R2 = R2 + 1
		B		NextRow2		// go back to NextRow2
EndRows2:	
		BX		LR
		.end
