
#if 0

#define BF_CM(...) BF_SCAN(BF_SEQ_EAT BF_LPAREN BF_CM_UP_0(__VA_ARGS__))

#define BF_CM_UP_0(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_1( BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_1(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_2( BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_2(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_3( BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_3(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_4( BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_4(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_5( BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_5(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_6( BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_6(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_7( BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_7(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_8( BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_8(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_9( BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_9(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_10(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_10(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_11(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_11(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_12(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_12(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_13(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_13(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_14(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_14(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_15(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_15(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_16(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))
#define BF_CM_UP_16(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_17(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__))

#define BF_CM_PASS_UP_1(P,i,tl,t,tr,fs,f,...)   BF_CM_UP_1 x
#define BF_CM_PASS_UP_2(P,i,tl,t,tr,fs,f,...)   BF_CM_UP_2 x
#define BF_CM_PASS_UP_3(P,i,tl,t,tr,fs,f,...)   BF_CM_UP_3 x
#define BF_CM_PASS_UP_4(P,i,tl,t,tr,fs,f,...)   BF_CM_UP_4 x
#define BF_CM_PASS_UP_5(P,i,tl,t,tr,fs,f,...)   BF_CM_UP_5 x
#define BF_CM_PASS_UP_6(P,i,tl,t,tr,fs,f,...)   BF_CM_UP_6 x
#define BF_CM_PASS_UP_7(P,i,tl,t,tr,fs,f,...)   BF_CM_UP_7 x
#define BF_CM_PASS_UP_8(P,i,tl,t,tr,fs,f,...)   BF_CM_UP_8 x
#define BF_CM_PASS_UP_9(P,i,tl,t,tr,fs,f,...)   BF_CM_UP_9 x
#define BF_CM_PASS_UP_10(P,i,tl,t,tr,fs,f,...)  BF_CM_UP_10 x
#define BF_CM_PASS_UP_11(P,i,tl,t,tr,fs,f,...)  BF_CM_UP_11 x
#define BF_CM_PASS_UP_12(P,i,tl,t,tr,fs,f,...)  BF_CM_UP_12 x
#define BF_CM_PASS_UP_13(P,i,tl,t,tr,fs,f,...)  BF_CM_UP_13 x
#define BF_CM_PASS_UP_14(P,i,tl,t,tr,fs,f,...)  BF_CM_UP_14 x
#define BF_CM_PASS_UP_15(P,i,tl,t,tr,fs,f,...)  BF_CM_UP_15 x
#define BF_CM_PASS_UP_16(P,i,tl,t,tr,fs,f,...)  BF_CM_UP_16 x
#define BF_CM_PASS_UP_17(P,i,tl,t,tr,fs,f,...)  BF_CM_ERROR_NO_MORE_MACHINE_STATES x

#define BF_CM_ERROR_NO_MORE_MACHINE_STATES()

#elif 1


#define BF_CM(...) BF_SCAN(BF_SEQ_EAT BF_LPAREN BF_CM_UP_0(__VA_ARGS__))

#define BF_CM_UP_0(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_1 (BF_CM_PASS_DN_0 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_1(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_2 (BF_CM_PASS_DN_1 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_2(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_3 (BF_CM_PASS_DN_2 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_3(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_4 (BF_CM_PASS_DN_3 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_4(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_5 (BF_CM_PASS_DN_4 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_5(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_6 (BF_CM_PASS_DN_5 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_6(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_7 (BF_CM_PASS_DN_6 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_7(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_8 (BF_CM_PASS_DN_7 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_8(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_9 (BF_CM_PASS_DN_8 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_9(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_UP_10(BF_CM_PASS_DN_9 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_10(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_11(BF_CM_PASS_DN_10(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_11(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_12(BF_CM_PASS_DN_11(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_12(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_13(BF_CM_PASS_DN_12(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_13(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_14(BF_CM_PASS_DN_13(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_14(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_15(BF_CM_PASS_DN_14(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_15(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_16(BF_CM_PASS_DN_15(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_16(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_17(BF_CM_PASS_DN_16(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_17(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_18(BF_CM_PASS_DN_17(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_18(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_19(BF_CM_PASS_DN_18(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_19(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_20(BF_CM_PASS_DN_19(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_20(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_21(BF_CM_PASS_DN_20(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_21(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_22(BF_CM_PASS_DN_21(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_22(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_23(BF_CM_PASS_DN_22(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_23(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_24(BF_CM_PASS_DN_23(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_24(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_25(BF_CM_PASS_DN_24(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_25(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_26(BF_CM_PASS_DN_25(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_26(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_27(BF_CM_PASS_DN_26(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_27(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_28(BF_CM_PASS_DN_27(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_28(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_29(BF_CM_PASS_DN_28(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_29(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_30(BF_CM_PASS_DN_29(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_30(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_31(BF_CM_PASS_DN_30(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_UP_31(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_UP_32(BF_CM_PASS_DN_31(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))

