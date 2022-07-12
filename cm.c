
#define BF_CM(...) CM_SCAN(CM_EAT CM_LPAREN CM_0(__VA_ARGS__))
#define CM_SCAN(...) __VA_ARGS__
#define CM_EAT(...)
#define CM_LPAREN (

#define CM_0(P,i,tl,t,tr,is,f,...)  CM_P1 (CM_P1 (CM_P1 (CM_P1 (BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_1(P,i,tl,t,tr,is,f,...)  CM_P2 (CM_P2 (CM_P2 (CM_P2 (BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_2(P,i,tl,t,tr,is,f,...)  CM_P3 (CM_P3 (CM_P3 (CM_P3 (BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_3(P,i,tl,t,tr,is,f,...)  CM_P4 (CM_P4 (CM_P4 (CM_P4 (BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_4(P,i,tl,t,tr,is,f,...)  CM_P5 (CM_P5 (CM_P5 (CM_P5 (BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_5(P,i,tl,t,tr,is,f,...)  CM_P6 (CM_P6 (CM_P6 (CM_P6 (BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_6(P,i,tl,t,tr,is,f,...)  CM_P7 (CM_P7 (CM_P7 (CM_P7 (BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_7(P,i,tl,t,tr,is,f,...)  CM_P8 (CM_P8 (CM_P8 (CM_P8 (BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_8(P,i,tl,t,tr,is,f,...)  CM_P9 (CM_P9 (CM_P9 (CM_P9 (BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_9(P,i,tl,t,tr,is,f,...)  CM_P10(CM_P10(CM_P10(CM_P10(BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_10(P,i,tl,t,tr,is,f,...) CM_P11(CM_P11(CM_P11(CM_P11(BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_11(P,i,tl,t,tr,is,f,...) CM_P12(CM_P12(CM_P12(CM_P12(BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_12(P,i,tl,t,tr,is,f,...) CM_P13(CM_P13(CM_P13(CM_P13(BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_13(P,i,tl,t,tr,is,f,...) CM_P14(CM_P14(CM_P14(CM_P14(BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_14(P,i,tl,t,tr,is,f,...) CM_P15(CM_P15(CM_P15(CM_P15(BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_15(P,i,tl,t,tr,is,f,...) CM_P16(CM_P16(CM_P16(CM_P16(BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)))))
#define CM_16(P,i,tl,t,tr,is,f,...) BF__##f(,P##i,P##tl,P##t,P##tr,P##is,P##__VA_ARGS__)

#define CM_P0(x)  CM_0 x
#define CM_P1(x)  CM_1 x
#define CM_P2(x)  CM_2 x
#define CM_P3(x)  CM_3 x
#define CM_P4(x)  CM_4 x
#define CM_P5(x)  CM_5 x
#define CM_P6(x)  CM_6 x
#define CM_P7(x)  CM_7 x
#define CM_P8(x)  CM_8 x
#define CM_P9(x)  CM_9 x
#define CM_P10(x) CM_10 x
#define CM_P11(x) CM_11 x
#define CM_P12(x) CM_12 x
#define CM_P13(x) CM_13 x
#define CM_P14(x) CM_14 x
#define CM_P15(x) CM_15 x
#define CM_P16(x) CM_16 x

