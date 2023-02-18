;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _VFD_printf
	.globl _VFD_putc
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _FL
	.globl _P
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _C_T2
	.globl _CP_RL2
	.globl _T2CON_7
	.globl _T2CON_6
	.globl _T2CON_5
	.globl _T2CON_4
	.globl _T2CON_3
	.globl _T2CON_2
	.globl _T2CON_1
	.globl _T2CON_0
	.globl _PT2
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ET2
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _T2EX
	.globl _T2
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _nothing
	.globl _B
	.globl _A
	.globl _ACC
	.globl _PSW
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2MOD
	.globl _T2CON
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _dirT
	.globl _offsetT
	.globl _T
	.globl _dirRH
	.globl _offsetRH
	.globl _RH
	.globl _mDelay10uS
	.globl _mDelaymS
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_T2CON	=	0x00c8
_T2MOD	=	0x00c9
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
_PSW	=	0x00d0
_ACC	=	0x00e0
_A	=	0x00e0
_B	=	0x00f0
_nothing	=	0x00ff
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_T2	=	0x0090
_T2EX	=	0x0091
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_ET2	=	0x00ad
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_PT2	=	0x00bd
_T2CON_0	=	0x00c8
_T2CON_1	=	0x00c9
_T2CON_2	=	0x00ca
_T2CON_3	=	0x00cb
_T2CON_4	=	0x00cc
_T2CON_5	=	0x00cd
_T2CON_6	=	0x00ce
_T2CON_7	=	0x00cf
_CP_RL2	=	0x00c8
_C_T2	=	0x00c9
_TR2	=	0x00ca
_EXEN2	=	0x00cb
_TCLK	=	0x00cc
_RCLK	=	0x00cd
_EXF2	=	0x00ce
_TF2	=	0x00cf
_P	=	0x00d0
_FL	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_RH::
	.ds 2
_offsetRH::
	.ds 1
_dirRH::
	.ds 1
_T::
	.ds 2
_offsetT::
	.ds 1
_dirT::
	.ds 1
_main_chksum_327680_70:
	.ds 1
_main_humidity_131073_48:
	.ds 5
_main_temperature_131074_49:
	.ds 6
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	main.c:58: unsigned char offsetRH = 0;
	mov	_offsetRH,#0x00
;	main.c:59: char dirRH = 1;
	mov	_dirRH,#0x01
;	main.c:61: unsigned char offsetT = 0;
	mov	_offsetT,#0x00
;	main.c:62: char dirT = 1;
	mov	_dirT,#0x01
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'mDelay10uS'
;------------------------------------------------------------
;n                         Allocated to registers 
;------------------------------------------------------------
;	main.c:64: void mDelay10uS(unsigned int n)  // Delay in units of 10 uS
;	-----------------------------------------
;	 function mDelay10uS
;	-----------------------------------------
_mDelay10uS:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r6,dpl
	mov	r7,dph
;	main.c:66: while ( n )
00101$:
	mov	a,r6
	orl	a,r7
	jz	00104$
;	main.c:68: ++ nothing;
	inc	_nothing
;	main.c:69: -- n;
	dec	r6
	cjne	r6,#0xff,00116$
	dec	r7
00116$:
	sjmp	00101$
00104$:
;	main.c:71: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'mDelaymS'
;------------------------------------------------------------
;n                         Allocated to registers 
;------------------------------------------------------------
;	main.c:73: void mDelaymS(unsigned int n)                              // Delay in mS
;	-----------------------------------------
;	 function mDelaymS
;	-----------------------------------------
_mDelaymS:
	mov	r6,dpl
	mov	r7,dph
;	main.c:75: while ( n )
00101$:
	mov	a,r6
	orl	a,r7
	jz	00104$
;	main.c:78: mDelay10uS(100);
	mov	dptr,#0x0064
	push	ar7
	push	ar6
	lcall	_mDelay10uS
	pop	ar6
	pop	ar7
;	main.c:79: -- n;
	dec	r6
	cjne	r6,#0xff,00116$
	dec	r7
00116$:
	sjmp	00101$
00104$:
;	main.c:81: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'VFD_putc'
;------------------------------------------------------------
;c                         Allocated to registers r7 
;------------------------------------------------------------
;	main.c:83: void VFD_putc(char c)
;	-----------------------------------------
;	 function VFD_putc
;	-----------------------------------------
_VFD_putc:
	mov	r7,dpl
