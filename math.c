
#define BF_INC(x) BF_INC_##x
#define BF_PINC(x) BF_INC(x)

// seq 0 255 |awk '{printf("#define BF_INC_%x %x\n", $1, $1 == 0xFF ? 0 : ($1+1))}'

#define BF_INC_0 1
#define BF_INC_1 2
#define BF_INC_2 3
#define BF_INC_3 4
#define BF_INC_4 5
#define BF_INC_5 6
#define BF_INC_6 7
#define BF_INC_7 8
#define BF_INC_8 9
#define BF_INC_9 a
#define BF_INC_a b
#define BF_INC_b c
#define BF_INC_c d
#define BF_INC_d e
#define BF_INC_e f
#define BF_INC_f 10
#define BF_INC_10 11
#define BF_INC_11 12
#define BF_INC_12 13
#define BF_INC_13 14
#define BF_INC_14 15
#define BF_INC_15 16
#define BF_INC_16 17
#define BF_INC_17 18
#define BF_INC_18 19
#define BF_INC_19 1a
#define BF_INC_1a 1b
#define BF_INC_1b 1c
#define BF_INC_1c 1d
#define BF_INC_1d 1e
#define BF_INC_1e 1f
#define BF_INC_1f 20
#define BF_INC_20 21
#define BF_INC_21 22
#define BF_INC_22 23
#define BF_INC_23 24
#define BF_INC_24 25
#define BF_INC_25 26
#define BF_INC_26 27
#define BF_INC_27 28
#define BF_INC_28 29
#define BF_INC_29 2a
#define BF_INC_2a 2b
#define BF_INC_2b 2c
#define BF_INC_2c 2d
#define BF_INC_2d 2e
#define BF_INC_2e 2f
#define BF_INC_2f 30
#define BF_INC_30 31
#define BF_INC_31 32
#define BF_INC_32 33
#define BF_INC_33 34
#define BF_INC_34 35
#define BF_INC_35 36
#define BF_INC_36 37
#define BF_INC_37 38
#define BF_INC_38 39
#define BF_INC_39 3a
#define BF_INC_3a 3b
#define BF_INC_3b 3c
#define BF_INC_3c 3d
#define BF_INC_3d 3e
#define BF_INC_3e 3f
#define BF_INC_3f 40
#define BF_INC_40 41
#define BF_INC_41 42
#define BF_INC_42 43
#define BF_INC_43 44
#define BF_INC_44 45
#define BF_INC_45 46
#define BF_INC_46 47
#define BF_INC_47 48
#define BF_INC_48 49
#define BF_INC_49 4a
#define BF_INC_4a 4b
#define BF_INC_4b 4c
#define BF_INC_4c 4d
#define BF_INC_4d 4e
#define BF_INC_4e 4f
#define BF_INC_4f 50
#define BF_INC_50 51
#define BF_INC_51 52
#define BF_INC_52 53
#define BF_INC_53 54
#define BF_INC_54 55
#define BF_INC_55 56
#define BF_INC_56 57
#define BF_INC_57 58
#define BF_INC_58 59
#define BF_INC_59 5a
#define BF_INC_5a 5b
#define BF_INC_5b 5c
#define BF_INC_5c 5d
#define BF_INC_5d 5e
#define BF_INC_5e 5f
#define BF_INC_5f 60
#define BF_INC_60 61
#define BF_INC_61 62
#define BF_INC_62 63
#define BF_INC_63 64
#define BF_INC_64 65
#define BF_INC_65 66
#define BF_INC_66 67
#define BF_INC_67 68
#define BF_INC_68 69
#define BF_INC_69 6a
#define BF_INC_6a 6b
#define BF_INC_6b 6c
#define BF_INC_6c 6d
#define BF_INC_6d 6e
#define BF_INC_6e 6f
#define BF_INC_6f 70
#define BF_INC_70 71
#define BF_INC_71 72
#define BF_INC_72 73
#define BF_INC_73 74
#define BF_INC_74 75
#define BF_INC_75 76
#define BF_INC_76 77
#define BF_INC_77 78
#define BF_INC_78 79
#define BF_INC_79 7a
#define BF_INC_7a 7b
#define BF_INC_7b 7c
#define BF_INC_7c 7d
#define BF_INC_7d 7e
#define BF_INC_7e 7f
#define BF_INC_7f 80
#define BF_INC_80 81
#define BF_INC_81 82
#define BF_INC_82 83
#define BF_INC_83 84
#define BF_INC_84 85
#define BF_INC_85 86
#define BF_INC_86 87
#define BF_INC_87 88
#define BF_INC_88 89
#define BF_INC_89 8a
#define BF_INC_8a 8b
#define BF_INC_8b 8c
#define BF_INC_8c 8d
#define BF_INC_8d 8e
#define BF_INC_8e 8f
#define BF_INC_8f 90
#define BF_INC_90 91
#define BF_INC_91 92
#define BF_INC_92 93
#define BF_INC_93 94
#define BF_INC_94 95
#define BF_INC_95 96
#define BF_INC_96 97
#define BF_INC_97 98
#define BF_INC_98 99
#define BF_INC_99 9a
#define BF_INC_9a 9b
#define BF_INC_9b 9c
#define BF_INC_9c 9d
#define BF_INC_9d 9e
#define BF_INC_9e 9f
#define BF_INC_9f a0
#define BF_INC_a0 a1
#define BF_INC_a1 a2
#define BF_INC_a2 a3
#define BF_INC_a3 a4
#define BF_INC_a4 a5
#define BF_INC_a5 a6
#define BF_INC_a6 a7
#define BF_INC_a7 a8
#define BF_INC_a8 a9
#define BF_INC_a9 aa
#define BF_INC_aa ab
#define BF_INC_ab ac
#define BF_INC_ac ad
#define BF_INC_ad ae
#define BF_INC_ae af
#define BF_INC_af b0
#define BF_INC_b0 b1
#define BF_INC_b1 b2
#define BF_INC_b2 b3
#define BF_INC_b3 b4
#define BF_INC_b4 b5
#define BF_INC_b5 b6
#define BF_INC_b6 b7
#define BF_INC_b7 b8
#define BF_INC_b8 b9
#define BF_INC_b9 ba
#define BF_INC_ba bb
#define BF_INC_bb bc
#define BF_INC_bc bd
#define BF_INC_bd be
#define BF_INC_be bf
#define BF_INC_bf c0
#define BF_INC_c0 c1
#define BF_INC_c1 c2
#define BF_INC_c2 c3
#define BF_INC_c3 c4
#define BF_INC_c4 c5
#define BF_INC_c5 c6
#define BF_INC_c6 c7
#define BF_INC_c7 c8
#define BF_INC_c8 c9
#define BF_INC_c9 ca
#define BF_INC_ca cb
#define BF_INC_cb cc
#define BF_INC_cc cd
#define BF_INC_cd ce
#define BF_INC_ce cf
#define BF_INC_cf d0
#define BF_INC_d0 d1
#define BF_INC_d1 d2
#define BF_INC_d2 d3
#define BF_INC_d3 d4
#define BF_INC_d4 d5
#define BF_INC_d5 d6
#define BF_INC_d6 d7
#define BF_INC_d7 d8
#define BF_INC_d8 d9
#define BF_INC_d9 da
#define BF_INC_da db
#define BF_INC_db dc
#define BF_INC_dc dd
#define BF_INC_dd de
#define BF_INC_de df
#define BF_INC_df e0
#define BF_INC_e0 e1
#define BF_INC_e1 e2
#define BF_INC_e2 e3
#define BF_INC_e3 e4
#define BF_INC_e4 e5
#define BF_INC_e5 e6
#define BF_INC_e6 e7
#define BF_INC_e7 e8
#define BF_INC_e8 e9
#define BF_INC_e9 ea
#define BF_INC_ea eb
#define BF_INC_eb ec
#define BF_INC_ec ed
#define BF_INC_ed ee
#define BF_INC_ee ef
#define BF_INC_ef f0
#define BF_INC_f0 f1
#define BF_INC_f1 f2
#define BF_INC_f2 f3
#define BF_INC_f3 f4
#define BF_INC_f4 f5
#define BF_INC_f5 f6
#define BF_INC_f6 f7
#define BF_INC_f7 f8
#define BF_INC_f8 f9
#define BF_INC_f9 fa
#define BF_INC_fa fb
#define BF_INC_fb fc
#define BF_INC_fc fd
#define BF_INC_fd fe
#define BF_INC_fe ff
#define BF_INC_ff 0


#define BF_DEC(x) BF_DEC_##x
#define BF_PDEC(x) BF_DEC(x)

// seq 0 255 |awk '{printf("#define BF_DEC_%x %x\n", $1, $1 == 0xFF ? fe : ($1-1))}'

