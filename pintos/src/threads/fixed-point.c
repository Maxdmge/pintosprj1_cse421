//#include "threads/thread.h"
#include "threads/fixed-point.h"

FixedP convToFixed(int num){
    return num*F;
}

int convToInt(FixedP f){
    return f/F;
}

int roundConvToInt(FixedP f){
    if(f>0){
        return (f +(F*2)/F);

    }else{
        
        return (f - (F*2)/F);
    }
}

// a+b
FixedP fixedAdd(FixedP a, FixedP b){
    return a+b;
}

// a-b;
FixedP fixedSub(FixedP a, FixedP b){
    return a-b;
}

// fixed point plus int, a+b
FixedP fixedAddInt(FixedP a, int b){
    return(a + (b*F));
}

// fixed oint subtrct int, a-b
FixedP fixedSubInt(FixedP a, int b){
    return(a - (b*F));
}

// Fixed point multiplication, a*b
FixedP fixedMull (FixedP a, FixedP b){

//int64_t temp = a * b;
return (int32_t) ((((int64_t) a) * b) / F);
}

// Fixed point division, a/b
FixedP fixedDiv (FixedP a, FixedP b){

//int64_t temp = a * F;
return (int32_t) ((((int64_t) a) * F) / b);
}

// Fixed devided by int, a/b
FixedP fixedDivInt (FixedP a, int b){

return  a/ b;
}

// Fixed mutilplied by int, a*b
FixedP fixedMulInt (FixedP a, int b){
    return a*b;
}