;	main.c:86: mDelay10uS(10);
	mov	dptr,#0x000a
	push	ar7
	lcall	_mDelay10uS
	pop	ar7
;	main.c:87: VFD_CS = 0;
;	assignBit
	clr	_P3_3
;	main.c:88: VFD_DATA = c;
	mov	_P1,r7
;	main.c:89: VFD_WR = 0;
;	assignBit
	clr	_P3_2
;	main.c:90: VFD_WR = 1;
;	assignBit
	setb	_P3_2
;	main.c:91: VFD_CS = 1;
;	assignBit
	setb	_P3_3
;	main.c:92: return;
;	main.c:93: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'VFD_printf'
;------------------------------------------------------------
;str                       Allocated to registers r5 r6 r7 
;i                         Allocated to registers r4 
;------------------------------------------------------------
;	main.c:103: void VFD_printf(char* str)
;	-----------------------------------------
;	 function VFD_printf
;	-----------------------------------------
_VFD_printf:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	main.c:106: while(str[i])
	mov	r4,#0x00
00101$:
	mov	a,r4
	add	a,r5
	mov	r1,a
	clr	a
	addc	a,r6
	mov	r2,a
	mov	ar3,r7
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r3,a
	jz	00104$
;	main.c:108: VFD_putc(str[i]);
	mov	dpl,r3
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_VFD_putc
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	main.c:109: i++;
	inc	r4
	sjmp	00101$
00104$:
;	main.c:111: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;__1310720001              Allocated to registers 
;cmd                       Allocated to registers 
;__1310720003              Allocated to registers 
;cmd                       Allocated to registers 
;__1310720001              Allocated to registers 
;cmd                       Allocated to registers 
;__1310720003              Allocated to registers 
;cmd                       Allocated to registers 
;chksum                    Allocated with name '_main_chksum_327680_70'
;i                         Allocated to registers r7 
;i                         Allocated to registers r7 
;i                         Allocated to registers r7 
;res                       Allocated to registers r6 
;humidity                  Allocated with name '_main_humidity_131073_48'
;temperature               Allocated with name '_main_temperature_131074_49'
;__1310720001              Allocated to registers 
;cmd                       Allocated to registers 
;__1310720003              Allocated to registers 
;cmd                       Allocated to registers 
;__1966100010              Allocated to registers 
;offset                    Allocated to registers r7 
;__1310720001              Allocated to registers 
;cmd                       Allocated to registers 
;__1310720003              Allocated to registers 
;cmd                       Allocated to registers 
;__1966100013              Allocated to registers 
;offset                    Allocated to registers r7 
;------------------------------------------------------------
;	main.c:229: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	main.c:235: DHT_DATA = 1;       // Enable pull-up resistor
;	assignBit
	setb	_P3_7
;	main.c:237: LED_TEST = 0;
;	assignBit
	clr	_P3_6
;	main.c:240: mDelaymS(10);
	mov	dptr,#0x000a
	lcall	_mDelaymS
;	main.c:98: VFD_putc(cmd);
	mov	dpl,#0x0d
	lcall	_VFD_putc
;	main.c:100: mDelay10uS(100);
	mov	dptr,#0x0064
	lcall	_mDelay10uS
;	main.c:98: VFD_putc(cmd);
	mov	dpl,#0x0e
	lcall	_VFD_putc
;	main.c:100: mDelay10uS(100);
	mov	dptr,#0x0064
	lcall	_mDelay10uS
;	main.c:242: VFD_printf("Howdy!");
	mov	dptr,#___str_0
	mov	b,#0x80
	lcall	_VFD_printf
;	main.c:244: mDelaymS(1000);
	mov	dptr,#0x03e8
	lcall	_mDelaymS
;	main.c:246: while(1)
00112$:
;	main.c:98: VFD_putc(cmd);
	mov	dpl,#0x0d
	lcall	_VFD_putc
;	main.c:100: mDelay10uS(100);
	mov	dptr,#0x0064
	lcall	_mDelay10uS
;	main.c:98: VFD_putc(cmd);
	mov	dpl,#0x0e
	lcall	_VFD_putc
;	main.c:100: mDelay10uS(100);
	mov	dptr,#0x0064
	lcall	_mDelay10uS
;	main.c:131: DHT_DATA = 0;
;	assignBit
	clr	_P3_7
;	main.c:133: mDelay10uS(100);
	mov	dptr,#0x0064
	lcall	_mDelay10uS
