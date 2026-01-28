//===-- divmoddi4.c - Implement __divmoddi4 -------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements __divmoddi4 for the compiler_rt library.
//
//===----------------------------------------------------------------------===//

#include <stdint.h>
#include <limits.h>

// Returns: a / b, *rem = a % b

extern uint64_t __udivmoddi4(uint64_t num, uint64_t den, uint64_t * rem);

int64_t __divmoddi4(int64_t a, int64_t b, int64_t *rem) {
	  const int bits_in_dword_m1 = (int)(sizeof(int64_t) * CHAR_BIT) - 1;
	  int64_t s_a = a >> bits_in_dword_m1;                   // s_a = a < 0 ? -1 : 0
	  int64_t s_b = b >> bits_in_dword_m1;                   // s_b = b < 0 ? -1 : 0
	  a = (uint64_t)(a ^ s_a) - s_a;                          // negate if s_a == -1
	  b = (uint64_t)(b ^ s_b) - s_b;                          // negate if s_b == -1
	  s_b ^= s_a;                                           // sign of quotient
	  uint64_t r;
	  int64_t q = (__udivmoddi4(a, b, &r) ^ s_b) - s_b;      // negate if s_b == -1
	  *rem = (r ^ s_a) - s_a;                               // negate if s_a == -1
	  return q;
}
