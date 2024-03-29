/*
 * include/arch/loongarch64/machine/asm.h
 */

#ifndef _MACHINE_ASM_H
#define _MACHINE_ASM_H

/*
 * ENTRY - declare entry point
 */
#define ENTRY(symbol)                           \
	.globl  symbol;                         \
	.align  2;                              \
	.type   symbol, @function;              \
symbol:

/*
 * END - mark end of function
 */
#define END(function)                           \
	.size   function, . - function


#endif				/* _MACHINE_ASM_H */
