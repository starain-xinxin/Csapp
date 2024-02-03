/* 
 * CS:APP Data Lab 
 * 
 * <starain 2024.1.31>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 *不要包含<stdio.h>头文件，但可以使用printf等函数。
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully. 阅读以下说明：
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
整数编码规则：
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
  将每个函数中的“return”语句替换为一个或更多行实现该函数的C代码。
  你的代码必须符合以下风格:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      // 简要介绍你的实现方法
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  每个"Expr"是一个表达式，只使用以下内容:
  1. 整数常量0到255 (0xFF)，包括在内。你是不允许使用像0xffffffff这样的大常量。
  2. 函数参数和局部变量(没有全局变量)。
  3. 一元整数运算!～
  4. 二进制整数运算& ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.
  有些问题甚至进一步限制了允许的操作符集合。
  每个“Expr”可以由多个操作符组成。
  你不受限于每行一个操作符。

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.
  明确禁止您:
  1. 使用任何控制结构，如if、do、while、for、switch等。
  2. 定义或使用任意宏。
  3. 在此文件中定义任何附加函数。
  4. 调用任意函数。
  5. 使用任何其他操作，如&&、||、-或?:
  6. 使用任何形式的铸造。
  7. 使用除int以外的任何数据类型。这意味着你
  不能使用数组、结构体或联合。

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  您可以假设您的机器:
  1. 使用2s补码，32位整数表示。
  2. 按算术方式执行右移。
  3. 移位时是否有不可预测的行为，如果移位量小于0或大于31。


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES
浮点数编码规则：

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.
对于需要实现浮点运算的问题，编码规则不那么严格。
允许使用循环和有条件的控制。
可以同时使用int型和unsigned型。
您可以使用任意整数和无符号常量。
你可以用任何算术，对整型或无符号数据进行逻辑或比较操作。

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.

明确禁止您:
  1. 定义或使用任意宏。
  2. 在此文件中定义任何附加函数。
  3. 调用任意函数。
  4. 使用任何形式的铸造。
  5. 使用除int或unsigned以外的任何数据类型。这意味着你
  不能使用数组、结构体或联合。
  6. 使用任何浮点数据类型、操作或常量。


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
注:
  1. 使用dlc(数据实验室检查器)编译器(在讲义中描述)来检查你的解决方案的合法性。
  2. 每个函数都有一个最大操作数(整数，逻辑，或比较)，您可以在您的实现中使用函数的。最大操作符计数由dlc检查。
     注意，赋值('=')不被计算在内;你可以用很多
     这些都是你想要的，没有惩罚。
  3. 使用最好的测试工具来检查函数的正确性。
  4. 使用BDD检查器正式验证您的功能
  5. 中给出了每个函数的最大操作数每个函数的头注释。如果有任何矛盾在写入和此文件中的最大操作之间，请考虑这个文件是权威的来源。

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* ops: 10*/
  /*
    全F数的得到：~0
  */
  int result = ~0;
  int a = x & (~y);
  int b = (~x) & (y);
  result = result & ~a;
  result = result & ~b; 
  return ~result;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  int result = 8;
  result  = result << 28;
  return result;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /* 0xff...ffff的边界需要注意！！！ */
  int a = x + 1;
  a = a ^ x;
  a = a+1;
  a = !a;
  a = a^(!(x + 1));
  return a;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /* 千万注意 << 这个运算符号的优先级小于 + */
  int a  = 170;
  a = a + (a<<8) + (a<<16) + (a<<24);
  x = x & a;
  return !(x ^ a);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x)+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int a = 0x30;
  int x2 = x & (~0x7);
  int result = !(x2 ^ a);
  // 两个特例
  int result2 = !(x ^ 0x38);
  int result3 = !(x ^ 0x39);
  // 或连接
  return result|result2|result3;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /* 这题主要用了算术移位的效果 */
  int a = !(x^0);
  a = a << 31;
  a = ~(a >> 31);
  return (y & a) + (z & (~a));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
