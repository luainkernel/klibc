//===-- aeabi_uldivmod.S - EABI uldivmod implementation -------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// struct { uint64_t quot, uint64_t rem}
//        __aeabi_uldivmod(uint64_t numerator, uint64_t denominator) {
//   uint64_t rem, quot;
//   quot = __udivmoddi4(numerator, denominator, &rem);
//   return {quot, rem};
// }

.syntax unified
.p2align 2

.globl __aeabi_uldivmod
.type __aeabi_uldivmod, %function

__aeabi_uldivmod:
        push    {r6, lr}
        sub	sp, sp, #16
        add	r6, sp, #8
        str	r6, [sp]
        bl	__udivmoddi4
        ldr	r2, [sp, #8]
        ldr	r3, [sp, #12]
        add	sp, sp, #16
        pop     {r6, pc}

.size __aeabi_uldivmod, .-__aeabi_uldivmod

.section .note.GNU-stack,"",%progbits

