/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return  ~(~x & ~y) & ~(x & y);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if(x){
          if(y){
              if((x>>31)^(y>>31)){
                  return 0;
              }else{
                  return 1;
              }}
          else{           
            return 0;
          }}
    else{
        if(!y){
            return 1;
        }
        else return 0;
    }
  
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int r;
    int s;
    r = 0;

    s = (v >> 16 > 0) << 4;  
    v = v >> s;
    r = r | s;

    s = (v >> 8 > 0) << 3;   
    v = v >> s;
    r = r | s;

    s = (v >> 4 > 0) << 2; 
    v = v >> s;
    r = r | s;

    s = (v >> 2 > 0) << 1;  
    v = v >> s;
    r = r | s;

    s = v >> 1 > 0;     
    r = r | s;

    return r;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
   int on;
    int om;
    int a;
    int b;
    int mask;
    on = n << 3;                     
    om = m << 3;                     
    a = (x >> on) & 0xFF;            
    b = (x >> om) & 0xFF;            
    mask = ~((0xFF << on) | (0xFF << om));   
    return (x & mask) | (b << on) | (a << om);
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned r=0;
    int i=32;
    while(i){
        r=r<<1;
        r=r|(v&1);
        v=v>>1;
        i--;
    }
    return r;

}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int y;
    int r;
    int s;
    y = ~x;
    r = 0;

    s = (!(y >> 16)) << 4;    
    y = y << s;
    r = r + s;
    s = (!(y >> 24)) << 3;    
    y = y << s;
    r = r + s;
    s = (!(y >> 28)) << 2;    
    y = y << s;
    r = r + s;
    s = (!(y >> 30)) << 1;   
    y = y << s;
    r = r + s;
    r = r + !(y >> 31);      
    r = r + !y;               // x = -1（y = 0）时补 1，答案 32
    return r;

}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned ux, sign, e, m, rest;
    if (!x) return 0;
    ux = x; 
    sign = ux & 0x80000000;
    if (x < 0) ux = ~ux + 1;             
    e = 0;
    while (!(ux >> 31)) { ux <<= 1; e++; }  
    m = (ux & 0x7FFFFFFF) >> 8;             
    rest = ux & 0xFF;                        
    if (rest > 0x80) m = m + 1;             
    else if (rest == 0x80) { if (m & 1) m = m + 1; } 
    if (m >> 23) { m = 0; e = e - 1; }      
    return sign | ((158 - e) << 23) | m;   

}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned exp = (uf >> 23) & 0xFF;
    unsigned sign = uf & 0x80000000u;
    if (exp == 0xFF) return uf;
    if (exp == 0) return sign | (uf << 1);  
    exp = exp + 1;                         
    if (exp == 0xFF) return sign | 0x7F800000;  
    return sign | (exp << 23) | (uf & 0x7FFFFF);
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    int sign = uf2 >> 31;
    int exp  = (uf2 >> 20) & 0x7FF;
    int e, s;
    unsigned hi, mag;
    if (!exp) return 0;                      /* 阶码 0：0 或非规格化 → 下溢 */
    e = exp - 1023;
    if (e < 0) return 0;                     /* |x| < 1 → 下溢 */
    if (e > 30) return -2147483647 - 1;      /* 上溢 → 0x80000000（纯 int 常量，无转换） */
    hi = (uf2 & 0xFFFFF) | 0x100000;         /* 21 位：隐含的 1 + 尾数高 20 位 */
    s = 52 - e;                              /* 53 位尾数整体右移 s 位 */
    if (s >= 32) mag = hi >> (s - 32);       /* 低 32 位全被移掉 */
    else mag = (hi << (32 - s)) | (uf1 >> s);
    if (sign) return -mag;
    return mag;            
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if (x > 127)   return 0x7F800000;          
    if (x < -149)  return 0;                   
    if (x >= -126) return (x + 127) << 23;     
    return 1 << (x + 149);      
}