#define BF_DEC_0 ff
#define BF_DEC_1 0
#define BF_DEC_2 1
#define BF_DEC_3 2
#define BF_DEC_4 3
#define BF_DEC_5 4
#define BF_DEC_6 5
#define BF_DEC_7 6
#define BF_DEC_8 7
#define BF_DEC_9 8
#define BF_DEC_a 9
#define BF_DEC_b a
#define BF_DEC_c b
#define BF_DEC_d c
#define BF_DEC_e d
#define BF_DEC_f e
#define BF_DEC_10 f
#define BF_DEC_11 10
#define BF_DEC_12 11
#define BF_DEC_13 12
#define BF_DEC_14 13
#define BF_DEC_15 14
#define BF_DEC_16 15
#define BF_DEC_17 16
#define BF_DEC_18 17
#define BF_DEC_19 18
#define BF_DEC_1a 19
#define BF_DEC_1b 1a
#define BF_DEC_1c 1b
#define BF_DEC_1d 1c
#define BF_DEC_1e 1d
#define BF_DEC_1f 1e
#define BF_DEC_20 1f
#define BF_DEC_21 20
#define BF_DEC_22 21
#define BF_DEC_23 22
#define BF_DEC_24 23
#define BF_DEC_25 24
#define BF_DEC_26 25
#define BF_DEC_27 26
#define BF_DEC_28 27
#define BF_DEC_29 28
#define BF_DEC_2a 29
#define BF_DEC_2b 2a
#define BF_DEC_2c 2b
#define BF_DEC_2d 2c
#define BF_DEC_2e 2d
#define BF_DEC_2f 2e
#define BF_DEC_30 2f
#define BF_DEC_31 30
#define BF_DEC_32 31
#define BF_DEC_33 32
#define BF_DEC_34 33
#define BF_DEC_35 34
#define BF_DEC_36 35
#define BF_DEC_37 36
#define BF_DEC_38 37
#define BF_DEC_39 38
#define BF_DEC_3a 39
#define BF_DEC_3b 3a
#define BF_DEC_3c 3b
#define BF_DEC_3d 3c
#define BF_DEC_3e 3d
#define BF_DEC_3f 3e
#define BF_DEC_40 3f
#define BF_DEC_41 40
#define BF_DEC_42 41
#define BF_DEC_43 42
#define BF_DEC_44 43
#define BF_DEC_45 44
#define BF_DEC_46 45
#define BF_DEC_47 46
#define BF_DEC_48 47
#define BF_DEC_49 48
#define BF_DEC_4a 49
#define BF_DEC_4b 4a
#define BF_DEC_4c 4b
#define BF_DEC_4d 4c
#define BF_DEC_4e 4d
#define BF_DEC_4f 4e
#define BF_DEC_50 4f
#define BF_DEC_51 50
#define BF_DEC_52 51
#define BF_DEC_53 52
#define BF_DEC_54 53
#define BF_DEC_55 54
#define BF_DEC_56 55
#define BF_DEC_57 56
#define BF_DEC_58 57
#define BF_DEC_59 58
#define BF_DEC_5a 59
#define BF_DEC_5b 5a
#define BF_DEC_5c 5b
#define BF_DEC_5d 5c
#define BF_DEC_5e 5d
#define BF_DEC_5f 5e
#define BF_DEC_60 5f
#define BF_DEC_61 60
#define BF_DEC_62 61
#define BF_DEC_63 62
#define BF_DEC_64 63
#define BF_DEC_65 64
#define BF_DEC_66 65
#define BF_DEC_67 66
#define BF_DEC_68 67
#define BF_DEC_69 68
#define BF_DEC_6a 69
#define BF_DEC_6b 6a
#define BF_DEC_6c 6b
#define BF_DEC_6d 6c
#define BF_DEC_6e 6d
#define BF_DEC_6f 6e
#define BF_DEC_70 6f
#define BF_DEC_71 70
#define BF_DEC_72 71
#define BF_DEC_73 72
#define BF_DEC_74 73
#define BF_DEC_75 74
#define BF_DEC_76 75
#define BF_DEC_77 76
#define BF_DEC_78 77
#define BF_DEC_79 78
#define BF_DEC_7a 79
#define BF_DEC_7b 7a
#define BF_DEC_7c 7b
#define BF_DEC_7d 7c
#define BF_DEC_7e 7d
#define BF_DEC_7f 7e
#define BF_DEC_80 7f
#define BF_DEC_81 80
#define BF_DEC_82 81
#define BF_DEC_83 82
#define BF_DEC_84 83
#define BF_DEC_85 84
#define BF_DEC_86 85
#define BF_DEC_87 86
#define BF_DEC_88 87
#define BF_DEC_89 88
#define BF_DEC_8a 89
#define BF_DEC_8b 8a
#define BF_DEC_8c 8b
#define BF_DEC_8d 8c
#define BF_DEC_8e 8d
#define BF_DEC_8f 8e
#define BF_DEC_90 8f
#define BF_DEC_91 90
#define BF_DEC_92 91
#define BF_DEC_93 92
#define BF_DEC_94 93
#define BF_DEC_95 94
#define BF_DEC_96 95
#define BF_DEC_97 96
#define BF_DEC_98 97
#define BF_DEC_99 98
#define BF_DEC_9a 99
#define BF_DEC_9b 9a
#define BF_DEC_9c 9b
#define BF_DEC_9d 9c
#define BF_DEC_9e 9d
#define BF_DEC_9f 9e
#define BF_DEC_a0 9f
#define BF_DEC_a1 a0
#define BF_DEC_a2 a1
#define BF_DEC_a3 a2
#define BF_DEC_a4 a3
#define BF_DEC_a5 a4
#define BF_DEC_a6 a5
#define BF_DEC_a7 a6
#define BF_DEC_a8 a7
#define BF_DEC_a9 a8
#define BF_DEC_aa a9
#define BF_DEC_ab aa
#define BF_DEC_ac ab
#define BF_DEC_ad ac
#define BF_DEC_ae ad
#define BF_DEC_af ae
#define BF_DEC_b0 af
#define BF_DEC_b1 b0
#define BF_DEC_b2 b1
#define BF_DEC_b3 b2
#define BF_DEC_b4 b3
#define BF_DEC_b5 b4
#define BF_DEC_b6 b5
#define BF_DEC_b7 b6
#define BF_DEC_b8 b7
#define BF_DEC_b9 b8
#define BF_DEC_ba b9
#define BF_DEC_bb ba
#define BF_DEC_bc bb
#define BF_DEC_bd bc
#define BF_DEC_be bd
#define BF_DEC_bf be
#define BF_DEC_c0 bf
#define BF_DEC_c1 c0
#define BF_DEC_c2 c1
#define BF_DEC_c3 c2
#define BF_DEC_c4 c3
#define BF_DEC_c5 c4
#define BF_DEC_c6 c5
#define BF_DEC_c7 c6
#define BF_DEC_c8 c7
#define BF_DEC_c9 c8
#define BF_DEC_ca c9
#define BF_DEC_cb ca
#define BF_DEC_cc cb
#define BF_DEC_cd cc
#define BF_DEC_ce cd
#define BF_DEC_cf ce
#define BF_DEC_d0 cf
#define BF_DEC_d1 d0
#define BF_DEC_d2 d1
#define BF_DEC_d3 d2
#define BF_DEC_d4 d3
#define BF_DEC_d5 d4
#define BF_DEC_d6 d5
#define BF_DEC_d7 d6
#define BF_DEC_d8 d7
#define BF_DEC_d9 d8
#define BF_DEC_da d9
#define BF_DEC_db da
#define BF_DEC_dc db
#define BF_DEC_dd dc
#define BF_DEC_de dd
#define BF_DEC_df de
#define BF_DEC_e0 df
#define BF_DEC_e1 e0
#define BF_DEC_e2 e1
#define BF_DEC_e3 e2
#define BF_DEC_e4 e3
#define BF_DEC_e5 e4
#define BF_DEC_e6 e5
#define BF_DEC_e7 e6
#define BF_DEC_e8 e7
#define BF_DEC_e9 e8
#define BF_DEC_ea e9
#define BF_DEC_eb ea
#define BF_DEC_ec eb
#define BF_DEC_ed ec
#define BF_DEC_ee ed
#define BF_DEC_ef ee
#define BF_DEC_f0 ef
#define BF_DEC_f1 f0
#define BF_DEC_f2 f1
#define BF_DEC_f3 f2
#define BF_DEC_f4 f3
#define BF_DEC_f5 f4
#define BF_DEC_f6 f5
#define BF_DEC_f7 f6
#define BF_DEC_f8 f7
#define BF_DEC_f9 f8
#define BF_DEC_fa f9
#define BF_DEC_fb fa
#define BF_DEC_fc fb
#define BF_DEC_fd fc
#define BF_DEC_fe fd
#define BF_DEC_ff fe

// awk 'BEGIN{for(i=0;i<256;++i){printf("#define BF_ADD_TO_%x(F) F(",i);for(j=-7;j<8;++j)if(j>1||j<-1)printf("%x,",(x=(i+j)%256)<0?256+x:x);printf("%x)\n",(i+j)%256);}}'