#define BF_CM_DN_0(P,i,tl,t,tr,fs,f,...)                                    BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__  )
#define BF_CM_DN_1(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_DN_0 (BF_CM_PASS_DN_0 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_2(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_DN_1 (BF_CM_PASS_DN_1 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_3(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_DN_2 (BF_CM_PASS_DN_2 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_4(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_DN_3 (BF_CM_PASS_DN_3 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_5(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_DN_4 (BF_CM_PASS_DN_4 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_6(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_DN_5 (BF_CM_PASS_DN_5 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_7(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_DN_6 (BF_CM_PASS_DN_6 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_8(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_DN_7 (BF_CM_PASS_DN_7 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_9(P,i,tl,t,tr,fs,f,...)  BF_CM_PASS_DN_8 (BF_CM_PASS_DN_8 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_10(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_9 (BF_CM_PASS_DN_9 (BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_11(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_10(BF_CM_PASS_DN_10(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_12(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_11(BF_CM_PASS_DN_11(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_13(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_12(BF_CM_PASS_DN_12(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_14(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_13(BF_CM_PASS_DN_13(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_15(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_14(BF_CM_PASS_DN_14(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_16(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_15(BF_CM_PASS_DN_15(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_17(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_16(BF_CM_PASS_DN_16(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_18(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_17(BF_CM_PASS_DN_17(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_19(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_18(BF_CM_PASS_DN_18(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_20(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_19(BF_CM_PASS_DN_19(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_21(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_20(BF_CM_PASS_DN_20(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_22(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_21(BF_CM_PASS_DN_21(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_23(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_22(BF_CM_PASS_DN_22(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_24(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_23(BF_CM_PASS_DN_23(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_25(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_24(BF_CM_PASS_DN_24(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_26(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_25(BF_CM_PASS_DN_25(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_27(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_26(BF_CM_PASS_DN_26(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_28(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_27(BF_CM_PASS_DN_27(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_29(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_28(BF_CM_PASS_DN_28(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_30(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_29(BF_CM_PASS_DN_29(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))
#define BF_CM_DN_31(P,i,tl,t,tr,fs,f,...) BF_CM_PASS_DN_30(BF_CM_PASS_DN_30(BF__##f(,P##i,P##tl,P##t,P##tr,P##fs,P##__VA_ARGS__)))