;	main.c:135: DHT_DATA = 1;
;	assignBit
	setb	_P3_7
;	main.c:145: while(DHT_DATA)
00121$:
	jb	_P3_7,00121$
;	main.c:151: while(!DHT_DATA)
00124$:
	jnb	_P3_7,00124$
;	main.c:157: while(DHT_DATA)
00127$:
	jb	_P3_7,00127$
;	main.c:165: for(unsigned char i = 0; i < 16; i++)
	mov	r7,#0x00
00175$:
	cjne	r7,#0x10,00325$
00325$:
	jnc	00138$
;	main.c:167: while(!DHT_DATA);	//wait for pulse to begin
00130$:
	jnb	_P3_7,00130$
;	main.c:170: mDelay10uS(4);
	mov	dptr,#0x0004
	push	ar7
	lcall	_mDelay10uS
	pop	ar7
;	main.c:172: RH = RH << 1;
	mov	a,_RH
	add	a,_RH
	mov	_RH,a
	mov	a,(_RH + 1)
	rlc	a
	mov	(_RH + 1),a
;	main.c:173: if(DHT_DATA)
	jnb	_P3_7,00135$
;	main.c:175: RH = RH | 1;
	orl	_RH,#0x01
;	main.c:178: while(DHT_DATA);	//wait for pulse to end (if it hasnt already)
00135$:
	jb	_P3_7,00135$
;	main.c:165: for(unsigned char i = 0; i < 16; i++)
	inc	r7
	sjmp	00175$
00138$:
;	main.c:184: for(unsigned char i = 0; i < 16; i++)
	mov	r7,#0x00
00178$:
	cjne	r7,#0x10,00330$
00330$:
	jnc	00147$
;	main.c:186: while(!DHT_DATA);
00139$:
	jnb	_P3_7,00139$
;	main.c:189: mDelay10uS(4);
	mov	dptr,#0x0004
	push	ar7
	lcall	_mDelay10uS
	pop	ar7
;	main.c:191: T = T << 1;
	mov	a,_T
	add	a,_T
	mov	_T,a
	mov	a,(_T + 1)
	rlc	a
	mov	(_T + 1),a
;	main.c:192: if(DHT_DATA)
	jnb	_P3_7,00144$
;	main.c:194: T = T | 1;
	orl	_T,#0x01
;	main.c:197: while(DHT_DATA);
00144$:
	jb	_P3_7,00144$
;	main.c:184: for(unsigned char i = 0; i < 16; i++)
	inc	r7
	sjmp	00178$
00147$:
;	main.c:203: for(unsigned char i = 0; i < 8; i++)
	mov	r7,#0x00
00181$:
	cjne	r7,#0x08,00335$
00335$:
	jnc	00156$
;	main.c:205: while(!DHT_DATA);
00148$:
	jnb	_P3_7,00148$
;	main.c:208: mDelay10uS(4);
	mov	dptr,#0x0004
	push	ar7
	lcall	_mDelay10uS
	pop	ar7
;	main.c:210: chksum = chksum << 1;
	mov	a,_main_chksum_327680_70
	mov	r6,a
	add	a,acc
	mov	_main_chksum_327680_70,a
;	main.c:211: if(DHT_DATA)
	jnb	_P3_7,00153$
;	main.c:213: chksum = chksum | 1;
	orl	_main_chksum_327680_70,#0x01
;	main.c:216: while(DHT_DATA);
00153$:
	jb	_P3_7,00153$
;	main.c:203: for(unsigned char i = 0; i < 8; i++)
	inc	r7
	sjmp	00181$
00156$:
;	main.c:221: unsigned char res = (RH & 0xFF) + (RH >> 8) + (T & 0xFF) + (T >> 8);
	mov	r7,_RH
	mov	a,(_RH + 1)
	add	a,r7
	mov	r6,a
	mov	a,_T
	add	a,r6
	mov	r6,a
	mov	a,(_T + 1)
	add	a,r6
;	main.c:222: if (res != chksum)
	cjne	a,_main_chksum_327680_70,00340$
	sjmp	00159$
00340$:
;	main.c:224: RH = 0xDEAD;
	mov	_RH,#0xad
	mov	(_RH + 1),#0xde
;	main.c:225: T = 0xBEEF;
	mov	_T,#0xef
	mov	(_T + 1),#0xbe