#define BF_ADD_TO_0(F) F(f9,fa,fb,fc,fd,fe,2,3,4,5,6,7,8)
#define BF_ADD_TO_1(F) F(fa,fb,fc,fd,fe,ff,3,4,5,6,7,8,9)
#define BF_ADD_TO_2(F) F(fb,fc,fd,fe,ff,0,4,5,6,7,8,9,a)
#define BF_ADD_TO_3(F) F(fc,fd,fe,ff,0,1,5,6,7,8,9,a,b)
#define BF_ADD_TO_4(F) F(fd,fe,ff,0,1,2,6,7,8,9,a,b,c)
#define BF_ADD_TO_5(F) F(fe,ff,0,1,2,3,7,8,9,a,b,c,d)
#define BF_ADD_TO_6(F) F(ff,0,1,2,3,4,8,9,a,b,c,d,e)
#define BF_ADD_TO_7(F) F(0,1,2,3,4,5,9,a,b,c,d,e,f)
#define BF_ADD_TO_8(F) F(1,2,3,4,5,6,a,b,c,d,e,f,10)
#define BF_ADD_TO_9(F) F(2,3,4,5,6,7,b,c,d,e,f,10,11)
#define BF_ADD_TO_a(F) F(3,4,5,6,7,8,c,d,e,f,10,11,12)
#define BF_ADD_TO_b(F) F(4,5,6,7,8,9,d,e,f,10,11,12,13)
#define BF_ADD_TO_c(F) F(5,6,7,8,9,a,e,f,10,11,12,13,14)
#define BF_ADD_TO_d(F) F(6,7,8,9,a,b,f,10,11,12,13,14,15)
#define BF_ADD_TO_e(F) F(7,8,9,a,b,c,10,11,12,13,14,15,16)
#define BF_ADD_TO_f(F) F(8,9,a,b,c,d,11,12,13,14,15,16,17)
#define BF_ADD_TO_10(F) F(9,a,b,c,d,e,12,13,14,15,16,17,18)
#define BF_ADD_TO_11(F) F(a,b,c,d,e,f,13,14,15,16,17,18,19)
#define BF_ADD_TO_12(F) F(b,c,d,e,f,10,14,15,16,17,18,19,1a)
#define BF_ADD_TO_13(F) F(c,d,e,f,10,11,15,16,17,18,19,1a,1b)
#define BF_ADD_TO_14(F) F(d,e,f,10,11,12,16,17,18,19,1a,1b,1c)
#define BF_ADD_TO_15(F) F(e,f,10,11,12,13,17,18,19,1a,1b,1c,1d)
#define BF_ADD_TO_16(F) F(f,10,11,12,13,14,18,19,1a,1b,1c,1d,1e)
#define BF_ADD_TO_17(F) F(10,11,12,13,14,15,19,1a,1b,1c,1d,1e,1f)
#define BF_ADD_TO_18(F) F(11,12,13,14,15,16,1a,1b,1c,1d,1e,1f,20)
#define BF_ADD_TO_19(F) F(12,13,14,15,16,17,1b,1c,1d,1e,1f,20,21)
#define BF_ADD_TO_1a(F) F(13,14,15,16,17,18,1c,1d,1e,1f,20,21,22)
#define BF_ADD_TO_1b(F) F(14,15,16,17,18,19,1d,1e,1f,20,21,22,23)
#define BF_ADD_TO_1c(F) F(15,16,17,18,19,1a,1e,1f,20,21,22,23,24)
#define BF_ADD_TO_1d(F) F(16,17,18,19,1a,1b,1f,20,21,22,23,24,25)
#define BF_ADD_TO_1e(F) F(17,18,19,1a,1b,1c,20,21,22,23,24,25,26)
#define BF_ADD_TO_1f(F) F(18,19,1a,1b,1c,1d,21,22,23,24,25,26,27)
#define BF_ADD_TO_20(F) F(19,1a,1b,1c,1d,1e,22,23,24,25,26,27,28)
#define BF_ADD_TO_21(F) F(1a,1b,1c,1d,1e,1f,23,24,25,26,27,28,29)
#define BF_ADD_TO_22(F) F(1b,1c,1d,1e,1f,20,24,25,26,27,28,29,2a)
#define BF_ADD_TO_23(F) F(1c,1d,1e,1f,20,21,25,26,27,28,29,2a,2b)
#define BF_ADD_TO_24(F) F(1d,1e,1f,20,21,22,26,27,28,29,2a,2b,2c)
#define BF_ADD_TO_25(F) F(1e,1f,20,21,22,23,27,28,29,2a,2b,2c,2d)
#define BF_ADD_TO_26(F) F(1f,20,21,22,23,24,28,29,2a,2b,2c,2d,2e)
#define BF_ADD_TO_27(F) F(20,21,22,23,24,25,29,2a,2b,2c,2d,2e,2f)
#define BF_ADD_TO_28(F) F(21,22,23,24,25,26,2a,2b,2c,2d,2e,2f,30)
#define BF_ADD_TO_29(F) F(22,23,24,25,26,27,2b,2c,2d,2e,2f,30,31)
#define BF_ADD_TO_2a(F) F(23,24,25,26,27,28,2c,2d,2e,2f,30,31,32)
#define BF_ADD_TO_2b(F) F(24,25,26,27,28,29,2d,2e,2f,30,31,32,33)
#define BF_ADD_TO_2c(F) F(25,26,27,28,29,2a,2e,2f,30,31,32,33,34)
#define BF_ADD_TO_2d(F) F(26,27,28,29,2a,2b,2f,30,31,32,33,34,35)
#define BF_ADD_TO_2e(F) F(27,28,29,2a,2b,2c,30,31,32,33,34,35,36)
#define BF_ADD_TO_2f(F) F(28,29,2a,2b,2c,2d,31,32,33,34,35,36,37)
#define BF_ADD_TO_30(F) F(29,2a,2b,2c,2d,2e,32,33,34,35,36,37,38)
#define BF_ADD_TO_31(F) F(2a,2b,2c,2d,2e,2f,33,34,35,36,37,38,39)
#define BF_ADD_TO_32(F) F(2b,2c,2d,2e,2f,30,34,35,36,37,38,39,3a)
#define BF_ADD_TO_33(F) F(2c,2d,2e,2f,30,31,35,36,37,38,39,3a,3b)
#define BF_ADD_TO_34(F) F(2d,2e,2f,30,31,32,36,37,38,39,3a,3b,3c)
#define BF_ADD_TO_35(F) F(2e,2f,30,31,32,33,37,38,39,3a,3b,3c,3d)
#define BF_ADD_TO_36(F) F(2f,30,31,32,33,34,38,39,3a,3b,3c,3d,3e)
#define BF_ADD_TO_37(F) F(30,31,32,33,34,35,39,3a,3b,3c,3d,3e,3f)
#define BF_ADD_TO_38(F) F(31,32,33,34,35,36,3a,3b,3c,3d,3e,3f,40)
#define BF_ADD_TO_39(F) F(32,33,34,35,36,37,3b,3c,3d,3e,3f,40,41)
#define BF_ADD_TO_3a(F) F(33,34,35,36,37,38,3c,3d,3e,3f,40,41,42)
#define BF_ADD_TO_3b(F) F(34,35,36,37,38,39,3d,3e,3f,40,41,42,43)
#define BF_ADD_TO_3c(F) F(35,36,37,38,39,3a,3e,3f,40,41,42,43,44)
#define BF_ADD_TO_3d(F) F(36,37,38,39,3a,3b,3f,40,41,42,43,44,45)
#define BF_ADD_TO_3e(F) F(37,38,39,3a,3b,3c,40,41,42,43,44,45,46)
#define BF_ADD_TO_3f(F) F(38,39,3a,3b,3c,3d,41,42,43,44,45,46,47)
#define BF_ADD_TO_40(F) F(39,3a,3b,3c,3d,3e,42,43,44,45,46,47,48)
#define BF_ADD_TO_41(F) F(3a,3b,3c,3d,3e,3f,43,44,45,46,47,48,49)
#define BF_ADD_TO_42(F) F(3b,3c,3d,3e,3f,40,44,45,46,47,48,49,4a)
#define BF_ADD_TO_43(F) F(3c,3d,3e,3f,40,41,45,46,47,48,49,4a,4b)
#define BF_ADD_TO_44(F) F(3d,3e,3f,40,41,42,46,47,48,49,4a,4b,4c)
#define BF_ADD_TO_45(F) F(3e,3f,40,41,42,43,47,48,49,4a,4b,4c,4d)
#define BF_ADD_TO_46(F) F(3f,40,41,42,43,44,48,49,4a,4b,4c,4d,4e)
#define BF_ADD_TO_47(F) F(40,41,42,43,44,45,49,4a,4b,4c,4d,4e,4f)
#define BF_ADD_TO_48(F) F(41,42,43,44,45,46,4a,4b,4c,4d,4e,4f,50)
#define BF_ADD_TO_49(F) F(42,43,44,45,46,47,4b,4c,4d,4e,4f,50,51)
#define BF_ADD_TO_4a(F) F(43,44,45,46,47,48,4c,4d,4e,4f,50,51,52)
#define BF_ADD_TO_4b(F) F(44,45,46,47,48,49,4d,4e,4f,50,51,52,53)
#define BF_ADD_TO_4c(F) F(45,46,47,48,49,4a,4e,4f,50,51,52,53,54)
#define BF_ADD_TO_4d(F) F(46,47,48,49,4a,4b,4f,50,51,52,53,54,55)
#define BF_ADD_TO_4e(F) F(47,48,49,4a,4b,4c,50,51,52,53,54,55,56)
#define BF_ADD_TO_4f(F) F(48,49,4a,4b,4c,4d,51,52,53,54,55,56,57)
#define BF_ADD_TO_50(F) F(49,4a,4b,4c,4d,4e,52,53,54,55,56,57,58)
#define BF_ADD_TO_51(F) F(4a,4b,4c,4d,4e,4f,53,54,55,56,57,58,59)
#define BF_ADD_TO_52(F) F(4b,4c,4d,4e,4f,50,54,55,56,57,58,59,5a)
#define BF_ADD_TO_53(F) F(4c,4d,4e,4f,50,51,55,56,57,58,59,5a,5b)
#define BF_ADD_TO_54(F) F(4d,4e,4f,50,51,52,56,57,58,59,5a,5b,5c)
#define BF_ADD_TO_55(F) F(4e,4f,50,51,52,53,57,58,59,5a,5b,5c,5d)
#define BF_ADD_TO_56(F) F(4f,50,51,52,53,54,58,59,5a,5b,5c,5d,5e)
#define BF_ADD_TO_57(F) F(50,51,52,53,54,55,59,5a,5b,5c,5d,5e,5f)
#define BF_ADD_TO_58(F) F(51,52,53,54,55,56,5a,5b,5c,5d,5e,5f,60)
#define BF_ADD_TO_59(F) F(52,53,54,55,56,57,5b,5c,5d,5e,5f,60,61)
#define BF_ADD_TO_5a(F) F(53,54,55,56,57,58,5c,5d,5e,5f,60,61,62)
#define BF_ADD_TO_5b(F) F(54,55,56,57,58,59,5d,5e,5f,60,61,62,63)
#define BF_ADD_TO_5c(F) F(55,56,57,58,59,5a,5e,5f,60,61,62,63,64)
#define BF_ADD_TO_5d(F) F(56,57,58,59,5a,5b,5f,60,61,62,63,64,65)
#define BF_ADD_TO_5e(F) F(57,58,59,5a,5b,5c,60,61,62,63,64,65,66)
#define BF_ADD_TO_5f(F) F(58,59,5a,5b,5c,5d,61,62,63,64,65,66,67)
#define BF_ADD_TO_60(F) F(59,5a,5b,5c,5d,5e,62,63,64,65,66,67,68)
#define BF_ADD_TO_61(F) F(5a,5b,5c,5d,5e,5f,63,64,65,66,67,68,69)
#define BF_ADD_TO_62(F) F(5b,5c,5d,5e,5f,60,64,65,66,67,68,69,6a)
#define BF_ADD_TO_63(F) F(5c,5d,5e,5f,60,61,65,66,67,68,69,6a,6b)
#define BF_ADD_TO_64(F) F(5d,5e,5f,60,61,62,66,67,68,69,6a,6b,6c)
#define BF_ADD_TO_65(F) F(5e,5f,60,61,62,63,67,68,69,6a,6b,6c,6d)
#define BF_ADD_TO_66(F) F(5f,60,61,62,63,64,68,69,6a,6b,6c,6d,6e)
#define BF_ADD_TO_67(F) F(60,61,62,63,64,65,69,6a,6b,6c,6d,6e,6f)
#define BF_ADD_TO_68(F) F(61,62,63,64,65,66,6a,6b,6c,6d,6e,6f,70)
#define BF_ADD_TO_69(F) F(62,63,64,65,66,67,6b,6c,6d,6e,6f,70,71)
#define BF_ADD_TO_6a(F) F(63,64,65,66,67,68,6c,6d,6e,6f,70,71,72)
#define BF_ADD_TO_6b(F) F(64,65,66,67,68,69,6d,6e,6f,70,71,72,73)
#define BF_ADD_TO_6c(F) F(65,66,67,68,69,6a,6e,6f,70,71,72,73,74)
#define BF_ADD_TO_6d(F) F(66,67,68,69,6a,6b,6f,70,71,72,73,74,75)
#define BF_ADD_TO_6e(F) F(67,68,69,6a,6b,6c,70,71,72,73,74,75,76)
#define BF_ADD_TO_6f(F) F(68,69,6a,6b,6c,6d,71,72,73,74,75,76,77)
#define BF_ADD_TO_70(F) F(69,6a,6b,6c,6d,6e,72,73,74,75,76,77,78)
#define BF_ADD_TO_71(F) F(6a,6b,6c,6d,6e,6f,73,74,75,76,77,78,79)
#define BF_ADD_TO_72(F) F(6b,6c,6d,6e,6f,70,74,75,76,77,78,79,7a)
#define BF_ADD_TO_73(F) F(6c,6d,6e,6f,70,71,75,76,77,78,79,7a,7b)
#define BF_ADD_TO_74(F) F(6d,6e,6f,70,71,72,76,77,78,79,7a,7b,7c)
#define BF_ADD_TO_75(F) F(6e,6f,70,71,72,73,77,78,79,7a,7b,7c,7d)
#define BF_ADD_TO_76(F) F(6f,70,71,72,73,74,78,79,7a,7b,7c,7d,7e)
#define BF_ADD_TO_77(F) F(70,71,72,73,74,75,79,7a,7b,7c,7d,7e,7f)
#define BF_ADD_TO_78(F) F(71,72,73,74,75,76,7a,7b,7c,7d,7e,7f,80)
#define BF_ADD_TO_79(F) F(72,73,74,75,76,77,7b,7c,7d,7e,7f,80,81)
#define BF_ADD_TO_7a(F) F(73,74,75,76,77,78,7c,7d,7e,7f,80,81,82)
#define BF_ADD_TO_7b(F) F(74,75,76,77,78,79,7d,7e,7f,80,81,82,83)
#define BF_ADD_TO_7c(F) F(75,76,77,78,79,7a,7e,7f,80,81,82,83,84)
#define BF_ADD_TO_7d(F) F(76,77,78,79,7a,7b,7f,80,81,82,83,84,85)
#define BF_ADD_TO_7e(F) F(77,78,79,7a,7b,7c,80,81,82,83,84,85,86)
#define BF_ADD_TO_7f(F) F(78,79,7a,7b,7c,7d,81,82,83,84,85,86,87)
#define BF_ADD_TO_80(F) F(79,7a,7b,7c,7d,7e,82,83,84,85,86,87,88)
#define BF_ADD_TO_81(F) F(7a,7b,7c,7d,7e,7f,83,84,85,86,87,88,89)
#define BF_ADD_TO_82(F) F(7b,7c,7d,7e,7f,80,84,85,86,87,88,89,8a)
#define BF_ADD_TO_83(F) F(7c,7d,7e,7f,80,81,85,86,87,88,89,8a,8b)
#define BF_ADD_TO_84(F) F(7d,7e,7f,80,81,82,86,87,88,89,8a,8b,8c)
#define BF_ADD_TO_85(F) F(7e,7f,80,81,82,83,87,88,89,8a,8b,8c,8d)
#define BF_ADD_TO_86(F) F(7f,80,81,82,83,84,88,89,8a,8b,8c,8d,8e)
#define BF_ADD_TO_87(F) F(80,81,82,83,84,85,89,8a,8b,8c,8d,8e,8f)
#define BF_ADD_TO_88(F) F(81,82,83,84,85,86,8a,8b,8c,8d,8e,8f,90)
#define BF_ADD_TO_89(F) F(82,83,84,85,86,87,8b,8c,8d,8e,8f,90,91)
#define BF_ADD_TO_8a(F) F(83,84,85,86,87,88,8c,8d,8e,8f,90,91,92)
#define BF_ADD_TO_8b(F) F(84,85,86,87,88,89,8d,8e,8f,90,91,92,93)
#define BF_ADD_TO_8c(F) F(85,86,87,88,89,8a,8e,8f,90,91,92,93,94)
#define BF_ADD_TO_8d(F) F(86,87,88,89,8a,8b,8f,90,91,92,93,94,95)
#define BF_ADD_TO_8e(F) F(87,88,89,8a,8b,8c,90,91,92,93,94,95,96)
#define BF_ADD_TO_8f(F) F(88,89,8a,8b,8c,8d,91,92,93,94,95,96,97)
#define BF_ADD_TO_90(F) F(89,8a,8b,8c,8d,8e,92,93,94,95,96,97,98)
#define BF_ADD_TO_91(F) F(8a,8b,8c,8d,8e,8f,93,94,95,96,97,98,99)
#define BF_ADD_TO_92(F) F(8b,8c,8d,8e,8f,90,94,95,96,97,98,99,9a)
#define BF_ADD_TO_93(F) F(8c,8d,8e,8f,90,91,95,96,97,98,99,9a,9b)
#define BF_ADD_TO_94(F) F(8d,8e,8f,90,91,92,96,97,98,99,9a,9b,9c)
#define BF_ADD_TO_95(F) F(8e,8f,90,91,92,93,97,98,99,9a,9b,9c,9d)
#define BF_ADD_TO_96(F) F(8f,90,91,92,93,94,98,99,9a,9b,9c,9d,9e)
#define BF_ADD_TO_97(F) F(90,91,92,93,94,95,99,9a,9b,9c,9d,9e,9f)
#define BF_ADD_TO_98(F) F(91,92,93,94,95,96,9a,9b,9c,9d,9e,9f,a0)
#define BF_ADD_TO_99(F) F(92,93,94,95,96,97,9b,9c,9d,9e,9f,a0,a1)
#define BF_ADD_TO_9a(F) F(93,94,95,96,97,98,9c,9d,9e,9f,a0,a1,a2)
#define BF_ADD_TO_9b(F) F(94,95,96,97,98,99,9d,9e,9f,a0,a1,a2,a3)
#define BF_ADD_TO_9c(F) F(95,96,97,98,99,9a,9e,9f,a0,a1,a2,a3,a4)
#define BF_ADD_TO_9d(F) F(96,97,98,99,9a,9b,9f,a0,a1,a2,a3,a4,a5)
#define BF_ADD_TO_9e(F) F(97,98,99,9a,9b,9c,a0,a1,a2,a3,a4,a5,a6)
#define BF_ADD_TO_9f(F) F(98,99,9a,9b,9c,9d,a1,a2,a3,a4,a5,a6,a7)
#define BF_ADD_TO_a0(F) F(99,9a,9b,9c,9d,9e,a2,a3,a4,a5,a6,a7,a8)
#define BF_ADD_TO_a1(F) F(9a,9b,9c,9d,9e,9f,a3,a4,a5,a6,a7,a8,a9)
#define BF_ADD_TO_a2(F) F(9b,9c,9d,9e,9f,a0,a4,a5,a6,a7,a8,a9,aa)
#define BF_ADD_TO_a3(F) F(9c,9d,9e,9f,a0,a1,a5,a6,a7,a8,a9,aa,ab)
#define BF_ADD_TO_a4(F) F(9d,9e,9f,a0,a1,a2,a6,a7,a8,a9,aa,ab,ac)
#define BF_ADD_TO_a5(F) F(9e,9f,a0,a1,a2,a3,a7,a8,a9,aa,ab,ac,ad)
#define BF_ADD_TO_a6(F) F(9f,a0,a1,a2,a3,a4,a8,a9,aa,ab,ac,ad,ae)
#define BF_ADD_TO_a7(F) F(a0,a1,a2,a3,a4,a5,a9,aa,ab,ac,ad,ae,af)
#define BF_ADD_TO_a8(F) F(a1,a2,a3,a4,a5,a6,aa,ab,ac,ad,ae,af,b0)
#define BF_ADD_TO_a9(F) F(a2,a3,a4,a5,a6,a7,ab,ac,ad,ae,af,b0,b1)
#define BF_ADD_TO_aa(F) F(a3,a4,a5,a6,a7,a8,ac,ad,ae,af,b0,b1,b2)
#define BF_ADD_TO_ab(F) F(a4,a5,a6,a7,a8,a9,ad,ae,af,b0,b1,b2,b3)
#define BF_ADD_TO_ac(F) F(a5,a6,a7,a8,a9,aa,ae,af,b0,b1,b2,b3,b4)
#define BF_ADD_TO_ad(F) F(a6,a7,a8,a9,aa,ab,af,b0,b1,b2,b3,b4,b5)
#define BF_ADD_TO_ae(F) F(a7,a8,a9,aa,ab,ac,b0,b1,b2,b3,b4,b5,b6)
#define BF_ADD_TO_af(F) F(a8,a9,aa,ab,ac,ad,b1,b2,b3,b4,b5,b6,b7)
#define BF_ADD_TO_b0(F) F(a9,aa,ab,ac,ad,ae,b2,b3,b4,b5,b6,b7,b8)
#define BF_ADD_TO_b1(F) F(aa,ab,ac,ad,ae,af,b3,b4,b5,b6,b7,b8,b9)
#define BF_ADD_TO_b2(F) F(ab,ac,ad,ae,af,b0,b4,b5,b6,b7,b8,b9,ba)
#define BF_ADD_TO_b3(F) F(ac,ad,ae,af,b0,b1,b5,b6,b7,b8,b9,ba,bb)
#define BF_ADD_TO_b4(F) F(ad,ae,af,b0,b1,b2,b6,b7,b8,b9,ba,bb,bc)
#define BF_ADD_TO_b5(F) F(ae,af,b0,b1,b2,b3,b7,b8,b9,ba,bb,bc,bd)
#define BF_ADD_TO_b6(F) F(af,b0,b1,b2,b3,b4,b8,b9,ba,bb,bc,bd,be)
#define BF_ADD_TO_b7(F) F(b0,b1,b2,b3,b4,b5,b9,ba,bb,bc,bd,be,bf)
#define BF_ADD_TO_b8(F) F(b1,b2,b3,b4,b5,b6,ba,bb,bc,bd,be,bf,c0)
#define BF_ADD_TO_b9(F) F(b2,b3,b4,b5,b6,b7,bb,bc,bd,be,bf,c0,c1)
#define BF_ADD_TO_ba(F) F(b3,b4,b5,b6,b7,b8,bc,bd,be,bf,c0,c1,c2)
#define BF_ADD_TO_bb(F) F(b4,b5,b6,b7,b8,b9,bd,be,bf,c0,c1,c2,c3)
#define BF_ADD_TO_bc(F) F(b5,b6,b7,b8,b9,ba,be,bf,c0,c1,c2,c3,c4)
#define BF_ADD_TO_bd(F) F(b6,b7,b8,b9,ba,bb,bf,c0,c1,c2,c3,c4,c5)
#define BF_ADD_TO_be(F) F(b7,b8,b9,ba,bb,bc,c0,c1,c2,c3,c4,c5,c6)
#define BF_ADD_TO_bf(F) F(b8,b9,ba,bb,bc,bd,c1,c2,c3,c4,c5,c6,c7)
#define BF_ADD_TO_c0(F) F(b9,ba,bb,bc,bd,be,c2,c3,c4,c5,c6,c7,c8)
#define BF_ADD_TO_c1(F) F(ba,bb,bc,bd,be,bf,c3,c4,c5,c6,c7,c8,c9)
#define BF_ADD_TO_c2(F) F(bb,bc,bd,be,bf,c0,c4,c5,c6,c7,c8,c9,ca)
#define BF_ADD_TO_c3(F) F(bc,bd,be,bf,c0,c1,c5,c6,c7,c8,c9,ca,cb)
#define BF_ADD_TO_c4(F) F(bd,be,bf,c0,c1,c2,c6,c7,c8,c9,ca,cb,cc)
#define BF_ADD_TO_c5(F) F(be,bf,c0,c1,c2,c3,c7,c8,c9,ca,cb,cc,cd)
#define BF_ADD_TO_c6(F) F(bf,c0,c1,c2,c3,c4,c8,c9,ca,cb,cc,cd,ce)
#define BF_ADD_TO_c7(F) F(c0,c1,c2,c3,c4,c5,c9,ca,cb,cc,cd,ce,cf)
#define BF_ADD_TO_c8(F) F(c1,c2,c3,c4,c5,c6,ca,cb,cc,cd,ce,cf,d0)
#define BF_ADD_TO_c9(F) F(c2,c3,c4,c5,c6,c7,cb,cc,cd,ce,cf,d0,d1)
#define BF_ADD_TO_ca(F) F(c3,c4,c5,c6,c7,c8,cc,cd,ce,cf,d0,d1,d2)
#define BF_ADD_TO_cb(F) F(c4,c5,c6,c7,c8,c9,cd,ce,cf,d0,d1,d2,d3)
#define BF_ADD_TO_cc(F) F(c5,c6,c7,c8,c9,ca,ce,cf,d0,d1,d2,d3,d4)
#define BF_ADD_TO_cd(F) F(c6,c7,c8,c9,ca,cb,cf,d0,d1,d2,d3,d4,d5)
#define BF_ADD_TO_ce(F) F(c7,c8,c9,ca,cb,cc,d0,d1,d2,d3,d4,d5,d6)
#define BF_ADD_TO_cf(F) F(c8,c9,ca,cb,cc,cd,d1,d2,d3,d4,d5,d6,d7)
#define BF_ADD_TO_d0(F) F(c9,ca,cb,cc,cd,ce,d2,d3,d4,d5,d6,d7,d8)
#define BF_ADD_TO_d1(F) F(ca,cb,cc,cd,ce,cf,d3,d4,d5,d6,d7,d8,d9)
#define BF_ADD_TO_d2(F) F(cb,cc,cd,ce,cf,d0,d4,d5,d6,d7,d8,d9,da)
#define BF_ADD_TO_d3(F) F(cc,cd,ce,cf,d0,d1,d5,d6,d7,d8,d9,da,db)
#define BF_ADD_TO_d4(F) F(cd,ce,cf,d0,d1,d2,d6,d7,d8,d9,da,db,dc)
#define BF_ADD_TO_d5(F) F(ce,cf,d0,d1,d2,d3,d7,d8,d9,da,db,dc,dd)
#define BF_ADD_TO_d6(F) F(cf,d0,d1,d2,d3,d4,d8,d9,da,db,dc,dd,de)
#define BF_ADD_TO_d7(F) F(d0,d1,d2,d3,d4,d5,d9,da,db,dc,dd,de,df)
#define BF_ADD_TO_d8(F) F(d1,d2,d3,d4,d5,d6,da,db,dc,dd,de,df,e0)
#define BF_ADD_TO_d9(F) F(d2,d3,d4,d5,d6,d7,db,dc,dd,de,df,e0,e1)
#define BF_ADD_TO_da(F) F(d3,d4,d5,d6,d7,d8,dc,dd,de,df,e0,e1,e2)
#define BF_ADD_TO_db(F) F(d4,d5,d6,d7,d8,d9,dd,de,df,e0,e1,e2,e3)
#define BF_ADD_TO_dc(F) F(d5,d6,d7,d8,d9,da,de,df,e0,e1,e2,e3,e4)
#define BF_ADD_TO_dd(F) F(d6,d7,d8,d9,da,db,df,e0,e1,e2,e3,e4,e5)
#define BF_ADD_TO_de(F) F(d7,d8,d9,da,db,dc,e0,e1,e2,e3,e4,e5,e6)
#define BF_ADD_TO_df(F) F(d8,d9,da,db,dc,dd,e1,e2,e3,e4,e5,e6,e7)
#define BF_ADD_TO_e0(F) F(d9,da,db,dc,dd,de,e2,e3,e4,e5,e6,e7,e8)
#define BF_ADD_TO_e1(F) F(da,db,dc,dd,de,df,e3,e4,e5,e6,e7,e8,e9)
#define BF_ADD_TO_e2(F) F(db,dc,dd,de,df,e0,e4,e5,e6,e7,e8,e9,ea)
#define BF_ADD_TO_e3(F) F(dc,dd,de,df,e0,e1,e5,e6,e7,e8,e9,ea,eb)
#define BF_ADD_TO_e4(F) F(dd,de,df,e0,e1,e2,e6,e7,e8,e9,ea,eb,ec)
#define BF_ADD_TO_e5(F) F(de,df,e0,e1,e2,e3,e7,e8,e9,ea,eb,ec,ed)
#define BF_ADD_TO_e6(F) F(df,e0,e1,e2,e3,e4,e8,e9,ea,eb,ec,ed,ee)
#define BF_ADD_TO_e7(F) F(e0,e1,e2,e3,e4,e5,e9,ea,eb,ec,ed,ee,ef)
#define BF_ADD_TO_e8(F) F(e1,e2,e3,e4,e5,e6,ea,eb,ec,ed,ee,ef,f0)
#define BF_ADD_TO_e9(F) F(e2,e3,e4,e5,e6,e7,eb,ec,ed,ee,ef,f0,f1)
#define BF_ADD_TO_ea(F) F(e3,e4,e5,e6,e7,e8,ec,ed,ee,ef,f0,f1,f2)
#define BF_ADD_TO_eb(F) F(e4,e5,e6,e7,e8,e9,ed,ee,ef,f0,f1,f2,f3)
#define BF_ADD_TO_ec(F) F(e5,e6,e7,e8,e9,ea,ee,ef,f0,f1,f2,f3,f4)
#define BF_ADD_TO_ed(F) F(e6,e7,e8,e9,ea,eb,ef,f0,f1,f2,f3,f4,f5)
#define BF_ADD_TO_ee(F) F(e7,e8,e9,ea,eb,ec,f0,f1,f2,f3,f4,f5,f6)
#define BF_ADD_TO_ef(F) F(e8,e9,ea,eb,ec,ed,f1,f2,f3,f4,f5,f6,f7)
#define BF_ADD_TO_f0(F) F(e9,ea,eb,ec,ed,ee,f2,f3,f4,f5,f6,f7,f8)
#define BF_ADD_TO_f1(F) F(ea,eb,ec,ed,ee,ef,f3,f4,f5,f6,f7,f8,f9)
#define BF_ADD_TO_f2(F) F(eb,ec,ed,ee,ef,f0,f4,f5,f6,f7,f8,f9,fa)
#define BF_ADD_TO_f3(F) F(ec,ed,ee,ef,f0,f1,f5,f6,f7,f8,f9,fa,fb)
#define BF_ADD_TO_f4(F) F(ed,ee,ef,f0,f1,f2,f6,f7,f8,f9,fa,fb,fc)
#define BF_ADD_TO_f5(F) F(ee,ef,f0,f1,f2,f3,f7,f8,f9,fa,fb,fc,fd)
#define BF_ADD_TO_f6(F) F(ef,f0,f1,f2,f3,f4,f8,f9,fa,fb,fc,fd,fe)
#define BF_ADD_TO_f7(F) F(f0,f1,f2,f3,f4,f5,f9,fa,fb,fc,fd,fe,ff)
#define BF_ADD_TO_f8(F) F(f1,f2,f3,f4,f5,f6,fa,fb,fc,fd,fe,ff,0)
#define BF_ADD_TO_f9(F) F(f2,f3,f4,f5,f6,f7,fb,fc,fd,fe,ff,0,1)
#define BF_ADD_TO_fa(F) F(f3,f4,f5,f6,f7,f8,fc,fd,fe,ff,0,1,2)
#define BF_ADD_TO_fb(F) F(f4,f5,f6,f7,f8,f9,fd,fe,ff,0,1,2,3)
#define BF_ADD_TO_fc(F) F(f5,f6,f7,f8,f9,fa,fe,ff,0,1,2,3,4)
#define BF_ADD_TO_fd(F) F(f6,f7,f8,f9,fa,fb,ff,0,1,2,3,4,5)
#define BF_ADD_TO_fe(F) F(f7,f8,f9,fa,fb,fc,0,1,2,3,4,5,6)
#define BF_ADD_TO_ff(F) F(f8,f9,fa,fb,fc,fd,1,2,3,4,5,6,7)