#define BF_CM_PASS_UP_1(x)  BF_CM_UP_1 x
#define BF_CM_PASS_UP_2(x)  BF_CM_UP_2 x
#define BF_CM_PASS_UP_3(x)  BF_CM_UP_3 x
#define BF_CM_PASS_UP_4(x)  BF_CM_UP_4 x
#define BF_CM_PASS_UP_5(x)  BF_CM_UP_5 x
#define BF_CM_PASS_UP_6(x)  BF_CM_UP_6 x
#define BF_CM_PASS_UP_7(x)  BF_CM_UP_7 x
#define BF_CM_PASS_UP_8(x)  BF_CM_UP_8 x
#define BF_CM_PASS_UP_9(x)  BF_CM_UP_9 x
#define BF_CM_PASS_UP_10(x) BF_CM_UP_10 x
#define BF_CM_PASS_UP_11(x) BF_CM_UP_11 x
#define BF_CM_PASS_UP_12(x) BF_CM_UP_12 x
#define BF_CM_PASS_UP_13(x) BF_CM_UP_13 x
#define BF_CM_PASS_UP_14(x) BF_CM_UP_14 x
#define BF_CM_PASS_UP_15(x) BF_CM_UP_15 x
#define BF_CM_PASS_UP_16(x) BF_CM_UP_16 x
#define BF_CM_PASS_UP_17(x) BF_CM_UP_17 x
#define BF_CM_PASS_UP_18(x) BF_CM_UP_18 x
#define BF_CM_PASS_UP_19(x) BF_CM_UP_19 x
#define BF_CM_PASS_UP_20(x) BF_CM_UP_20 x
#define BF_CM_PASS_UP_21(x) BF_CM_UP_21 x
#define BF_CM_PASS_UP_22(x) BF_CM_UP_22 x
#define BF_CM_PASS_UP_23(x) BF_CM_UP_23 x
#define BF_CM_PASS_UP_24(x) BF_CM_UP_24 x
#define BF_CM_PASS_UP_25(x) BF_CM_UP_25 x
#define BF_CM_PASS_UP_26(x) BF_CM_UP_26 x
#define BF_CM_PASS_UP_27(x) BF_CM_UP_27 x
#define BF_CM_PASS_UP_28(x) BF_CM_UP_28 x
#define BF_CM_PASS_UP_29(x) BF_CM_UP_29 x
#define BF_CM_PASS_UP_30(x) BF_CM_UP_30 x
#define BF_CM_PASS_UP_31(x) BF_CM_UP_31 x
#define BF_CM_PASS_UP_32(x) BF_CM_ERROR_NO_MORE_MACHINE_STATES x

#define BF_CM_PASS_DN_0(x)  BF_CM_DN_0 x
#define BF_CM_PASS_DN_1(x)  BF_CM_DN_1 x
#define BF_CM_PASS_DN_2(x)  BF_CM_DN_2 x
#define BF_CM_PASS_DN_3(x)  BF_CM_DN_3 x
#define BF_CM_PASS_DN_4(x)  BF_CM_DN_4 x
#define BF_CM_PASS_DN_5(x)  BF_CM_DN_5 x
#define BF_CM_PASS_DN_6(x)  BF_CM_DN_6 x
#define BF_CM_PASS_DN_7(x)  BF_CM_DN_7 x
#define BF_CM_PASS_DN_8(x)  BF_CM_DN_8 x
#define BF_CM_PASS_DN_9(x)  BF_CM_DN_9 x
#define BF_CM_PASS_DN_10(x) BF_CM_DN_10 x
#define BF_CM_PASS_DN_11(x) BF_CM_DN_11 x
#define BF_CM_PASS_DN_12(x) BF_CM_DN_12 x
#define BF_CM_PASS_DN_13(x) BF_CM_DN_13 x
#define BF_CM_PASS_DN_14(x) BF_CM_DN_14 x
#define BF_CM_PASS_DN_15(x) BF_CM_DN_15 x
#define BF_CM_PASS_DN_16(x) BF_CM_DN_16 x
#define BF_CM_PASS_DN_17(x) BF_CM_DN_17 x
#define BF_CM_PASS_DN_18(x) BF_CM_DN_18 x
#define BF_CM_PASS_DN_19(x) BF_CM_DN_19 x
#define BF_CM_PASS_DN_20(x) BF_CM_DN_20 x
#define BF_CM_PASS_DN_21(x) BF_CM_DN_21 x
#define BF_CM_PASS_DN_22(x) BF_CM_DN_22 x
#define BF_CM_PASS_DN_23(x) BF_CM_DN_23 x
#define BF_CM_PASS_DN_24(x) BF_CM_DN_24 x
#define BF_CM_PASS_DN_25(x) BF_CM_DN_25 x
#define BF_CM_PASS_DN_26(x) BF_CM_DN_26 x
#define BF_CM_PASS_DN_27(x) BF_CM_DN_27 x
#define BF_CM_PASS_DN_28(x) BF_CM_DN_28 x
#define BF_CM_PASS_DN_29(x) BF_CM_DN_29 x
#define BF_CM_PASS_DN_30(x) BF_CM_DN_30 x
#define BF_CM_PASS_DN_31(x) BF_CM_DN_31 x

#define BF_CM_ERROR_NO_MORE_MACHINE_STATES()

#endif