;	main.c:250: DHT_read_data();
00159$:
;	main.c:253: humidity[4]=0x00;
	mov	(_main_humidity_131073_48 + 0x0004),#0x00
;	main.c:254: humidity[3] = RH % 10 + 0x30;
	mov	__moduint_PARM_2,#0x0a
	mov	(__moduint_PARM_2 + 1),#0x00
	mov	dpl,_RH
	mov	dph,(_RH + 1)
	lcall	__moduint
	mov	r6,dpl
	mov	a,#0x30
	add	a,r6
	mov	(_main_humidity_131073_48 + 0x0003),a
;	main.c:255: humidity[2] = '.';
	mov	(_main_humidity_131073_48 + 0x0002),#0x2e
;	main.c:256: RH = RH / 10;
	mov	__divuint_PARM_2,#0x0a
	mov	(__divuint_PARM_2 + 1),#0x00
	mov	dpl,_RH
	mov	dph,(_RH + 1)
	lcall	__divuint
;	main.c:257: humidity[1] = RH % 10 + 0x30;
	mov	_RH,dpl
	mov	(_RH + 1),dph
	mov	__moduint_PARM_2,#0x0a
	mov	(__moduint_PARM_2 + 1),#0x00
	lcall	__moduint
	mov	r6,dpl
	mov	a,#0x30
	add	a,r6
	mov	(_main_humidity_131073_48 + 0x0001),a
;	main.c:258: RH = RH / 10;
	mov	__divuint_PARM_2,#0x0a
	mov	(__divuint_PARM_2 + 1),#0x00
	mov	dpl,_RH
	mov	dph,(_RH + 1)
	lcall	__divuint
;	main.c:259: humidity[0] = RH % 10 + 0x30;
	mov	_RH,dpl
	mov	(_RH + 1),dph
	mov	__moduint_PARM_2,#0x0a
	mov	(__moduint_PARM_2 + 1),#0x00
	lcall	__moduint
	mov	r6,dpl
	mov	a,#0x30
	add	a,r6
	mov	_main_humidity_131073_48,a
;	main.c:262: temperature[0] = '+';
	mov	_main_temperature_131074_49,#0x2b
;	main.c:263: if(T & 0x8000)
	mov	a,(_T + 1)
	jnb	acc.7,00102$
;	main.c:264: temperature[0] = '-';
	mov	_main_temperature_131074_49,#0x2d
00102$:
;	main.c:265: T = T & 0x7FFF;
	anl	(_T + 1),#0x7f
;	main.c:266: temperature[5]=0x00;
	mov	(_main_temperature_131074_49 + 0x0005),#0x00
;	main.c:267: temperature[4] = T % 10 + 0x30;
	mov	__moduint_PARM_2,#0x0a
	mov	(__moduint_PARM_2 + 1),#0x00
	mov	dpl,_T
	mov	dph,(_T + 1)
	lcall	__moduint
	mov	r6,dpl
	mov	a,#0x30
	add	a,r6
	mov	(_main_temperature_131074_49 + 0x0004),a
;	main.c:268: temperature[3] = '.';
	mov	(_main_temperature_131074_49 + 0x0003),#0x2e
;	main.c:269: T = T / 10;
	mov	__divuint_PARM_2,#0x0a
	mov	(__divuint_PARM_2 + 1),#0x00
	mov	dpl,_T
	mov	dph,(_T + 1)
	lcall	__divuint
;	main.c:270: temperature[2] = T % 10 + 0x30;
	mov	_T,dpl
	mov	(_T + 1),dph
	mov	__moduint_PARM_2,#0x0a
	mov	(__moduint_PARM_2 + 1),#0x00
	lcall	__moduint
	mov	r6,dpl
	mov	a,#0x30
	add	a,r6
	mov	(_main_temperature_131074_49 + 0x0002),a
;	main.c:271: T = T / 10;
	mov	__divuint_PARM_2,#0x0a
	mov	(__divuint_PARM_2 + 1),#0x00
	mov	dpl,_T
	mov	dph,(_T + 1)
	lcall	__divuint
;	main.c:272: temperature[1] = T % 10 + 0x30;
	mov	_T,dpl
	mov	(_T + 1),dph
	mov	__moduint_PARM_2,#0x0a
	mov	(__moduint_PARM_2 + 1),#0x00
	lcall	__moduint
	mov	r6,dpl
	mov	a,#0x30
	add	a,r6
	mov	(_main_temperature_131074_49 + 0x0001),a
