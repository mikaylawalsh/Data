#if 0
INTEGER CODING RULES:

	Complete the body of each function with one
	or more lines of C code that implements the function. Your code
	must consist of a sequence of variable declarations, followed by
	a sequence of assignment statements, followed by a return statement.

	The general style is as follows:

	int funct(...) {
		/* brief description of how your implementation works */
		int var1 = expr1;
		...
		int varM = exprM;

		varJ = exprJ;
		...
		varN = exprN;

		return exprR;
	}

	Each "expr" is an expression using ONLY the following:
	1. Integer constants 0 through 255 (0xFF), inclusive. You are
	   not allowed to use big constants such as 0xFFFFFFFF.
	2. Function arguments and local variables (no global variables).
	3. Unary integer operations ! ~
	4. Binary integer operations & ^ | + << >>

	Some of the problems restrict the set of allowed operators even further.
	Each "expr" may consist of multiple operators. You are not restricted to
	one operator per line.

	You are expressly forbidden to:
	1. Use any control constructs such as if, do, while, for, switch, etc.
	2. Define or use any macros.
	3. Define any additional functions in this file.
	4. Call any functions.
	5. Use any other operations, such as &&, ||, ==, -, or ?:
	6. Use any form of casting.
	7. Use any data type other than int.  This implies that you
	   cannot use arrays, structs, or unions.


	You may assume that your machine:
	1. Uses 2s complement, 32-bit representations of integers.
	2. Performs right shifts arithmetically.
	3. Has unpredictable behavior when shifting an integer by more
	   than the word size.

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
#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 9.0.0.  Version 9.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, fourth edition, plus
   Amd. 1  and Amd. 2 and 273 characters from forthcoming  10646, fifth edition.
   (Amd. 2 was published 2016-05-01,
   see https://www.iso.org/obp/ui/#iso:std:iso-iec:10646:ed-4:v1:amd:2:v1:en) */
/* We do not support C11 <threads.h>.  */

/*
 * bit_and - Compute x&y using only ~ and |
 *   Examples: bit_and(6, 5) = 4
 *             bit_and(3, 12) = 0
 *   Legal ops: ~ |
 *   Illegal ops: ! & ^ + << >>
 *   Max ops: 8
 *   Points: 2
 */
int bit_and(int x, int y) { 
	/* In order to get the result of taking the "bitwise and" of signed inputs x and y, is by first 
	taking the complement of both x and y. After doing this, we take the "bitwise or" of those values 
	which will give us the opposite of the value we are looking for. In order to find the final result, 
	we take the complement of that value. We do this because by taking the or of the complements, we are 
	manipulating the bits that are now 0. Taking the final complement returns it to the orignal state. */

    int result = ~(~x | ~y);

	return result; }

/*
 * negate - Return -x
 *   Examples: negate(1) = -1
 *             negate(0) = 0
 *             negate(-33) = 33
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Points: 4
 */
int negate(int x) { 
	/* After looking at a couple of examples of positive and negative values, I noticed that the negative
	of an int in two's complement representation is just the complement of it plus 1. This is because
	when we are considering signed intergers, there is always one more negative value than positive so we
	need to adjust for this by adding 1. */

	int result = ~x + 1;

	return result; }

/*
 * is_equal - Return 1 if x == y, else return 0
 *   Examples: is_equal(5, 5) = 1
 *             is_equal(4, 5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Points: 4
 */
int is_equal(int x, int y) { 
	/* In order to determin if x is equal to y, we can use the exclusive or operator. Exclusive or becomes 
	the almost obvious choice since if if x and y are equal, it will return 0 and otherwise it will return some
	other number besides 0. However, we want to return 1 is x == y and 0 otherwise. This almost looks like
	the opposite of what we currently have, so in order to adjust for this, we can just take the logical not 
	of x ^ y. */ 

	return !(x ^ y);}

/*
 * div_pwr_2 - Compute x/(2^n), for 0 <= n <= 30
 *   Round toward zero
 *   Examples: div_pwr_2(15, 1) = 7
 *             div_pwr_2(-33, 4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Points: 4
 */
int div_pwr_2(int x, int n) { 
	/* For this problem, there are two cases we need to consider: (1) when x is positive and (2) when x
	is negative. To calculate the answer when x is positive, all we need to do is right shift x by n 
	bits. This is give us x / 2^n rounded towards 0. When x is negative, x >> n will still give x / 2^n 
	however, it will round the answer away from 0 which is not what we want. In order to take the floor of
	x / 2^n when x is negative, we need to do (x + (1<<n) - 1) >> n. However, since we can't use subtraction, 
	we need to negate 1 and add that. In order to determine which value we return, I used the same logic 
	that was used in conditional: y is either 0 or -1 based on the sign of x and from there either pos_answer 
	or neg_answer are returned. */ 

	int pos_answer = x >> n;
	
	int neg = ~(1) + 1;
	int neg_answer = (x + (1<<n)+neg) >> n;

	int y = ~(x >> 31); 
	int result = (y & pos_answer) | (~y & neg_answer);

	return result; }

/*
 * conditional - Compute the result of x ? y : z
 *   Examples: conditional(2, 4, 5) = 4
 *             conditional(0, 1, 2) = 2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Points: 6
 */
int conditional(int x, int y, int z) { 
	/* The goal of this function is to return y if x != 0 and return z is x = 0. My plan 
	was to use the idea that using bitwise and with 0, always gives 0 and using bitwise and 
	with -1, always gives the other input. This is essentially what we want, if x = -1 or 0,
	we can take the complement and and it with the other input. So the first step was finding 
	a way to get x to be -1 or 0. If x = 0, taking the logical not of it will give 1 and if 
	x != 0, not will give 0. This is close to what we want, except we want -1 and 0. So all we 
	need to do is take 1 away, however, since we can't use subtraction, we have to add the negation 
	of 1. Using the same logic as negate, we get neg_1 = ~1 + 1. Therefore, our new x value we 
	want to use for evaluation is !x + neg_1. Now, we have x = -1 if the original input was not 0 and 
	x = 1 if the input was 0. Then, using the logic from the beginning, we now have either x & y will be 
	y if x is -1 or ~x & z will be z if x = 0. The last step is using bitwise or to combine these 
	two since one of them will always produce 0, the other will be the output. */

	int neg_1 = ~(1) + 1;
	x = !x + neg_1;
	int r;
	r = x & y;
	r = r | (~x & z);

	return r; }

/*
 * add_ok - Return 0 if x+y will overflow, resulting in an incorrect computation.
 *			Return 1 otherwise
 *   Examples: add_ok(0x80000000, 0x80000000) = 0
 *             add_ok(0x80000000, 0x70000000) = 1
 * 			   add_ok(0xFFFFFFFF, 0x00000001) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Points: 6
 */
int add_ok(int x, int y) { 
	/* Since both inputs we are considering are signed, there is really just two cases we must consider: 
	(1) adding two positive ints results in a negative and (2) adding two negative ints that give a positive
	result. In order to determine if this is happening, we need to look at the 32nd bit in the number. To
	find this, we can right shift the int by 31. This will turn every bit in the number into the original 
	leftmost/most significant bit. If there is no overflow/underflow, the result of added the most signifcant 
	bits of both numbers should be the same as adding the two numbers and then looking at the most signicatnt 
	bit. So there are three values we are looking at: x's most signifcant bit (x_sig_bit), y's most signifcant 
	bit (y_sig_bit), and the most significan bit of x + y (x_plus_y). We want our function to return 1 when 
	x_sig_bit and y_sig_bit are the same, but x_sig_bit and x_plus_y is not the same -- and return 0 in any other
	case. In order to check if the values are not the same we can use exclusive or. After making a truth table for 
	this, I discovered that we can get the desired results by taking the complment of x_sig_bit ^ y_sig_bit and 
	taking the bitwise and of this with x_sig_bit ^ x_plus_y. Lastly, we take the logical not of this whole thing. 
	*/

	int x_sig_bit = x >> 31;
	int y_sig_bit = y >> 31;
	int x_plus_y = (x+y) >> 31;

	int result = !(~(x_sig_bit ^ y_sig_bit) & (x_sig_bit ^ x_plus_y));

	return result; }

/*
 * leastBitPos - Return a mask that marks the position of the
 *   least significant 1 bit. If x == 0, return 0
 *   Examples: leastBitPos(96) = 0x20
 * 			   leastBitPos(7) = 0x01
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Points: 8
 */
int leastBitPos(int x) { 
	/* Finding the position of the least significant 1 bit in x is the same as finding the position of the least 
	significant 0 bit in the complement of x. If we add 1 to this number, the "carry" will be 0 when we reach the
	first 0 in the number since 1 + 0 does not require a carry. Once we reach this place value where the carry 
	goes to 0, the rest of the values to the left will just copy down from the orignal value. Therefore, we can use 
	bitwise and with the original value to deteremine the place where the value changes. This will give us the mask 
	of the position of the least significan 1 bit. 

	Ex. x = 0011	~x = 1100	~x+1 = 1101		(~x+1) & x = 0001	Meaning the least signifcant 1 is in the first place. 
	*/ 
	
	int result = ((~x) + 1) & x;
	
	return result; }

/*
 * abs_val - Return the absolute value of x
 *   Examples: abs_val(-1) = 1
 *             abs_val(33) = 33
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Points: 10
 */
int abs_val(int x) {
	/* When we take the absolute value of an int, we are considering the sign of the number. We know that
	the sign of the int is held in the leftmost bit. In order to look at this, we can shift the input by 31  
	bits right in order to have a 32 bit int filled with all values that are the most significant value of the
	input. This new int (called shift in our function) is either going to be all 1's (-1) or all 0's (0). If the 
	input is positive, shift will be 0, so x + shift will just give back x. If the input is negative, shift will
	be -1, so x + shift will give x - 1. When we take the exclusive or of any number with -1, we get the complement 
	of that value, but if we take the exclusive of of any number with 0, we get itself. The complement of a negative 
	number is one less than that as the postive value (as we determined in negate), so taking the exclusive or of 
	of x + shift with shift, we get the absolute value. If the input is positive, we just get the input back. */ 

	int shift = x >> 31;
	int result = ((x + shift) ^ shift);

	return result; }

/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0
 * 			   bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 * 	 Illegal ops: !
 *   Max ops: 12
 *   Points: 10
 */
int bang(int x) { 
	/* For this problem, we want to return 0 if x != 0 and return 1 if x = 0. 
	In order to solve this, I first had to think about what the difference is 
	between 0 and all other numbers. Although there are many answers, the one 
	that is really helpful here is the fact that the negation of 0 is 0. For 
	any other number, the most significant bit of the negation will be the opposite 
	of that of the original. This is the fact we are going to exploit in order 
	to complete this. In order to do this, we take the bitwise or of the input and 
	its negation and then look at the most significant bit. If it is 0, we want to 
	return 1 and if it is 1 we want to return 0. So, next we can shift the or of the 
	input and its negation by 31 bits in order to have an int filled with all 0s or 1s. 
	Lastly, we need to just add 1 in order to return 1 if it is 0 and 0 if it is -1. */

	int result = ((~x + 1) | x ) >> 31;

	return result + 1; }
