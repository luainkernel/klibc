#include <linux/module.h>
#include <linux/types.h>

extern uint64_t __udivmoddi4(uint64_t num, uint64_t den, uint64_t * rem);

typedef struct {
	uint64_t quot;
	uint64_t rem;
} uint64_res_t;

__inline__ uint64_res_t __aeabi_uldivmod(uint64_t numerator, uint64_t denominator) {
	uint64_t rem, quot;
	quot = __udivmoddi4(numerator, denominator, &rem);
	return (uint64_res_t){quot, rem};
}
EXPORT_SYMBOL(__aeabi_uldivmod);

typedef struct {
	int64_t quot;
	int64_t rem;
} int64_res_t;

__inline__ int64_res_t __aeabi_ldivmod(int64_t num, int64_t den) {
    int neg_rem = 0, neg_quot = 0;
    int64_t rem, quot;

    if (num < 0) {
        num = -num;
        neg_rem = 1;
    }
    if (den < 0) {
        den = -den;
        neg_quot = 1;
    }
    neg_quot ^= neg_rem;

    quot = __udivmoddi4(num, den, &rem);

    return (int64_res_t){
        neg_quot ? -quot : quot,
        neg_rem ? -rem : rem
    };
}
EXPORT_SYMBOL(__aeabi_ldivmod);