;	main.c:98: VFD_putc(cmd);
	mov	dpl,#0x0d
	lcall	_VFD_putc
;	main.c:100: mDelay10uS(100);
	mov	dptr,#0x0064
	lcall	_mDelay10uS
;	main.c:98: VFD_putc(cmd);
	mov	dpl,#0x0e
	lcall	_VFD_putc
;	main.c:100: mDelay10uS(100);
	mov	dptr,#0x0064
	lcall	_mDelay10uS
;	main.c:275: VFD_padding(offsetRH);
	mov	r7,_offsetRH
;	main.c:115: while(offset != 0)
00163$:
	mov	a,r7
	jz	00166$
;	main.c:117: VFD_putc(' ');
	mov	dpl,#0x20
	push	ar7
	lcall	_VFD_putc
	pop	ar7
;	main.c:118: offset--;
	dec	r7
;	main.c:275: VFD_padding(offsetRH);
	sjmp	00163$
00166$:
;	main.c:276: VFD_printf("Humidity: ");
	mov	dptr,#___str_1
	mov	b,#0x80
	lcall	_VFD_printf
;	main.c:277: VFD_printf(humidity);
	mov	dptr,#_main_humidity_131073_48
	mov	b,#0x40
	lcall	_VFD_printf
;	main.c:279: mDelaymS(1000);
	mov	dptr,#0x03e8
	lcall	_mDelaymS
;	main.c:280: LED_TEST = 0;
;	assignBit
	clr	_P3_6
;	main.c:98: VFD_putc(cmd);
	mov	dpl,#0x0d
	lcall	_VFD_putc
;	main.c:100: mDelay10uS(100);
	mov	dptr,#0x0064
	lcall	_mDelay10uS
;	main.c:98: VFD_putc(cmd);
	mov	dpl,#0x0e
	lcall	_VFD_putc
;	main.c:100: mDelay10uS(100);
	mov	dptr,#0x0064
	lcall	_mDelay10uS
;	main.c:283: VFD_padding(offsetT);
	mov	r7,_offsetT
;	main.c:115: while(offset != 0)
00170$:
	mov	a,r7
	jz	00173$
;	main.c:117: VFD_putc(' ');
	mov	dpl,#0x20
	push	ar7
	lcall	_VFD_putc
	pop	ar7
;	main.c:118: offset--;
	dec	r7
;	main.c:283: VFD_padding(offsetT);
	sjmp	00170$
00173$:
;	main.c:284: VFD_printf("Temperature: ");
	mov	dptr,#___str_2
	mov	b,#0x80
	lcall	_VFD_printf
;	main.c:285: VFD_printf(temperature);
	mov	dptr,#_main_temperature_131074_49
	mov	b,#0x40
	lcall	_VFD_printf
;	main.c:287: mDelaymS(1000);
	mov	dptr,#0x03e8
	lcall	_mDelaymS
;	main.c:288: LED_TEST = 1;
;	assignBit
	setb	_P3_6
;	main.c:290: offsetRH = offsetRH + dirRH;
	mov	a,_dirRH
	add	a,_offsetRH
	mov	_offsetRH,a
;	main.c:291: if (offsetRH == 6)
	mov	a,#0x06
	cjne	a,_offsetRH,00104$
;	main.c:292: dirRH = -1;
	mov	_dirRH,#0xff
00104$:
;	main.c:293: if (offsetRH == 0)
	mov	a,_offsetRH
	jnz	00106$
;	main.c:294: dirRH = 1;
	mov	_dirRH,#0x01
00106$:
;	main.c:296: offsetT = offsetT + dirT;
	mov	a,_dirT
	add	a,_offsetT
	mov	_offsetT,a
;	main.c:297: if (offsetT == 2)
	mov	a,#0x02
	cjne	a,_offsetT,00108$
;	main.c:298: dirT = -1;
	mov	_dirT,#0xff
00108$:
;	main.c:299: if (offsetT == 0)
	mov	a,_offsetT
	jz	00349$
	ljmp	00112$
00349$:
;	main.c:300: dirT = 1;
	mov	_dirT,#0x01
;	main.c:302: return;
;	main.c:303: }
	ljmp	00112$
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area CONST   (CODE)
___str_0:
	.ascii "Howdy!"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_1:
	.ascii "Humidity: "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_2:
	.ascii "Temperature: "
	.db 0x00
	.area CSEG    (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