#define BF_SUB_AT_7(a,b,c,d,e,f,g,h,i,j,k,l,m) a
#define BF_SUB_AT_6(a,b,c,d,e,f,g,h,i,j,k,l,m) b
#define BF_SUB_AT_5(a,b,c,d,e,f,g,h,i,j,k,l,m) c
#define BF_SUB_AT_4(a,b,c,d,e,f,g,h,i,j,k,l,m) d
#define BF_SUB_AT_3(a,b,c,d,e,f,g,h,i,j,k,l,m) e
#define BF_SUB_AT_2(a,b,c,d,e,f,g,h,i,j,k,l,m) f
#define BF_ADD_AT_2(a,b,c,d,e,f,g,h,i,j,k,l,m) g
#define BF_ADD_AT_3(a,b,c,d,e,f,g,h,i,j,k,l,m) h
#define BF_ADD_AT_4(a,b,c,d,e,f,g,h,i,j,k,l,m) i
#define BF_ADD_AT_5(a,b,c,d,e,f,g,h,i,j,k,l,m) j
#define BF_ADD_AT_6(a,b,c,d,e,f,g,h,i,j,k,l,m) k
#define BF_ADD_AT_7(a,b,c,d,e,f,g,h,i,j,k,l,m) l
#define BF_ADD_AT_8(a,b,c,d,e,f,g,h,i,j,k,l,m) m

