//===-- aeabi_ldivmod.S - EABI ldivmod implementation ---------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// struct { int64_t quot, int64_t rem}
//        __aeabi_ldivmod(int64_t numerator, int64_t denominator) {
//   int64_t rem, quot;
//   quot = __divmoddi4(numerator, denominator, &rem);
//   return {quot, rem};
// }

.syntax unified
.p2align 2

.globl __aeabi_ldivmod
.type __aeabi_ldivmod, %function

__aeabi_ldivmod:
        push    {r6, lr}
        sub     sp, sp, #16
        add     r6, sp, #8
        str     r6, [sp]
        bl      __divmoddi4
        ldr     r2, [sp, #8]
        ldr     r3, [sp, #12]
        add     sp, sp, #16
        pop     {r6, pc}

.size __aeabi_ldivmod, .-__aeabi_ldivmod

.section .note.GNU-stack,"",%progbits