// 考虑临界情况 x = 0x1000...0000
    int sign_x, sign_y, a, x_, b, flag1, result, num;
    a = 1 << 31;
    // sign_x = !(x&a);  sign_y = !(y&a);
    sign_x = (x>>31);  sign_y = (y>>31);
    // 若x，y同符号；
    flag1 = !(x ^ a);   // x是否为Tmin， 若flag=00...0001,则 b = 1
    x_ = (~x) + 1;
    b = x_ + y;   // b = y-x;
    b = b & a;
    b = !(!(b ^ a));  // b表示在x不为Tmin时的表现
    b = b | flag1;
    num = sign_x + (~sign_y+1);  // num = 0时，xy同号，FF...FFFF(-1)应当返回0，00...0001应当返回1
    // result = ((!(sign_x^sign_y))&b) | (!(num+1))&(num);
    result = ((!(sign_x^sign_y))&b) | !(~num);
    return result;
  
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int a, flag;
  a = x ^ (~x + 1);
  a = a >> 31;
  a = a + 1;
  flag = (x >> 31) + 1;
  return flag & a;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    int count, a, x_, num, tf, neg1, offset, neg_sign;
    
    neg1 = ~0;    // -1常量
    neg_sign = !((x&(1<<31))^(1<<31));    // 是否为负数？
    x_ = ((neg_sign+neg1)&x) + (((!neg_sign)+neg1)&(((~x)+1)+neg1));  //负数转为正数来做；
    a = ~(1 << 31);   // 0111...1111
    x_ = x_ & a;   // 把符号位去掉
    count = 1;    // 符号位占一位
    
    // 判断前后16位
    num = ((0xff<<8) + 0xff)<<16;   // num = 1111 1111 1111 1111 0000 0000 0000 0000
    tf = !(num&x_); //若在前面，tf为1111...1111;若在后面：tf为0000...0000
    count = count + ((tf+neg1) & 16);
    // 判断前后8位
    offset = (tf+neg1)&16;
    num = 0xff << (8+offset);
    tf = !(num&x_);
    count = count + ((tf+neg1) & 8);
    // 判断前4位
    offset = ((tf+neg1)&8) + offset;
    num = 0xf << (4+offset);
    tf = !(num&x_);
    count = count + ((tf+neg1) & 4);
    // 判断前后2位
    offset =((tf+neg1)&4) + offset;
    num = 0x3<< (2+offset);
    tf = !(num&x_);
    count = count + ((tf+neg1) & 2);
    // 判断前后1位
    offset = ((tf+neg1)&2) + offset;
    num = 0x1<< (1+offset);
    tf = !(num&x_);
    count = count + ((tf+neg1) & 1);
    // 最后一次判断
    offset = ((tf+neg1)&1) + offset;
    num = 0x1<< (offset);
    tf = !(num&x_);
    count = count + ((tf+neg1) & 1);
    
    return count;
}

//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned exp, frac, s, mask1, mask2, mask3, result;
    mask1 = 1 << 31;
    mask2 = 0xff << 23;
    mask3 = ~(mask1 + mask2);
    s = uf & mask1;
    exp = uf & mask2;
    frac = uf & mask3;
    // NaN与无穷的情况
    if (exp == mask2)
      return uf;
    // 规格与非规格
    else{
      // 非规格区： 符号位不动，剩下的<<1
      if (!exp){
        result = s + ((exp << 1)&~mask1) + (frac << 1);
        return result;
      }
      // 规格区： 符号位不动， exp位+1
      else{
          result = s + (exp+(1<<23)) + frac;
          return result;
      }
      
    }
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    unsigned s, exp, frac, mask1, mask2, mask3, F;  int result, E;
    mask1 = 1<<31;  mask2 = 0xff<<23;   mask3 = ~(mask1+mask2);
    s = !!(uf & mask1);   exp = (uf & mask2) >> 23;   frac = uf & mask3;    E = exp - 127;
    // 无穷 NaN
    if(exp == 0xff || E > 31)  return mask1;
    // 由于0.xxx都将被舍去, 整数溢出也会舍去
    if(E<0)  return 0;
    F = frac + (1<<23);
    // 判断E与23的关系
    // E>=23指数幂够高，左移或不移
    if(E>=23)
        F = F << (E-23);
    else
        F = F >> (23-E);
    if(s)	result = F* ~0;
    else    result = F;
    return result;
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
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	int result;
	// 非规格区
	if(x>=-149 && x<=-127){
		result = (1 << 22) >> (-x - 127);
	}
	else if(x<=127 && x >=-126){
		result = (x+127) << 23;
	}
	else if(x<-149)		return 0;
	else	return (0xff<<23);
    return result;
}