// awk 'BEGIN{for(i=0;i<=255;++i){printf("#define BF_ADD10_TO_%x(F) F(",i);for(j=1;j<15;++j)printf("%x,",(i+j*16)%256);printf("%x)\n",(i+15*16)%256);}}'

#define BF_ADD10_TO_0(F) F(10,20,30,40,50,60,70,80,90,a0,b0,c0,d0,e0,f0)
#define BF_ADD10_TO_1(F) F(11,21,31,41,51,61,71,81,91,a1,b1,c1,d1,e1,f1)
#define BF_ADD10_TO_2(F) F(12,22,32,42,52,62,72,82,92,a2,b2,c2,d2,e2,f2)
#define BF_ADD10_TO_3(F) F(13,23,33,43,53,63,73,83,93,a3,b3,c3,d3,e3,f3)
#define BF_ADD10_TO_4(F) F(14,24,34,44,54,64,74,84,94,a4,b4,c4,d4,e4,f4)
#define BF_ADD10_TO_5(F) F(15,25,35,45,55,65,75,85,95,a5,b5,c5,d5,e5,f5)
#define BF_ADD10_TO_6(F) F(16,26,36,46,56,66,76,86,96,a6,b6,c6,d6,e6,f6)
#define BF_ADD10_TO_7(F) F(17,27,37,47,57,67,77,87,97,a7,b7,c7,d7,e7,f7)
#define BF_ADD10_TO_8(F) F(18,28,38,48,58,68,78,88,98,a8,b8,c8,d8,e8,f8)
#define BF_ADD10_TO_9(F) F(19,29,39,49,59,69,79,89,99,a9,b9,c9,d9,e9,f9)
#define BF_ADD10_TO_a(F) F(1a,2a,3a,4a,5a,6a,7a,8a,9a,aa,ba,ca,da,ea,fa)
#define BF_ADD10_TO_b(F) F(1b,2b,3b,4b,5b,6b,7b,8b,9b,ab,bb,cb,db,eb,fb)
#define BF_ADD10_TO_c(F) F(1c,2c,3c,4c,5c,6c,7c,8c,9c,ac,bc,cc,dc,ec,fc)
#define BF_ADD10_TO_d(F) F(1d,2d,3d,4d,5d,6d,7d,8d,9d,ad,bd,cd,dd,ed,fd)
#define BF_ADD10_TO_e(F) F(1e,2e,3e,4e,5e,6e,7e,8e,9e,ae,be,ce,de,ee,fe)
#define BF_ADD10_TO_f(F) F(1f,2f,3f,4f,5f,6f,7f,8f,9f,af,bf,cf,df,ef,ff)
#define BF_ADD10_TO_10(F) F(20,30,40,50,60,70,80,90,a0,b0,c0,d0,e0,f0,0)
#define BF_ADD10_TO_11(F) F(21,31,41,51,61,71,81,91,a1,b1,c1,d1,e1,f1,1)
#define BF_ADD10_TO_12(F) F(22,32,42,52,62,72,82,92,a2,b2,c2,d2,e2,f2,2)
#define BF_ADD10_TO_13(F) F(23,33,43,53,63,73,83,93,a3,b3,c3,d3,e3,f3,3)
#define BF_ADD10_TO_14(F) F(24,34,44,54,64,74,84,94,a4,b4,c4,d4,e4,f4,4)
#define BF_ADD10_TO_15(F) F(25,35,45,55,65,75,85,95,a5,b5,c5,d5,e5,f5,5)
#define BF_ADD10_TO_16(F) F(26,36,46,56,66,76,86,96,a6,b6,c6,d6,e6,f6,6)
#define BF_ADD10_TO_17(F) F(27,37,47,57,67,77,87,97,a7,b7,c7,d7,e7,f7,7)
#define BF_ADD10_TO_18(F) F(28,38,48,58,68,78,88,98,a8,b8,c8,d8,e8,f8,8)
#define BF_ADD10_TO_19(F) F(29,39,49,59,69,79,89,99,a9,b9,c9,d9,e9,f9,9)
#define BF_ADD10_TO_1a(F) F(2a,3a,4a,5a,6a,7a,8a,9a,aa,ba,ca,da,ea,fa,a)
#define BF_ADD10_TO_1b(F) F(2b,3b,4b,5b,6b,7b,8b,9b,ab,bb,cb,db,eb,fb,b)
#define BF_ADD10_TO_1c(F) F(2c,3c,4c,5c,6c,7c,8c,9c,ac,bc,cc,dc,ec,fc,c)
#define BF_ADD10_TO_1d(F) F(2d,3d,4d,5d,6d,7d,8d,9d,ad,bd,cd,dd,ed,fd,d)
#define BF_ADD10_TO_1e(F) F(2e,3e,4e,5e,6e,7e,8e,9e,ae,be,ce,de,ee,fe,e)
#define BF_ADD10_TO_1f(F) F(2f,3f,4f,5f,6f,7f,8f,9f,af,bf,cf,df,ef,ff,f)
#define BF_ADD10_TO_20(F) F(30,40,50,60,70,80,90,a0,b0,c0,d0,e0,f0,0,10)
#define BF_ADD10_TO_21(F) F(31,41,51,61,71,81,91,a1,b1,c1,d1,e1,f1,1,11)
#define BF_ADD10_TO_22(F) F(32,42,52,62,72,82,92,a2,b2,c2,d2,e2,f2,2,12)
#define BF_ADD10_TO_23(F) F(33,43,53,63,73,83,93,a3,b3,c3,d3,e3,f3,3,13)
#define BF_ADD10_TO_24(F) F(34,44,54,64,74,84,94,a4,b4,c4,d4,e4,f4,4,14)
#define BF_ADD10_TO_25(F) F(35,45,55,65,75,85,95,a5,b5,c5,d5,e5,f5,5,15)
#define BF_ADD10_TO_26(F) F(36,46,56,66,76,86,96,a6,b6,c6,d6,e6,f6,6,16)
#define BF_ADD10_TO_27(F) F(37,47,57,67,77,87,97,a7,b7,c7,d7,e7,f7,7,17)
#define BF_ADD10_TO_28(F) F(38,48,58,68,78,88,98,a8,b8,c8,d8,e8,f8,8,18)
#define BF_ADD10_TO_29(F) F(39,49,59,69,79,89,99,a9,b9,c9,d9,e9,f9,9,19)
#define BF_ADD10_TO_2a(F) F(3a,4a,5a,6a,7a,8a,9a,aa,ba,ca,da,ea,fa,a,1a)
#define BF_ADD10_TO_2b(F) F(3b,4b,5b,6b,7b,8b,9b,ab,bb,cb,db,eb,fb,b,1b)
#define BF_ADD10_TO_2c(F) F(3c,4c,5c,6c,7c,8c,9c,ac,bc,cc,dc,ec,fc,c,1c)
#define BF_ADD10_TO_2d(F) F(3d,4d,5d,6d,7d,8d,9d,ad,bd,cd,dd,ed,fd,d,1d)
#define BF_ADD10_TO_2e(F) F(3e,4e,5e,6e,7e,8e,9e,ae,be,ce,de,ee,fe,e,1e)
#define BF_ADD10_TO_2f(F) F(3f,4f,5f,6f,7f,8f,9f,af,bf,cf,df,ef,ff,f,1f)
#define BF_ADD10_TO_30(F) F(40,50,60,70,80,90,a0,b0,c0,d0,e0,f0,0,10,20)
#define BF_ADD10_TO_31(F) F(41,51,61,71,81,91,a1,b1,c1,d1,e1,f1,1,11,21)
#define BF_ADD10_TO_32(F) F(42,52,62,72,82,92,a2,b2,c2,d2,e2,f2,2,12,22)
#define BF_ADD10_TO_33(F) F(43,53,63,73,83,93,a3,b3,c3,d3,e3,f3,3,13,23)
#define BF_ADD10_TO_34(F) F(44,54,64,74,84,94,a4,b4,c4,d4,e4,f4,4,14,24)
#define BF_ADD10_TO_35(F) F(45,55,65,75,85,95,a5,b5,c5,d5,e5,f5,5,15,25)
#define BF_ADD10_TO_36(F) F(46,56,66,76,86,96,a6,b6,c6,d6,e6,f6,6,16,26)
#define BF_ADD10_TO_37(F) F(47,57,67,77,87,97,a7,b7,c7,d7,e7,f7,7,17,27)
#define BF_ADD10_TO_38(F) F(48,58,68,78,88,98,a8,b8,c8,d8,e8,f8,8,18,28)
#define BF_ADD10_TO_39(F) F(49,59,69,79,89,99,a9,b9,c9,d9,e9,f9,9,19,29)
#define BF_ADD10_TO_3a(F) F(4a,5a,6a,7a,8a,9a,aa,ba,ca,da,ea,fa,a,1a,2a)
#define BF_ADD10_TO_3b(F) F(4b,5b,6b,7b,8b,9b,ab,bb,cb,db,eb,fb,b,1b,2b)
#define BF_ADD10_TO_3c(F) F(4c,5c,6c,7c,8c,9c,ac,bc,cc,dc,ec,fc,c,1c,2c)
#define BF_ADD10_TO_3d(F) F(4d,5d,6d,7d,8d,9d,ad,bd,cd,dd,ed,fd,d,1d,2d)
#define BF_ADD10_TO_3e(F) F(4e,5e,6e,7e,8e,9e,ae,be,ce,de,ee,fe,e,1e,2e)
#define BF_ADD10_TO_3f(F) F(4f,5f,6f,7f,8f,9f,af,bf,cf,df,ef,ff,f,1f,2f)
#define BF_ADD10_TO_40(F) F(50,60,70,80,90,a0,b0,c0,d0,e0,f0,0,10,20,30)
#define BF_ADD10_TO_41(F) F(51,61,71,81,91,a1,b1,c1,d1,e1,f1,1,11,21,31)
#define BF_ADD10_TO_42(F) F(52,62,72,82,92,a2,b2,c2,d2,e2,f2,2,12,22,32)
#define BF_ADD10_TO_43(F) F(53,63,73,83,93,a3,b3,c3,d3,e3,f3,3,13,23,33)
#define BF_ADD10_TO_44(F) F(54,64,74,84,94,a4,b4,c4,d4,e4,f4,4,14,24,34)
#define BF_ADD10_TO_45(F) F(55,65,75,85,95,a5,b5,c5,d5,e5,f5,5,15,25,35)
#define BF_ADD10_TO_46(F) F(56,66,76,86,96,a6,b6,c6,d6,e6,f6,6,16,26,36)
#define BF_ADD10_TO_47(F) F(57,67,77,87,97,a7,b7,c7,d7,e7,f7,7,17,27,37)
#define BF_ADD10_TO_48(F) F(58,68,78,88,98,a8,b8,c8,d8,e8,f8,8,18,28,38)
#define BF_ADD10_TO_49(F) F(59,69,79,89,99,a9,b9,c9,d9,e9,f9,9,19,29,39)
#define BF_ADD10_TO_4a(F) F(5a,6a,7a,8a,9a,aa,ba,ca,da,ea,fa,a,1a,2a,3a)
#define BF_ADD10_TO_4b(F) F(5b,6b,7b,8b,9b,ab,bb,cb,db,eb,fb,b,1b,2b,3b)
#define BF_ADD10_TO_4c(F) F(5c,6c,7c,8c,9c,ac,bc,cc,dc,ec,fc,c,1c,2c,3c)
#define BF_ADD10_TO_4d(F) F(5d,6d,7d,8d,9d,ad,bd,cd,dd,ed,fd,d,1d,2d,3d)
#define BF_ADD10_TO_4e(F) F(5e,6e,7e,8e,9e,ae,be,ce,de,ee,fe,e,1e,2e,3e)
#define BF_ADD10_TO_4f(F) F(5f,6f,7f,8f,9f,af,bf,cf,df,ef,ff,f,1f,2f,3f)
#define BF_ADD10_TO_50(F) F(60,70,80,90,a0,b0,c0,d0,e0,f0,0,10,20,30,40)
#define BF_ADD10_TO_51(F) F(61,71,81,91,a1,b1,c1,d1,e1,f1,1,11,21,31,41)
#define BF_ADD10_TO_52(F) F(62,72,82,92,a2,b2,c2,d2,e2,f2,2,12,22,32,42)
#define BF_ADD10_TO_53(F) F(63,73,83,93,a3,b3,c3,d3,e3,f3,3,13,23,33,43)
#define BF_ADD10_TO_54(F) F(64,74,84,94,a4,b4,c4,d4,e4,f4,4,14,24,34,44)
#define BF_ADD10_TO_55(F) F(65,75,85,95,a5,b5,c5,d5,e5,f5,5,15,25,35,45)
#define BF_ADD10_TO_56(F) F(66,76,86,96,a6,b6,c6,d6,e6,f6,6,16,26,36,46)
#define BF_ADD10_TO_57(F) F(67,77,87,97,a7,b7,c7,d7,e7,f7,7,17,27,37,47)
#define BF_ADD10_TO_58(F) F(68,78,88,98,a8,b8,c8,d8,e8,f8,8,18,28,38,48)
#define BF_ADD10_TO_59(F) F(69,79,89,99,a9,b9,c9,d9,e9,f9,9,19,29,39,49)
#define BF_ADD10_TO_5a(F) F(6a,7a,8a,9a,aa,ba,ca,da,ea,fa,a,1a,2a,3a,4a)
#define BF_ADD10_TO_5b(F) F(6b,7b,8b,9b,ab,bb,cb,db,eb,fb,b,1b,2b,3b,4b)
#define BF_ADD10_TO_5c(F) F(6c,7c,8c,9c,ac,bc,cc,dc,ec,fc,c,1c,2c,3c,4c)
#define BF_ADD10_TO_5d(F) F(6d,7d,8d,9d,ad,bd,cd,dd,ed,fd,d,1d,2d,3d,4d)
#define BF_ADD10_TO_5e(F) F(6e,7e,8e,9e,ae,be,ce,de,ee,fe,e,1e,2e,3e,4e)
#define BF_ADD10_TO_5f(F) F(6f,7f,8f,9f,af,bf,cf,df,ef,ff,f,1f,2f,3f,4f)
#define BF_ADD10_TO_60(F) F(70,80,90,a0,b0,c0,d0,e0,f0,0,10,20,30,40,50)
#define BF_ADD10_TO_61(F) F(71,81,91,a1,b1,c1,d1,e1,f1,1,11,21,31,41,51)
#define BF_ADD10_TO_62(F) F(72,82,92,a2,b2,c2,d2,e2,f2,2,12,22,32,42,52)
#define BF_ADD10_TO_63(F) F(73,83,93,a3,b3,c3,d3,e3,f3,3,13,23,33,43,53)
#define BF_ADD10_TO_64(F) F(74,84,94,a4,b4,c4,d4,e4,f4,4,14,24,34,44,54)
#define BF_ADD10_TO_65(F) F(75,85,95,a5,b5,c5,d5,e5,f5,5,15,25,35,45,55)
#define BF_ADD10_TO_66(F) F(76,86,96,a6,b6,c6,d6,e6,f6,6,16,26,36,46,56)
#define BF_ADD10_TO_67(F) F(77,87,97,a7,b7,c7,d7,e7,f7,7,17,27,37,47,57)
#define BF_ADD10_TO_68(F) F(78,88,98,a8,b8,c8,d8,e8,f8,8,18,28,38,48,58)
#define BF_ADD10_TO_69(F) F(79,89,99,a9,b9,c9,d9,e9,f9,9,19,29,39,49,59)
#define BF_ADD10_TO_6a(F) F(7a,8a,9a,aa,ba,ca,da,ea,fa,a,1a,2a,3a,4a,5a)
#define BF_ADD10_TO_6b(F) F(7b,8b,9b,ab,bb,cb,db,eb,fb,b,1b,2b,3b,4b,5b)
#define BF_ADD10_TO_6c(F) F(7c,8c,9c,ac,bc,cc,dc,ec,fc,c,1c,2c,3c,4c,5c)
#define BF_ADD10_TO_6d(F) F(7d,8d,9d,ad,bd,cd,dd,ed,fd,d,1d,2d,3d,4d,5d)
#define BF_ADD10_TO_6e(F) F(7e,8e,9e,ae,be,ce,de,ee,fe,e,1e,2e,3e,4e,5e)
#define BF_ADD10_TO_6f(F) F(7f,8f,9f,af,bf,cf,df,ef,ff,f,1f,2f,3f,4f,5f)
#define BF_ADD10_TO_70(F) F(80,90,a0,b0,c0,d0,e0,f0,0,10,20,30,40,50,60)
#define BF_ADD10_TO_71(F) F(81,91,a1,b1,c1,d1,e1,f1,1,11,21,31,41,51,61)
#define BF_ADD10_TO_72(F) F(82,92,a2,b2,c2,d2,e2,f2,2,12,22,32,42,52,62)
#define BF_ADD10_TO_73(F) F(83,93,a3,b3,c3,d3,e3,f3,3,13,23,33,43,53,63)
#define BF_ADD10_TO_74(F) F(84,94,a4,b4,c4,d4,e4,f4,4,14,24,34,44,54,64)
#define BF_ADD10_TO_75(F) F(85,95,a5,b5,c5,d5,e5,f5,5,15,25,35,45,55,65)
#define BF_ADD10_TO_76(F) F(86,96,a6,b6,c6,d6,e6,f6,6,16,26,36,46,56,66)
#define BF_ADD10_TO_77(F) F(87,97,a7,b7,c7,d7,e7,f7,7,17,27,37,47,57,67)
#define BF_ADD10_TO_78(F) F(88,98,a8,b8,c8,d8,e8,f8,8,18,28,38,48,58,68)
#define BF_ADD10_TO_79(F) F(89,99,a9,b9,c9,d9,e9,f9,9,19,29,39,49,59,69)
#define BF_ADD10_TO_7a(F) F(8a,9a,aa,ba,ca,da,ea,fa,a,1a,2a,3a,4a,5a,6a)
#define BF_ADD10_TO_7b(F) F(8b,9b,ab,bb,cb,db,eb,fb,b,1b,2b,3b,4b,5b,6b)
#define BF_ADD10_TO_7c(F) F(8c,9c,ac,bc,cc,dc,ec,fc,c,1c,2c,3c,4c,5c,6c)
#define BF_ADD10_TO_7d(F) F(8d,9d,ad,bd,cd,dd,ed,fd,d,1d,2d,3d,4d,5d,6d)
#define BF_ADD10_TO_7e(F) F(8e,9e,ae,be,ce,de,ee,fe,e,1e,2e,3e,4e,5e,6e)
#define BF_ADD10_TO_7f(F) F(8f,9f,af,bf,cf,df,ef,ff,f,1f,2f,3f,4f,5f,6f)
#define BF_ADD10_TO_80(F) F(90,a0,b0,c0,d0,e0,f0,0,10,20,30,40,50,60,70)
#define BF_ADD10_TO_81(F) F(91,a1,b1,c1,d1,e1,f1,1,11,21,31,41,51,61,71)
#define BF_ADD10_TO_82(F) F(92,a2,b2,c2,d2,e2,f2,2,12,22,32,42,52,62,72)
#define BF_ADD10_TO_83(F) F(93,a3,b3,c3,d3,e3,f3,3,13,23,33,43,53,63,73)
#define BF_ADD10_TO_84(F) F(94,a4,b4,c4,d4,e4,f4,4,14,24,34,44,54,64,74)
#define BF_ADD10_TO_85(F) F(95,a5,b5,c5,d5,e5,f5,5,15,25,35,45,55,65,75)
#define BF_ADD10_TO_86(F) F(96,a6,b6,c6,d6,e6,f6,6,16,26,36,46,56,66,76)
#define BF_ADD10_TO_87(F) F(97,a7,b7,c7,d7,e7,f7,7,17,27,37,47,57,67,77)
#define BF_ADD10_TO_88(F) F(98,a8,b8,c8,d8,e8,f8,8,18,28,38,48,58,68,78)
#define BF_ADD10_TO_89(F) F(99,a9,b9,c9,d9,e9,f9,9,19,29,39,49,59,69,79)
#define BF_ADD10_TO_8a(F) F(9a,aa,ba,ca,da,ea,fa,a,1a,2a,3a,4a,5a,6a,7a)
#define BF_ADD10_TO_8b(F) F(9b,ab,bb,cb,db,eb,fb,b,1b,2b,3b,4b,5b,6b,7b)
#define BF_ADD10_TO_8c(F) F(9c,ac,bc,cc,dc,ec,fc,c,1c,2c,3c,4c,5c,6c,7c)
#define BF_ADD10_TO_8d(F) F(9d,ad,bd,cd,dd,ed,fd,d,1d,2d,3d,4d,5d,6d,7d)
#define BF_ADD10_TO_8e(F) F(9e,ae,be,ce,de,ee,fe,e,1e,2e,3e,4e,5e,6e,7e)
#define BF_ADD10_TO_8f(F) F(9f,af,bf,cf,df,ef,ff,f,1f,2f,3f,4f,5f,6f,7f)
#define BF_ADD10_TO_90(F) F(a0,b0,c0,d0,e0,f0,0,10,20,30,40,50,60,70,80)
#define BF_ADD10_TO_91(F) F(a1,b1,c1,d1,e1,f1,1,11,21,31,41,51,61,71,81)
#define BF_ADD10_TO_92(F) F(a2,b2,c2,d2,e2,f2,2,12,22,32,42,52,62,72,82)
#define BF_ADD10_TO_93(F) F(a3,b3,c3,d3,e3,f3,3,13,23,33,43,53,63,73,83)
#define BF_ADD10_TO_94(F) F(a4,b4,c4,d4,e4,f4,4,14,24,34,44,54,64,74,84)
#define BF_ADD10_TO_95(F) F(a5,b5,c5,d5,e5,f5,5,15,25,35,45,55,65,75,85)
#define BF_ADD10_TO_96(F) F(a6,b6,c6,d6,e6,f6,6,16,26,36,46,56,66,76,86)
#define BF_ADD10_TO_97(F) F(a7,b7,c7,d7,e7,f7,7,17,27,37,47,57,67,77,87)
#define BF_ADD10_TO_98(F) F(a8,b8,c8,d8,e8,f8,8,18,28,38,48,58,68,78,88)
#define BF_ADD10_TO_99(F) F(a9,b9,c9,d9,e9,f9,9,19,29,39,49,59,69,79,89)
#define BF_ADD10_TO_9a(F) F(aa,ba,ca,da,ea,fa,a,1a,2a,3a,4a,5a,6a,7a,8a)
#define BF_ADD10_TO_9b(F) F(ab,bb,cb,db,eb,fb,b,1b,2b,3b,4b,5b,6b,7b,8b)
#define BF_ADD10_TO_9c(F) F(ac,bc,cc,dc,ec,fc,c,1c,2c,3c,4c,5c,6c,7c,8c)
#define BF_ADD10_TO_9d(F) F(ad,bd,cd,dd,ed,fd,d,1d,2d,3d,4d,5d,6d,7d,8d)
#define BF_ADD10_TO_9e(F) F(ae,be,ce,de,ee,fe,e,1e,2e,3e,4e,5e,6e,7e,8e)
#define BF_ADD10_TO_9f(F) F(af,bf,cf,df,ef,ff,f,1f,2f,3f,4f,5f,6f,7f,8f)
#define BF_ADD10_TO_a0(F) F(b0,c0,d0,e0,f0,0,10,20,30,40,50,60,70,80,90)
#define BF_ADD10_TO_a1(F) F(b1,c1,d1,e1,f1,1,11,21,31,41,51,61,71,81,91)
#define BF_ADD10_TO_a2(F) F(b2,c2,d2,e2,f2,2,12,22,32,42,52,62,72,82,92)
#define BF_ADD10_TO_a3(F) F(b3,c3,d3,e3,f3,3,13,23,33,43,53,63,73,83,93)
#define BF_ADD10_TO_a4(F) F(b4,c4,d4,e4,f4,4,14,24,34,44,54,64,74,84,94)
#define BF_ADD10_TO_a5(F) F(b5,c5,d5,e5,f5,5,15,25,35,45,55,65,75,85,95)
#define BF_ADD10_TO_a6(F) F(b6,c6,d6,e6,f6,6,16,26,36,46,56,66,76,86,96)
#define BF_ADD10_TO_a7(F) F(b7,c7,d7,e7,f7,7,17,27,37,47,57,67,77,87,97)
#define BF_ADD10_TO_a8(F) F(b8,c8,d8,e8,f8,8,18,28,38,48,58,68,78,88,98)
#define BF_ADD10_TO_a9(F) F(b9,c9,d9,e9,f9,9,19,29,39,49,59,69,79,89,99)
#define BF_ADD10_TO_aa(F) F(ba,ca,da,ea,fa,a,1a,2a,3a,4a,5a,6a,7a,8a,9a)
#define BF_ADD10_TO_ab(F) F(bb,cb,db,eb,fb,b,1b,2b,3b,4b,5b,6b,7b,8b,9b)
#define BF_ADD10_TO_ac(F) F(bc,cc,dc,ec,fc,c,1c,2c,3c,4c,5c,6c,7c,8c,9c)
#define BF_ADD10_TO_ad(F) F(bd,cd,dd,ed,fd,d,1d,2d,3d,4d,5d,6d,7d,8d,9d)
#define BF_ADD10_TO_ae(F) F(be,ce,de,ee,fe,e,1e,2e,3e,4e,5e,6e,7e,8e,9e)
#define BF_ADD10_TO_af(F) F(bf,cf,df,ef,ff,f,1f,2f,3f,4f,5f,6f,7f,8f,9f)
#define BF_ADD10_TO_b0(F) F(c0,d0,e0,f0,0,10,20,30,40,50,60,70,80,90,a0)
#define BF_ADD10_TO_b1(F) F(c1,d1,e1,f1,1,11,21,31,41,51,61,71,81,91,a1)
#define BF_ADD10_TO_b2(F) F(c2,d2,e2,f2,2,12,22,32,42,52,62,72,82,92,a2)
#define BF_ADD10_TO_b3(F) F(c3,d3,e3,f3,3,13,23,33,43,53,63,73,83,93,a3)
#define BF_ADD10_TO_b4(F) F(c4,d4,e4,f4,4,14,24,34,44,54,64,74,84,94,a4)
#define BF_ADD10_TO_b5(F) F(c5,d5,e5,f5,5,15,25,35,45,55,65,75,85,95,a5)
#define BF_ADD10_TO_b6(F) F(c6,d6,e6,f6,6,16,26,36,46,56,66,76,86,96,a6)
#define BF_ADD10_TO_b7(F) F(c7,d7,e7,f7,7,17,27,37,47,57,67,77,87,97,a7)
#define BF_ADD10_TO_b8(F) F(c8,d8,e8,f8,8,18,28,38,48,58,68,78,88,98,a8)
#define BF_ADD10_TO_b9(F) F(c9,d9,e9,f9,9,19,29,39,49,59,69,79,89,99,a9)
#define BF_ADD10_TO_ba(F) F(ca,da,ea,fa,a,1a,2a,3a,4a,5a,6a,7a,8a,9a,aa)
#define BF_ADD10_TO_bb(F) F(cb,db,eb,fb,b,1b,2b,3b,4b,5b,6b,7b,8b,9b,ab)
#define BF_ADD10_TO_bc(F) F(cc,dc,ec,fc,c,1c,2c,3c,4c,5c,6c,7c,8c,9c,ac)
#define BF_ADD10_TO_bd(F) F(cd,dd,ed,fd,d,1d,2d,3d,4d,5d,6d,7d,8d,9d,ad)
#define BF_ADD10_TO_be(F) F(ce,de,ee,fe,e,1e,2e,3e,4e,5e,6e,7e,8e,9e,ae)
#define BF_ADD10_TO_bf(F) F(cf,df,ef,ff,f,1f,2f,3f,4f,5f,6f,7f,8f,9f,af)
#define BF_ADD10_TO_c0(F) F(d0,e0,f0,0,10,20,30,40,50,60,70,80,90,a0,b0)
#define BF_ADD10_TO_c1(F) F(d1,e1,f1,1,11,21,31,41,51,61,71,81,91,a1,b1)
#define BF_ADD10_TO_c2(F) F(d2,e2,f2,2,12,22,32,42,52,62,72,82,92,a2,b2)
#define BF_ADD10_TO_c3(F) F(d3,e3,f3,3,13,23,33,43,53,63,73,83,93,a3,b3)
#define BF_ADD10_TO_c4(F) F(d4,e4,f4,4,14,24,34,44,54,64,74,84,94,a4,b4)
#define BF_ADD10_TO_c5(F) F(d5,e5,f5,5,15,25,35,45,55,65,75,85,95,a5,b5)
#define BF_ADD10_TO_c6(F) F(d6,e6,f6,6,16,26,36,46,56,66,76,86,96,a6,b6)
#define BF_ADD10_TO_c7(F) F(d7,e7,f7,7,17,27,37,47,57,67,77,87,97,a7,b7)
#define BF_ADD10_TO_c8(F) F(d8,e8,f8,8,18,28,38,48,58,68,78,88,98,a8,b8)
#define BF_ADD10_TO_c9(F) F(d9,e9,f9,9,19,29,39,49,59,69,79,89,99,a9,b9)
#define BF_ADD10_TO_ca(F) F(da,ea,fa,a,1a,2a,3a,4a,5a,6a,7a,8a,9a,aa,ba)
#define BF_ADD10_TO_cb(F) F(db,eb,fb,b,1b,2b,3b,4b,5b,6b,7b,8b,9b,ab,bb)
#define BF_ADD10_TO_cc(F) F(dc,ec,fc,c,1c,2c,3c,4c,5c,6c,7c,8c,9c,ac,bc)
#define BF_ADD10_TO_cd(F) F(dd,ed,fd,d,1d,2d,3d,4d,5d,6d,7d,8d,9d,ad,bd)
#define BF_ADD10_TO_ce(F) F(de,ee,fe,e,1e,2e,3e,4e,5e,6e,7e,8e,9e,ae,be)
#define BF_ADD10_TO_cf(F) F(df,ef,ff,f,1f,2f,3f,4f,5f,6f,7f,8f,9f,af,bf)
#define BF_ADD10_TO_d0(F) F(e0,f0,0,10,20,30,40,50,60,70,80,90,a0,b0,c0)
#define BF_ADD10_TO_d1(F) F(e1,f1,1,11,21,31,41,51,61,71,81,91,a1,b1,c1)
#define BF_ADD10_TO_d2(F) F(e2,f2,2,12,22,32,42,52,62,72,82,92,a2,b2,c2)
#define BF_ADD10_TO_d3(F) F(e3,f3,3,13,23,33,43,53,63,73,83,93,a3,b3,c3)
#define BF_ADD10_TO_d4(F) F(e4,f4,4,14,24,34,44,54,64,74,84,94,a4,b4,c4)
#define BF_ADD10_TO_d5(F) F(e5,f5,5,15,25,35,45,55,65,75,85,95,a5,b5,c5)
#define BF_ADD10_TO_d6(F) F(e6,f6,6,16,26,36,46,56,66,76,86,96,a6,b6,c6)
#define BF_ADD10_TO_d7(F) F(e7,f7,7,17,27,37,47,57,67,77,87,97,a7,b7,c7)
#define BF_ADD10_TO_d8(F) F(e8,f8,8,18,28,38,48,58,68,78,88,98,a8,b8,c8)
#define BF_ADD10_TO_d9(F) F(e9,f9,9,19,29,39,49,59,69,79,89,99,a9,b9,c9)
#define BF_ADD10_TO_da(F) F(ea,fa,a,1a,2a,3a,4a,5a,6a,7a,8a,9a,aa,ba,ca)
#define BF_ADD10_TO_db(F) F(eb,fb,b,1b,2b,3b,4b,5b,6b,7b,8b,9b,ab,bb,cb)
#define BF_ADD10_TO_dc(F) F(ec,fc,c,1c,2c,3c,4c,5c,6c,7c,8c,9c,ac,bc,cc)
#define BF_ADD10_TO_dd(F) F(ed,fd,d,1d,2d,3d,4d,5d,6d,7d,8d,9d,ad,bd,cd)
#define BF_ADD10_TO_de(F) F(ee,fe,e,1e,2e,3e,4e,5e,6e,7e,8e,9e,ae,be,ce)
#define BF_ADD10_TO_df(F) F(ef,ff,f,1f,2f,3f,4f,5f,6f,7f,8f,9f,af,bf,cf)
#define BF_ADD10_TO_e0(F) F(f0,0,10,20,30,40,50,60,70,80,90,a0,b0,c0,d0)
#define BF_ADD10_TO_e1(F) F(f1,1,11,21,31,41,51,61,71,81,91,a1,b1,c1,d1)
#define BF_ADD10_TO_e2(F) F(f2,2,12,22,32,42,52,62,72,82,92,a2,b2,c2,d2)
#define BF_ADD10_TO_e3(F) F(f3,3,13,23,33,43,53,63,73,83,93,a3,b3,c3,d3)
#define BF_ADD10_TO_e4(F) F(f4,4,14,24,34,44,54,64,74,84,94,a4,b4,c4,d4)
#define BF_ADD10_TO_e5(F) F(f5,5,15,25,35,45,55,65,75,85,95,a5,b5,c5,d5)
#define BF_ADD10_TO_e6(F) F(f6,6,16,26,36,46,56,66,76,86,96,a6,b6,c6,d6)
#define BF_ADD10_TO_e7(F) F(f7,7,17,27,37,47,57,67,77,87,97,a7,b7,c7,d7)
#define BF_ADD10_TO_e8(F) F(f8,8,18,28,38,48,58,68,78,88,98,a8,b8,c8,d8)
#define BF_ADD10_TO_e9(F) F(f9,9,19,29,39,49,59,69,79,89,99,a9,b9,c9,d9)
#define BF_ADD10_TO_ea(F) F(fa,a,1a,2a,3a,4a,5a,6a,7a,8a,9a,aa,ba,ca,da)
#define BF_ADD10_TO_eb(F) F(fb,b,1b,2b,3b,4b,5b,6b,7b,8b,9b,ab,bb,cb,db)
#define BF_ADD10_TO_ec(F) F(fc,c,1c,2c,3c,4c,5c,6c,7c,8c,9c,ac,bc,cc,dc)
#define BF_ADD10_TO_ed(F) F(fd,d,1d,2d,3d,4d,5d,6d,7d,8d,9d,ad,bd,cd,dd)
#define BF_ADD10_TO_ee(F) F(fe,e,1e,2e,3e,4e,5e,6e,7e,8e,9e,ae,be,ce,de)
#define BF_ADD10_TO_ef(F) F(ff,f,1f,2f,3f,4f,5f,6f,7f,8f,9f,af,bf,cf,df)
#define BF_ADD10_TO_f0(F) F(0,10,20,30,40,50,60,70,80,90,a0,b0,c0,d0,e0)
#define BF_ADD10_TO_f1(F) F(1,11,21,31,41,51,61,71,81,91,a1,b1,c1,d1,e1)
#define BF_ADD10_TO_f2(F) F(2,12,22,32,42,52,62,72,82,92,a2,b2,c2,d2,e2)
#define BF_ADD10_TO_f3(F) F(3,13,23,33,43,53,63,73,83,93,a3,b3,c3,d3,e3)
#define BF_ADD10_TO_f4(F) F(4,14,24,34,44,54,64,74,84,94,a4,b4,c4,d4,e4)
#define BF_ADD10_TO_f5(F) F(5,15,25,35,45,55,65,75,85,95,a5,b5,c5,d5,e5)
#define BF_ADD10_TO_f6(F) F(6,16,26,36,46,56,66,76,86,96,a6,b6,c6,d6,e6)
#define BF_ADD10_TO_f7(F) F(7,17,27,37,47,57,67,77,87,97,a7,b7,c7,d7,e7)
#define BF_ADD10_TO_f8(F) F(8,18,28,38,48,58,68,78,88,98,a8,b8,c8,d8,e8)
#define BF_ADD10_TO_f9(F) F(9,19,29,39,49,59,69,79,89,99,a9,b9,c9,d9,e9)
#define BF_ADD10_TO_fa(F) F(a,1a,2a,3a,4a,5a,6a,7a,8a,9a,aa,ba,ca,da,ea)
#define BF_ADD10_TO_fb(F) F(b,1b,2b,3b,4b,5b,6b,7b,8b,9b,ab,bb,cb,db,eb)
#define BF_ADD10_TO_fc(F) F(c,1c,2c,3c,4c,5c,6c,7c,8c,9c,ac,bc,cc,dc,ec)
#define BF_ADD10_TO_fd(F) F(d,1d,2d,3d,4d,5d,6d,7d,8d,9d,ad,bd,cd,dd,ed)
#define BF_ADD10_TO_fe(F) F(e,1e,2e,3e,4e,5e,6e,7e,8e,9e,ae,be,ce,de,ee)
#define BF_ADD10_TO_ff(F) F(f,1f,2f,3f,4f,5f,6f,7f,8f,9f,af,bf,cf,df,ef)

