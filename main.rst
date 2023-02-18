                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _VFD_printf
                                     13 	.globl _VFD_putc
                                     14 	.globl _CY
                                     15 	.globl _AC
                                     16 	.globl _F0
                                     17 	.globl _RS1
                                     18 	.globl _RS0
                                     19 	.globl _OV
                                     20 	.globl _FL
                                     21 	.globl _P
                                     22 	.globl _TF2
                                     23 	.globl _EXF2
                                     24 	.globl _RCLK
                                     25 	.globl _TCLK
                                     26 	.globl _EXEN2
                                     27 	.globl _TR2
                                     28 	.globl _C_T2
                                     29 	.globl _CP_RL2
                                     30 	.globl _T2CON_7
                                     31 	.globl _T2CON_6
                                     32 	.globl _T2CON_5
                                     33 	.globl _T2CON_4
                                     34 	.globl _T2CON_3
                                     35 	.globl _T2CON_2
                                     36 	.globl _T2CON_1
                                     37 	.globl _T2CON_0
                                     38 	.globl _PT2
                                     39 	.globl _PS
                                     40 	.globl _PT1
                                     41 	.globl _PX1
                                     42 	.globl _PT0
                                     43 	.globl _PX0
                                     44 	.globl _RD
                                     45 	.globl _WR
                                     46 	.globl _T1
                                     47 	.globl _T0
                                     48 	.globl _INT1
                                     49 	.globl _INT0
                                     50 	.globl _TXD
                                     51 	.globl _RXD
                                     52 	.globl _P3_7
                                     53 	.globl _P3_6
                                     54 	.globl _P3_5
                                     55 	.globl _P3_4
                                     56 	.globl _P3_3
                                     57 	.globl _P3_2
                                     58 	.globl _P3_1
                                     59 	.globl _P3_0
                                     60 	.globl _EA
                                     61 	.globl _ET2
                                     62 	.globl _ES
                                     63 	.globl _ET1
                                     64 	.globl _EX1
                                     65 	.globl _ET0
                                     66 	.globl _EX0
                                     67 	.globl _P2_7
                                     68 	.globl _P2_6
                                     69 	.globl _P2_5
                                     70 	.globl _P2_4
                                     71 	.globl _P2_3
                                     72 	.globl _P2_2
                                     73 	.globl _P2_1
                                     74 	.globl _P2_0
                                     75 	.globl _SM0
                                     76 	.globl _SM1
                                     77 	.globl _SM2
                                     78 	.globl _REN
                                     79 	.globl _TB8
                                     80 	.globl _RB8
                                     81 	.globl _TI
                                     82 	.globl _RI
                                     83 	.globl _T2EX
                                     84 	.globl _T2
                                     85 	.globl _P1_7
                                     86 	.globl _P1_6
                                     87 	.globl _P1_5
                                     88 	.globl _P1_4
                                     89 	.globl _P1_3
                                     90 	.globl _P1_2
                                     91 	.globl _P1_1
                                     92 	.globl _P1_0
                                     93 	.globl _TF1
                                     94 	.globl _TR1
                                     95 	.globl _TF0
                                     96 	.globl _TR0
                                     97 	.globl _IE1
                                     98 	.globl _IT1
                                     99 	.globl _IE0
                                    100 	.globl _IT0
                                    101 	.globl _P0_7
                                    102 	.globl _P0_6
                                    103 	.globl _P0_5
                                    104 	.globl _P0_4
                                    105 	.globl _P0_3
                                    106 	.globl _P0_2
                                    107 	.globl _P0_1
                                    108 	.globl _P0_0
                                    109 	.globl _nothing
                                    110 	.globl _B
                                    111 	.globl _A
                                    112 	.globl _ACC
                                    113 	.globl _PSW
                                    114 	.globl _TH2
                                    115 	.globl _TL2
                                    116 	.globl _RCAP2H
                                    117 	.globl _RCAP2L
                                    118 	.globl _T2MOD
                                    119 	.globl _T2CON
                                    120 	.globl _IP
                                    121 	.globl _P3
                                    122 	.globl _IE
                                    123 	.globl _P2
                                    124 	.globl _SBUF
                                    125 	.globl _SCON
                                    126 	.globl _P1
                                    127 	.globl _TH1
                                    128 	.globl _TH0
                                    129 	.globl _TL1
                                    130 	.globl _TL0
                                    131 	.globl _TMOD
                                    132 	.globl _TCON
                                    133 	.globl _PCON
                                    134 	.globl _DPH
                                    135 	.globl _DPL
                                    136 	.globl _SP
                                    137 	.globl _P0
                                    138 	.globl _dirT
                                    139 	.globl _offsetT
                                    140 	.globl _T
                                    141 	.globl _dirRH
                                    142 	.globl _offsetRH
                                    143 	.globl _RH
                                    144 	.globl _mDelay10uS
                                    145 	.globl _mDelaymS
                                    146 ;--------------------------------------------------------
                                    147 ; special function registers
                                    148 ;--------------------------------------------------------
                                    149 	.area RSEG    (ABS,DATA)
      000000                        150 	.org 0x0000
                           000080   151 _P0	=	0x0080
                           000081   152 _SP	=	0x0081
                           000082   153 _DPL	=	0x0082
                           000083   154 _DPH	=	0x0083
                           000087   155 _PCON	=	0x0087
                           000088   156 _TCON	=	0x0088
                           000089   157 _TMOD	=	0x0089
                           00008A   158 _TL0	=	0x008a
                           00008B   159 _TL1	=	0x008b
                           00008C   160 _TH0	=	0x008c
                           00008D   161 _TH1	=	0x008d
                           000090   162 _P1	=	0x0090
                           000098   163 _SCON	=	0x0098
                           000099   164 _SBUF	=	0x0099
                           0000A0   165 _P2	=	0x00a0
                           0000A8   166 _IE	=	0x00a8
                           0000B0   167 _P3	=	0x00b0
                           0000B8   168 _IP	=	0x00b8
                           0000C8   169 _T2CON	=	0x00c8
                           0000C9   170 _T2MOD	=	0x00c9
                           0000CA   171 _RCAP2L	=	0x00ca
                           0000CB   172 _RCAP2H	=	0x00cb
                           0000CC   173 _TL2	=	0x00cc
                           0000CD   174 _TH2	=	0x00cd
                           0000D0   175 _PSW	=	0x00d0
                           0000E0   176 _ACC	=	0x00e0
                           0000E0   177 _A	=	0x00e0
                           0000F0   178 _B	=	0x00f0
                           0000FF   179 _nothing	=	0x00ff
                                    180 ;--------------------------------------------------------
                                    181 ; special function bits
                                    182 ;--------------------------------------------------------
                                    183 	.area RSEG    (ABS,DATA)
      000000                        184 	.org 0x0000
                           000080   185 _P0_0	=	0x0080
                           000081   186 _P0_1	=	0x0081
                           000082   187 _P0_2	=	0x0082
                           000083   188 _P0_3	=	0x0083
                           000084   189 _P0_4	=	0x0084
                           000085   190 _P0_5	=	0x0085
                           000086   191 _P0_6	=	0x0086
                           000087   192 _P0_7	=	0x0087
                           000088   193 _IT0	=	0x0088
                           000089   194 _IE0	=	0x0089
                           00008A   195 _IT1	=	0x008a
                           00008B   196 _IE1	=	0x008b
                           00008C   197 _TR0	=	0x008c
                           00008D   198 _TF0	=	0x008d
                           00008E   199 _TR1	=	0x008e
                           00008F   200 _TF1	=	0x008f
                           000090   201 _P1_0	=	0x0090
                           000091   202 _P1_1	=	0x0091
                           000092   203 _P1_2	=	0x0092
                           000093   204 _P1_3	=	0x0093
                           000094   205 _P1_4	=	0x0094
                           000095   206 _P1_5	=	0x0095
                           000096   207 _P1_6	=	0x0096
                           000097   208 _P1_7	=	0x0097
                           000090   209 _T2	=	0x0090
                           000091   210 _T2EX	=	0x0091
                           000098   211 _RI	=	0x0098
                           000099   212 _TI	=	0x0099
                           00009A   213 _RB8	=	0x009a
                           00009B   214 _TB8	=	0x009b
                           00009C   215 _REN	=	0x009c
                           00009D   216 _SM2	=	0x009d
                           00009E   217 _SM1	=	0x009e
                           00009F   218 _SM0	=	0x009f
                           0000A0   219 _P2_0	=	0x00a0
                           0000A1   220 _P2_1	=	0x00a1
                           0000A2   221 _P2_2	=	0x00a2
                           0000A3   222 _P2_3	=	0x00a3
                           0000A4   223 _P2_4	=	0x00a4
                           0000A5   224 _P2_5	=	0x00a5
                           0000A6   225 _P2_6	=	0x00a6
                           0000A7   226 _P2_7	=	0x00a7
                           0000A8   227 _EX0	=	0x00a8
                           0000A9   228 _ET0	=	0x00a9
                           0000AA   229 _EX1	=	0x00aa
                           0000AB   230 _ET1	=	0x00ab
                           0000AC   231 _ES	=	0x00ac
                           0000AD   232 _ET2	=	0x00ad
                           0000AF   233 _EA	=	0x00af
                           0000B0   234 _P3_0	=	0x00b0
                           0000B1   235 _P3_1	=	0x00b1
                           0000B2   236 _P3_2	=	0x00b2
                           0000B3   237 _P3_3	=	0x00b3
                           0000B4   238 _P3_4	=	0x00b4
                           0000B5   239 _P3_5	=	0x00b5
                           0000B6   240 _P3_6	=	0x00b6
                           0000B7   241 _P3_7	=	0x00b7
                           0000B0   242 _RXD	=	0x00b0
                           0000B1   243 _TXD	=	0x00b1
                           0000B2   244 _INT0	=	0x00b2
                           0000B3   245 _INT1	=	0x00b3
                           0000B4   246 _T0	=	0x00b4
                           0000B5   247 _T1	=	0x00b5
                           0000B6   248 _WR	=	0x00b6
                           0000B7   249 _RD	=	0x00b7
                           0000B8   250 _PX0	=	0x00b8
                           0000B9   251 _PT0	=	0x00b9
                           0000BA   252 _PX1	=	0x00ba
                           0000BB   253 _PT1	=	0x00bb
                           0000BC   254 _PS	=	0x00bc
                           0000BD   255 _PT2	=	0x00bd
                           0000C8   256 _T2CON_0	=	0x00c8
                           0000C9   257 _T2CON_1	=	0x00c9
                           0000CA   258 _T2CON_2	=	0x00ca
                           0000CB   259 _T2CON_3	=	0x00cb
                           0000CC   260 _T2CON_4	=	0x00cc
                           0000CD   261 _T2CON_5	=	0x00cd
                           0000CE   262 _T2CON_6	=	0x00ce
                           0000CF   263 _T2CON_7	=	0x00cf
                           0000C8   264 _CP_RL2	=	0x00c8
                           0000C9   265 _C_T2	=	0x00c9
                           0000CA   266 _TR2	=	0x00ca
                           0000CB   267 _EXEN2	=	0x00cb
                           0000CC   268 _TCLK	=	0x00cc
                           0000CD   269 _RCLK	=	0x00cd
                           0000CE   270 _EXF2	=	0x00ce
                           0000CF   271 _TF2	=	0x00cf
                           0000D0   272 _P	=	0x00d0
                           0000D1   273 _FL	=	0x00d1
                           0000D2   274 _OV	=	0x00d2
                           0000D3   275 _RS0	=	0x00d3
                           0000D4   276 _RS1	=	0x00d4
                           0000D5   277 _F0	=	0x00d5
                           0000D6   278 _AC	=	0x00d6
                           0000D7   279 _CY	=	0x00d7
                                    280 ;--------------------------------------------------------
                                    281 ; overlayable register banks
                                    282 ;--------------------------------------------------------
                                    283 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        284 	.ds 8
                                    285 ;--------------------------------------------------------
                                    286 ; internal ram data
                                    287 ;--------------------------------------------------------
                                    288 	.area DSEG    (DATA)
      000008                        289 _RH::
      000008                        290 	.ds 2
      00000A                        291 _offsetRH::
      00000A                        292 	.ds 1
      00000B                        293 _dirRH::
      00000B                        294 	.ds 1
      00000C                        295 _T::
      00000C                        296 	.ds 2
      00000E                        297 _offsetT::
      00000E                        298 	.ds 1
      00000F                        299 _dirT::
      00000F                        300 	.ds 1
      000010                        301 _main_chksum_327680_70:
      000010                        302 	.ds 1
      000011                        303 _main_humidity_131073_48:
      000011                        304 	.ds 5
      000016                        305 _main_temperature_131074_49:
      000016                        306 	.ds 6
                                    307 ;--------------------------------------------------------
                                    308 ; overlayable items in internal ram 
                                    309 ;--------------------------------------------------------
                                    310 	.area	OSEG    (OVR,DATA)
                                    311 ;--------------------------------------------------------
                                    312 ; Stack segment in internal ram 
                                    313 ;--------------------------------------------------------
                                    314 	.area	SSEG
      00001E                        315 __start__stack:
      00001E                        316 	.ds	1
                                    317 
                                    318 ;--------------------------------------------------------
                                    319 ; indirectly addressable internal ram data
                                    320 ;--------------------------------------------------------
                                    321 	.area ISEG    (DATA)
                                    322 ;--------------------------------------------------------
                                    323 ; absolute internal ram data
                                    324 ;--------------------------------------------------------
                                    325 	.area IABS    (ABS,DATA)
                                    326 	.area IABS    (ABS,DATA)
                                    327 ;--------------------------------------------------------
                                    328 ; bit data
                                    329 ;--------------------------------------------------------
                                    330 	.area BSEG    (BIT)
                                    331 ;--------------------------------------------------------
                                    332 ; paged external ram data
                                    333 ;--------------------------------------------------------
                                    334 	.area PSEG    (PAG,XDATA)
                                    335 ;--------------------------------------------------------
                                    336 ; external ram data
                                    337 ;--------------------------------------------------------
                                    338 	.area XSEG    (XDATA)
                                    339 ;--------------------------------------------------------
                                    340 ; absolute external ram data
                                    341 ;--------------------------------------------------------
                                    342 	.area XABS    (ABS,XDATA)
                                    343 ;--------------------------------------------------------
                                    344 ; external initialized ram data
                                    345 ;--------------------------------------------------------
                                    346 	.area XISEG   (XDATA)
                                    347 	.area HOME    (CODE)
                                    348 	.area GSINIT0 (CODE)
                                    349 	.area GSINIT1 (CODE)
                                    350 	.area GSINIT2 (CODE)
                                    351 	.area GSINIT3 (CODE)
                                    352 	.area GSINIT4 (CODE)
                                    353 	.area GSINIT5 (CODE)
                                    354 	.area GSINIT  (CODE)
                                    355 	.area GSFINAL (CODE)
                                    356 	.area CSEG    (CODE)
                                    357 ;--------------------------------------------------------
                                    358 ; interrupt vector 
                                    359 ;--------------------------------------------------------
                                    360 	.area HOME    (CODE)
      000000                        361 __interrupt_vect:
      000000 02 00 06         [24]  362 	ljmp	__sdcc_gsinit_startup
                                    363 ;--------------------------------------------------------
                                    364 ; global & static initialisations
                                    365 ;--------------------------------------------------------
                                    366 	.area HOME    (CODE)
                                    367 	.area GSINIT  (CODE)
                                    368 	.area GSFINAL (CODE)
                                    369 	.area GSINIT  (CODE)
                                    370 	.globl __sdcc_gsinit_startup
                                    371 	.globl __sdcc_program_startup
                                    372 	.globl __start__stack
                                    373 	.globl __mcs51_genXINIT
                                    374 	.globl __mcs51_genXRAMCLEAR
                                    375 	.globl __mcs51_genRAMCLEAR
                                    376 ;	main.c:58: unsigned char offsetRH = 0;
      00005F 75 0A 00         [24]  377 	mov	_offsetRH,#0x00
                                    378 ;	main.c:59: char dirRH = 1;
      000062 75 0B 01         [24]  379 	mov	_dirRH,#0x01
                                    380 ;	main.c:61: unsigned char offsetT = 0;
      000065 75 0E 00         [24]  381 	mov	_offsetT,#0x00
                                    382 ;	main.c:62: char dirT = 1;
      000068 75 0F 01         [24]  383 	mov	_dirT,#0x01
                                    384 	.area GSFINAL (CODE)
      00006B 02 00 03         [24]  385 	ljmp	__sdcc_program_startup
                                    386 ;--------------------------------------------------------
                                    387 ; Home
                                    388 ;--------------------------------------------------------
                                    389 	.area HOME    (CODE)
                                    390 	.area HOME    (CODE)
      000003                        391 __sdcc_program_startup:
      000003 02 00 EA         [24]  392 	ljmp	_main
                                    393 ;	return from main will return to caller
                                    394 ;--------------------------------------------------------
                                    395 ; code
                                    396 ;--------------------------------------------------------
                                    397 	.area CSEG    (CODE)
                                    398 ;------------------------------------------------------------
                                    399 ;Allocation info for local variables in function 'mDelay10uS'
                                    400 ;------------------------------------------------------------
                                    401 ;n                         Allocated to registers 
                                    402 ;------------------------------------------------------------
                                    403 ;	main.c:64: void mDelay10uS(unsigned int n)  // Delay in units of 10 uS
                                    404 ;	-----------------------------------------
                                    405 ;	 function mDelay10uS
                                    406 ;	-----------------------------------------
      00006E                        407 _mDelay10uS:
                           000007   408 	ar7 = 0x07
                           000006   409 	ar6 = 0x06
                           000005   410 	ar5 = 0x05
                           000004   411 	ar4 = 0x04
                           000003   412 	ar3 = 0x03
                           000002   413 	ar2 = 0x02
                           000001   414 	ar1 = 0x01
                           000000   415 	ar0 = 0x00
      00006E AE 82            [24]  416 	mov	r6,dpl
      000070 AF 83            [24]  417 	mov	r7,dph
                                    418 ;	main.c:66: while ( n )
      000072                        419 00101$:
      000072 EE               [12]  420 	mov	a,r6
      000073 4F               [12]  421 	orl	a,r7
      000074 60 09            [24]  422 	jz	00104$
                                    423 ;	main.c:68: ++ nothing;
      000076 05 FF            [12]  424 	inc	_nothing
                                    425 ;	main.c:69: -- n;
      000078 1E               [12]  426 	dec	r6
      000079 BE FF 01         [24]  427 	cjne	r6,#0xff,00116$
      00007C 1F               [12]  428 	dec	r7
      00007D                        429 00116$:
      00007D 80 F3            [24]  430 	sjmp	00101$
      00007F                        431 00104$:
                                    432 ;	main.c:71: }
      00007F 22               [24]  433 	ret
                                    434 ;------------------------------------------------------------
                                    435 ;Allocation info for local variables in function 'mDelaymS'
                                    436 ;------------------------------------------------------------
                                    437 ;n                         Allocated to registers 
                                    438 ;------------------------------------------------------------
                                    439 ;	main.c:73: void mDelaymS(unsigned int n)                              // Delay in mS
                                    440 ;	-----------------------------------------
                                    441 ;	 function mDelaymS
                                    442 ;	-----------------------------------------
      000080                        443 _mDelaymS:
      000080 AE 82            [24]  444 	mov	r6,dpl
      000082 AF 83            [24]  445 	mov	r7,dph
                                    446 ;	main.c:75: while ( n )
      000084                        447 00101$:
      000084 EE               [12]  448 	mov	a,r6
      000085 4F               [12]  449 	orl	a,r7
      000086 60 15            [24]  450 	jz	00104$
                                    451 ;	main.c:78: mDelay10uS(100);
      000088 90 00 64         [24]  452 	mov	dptr,#0x0064
      00008B C0 07            [24]  453 	push	ar7
      00008D C0 06            [24]  454 	push	ar6
      00008F 12 00 6E         [24]  455 	lcall	_mDelay10uS
      000092 D0 06            [24]  456 	pop	ar6
      000094 D0 07            [24]  457 	pop	ar7
                                    458 ;	main.c:79: -- n;
      000096 1E               [12]  459 	dec	r6
      000097 BE FF 01         [24]  460 	cjne	r6,#0xff,00116$
      00009A 1F               [12]  461 	dec	r7
      00009B                        462 00116$:
      00009B 80 E7            [24]  463 	sjmp	00101$
      00009D                        464 00104$:
                                    465 ;	main.c:81: }
      00009D 22               [24]  466 	ret
                                    467 ;------------------------------------------------------------
                                    468 ;Allocation info for local variables in function 'VFD_putc'
                                    469 ;------------------------------------------------------------
                                    470 ;c                         Allocated to registers r7 
                                    471 ;------------------------------------------------------------
                                    472 ;	main.c:83: void VFD_putc(char c)
                                    473 ;	-----------------------------------------
                                    474 ;	 function VFD_putc
                                    475 ;	-----------------------------------------
      00009E                        476 _VFD_putc:
      00009E AF 82            [24]  477 	mov	r7,dpl
                                    478 ;	main.c:86: mDelay10uS(10);
      0000A0 90 00 0A         [24]  479 	mov	dptr,#0x000a
      0000A3 C0 07            [24]  480 	push	ar7
      0000A5 12 00 6E         [24]  481 	lcall	_mDelay10uS
      0000A8 D0 07            [24]  482 	pop	ar7
                                    483 ;	main.c:87: VFD_CS = 0;
                                    484 ;	assignBit
      0000AA C2 B3            [12]  485 	clr	_P3_3
                                    486 ;	main.c:88: VFD_DATA = c;
      0000AC 8F 90            [24]  487 	mov	_P1,r7
                                    488 ;	main.c:89: VFD_WR = 0;
                                    489 ;	assignBit
      0000AE C2 B2            [12]  490 	clr	_P3_2
                                    491 ;	main.c:90: VFD_WR = 1;
                                    492 ;	assignBit
      0000B0 D2 B2            [12]  493 	setb	_P3_2
                                    494 ;	main.c:91: VFD_CS = 1;
                                    495 ;	assignBit
      0000B2 D2 B3            [12]  496 	setb	_P3_3
                                    497 ;	main.c:92: return;
                                    498 ;	main.c:93: }
      0000B4 22               [24]  499 	ret
                                    500 ;------------------------------------------------------------
                                    501 ;Allocation info for local variables in function 'VFD_printf'
                                    502 ;------------------------------------------------------------
                                    503 ;str                       Allocated to registers r5 r6 r7 
                                    504 ;i                         Allocated to registers r4 
                                    505 ;------------------------------------------------------------
                                    506 ;	main.c:103: void VFD_printf(char* str)
                                    507 ;	-----------------------------------------
                                    508 ;	 function VFD_printf
                                    509 ;	-----------------------------------------
      0000B5                        510 _VFD_printf:
      0000B5 AD 82            [24]  511 	mov	r5,dpl
      0000B7 AE 83            [24]  512 	mov	r6,dph
      0000B9 AF F0            [24]  513 	mov	r7,b
                                    514 ;	main.c:106: while(str[i])
      0000BB 7C 00            [12]  515 	mov	r4,#0x00
      0000BD                        516 00101$:
      0000BD EC               [12]  517 	mov	a,r4
      0000BE 2D               [12]  518 	add	a,r5
      0000BF F9               [12]  519 	mov	r1,a
      0000C0 E4               [12]  520 	clr	a
      0000C1 3E               [12]  521 	addc	a,r6
      0000C2 FA               [12]  522 	mov	r2,a
      0000C3 8F 03            [24]  523 	mov	ar3,r7
      0000C5 89 82            [24]  524 	mov	dpl,r1
      0000C7 8A 83            [24]  525 	mov	dph,r2
      0000C9 8B F0            [24]  526 	mov	b,r3
      0000CB 12 03 E9         [24]  527 	lcall	__gptrget
      0000CE FB               [12]  528 	mov	r3,a
      0000CF 60 18            [24]  529 	jz	00104$
                                    530 ;	main.c:108: VFD_putc(str[i]);
      0000D1 8B 82            [24]  531 	mov	dpl,r3
      0000D3 C0 07            [24]  532 	push	ar7
      0000D5 C0 06            [24]  533 	push	ar6
      0000D7 C0 05            [24]  534 	push	ar5
      0000D9 C0 04            [24]  535 	push	ar4
      0000DB 12 00 9E         [24]  536 	lcall	_VFD_putc
      0000DE D0 04            [24]  537 	pop	ar4
      0000E0 D0 05            [24]  538 	pop	ar5
      0000E2 D0 06            [24]  539 	pop	ar6
      0000E4 D0 07            [24]  540 	pop	ar7
                                    541 ;	main.c:109: i++;
      0000E6 0C               [12]  542 	inc	r4
      0000E7 80 D4            [24]  543 	sjmp	00101$
      0000E9                        544 00104$:
                                    545 ;	main.c:111: }
      0000E9 22               [24]  546 	ret
                                    547 ;------------------------------------------------------------
                                    548 ;Allocation info for local variables in function 'main'
                                    549 ;------------------------------------------------------------
                                    550 ;__1310720001              Allocated to registers 
                                    551 ;cmd                       Allocated to registers 
                                    552 ;__1310720003              Allocated to registers 
                                    553 ;cmd                       Allocated to registers 
                                    554 ;__1310720001              Allocated to registers 
                                    555 ;cmd                       Allocated to registers 
                                    556 ;__1310720003              Allocated to registers 
                                    557 ;cmd                       Allocated to registers 
                                    558 ;chksum                    Allocated with name '_main_chksum_327680_70'
                                    559 ;i                         Allocated to registers r7 
                                    560 ;i                         Allocated to registers r7 
                                    561 ;i                         Allocated to registers r7 
                                    562 ;res                       Allocated to registers r6 
                                    563 ;humidity                  Allocated with name '_main_humidity_131073_48'
                                    564 ;temperature               Allocated with name '_main_temperature_131074_49'
                                    565 ;__1310720001              Allocated to registers 
                                    566 ;cmd                       Allocated to registers 
                                    567 ;__1310720003              Allocated to registers 
                                    568 ;cmd                       Allocated to registers 
                                    569 ;__1966100010              Allocated to registers 
                                    570 ;offset                    Allocated to registers r7 
                                    571 ;__1310720001              Allocated to registers 
                                    572 ;cmd                       Allocated to registers 
                                    573 ;__1310720003              Allocated to registers 
                                    574 ;cmd                       Allocated to registers 
                                    575 ;__1966100013              Allocated to registers 
                                    576 ;offset                    Allocated to registers r7 
                                    577 ;------------------------------------------------------------
                                    578 ;	main.c:229: void main(void)
                                    579 ;	-----------------------------------------
                                    580 ;	 function main
                                    581 ;	-----------------------------------------
      0000EA                        582 _main:
                                    583 ;	main.c:235: DHT_DATA = 1;       // Enable pull-up resistor
                                    584 ;	assignBit
      0000EA D2 B7            [12]  585 	setb	_P3_7
                                    586 ;	main.c:237: LED_TEST = 0;
                                    587 ;	assignBit
      0000EC C2 B6            [12]  588 	clr	_P3_6
                                    589 ;	main.c:240: mDelaymS(10);
      0000EE 90 00 0A         [24]  590 	mov	dptr,#0x000a
      0000F1 12 00 80         [24]  591 	lcall	_mDelaymS
                                    592 ;	main.c:98: VFD_putc(cmd);
      0000F4 75 82 0D         [24]  593 	mov	dpl,#0x0d
      0000F7 12 00 9E         [24]  594 	lcall	_VFD_putc
                                    595 ;	main.c:100: mDelay10uS(100);
      0000FA 90 00 64         [24]  596 	mov	dptr,#0x0064
      0000FD 12 00 6E         [24]  597 	lcall	_mDelay10uS
                                    598 ;	main.c:98: VFD_putc(cmd);
      000100 75 82 0E         [24]  599 	mov	dpl,#0x0e
      000103 12 00 9E         [24]  600 	lcall	_VFD_putc
                                    601 ;	main.c:100: mDelay10uS(100);
      000106 90 00 64         [24]  602 	mov	dptr,#0x0064
      000109 12 00 6E         [24]  603 	lcall	_mDelay10uS
                                    604 ;	main.c:242: VFD_printf("Howdy!");
      00010C 90 04 09         [24]  605 	mov	dptr,#___str_0
      00010F 75 F0 80         [24]  606 	mov	b,#0x80
      000112 12 00 B5         [24]  607 	lcall	_VFD_printf
                                    608 ;	main.c:244: mDelaymS(1000);
      000115 90 03 E8         [24]  609 	mov	dptr,#0x03e8
      000118 12 00 80         [24]  610 	lcall	_mDelaymS
                                    611 ;	main.c:246: while(1)
      00011B                        612 00112$:
                                    613 ;	main.c:98: VFD_putc(cmd);
      00011B 75 82 0D         [24]  614 	mov	dpl,#0x0d
      00011E 12 00 9E         [24]  615 	lcall	_VFD_putc
                                    616 ;	main.c:100: mDelay10uS(100);
      000121 90 00 64         [24]  617 	mov	dptr,#0x0064
      000124 12 00 6E         [24]  618 	lcall	_mDelay10uS
                                    619 ;	main.c:98: VFD_putc(cmd);
      000127 75 82 0E         [24]  620 	mov	dpl,#0x0e
      00012A 12 00 9E         [24]  621 	lcall	_VFD_putc
                                    622 ;	main.c:100: mDelay10uS(100);
      00012D 90 00 64         [24]  623 	mov	dptr,#0x0064
      000130 12 00 6E         [24]  624 	lcall	_mDelay10uS
                                    625 ;	main.c:131: DHT_DATA = 0;
                                    626 ;	assignBit
      000133 C2 B7            [12]  627 	clr	_P3_7
                                    628 ;	main.c:133: mDelay10uS(100);
      000135 90 00 64         [24]  629 	mov	dptr,#0x0064
      000138 12 00 6E         [24]  630 	lcall	_mDelay10uS
                                    631 ;	main.c:135: DHT_DATA = 1;
                                    632 ;	assignBit
      00013B D2 B7            [12]  633 	setb	_P3_7
                                    634 ;	main.c:145: while(DHT_DATA)
      00013D                        635 00121$:
      00013D 20 B7 FD         [24]  636 	jb	_P3_7,00121$
                                    637 ;	main.c:151: while(!DHT_DATA)
      000140                        638 00124$:
      000140 30 B7 FD         [24]  639 	jnb	_P3_7,00124$
                                    640 ;	main.c:157: while(DHT_DATA)
      000143                        641 00127$:
      000143 20 B7 FD         [24]  642 	jb	_P3_7,00127$
                                    643 ;	main.c:165: for(unsigned char i = 0; i < 16; i++)
      000146 7F 00            [12]  644 	mov	r7,#0x00
      000148                        645 00175$:
      000148 BF 10 00         [24]  646 	cjne	r7,#0x10,00325$
      00014B                        647 00325$:
      00014B 50 24            [24]  648 	jnc	00138$
                                    649 ;	main.c:167: while(!DHT_DATA);	//wait for pulse to begin
      00014D                        650 00130$:
      00014D 30 B7 FD         [24]  651 	jnb	_P3_7,00130$
                                    652 ;	main.c:170: mDelay10uS(4);
      000150 90 00 04         [24]  653 	mov	dptr,#0x0004
      000153 C0 07            [24]  654 	push	ar7
      000155 12 00 6E         [24]  655 	lcall	_mDelay10uS
      000158 D0 07            [24]  656 	pop	ar7
                                    657 ;	main.c:172: RH = RH << 1;
      00015A E5 08            [12]  658 	mov	a,_RH
      00015C 25 08            [12]  659 	add	a,_RH
      00015E F5 08            [12]  660 	mov	_RH,a
      000160 E5 09            [12]  661 	mov	a,(_RH + 1)
      000162 33               [12]  662 	rlc	a
      000163 F5 09            [12]  663 	mov	(_RH + 1),a
                                    664 ;	main.c:173: if(DHT_DATA)
      000165 30 B7 03         [24]  665 	jnb	_P3_7,00135$
                                    666 ;	main.c:175: RH = RH | 1;
      000168 43 08 01         [24]  667 	orl	_RH,#0x01
                                    668 ;	main.c:178: while(DHT_DATA);	//wait for pulse to end (if it hasnt already)
      00016B                        669 00135$:
      00016B 20 B7 FD         [24]  670 	jb	_P3_7,00135$
                                    671 ;	main.c:165: for(unsigned char i = 0; i < 16; i++)
      00016E 0F               [12]  672 	inc	r7
      00016F 80 D7            [24]  673 	sjmp	00175$
      000171                        674 00138$:
                                    675 ;	main.c:184: for(unsigned char i = 0; i < 16; i++)
      000171 7F 00            [12]  676 	mov	r7,#0x00
      000173                        677 00178$:
      000173 BF 10 00         [24]  678 	cjne	r7,#0x10,00330$
      000176                        679 00330$:
      000176 50 24            [24]  680 	jnc	00147$
                                    681 ;	main.c:186: while(!DHT_DATA);
      000178                        682 00139$:
      000178 30 B7 FD         [24]  683 	jnb	_P3_7,00139$
                                    684 ;	main.c:189: mDelay10uS(4);
      00017B 90 00 04         [24]  685 	mov	dptr,#0x0004
      00017E C0 07            [24]  686 	push	ar7
      000180 12 00 6E         [24]  687 	lcall	_mDelay10uS
      000183 D0 07            [24]  688 	pop	ar7
                                    689 ;	main.c:191: T = T << 1;
      000185 E5 0C            [12]  690 	mov	a,_T
      000187 25 0C            [12]  691 	add	a,_T
      000189 F5 0C            [12]  692 	mov	_T,a
      00018B E5 0D            [12]  693 	mov	a,(_T + 1)
      00018D 33               [12]  694 	rlc	a
      00018E F5 0D            [12]  695 	mov	(_T + 1),a
                                    696 ;	main.c:192: if(DHT_DATA)
      000190 30 B7 03         [24]  697 	jnb	_P3_7,00144$
                                    698 ;	main.c:194: T = T | 1;
      000193 43 0C 01         [24]  699 	orl	_T,#0x01
                                    700 ;	main.c:197: while(DHT_DATA);
      000196                        701 00144$:
      000196 20 B7 FD         [24]  702 	jb	_P3_7,00144$
                                    703 ;	main.c:184: for(unsigned char i = 0; i < 16; i++)
      000199 0F               [12]  704 	inc	r7
      00019A 80 D7            [24]  705 	sjmp	00178$
      00019C                        706 00147$:
                                    707 ;	main.c:203: for(unsigned char i = 0; i < 8; i++)
      00019C 7F 00            [12]  708 	mov	r7,#0x00
      00019E                        709 00181$:
      00019E BF 08 00         [24]  710 	cjne	r7,#0x08,00335$
      0001A1                        711 00335$:
      0001A1 50 20            [24]  712 	jnc	00156$
                                    713 ;	main.c:205: while(!DHT_DATA);
      0001A3                        714 00148$:
      0001A3 30 B7 FD         [24]  715 	jnb	_P3_7,00148$
                                    716 ;	main.c:208: mDelay10uS(4);
      0001A6 90 00 04         [24]  717 	mov	dptr,#0x0004
      0001A9 C0 07            [24]  718 	push	ar7
      0001AB 12 00 6E         [24]  719 	lcall	_mDelay10uS
      0001AE D0 07            [24]  720 	pop	ar7
                                    721 ;	main.c:210: chksum = chksum << 1;
      0001B0 E5 10            [12]  722 	mov	a,_main_chksum_327680_70
      0001B2 FE               [12]  723 	mov	r6,a
      0001B3 25 E0            [12]  724 	add	a,acc
      0001B5 F5 10            [12]  725 	mov	_main_chksum_327680_70,a
                                    726 ;	main.c:211: if(DHT_DATA)
      0001B7 30 B7 03         [24]  727 	jnb	_P3_7,00153$
                                    728 ;	main.c:213: chksum = chksum | 1;
      0001BA 43 10 01         [24]  729 	orl	_main_chksum_327680_70,#0x01
                                    730 ;	main.c:216: while(DHT_DATA);
      0001BD                        731 00153$:
      0001BD 20 B7 FD         [24]  732 	jb	_P3_7,00153$
                                    733 ;	main.c:203: for(unsigned char i = 0; i < 8; i++)
      0001C0 0F               [12]  734 	inc	r7
      0001C1 80 DB            [24]  735 	sjmp	00181$
      0001C3                        736 00156$:
                                    737 ;	main.c:221: unsigned char res = (RH & 0xFF) + (RH >> 8) + (T & 0xFF) + (T >> 8);
      0001C3 AF 08            [24]  738 	mov	r7,_RH
      0001C5 E5 09            [12]  739 	mov	a,(_RH + 1)
      0001C7 2F               [12]  740 	add	a,r7
      0001C8 FE               [12]  741 	mov	r6,a
      0001C9 E5 0C            [12]  742 	mov	a,_T
      0001CB 2E               [12]  743 	add	a,r6
      0001CC FE               [12]  744 	mov	r6,a
      0001CD E5 0D            [12]  745 	mov	a,(_T + 1)
      0001CF 2E               [12]  746 	add	a,r6
                                    747 ;	main.c:222: if (res != chksum)
      0001D0 B5 10 02         [24]  748 	cjne	a,_main_chksum_327680_70,00340$
      0001D3 80 0C            [24]  749 	sjmp	00159$
      0001D5                        750 00340$:
                                    751 ;	main.c:224: RH = 0xDEAD;
      0001D5 75 08 AD         [24]  752 	mov	_RH,#0xad
      0001D8 75 09 DE         [24]  753 	mov	(_RH + 1),#0xde
                                    754 ;	main.c:225: T = 0xBEEF;
      0001DB 75 0C EF         [24]  755 	mov	_T,#0xef
      0001DE 75 0D BE         [24]  756 	mov	(_T + 1),#0xbe
                                    757 ;	main.c:250: DHT_read_data();
      0001E1                        758 00159$:
                                    759 ;	main.c:253: humidity[4]=0x00;
      0001E1 75 15 00         [24]  760 	mov	(_main_humidity_131073_48 + 0x0004),#0x00
                                    761 ;	main.c:254: humidity[3] = RH % 10 + 0x30;
      0001E4 75 1C 0A         [24]  762 	mov	__moduint_PARM_2,#0x0a
      0001E7 75 1D 00         [24]  763 	mov	(__moduint_PARM_2 + 1),#0x00
      0001EA 85 08 82         [24]  764 	mov	dpl,_RH
      0001ED 85 09 83         [24]  765 	mov	dph,(_RH + 1)
      0001F0 12 03 9C         [24]  766 	lcall	__moduint
      0001F3 AE 82            [24]  767 	mov	r6,dpl
      0001F5 74 30            [12]  768 	mov	a,#0x30
      0001F7 2E               [12]  769 	add	a,r6
      0001F8 F5 14            [12]  770 	mov	(_main_humidity_131073_48 + 0x0003),a
                                    771 ;	main.c:255: humidity[2] = '.';
      0001FA 75 13 2E         [24]  772 	mov	(_main_humidity_131073_48 + 0x0002),#0x2e
                                    773 ;	main.c:256: RH = RH / 10;
      0001FD 75 1C 0A         [24]  774 	mov	__divuint_PARM_2,#0x0a
      000200 75 1D 00         [24]  775 	mov	(__divuint_PARM_2 + 1),#0x00
      000203 85 08 82         [24]  776 	mov	dpl,_RH
      000206 85 09 83         [24]  777 	mov	dph,(_RH + 1)
      000209 12 03 73         [24]  778 	lcall	__divuint
                                    779 ;	main.c:257: humidity[1] = RH % 10 + 0x30;
      00020C 85 82 08         [24]  780 	mov	_RH,dpl
      00020F 85 83 09         [24]  781 	mov	(_RH + 1),dph
      000212 75 1C 0A         [24]  782 	mov	__moduint_PARM_2,#0x0a
      000215 75 1D 00         [24]  783 	mov	(__moduint_PARM_2 + 1),#0x00
      000218 12 03 9C         [24]  784 	lcall	__moduint
      00021B AE 82            [24]  785 	mov	r6,dpl
      00021D 74 30            [12]  786 	mov	a,#0x30
      00021F 2E               [12]  787 	add	a,r6
      000220 F5 12            [12]  788 	mov	(_main_humidity_131073_48 + 0x0001),a
                                    789 ;	main.c:258: RH = RH / 10;
      000222 75 1C 0A         [24]  790 	mov	__divuint_PARM_2,#0x0a
      000225 75 1D 00         [24]  791 	mov	(__divuint_PARM_2 + 1),#0x00
      000228 85 08 82         [24]  792 	mov	dpl,_RH
      00022B 85 09 83         [24]  793 	mov	dph,(_RH + 1)
      00022E 12 03 73         [24]  794 	lcall	__divuint
                                    795 ;	main.c:259: humidity[0] = RH % 10 + 0x30;
      000231 85 82 08         [24]  796 	mov	_RH,dpl
      000234 85 83 09         [24]  797 	mov	(_RH + 1),dph
      000237 75 1C 0A         [24]  798 	mov	__moduint_PARM_2,#0x0a
      00023A 75 1D 00         [24]  799 	mov	(__moduint_PARM_2 + 1),#0x00
      00023D 12 03 9C         [24]  800 	lcall	__moduint
      000240 AE 82            [24]  801 	mov	r6,dpl
      000242 74 30            [12]  802 	mov	a,#0x30
      000244 2E               [12]  803 	add	a,r6
      000245 F5 11            [12]  804 	mov	_main_humidity_131073_48,a
                                    805 ;	main.c:262: temperature[0] = '+';
      000247 75 16 2B         [24]  806 	mov	_main_temperature_131074_49,#0x2b
                                    807 ;	main.c:263: if(T & 0x8000)
      00024A E5 0D            [12]  808 	mov	a,(_T + 1)
      00024C 30 E7 03         [24]  809 	jnb	acc.7,00102$
                                    810 ;	main.c:264: temperature[0] = '-';
      00024F 75 16 2D         [24]  811 	mov	_main_temperature_131074_49,#0x2d
      000252                        812 00102$:
                                    813 ;	main.c:265: T = T & 0x7FFF;
      000252 53 0D 7F         [24]  814 	anl	(_T + 1),#0x7f
                                    815 ;	main.c:266: temperature[5]=0x00;
      000255 75 1B 00         [24]  816 	mov	(_main_temperature_131074_49 + 0x0005),#0x00
                                    817 ;	main.c:267: temperature[4] = T % 10 + 0x30;
      000258 75 1C 0A         [24]  818 	mov	__moduint_PARM_2,#0x0a
      00025B 75 1D 00         [24]  819 	mov	(__moduint_PARM_2 + 1),#0x00
      00025E 85 0C 82         [24]  820 	mov	dpl,_T
      000261 85 0D 83         [24]  821 	mov	dph,(_T + 1)
      000264 12 03 9C         [24]  822 	lcall	__moduint
      000267 AE 82            [24]  823 	mov	r6,dpl
      000269 74 30            [12]  824 	mov	a,#0x30
      00026B 2E               [12]  825 	add	a,r6
      00026C F5 1A            [12]  826 	mov	(_main_temperature_131074_49 + 0x0004),a
                                    827 ;	main.c:268: temperature[3] = '.';
      00026E 75 19 2E         [24]  828 	mov	(_main_temperature_131074_49 + 0x0003),#0x2e
                                    829 ;	main.c:269: T = T / 10;
      000271 75 1C 0A         [24]  830 	mov	__divuint_PARM_2,#0x0a
      000274 75 1D 00         [24]  831 	mov	(__divuint_PARM_2 + 1),#0x00
      000277 85 0C 82         [24]  832 	mov	dpl,_T
      00027A 85 0D 83         [24]  833 	mov	dph,(_T + 1)
      00027D 12 03 73         [24]  834 	lcall	__divuint
                                    835 ;	main.c:270: temperature[2] = T % 10 + 0x30;
      000280 85 82 0C         [24]  836 	mov	_T,dpl
      000283 85 83 0D         [24]  837 	mov	(_T + 1),dph
      000286 75 1C 0A         [24]  838 	mov	__moduint_PARM_2,#0x0a
      000289 75 1D 00         [24]  839 	mov	(__moduint_PARM_2 + 1),#0x00
      00028C 12 03 9C         [24]  840 	lcall	__moduint
      00028F AE 82            [24]  841 	mov	r6,dpl
      000291 74 30            [12]  842 	mov	a,#0x30
      000293 2E               [12]  843 	add	a,r6
      000294 F5 18            [12]  844 	mov	(_main_temperature_131074_49 + 0x0002),a
                                    845 ;	main.c:271: T = T / 10;
      000296 75 1C 0A         [24]  846 	mov	__divuint_PARM_2,#0x0a
      000299 75 1D 00         [24]  847 	mov	(__divuint_PARM_2 + 1),#0x00
      00029C 85 0C 82         [24]  848 	mov	dpl,_T
      00029F 85 0D 83         [24]  849 	mov	dph,(_T + 1)
      0002A2 12 03 73         [24]  850 	lcall	__divuint
                                    851 ;	main.c:272: temperature[1] = T % 10 + 0x30;
      0002A5 85 82 0C         [24]  852 	mov	_T,dpl
      0002A8 85 83 0D         [24]  853 	mov	(_T + 1),dph
      0002AB 75 1C 0A         [24]  854 	mov	__moduint_PARM_2,#0x0a
      0002AE 75 1D 00         [24]  855 	mov	(__moduint_PARM_2 + 1),#0x00
      0002B1 12 03 9C         [24]  856 	lcall	__moduint
      0002B4 AE 82            [24]  857 	mov	r6,dpl
      0002B6 74 30            [12]  858 	mov	a,#0x30
      0002B8 2E               [12]  859 	add	a,r6
      0002B9 F5 17            [12]  860 	mov	(_main_temperature_131074_49 + 0x0001),a
                                    861 ;	main.c:98: VFD_putc(cmd);
      0002BB 75 82 0D         [24]  862 	mov	dpl,#0x0d
      0002BE 12 00 9E         [24]  863 	lcall	_VFD_putc
                                    864 ;	main.c:100: mDelay10uS(100);
      0002C1 90 00 64         [24]  865 	mov	dptr,#0x0064
      0002C4 12 00 6E         [24]  866 	lcall	_mDelay10uS
                                    867 ;	main.c:98: VFD_putc(cmd);
      0002C7 75 82 0E         [24]  868 	mov	dpl,#0x0e
      0002CA 12 00 9E         [24]  869 	lcall	_VFD_putc
                                    870 ;	main.c:100: mDelay10uS(100);
      0002CD 90 00 64         [24]  871 	mov	dptr,#0x0064
      0002D0 12 00 6E         [24]  872 	lcall	_mDelay10uS
                                    873 ;	main.c:275: VFD_padding(offsetRH);
      0002D3 AF 0A            [24]  874 	mov	r7,_offsetRH
                                    875 ;	main.c:115: while(offset != 0)
      0002D5                        876 00163$:
      0002D5 EF               [12]  877 	mov	a,r7
      0002D6 60 0D            [24]  878 	jz	00166$
                                    879 ;	main.c:117: VFD_putc(' ');
      0002D8 75 82 20         [24]  880 	mov	dpl,#0x20
      0002DB C0 07            [24]  881 	push	ar7
      0002DD 12 00 9E         [24]  882 	lcall	_VFD_putc
      0002E0 D0 07            [24]  883 	pop	ar7
                                    884 ;	main.c:118: offset--;
      0002E2 1F               [12]  885 	dec	r7
                                    886 ;	main.c:275: VFD_padding(offsetRH);
      0002E3 80 F0            [24]  887 	sjmp	00163$
      0002E5                        888 00166$:
                                    889 ;	main.c:276: VFD_printf("Humidity: ");
      0002E5 90 04 10         [24]  890 	mov	dptr,#___str_1
      0002E8 75 F0 80         [24]  891 	mov	b,#0x80
      0002EB 12 00 B5         [24]  892 	lcall	_VFD_printf
                                    893 ;	main.c:277: VFD_printf(humidity);
      0002EE 90 00 11         [24]  894 	mov	dptr,#_main_humidity_131073_48
      0002F1 75 F0 40         [24]  895 	mov	b,#0x40
      0002F4 12 00 B5         [24]  896 	lcall	_VFD_printf
                                    897 ;	main.c:279: mDelaymS(1000);
      0002F7 90 03 E8         [24]  898 	mov	dptr,#0x03e8
      0002FA 12 00 80         [24]  899 	lcall	_mDelaymS
                                    900 ;	main.c:280: LED_TEST = 0;
                                    901 ;	assignBit
      0002FD C2 B6            [12]  902 	clr	_P3_6
                                    903 ;	main.c:98: VFD_putc(cmd);
      0002FF 75 82 0D         [24]  904 	mov	dpl,#0x0d
      000302 12 00 9E         [24]  905 	lcall	_VFD_putc
                                    906 ;	main.c:100: mDelay10uS(100);
      000305 90 00 64         [24]  907 	mov	dptr,#0x0064
      000308 12 00 6E         [24]  908 	lcall	_mDelay10uS
                                    909 ;	main.c:98: VFD_putc(cmd);
      00030B 75 82 0E         [24]  910 	mov	dpl,#0x0e
      00030E 12 00 9E         [24]  911 	lcall	_VFD_putc
                                    912 ;	main.c:100: mDelay10uS(100);
      000311 90 00 64         [24]  913 	mov	dptr,#0x0064
      000314 12 00 6E         [24]  914 	lcall	_mDelay10uS
                                    915 ;	main.c:283: VFD_padding(offsetT);
      000317 AF 0E            [24]  916 	mov	r7,_offsetT
                                    917 ;	main.c:115: while(offset != 0)
      000319                        918 00170$:
      000319 EF               [12]  919 	mov	a,r7
      00031A 60 0D            [24]  920 	jz	00173$
                                    921 ;	main.c:117: VFD_putc(' ');
      00031C 75 82 20         [24]  922 	mov	dpl,#0x20
      00031F C0 07            [24]  923 	push	ar7
      000321 12 00 9E         [24]  924 	lcall	_VFD_putc
      000324 D0 07            [24]  925 	pop	ar7
                                    926 ;	main.c:118: offset--;
      000326 1F               [12]  927 	dec	r7
                                    928 ;	main.c:283: VFD_padding(offsetT);
      000327 80 F0            [24]  929 	sjmp	00170$
      000329                        930 00173$:
                                    931 ;	main.c:284: VFD_printf("Temperature: ");
      000329 90 04 1B         [24]  932 	mov	dptr,#___str_2
      00032C 75 F0 80         [24]  933 	mov	b,#0x80
      00032F 12 00 B5         [24]  934 	lcall	_VFD_printf
                                    935 ;	main.c:285: VFD_printf(temperature);
      000332 90 00 16         [24]  936 	mov	dptr,#_main_temperature_131074_49
      000335 75 F0 40         [24]  937 	mov	b,#0x40
      000338 12 00 B5         [24]  938 	lcall	_VFD_printf
                                    939 ;	main.c:287: mDelaymS(1000);
      00033B 90 03 E8         [24]  940 	mov	dptr,#0x03e8
      00033E 12 00 80         [24]  941 	lcall	_mDelaymS
                                    942 ;	main.c:288: LED_TEST = 1;
                                    943 ;	assignBit
      000341 D2 B6            [12]  944 	setb	_P3_6
                                    945 ;	main.c:290: offsetRH = offsetRH + dirRH;
      000343 E5 0B            [12]  946 	mov	a,_dirRH
      000345 25 0A            [12]  947 	add	a,_offsetRH
      000347 F5 0A            [12]  948 	mov	_offsetRH,a
                                    949 ;	main.c:291: if (offsetRH == 6)
      000349 74 06            [12]  950 	mov	a,#0x06
      00034B B5 0A 03         [24]  951 	cjne	a,_offsetRH,00104$
                                    952 ;	main.c:292: dirRH = -1;
      00034E 75 0B FF         [24]  953 	mov	_dirRH,#0xff
      000351                        954 00104$:
                                    955 ;	main.c:293: if (offsetRH == 0)
      000351 E5 0A            [12]  956 	mov	a,_offsetRH
      000353 70 03            [24]  957 	jnz	00106$
                                    958 ;	main.c:294: dirRH = 1;
      000355 75 0B 01         [24]  959 	mov	_dirRH,#0x01
      000358                        960 00106$:
                                    961 ;	main.c:296: offsetT = offsetT + dirT;
      000358 E5 0F            [12]  962 	mov	a,_dirT
      00035A 25 0E            [12]  963 	add	a,_offsetT
      00035C F5 0E            [12]  964 	mov	_offsetT,a
                                    965 ;	main.c:297: if (offsetT == 2)
      00035E 74 02            [12]  966 	mov	a,#0x02
      000360 B5 0E 03         [24]  967 	cjne	a,_offsetT,00108$
                                    968 ;	main.c:298: dirT = -1;
      000363 75 0F FF         [24]  969 	mov	_dirT,#0xff
      000366                        970 00108$:
                                    971 ;	main.c:299: if (offsetT == 0)
      000366 E5 0E            [12]  972 	mov	a,_offsetT
      000368 60 03            [24]  973 	jz	00349$
      00036A 02 01 1B         [24]  974 	ljmp	00112$
      00036D                        975 00349$:
                                    976 ;	main.c:300: dirT = 1;
      00036D 75 0F 01         [24]  977 	mov	_dirT,#0x01
                                    978 ;	main.c:302: return;
                                    979 ;	main.c:303: }
      000370 02 01 1B         [24]  980 	ljmp	00112$
                                    981 	.area CSEG    (CODE)
                                    982 	.area CONST   (CODE)
                                    983 	.area CONST   (CODE)
      000409                        984 ___str_0:
      000409 48 6F 77 64 79 21      985 	.ascii "Howdy!"
      00040F 00                     986 	.db 0x00
                                    987 	.area CSEG    (CODE)
                                    988 	.area CONST   (CODE)
      000410                        989 ___str_1:
      000410 48 75 6D 69 64 69 74   990 	.ascii "Humidity: "
             79 3A 20
      00041A 00                     991 	.db 0x00
                                    992 	.area CSEG    (CODE)
                                    993 	.area CONST   (CODE)
      00041B                        994 ___str_2:
      00041B 54 65 6D 70 65 72 61   995 	.ascii "Temperature: "
             74 75 72 65 3A 20
      000428 00                     996 	.db 0x00
                                    997 	.area CSEG    (CODE)
                                    998 	.area XINIT   (CODE)
                                    999 	.area CABS    (ABS,CODE)