#define BF_ADD_AT_10(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) a
#define BF_ADD_AT_20(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) b
#define BF_ADD_AT_30(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) c
#define BF_ADD_AT_40(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) d
#define BF_ADD_AT_50(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) e
#define BF_ADD_AT_60(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) f
#define BF_ADD_AT_70(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) g
#define BF_ADD_AT_80(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) h
#define BF_ADD_AT_90(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) i
#define BF_ADD_AT_a0(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) j
#define BF_ADD_AT_b0(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) k
#define BF_ADD_AT_c0(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) l
#define BF_ADD_AT_d0(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) m
#define BF_ADD_AT_e0(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) n
#define BF_ADD_AT_f0(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) o

#define BF_ADD_CAT(a,b) a##b
#define BF_ADD_PCAT(a,b) BF_ADD_CAT(a,b)

#define BF_ADD_1(x) BF_INC_##x
#define BF_ADD_2(x) BF_ADD_TO_##x(BF_ADD_AT_2)
#define BF_ADD_3(x) BF_ADD_TO_##x(BF_ADD_AT_3)
#define BF_ADD_4(x) BF_ADD_TO_##x(BF_ADD_AT_4)
#define BF_ADD_5(x) BF_ADD_TO_##x(BF_ADD_AT_5)
#define BF_ADD_6(x) BF_ADD_TO_##x(BF_ADD_AT_6)
#define BF_ADD_7(x) BF_ADD_TO_##x(BF_ADD_AT_7)
#define BF_ADD_8(x) BF_ADD_TO_##x(BF_ADD_AT_8)
#define BF_ADD_9(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_10)
#define BF_ADD_a(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_10)
#define BF_ADD_b(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_10)
#define BF_ADD_c(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_10)
#define BF_ADD_d(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_10)
#define BF_ADD_e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_10)
#define BF_ADD_f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_10)
#define BF_ADD_10(x) BF_ADD10_TO_##x(BF_ADD_AT_10)
#define BF_ADD_11(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_10)
#define BF_ADD_12(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_10)
#define BF_ADD_13(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_10)
#define BF_ADD_14(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_10)
#define BF_ADD_15(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_10)
#define BF_ADD_16(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_10)
#define BF_ADD_17(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_10)
#define BF_ADD_18(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_10)
#define BF_ADD_19(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_20)
#define BF_ADD_1a(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_20)
#define BF_ADD_1b(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_20)
#define BF_ADD_1c(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_20)
#define BF_ADD_1d(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_20)
#define BF_ADD_1e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_20)
#define BF_ADD_1f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_20)
#define BF_ADD_20(x) BF_ADD10_TO_##x(BF_ADD_AT_20)
#define BF_ADD_21(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_20)
#define BF_ADD_22(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_20)
#define BF_ADD_23(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_20)
#define BF_ADD_24(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_20)
#define BF_ADD_25(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_20)
#define BF_ADD_26(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_20)
#define BF_ADD_27(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_20)
#define BF_ADD_28(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_20)
#define BF_ADD_29(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_30)
#define BF_ADD_2a(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_30)
#define BF_ADD_2b(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_30)
#define BF_ADD_2c(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_30)
#define BF_ADD_2d(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_30)
#define BF_ADD_2e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_30)
#define BF_ADD_2f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_30)
#define BF_ADD_30(x) BF_ADD10_TO_##x(BF_ADD_AT_30)
#define BF_ADD_31(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_30)
#define BF_ADD_32(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_30)
#define BF_ADD_33(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_30)
#define BF_ADD_34(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_30)
#define BF_ADD_35(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_30)
#define BF_ADD_36(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_30)
#define BF_ADD_37(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_30)
#define BF_ADD_38(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_30)
#define BF_ADD_39(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_40)
#define BF_ADD_3a(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_40)
#define BF_ADD_3b(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_40)
#define BF_ADD_3c(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_40)
#define BF_ADD_3d(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_40)
#define BF_ADD_3e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_40)
#define BF_ADD_3f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_40)
#define BF_ADD_40(x) BF_ADD10_TO_##x(BF_ADD_AT_40)
#define BF_ADD_41(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_40)
#define BF_ADD_42(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_40)
#define BF_ADD_43(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_40)
#define BF_ADD_44(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_40)
#define BF_ADD_45(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_40)
#define BF_ADD_46(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_40)
#define BF_ADD_47(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_40)
#define BF_ADD_48(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_40)
#define BF_ADD_49(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_50)
#define BF_ADD_4a(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_50)
#define BF_ADD_4b(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_50)
#define BF_ADD_4c(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_50)
#define BF_ADD_4d(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_50)
#define BF_ADD_4e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_50)
#define BF_ADD_4f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_50)
#define BF_ADD_50(x) BF_ADD10_TO_##x(BF_ADD_AT_50)
#define BF_ADD_51(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_50)
#define BF_ADD_52(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_50)
#define BF_ADD_53(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_50)
#define BF_ADD_54(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_50)
#define BF_ADD_55(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_50)
#define BF_ADD_56(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_50)
#define BF_ADD_57(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_50)
#define BF_ADD_58(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_50)
#define BF_ADD_59(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_60)
#define BF_ADD_5a(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_60)
#define BF_ADD_5b(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_60)
#define BF_ADD_5c(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_60)
#define BF_ADD_5d(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_60)
#define BF_ADD_5e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_60)
#define BF_ADD_5f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_60)
#define BF_ADD_60(x) BF_ADD10_TO_##x(BF_ADD_AT_60)
#define BF_ADD_61(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_60)
#define BF_ADD_62(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_60)
#define BF_ADD_63(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_60)
#define BF_ADD_64(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_60)
#define BF_ADD_65(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_60)
#define BF_ADD_66(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_60)
#define BF_ADD_67(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_60)
#define BF_ADD_68(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_60)
#define BF_ADD_69(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_70)
#define BF_ADD_6a(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_70)
#define BF_ADD_6b(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_70)
#define BF_ADD_6c(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_70)
#define BF_ADD_6d(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_70)
#define BF_ADD_6e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_70)
#define BF_ADD_6f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_70)
#define BF_ADD_70(x) BF_ADD10_TO_##x(BF_ADD_AT_70)
#define BF_ADD_71(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_70)
#define BF_ADD_72(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_70)
#define BF_ADD_73(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_70)
#define BF_ADD_74(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_70)
#define BF_ADD_75(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_70)
#define BF_ADD_76(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_70)
#define BF_ADD_77(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_70)
#define BF_ADD_78(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_70)
#define BF_ADD_79(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_80)
#define BF_ADD_7a(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_80)
#define BF_ADD_7b(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_80)
#define BF_ADD_7c(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_80)
#define BF_ADD_7d(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_80)
#define BF_ADD_7e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_80)
#define BF_ADD_7f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_80)
#define BF_ADD_80(x) BF_ADD10_TO_##x(BF_ADD_AT_80)
#define BF_ADD_81(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_80)
#define BF_ADD_82(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_80)
#define BF_ADD_83(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_80)
#define BF_ADD_84(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_80)
#define BF_ADD_85(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_80)
#define BF_ADD_86(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_80)
#define BF_ADD_87(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_80)
#define BF_ADD_88(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_80)
#define BF_ADD_89(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_90)
#define BF_ADD_8a(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_90)
#define BF_ADD_8b(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_90)
#define BF_ADD_8c(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_90)
#define BF_ADD_8d(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_90)
#define BF_ADD_8e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_90)
#define BF_ADD_8f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_90)
#define BF_ADD_90(x) BF_ADD10_TO_##x(BF_ADD_AT_90)
#define BF_ADD_91(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_90)
#define BF_ADD_92(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_90)
#define BF_ADD_93(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_90)
#define BF_ADD_94(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_90)
#define BF_ADD_95(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_90)
#define BF_ADD_96(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_90)
#define BF_ADD_97(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_90)
#define BF_ADD_98(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_90)
#define BF_ADD_99(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_a0)
#define BF_ADD_9a(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_a0)
#define BF_ADD_9b(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_a0)
#define BF_ADD_9c(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_a0)
#define BF_ADD_9d(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_a0)
#define BF_ADD_9e(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_a0)
#define BF_ADD_9f(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_a0)
#define BF_ADD_a0(x) BF_ADD10_TO_##x(BF_ADD_AT_a0)
#define BF_ADD_a1(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_a0)
#define BF_ADD_a2(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_a0)
#define BF_ADD_a3(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_a0)
#define BF_ADD_a4(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_a0)
#define BF_ADD_a5(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_a0)
#define BF_ADD_a6(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_a0)
#define BF_ADD_a7(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_a0)
#define BF_ADD_a8(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_a0)
#define BF_ADD_a9(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_b0)
#define BF_ADD_aa(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_b0)
#define BF_ADD_ab(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_b0)
#define BF_ADD_ac(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_b0)
#define BF_ADD_ad(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_b0)
#define BF_ADD_ae(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_b0)
#define BF_ADD_af(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_b0)
#define BF_ADD_b0(x) BF_ADD10_TO_##x(BF_ADD_AT_b0)
#define BF_ADD_b1(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_b0)
#define BF_ADD_b2(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_b0)
#define BF_ADD_b3(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_b0)
#define BF_ADD_b4(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_b0)
#define BF_ADD_b5(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_b0)
#define BF_ADD_b6(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_b0)
#define BF_ADD_b7(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_b0)
#define BF_ADD_b8(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_b0)
#define BF_ADD_b9(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_c0)
#define BF_ADD_ba(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_c0)
#define BF_ADD_bb(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_c0)
#define BF_ADD_bc(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_c0)
#define BF_ADD_bd(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_c0)
#define BF_ADD_be(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_c0)
#define BF_ADD_bf(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_c0)
#define BF_ADD_c0(x) BF_ADD10_TO_##x(BF_ADD_AT_c0)
#define BF_ADD_c1(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_c0)
#define BF_ADD_c2(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_c0)
#define BF_ADD_c3(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_c0)
#define BF_ADD_c4(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_c0)
#define BF_ADD_c5(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_c0)
#define BF_ADD_c6(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_c0)
#define BF_ADD_c7(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_c0)
#define BF_ADD_c8(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_c0)
#define BF_ADD_c9(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_d0)
#define BF_ADD_ca(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_d0)
#define BF_ADD_cb(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_d0)
#define BF_ADD_cc(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_d0)
#define BF_ADD_cd(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_d0)
#define BF_ADD_ce(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_d0)
#define BF_ADD_cf(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_d0)
#define BF_ADD_d0(x) BF_ADD10_TO_##x(BF_ADD_AT_d0)
#define BF_ADD_d1(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_d0)
#define BF_ADD_d2(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_d0)
#define BF_ADD_d3(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_d0)
#define BF_ADD_d4(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_d0)
#define BF_ADD_d5(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_d0)
#define BF_ADD_d6(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_d0)
#define BF_ADD_d7(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_d0)
#define BF_ADD_d8(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_d0)
#define BF_ADD_d9(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_e0)
#define BF_ADD_da(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_e0)
#define BF_ADD_db(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_e0)
#define BF_ADD_dc(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_e0)
#define BF_ADD_dd(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_e0)
#define BF_ADD_de(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_e0)
#define BF_ADD_df(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_e0)
#define BF_ADD_e0(x) BF_ADD10_TO_##x(BF_ADD_AT_e0)
#define BF_ADD_e1(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_e0)
#define BF_ADD_e2(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_e0)
#define BF_ADD_e3(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_e0)
#define BF_ADD_e4(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_e0)
#define BF_ADD_e5(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_e0)
#define BF_ADD_e6(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_e0)
#define BF_ADD_e7(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_e0)
#define BF_ADD_e8(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_e0)
#define BF_ADD_e9(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_7))(BF_ADD_AT_f0)
#define BF_ADD_ea(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_6))(BF_ADD_AT_f0)
#define BF_ADD_eb(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_5))(BF_ADD_AT_f0)
#define BF_ADD_ec(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_4))(BF_ADD_AT_f0)
#define BF_ADD_ed(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_3))(BF_ADD_AT_f0)
#define BF_ADD_ee(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_SUB_AT_2))(BF_ADD_AT_f0)
#define BF_ADD_ef(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_DEC_##x)(BF_ADD_AT_f0)
#define BF_ADD_f0(x) BF_ADD10_TO_##x(BF_ADD_AT_f0)
#define BF_ADD_f1(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_INC_##x)(BF_ADD_AT_f0)
#define BF_ADD_f2(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_2))(BF_ADD_AT_f0)
#define BF_ADD_f3(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_3))(BF_ADD_AT_f0)
#define BF_ADD_f4(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_4))(BF_ADD_AT_f0)
#define BF_ADD_f5(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_5))(BF_ADD_AT_f0)
#define BF_ADD_f6(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_6))(BF_ADD_AT_f0)
#define BF_ADD_f7(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_7))(BF_ADD_AT_f0)
#define BF_ADD_f8(x) BF_ADD_PCAT(BF_ADD10_TO_, BF_ADD_TO_##x(BF_ADD_AT_8))(BF_ADD_AT_f0)
#define BF_ADD_f9(x) BF_ADD_TO_##x(BF_SUB_AT_7)
#define BF_ADD_fa(x) BF_ADD_TO_##x(BF_SUB_AT_6)
#define BF_ADD_fb(x) BF_ADD_TO_##x(BF_SUB_AT_5)
#define BF_ADD_fc(x) BF_ADD_TO_##x(BF_SUB_AT_4)
#define BF_ADD_fd(x) BF_ADD_TO_##x(BF_SUB_AT_3)
#define BF_ADD_fe(x) BF_ADD_TO_##x(BF_SUB_AT_2)
#define BF_ADD_ff(x) BF_DEC_##x


