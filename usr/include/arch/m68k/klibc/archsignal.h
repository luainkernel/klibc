/*
 * arch/m68k/include/klibc/archsignal.h
 *
 * Architecture-specific signal definitions
 *
 */

#ifndef _KLIBC_ARCHSIGNAL_H
#define _KLIBC_ARCHSIGNAL_H

#define _NSIG		64
#define _NSIG_BPW	32
#define _NSIG_WORDS	(_NSIG / _NSIG_BPW)

typedef struct {
	unsigned long sig[_NSIG_WORDS];
} sigset_t;

#define SIGHUP		1
#define SIGINT		2
#define SIGQUIT		3
#define SIGILL		4
#define SIGTRAP		5
#define SIGABRT		6
#define SIGIOT		6
#define SIGBUS		7
#define SIGFPE		8
#define SIGKILL		9
#define SIGUSR1		10
#define SIGSEGV		11
#define SIGUSR2		12
#define SIGPIPE		13
#define SIGALRM		14
#define SIGTERM		15
#define SIGSTKFLT	16
#define SIGCHLD		17
#define SIGCONT		18
#define SIGSTOP		19
#define SIGTSTP		20
#define SIGTTIN		21
#define SIGTTOU		22
#define SIGURG		23
#define SIGXCPU		24
#define SIGXFSZ		25
#define SIGVTALRM	26
#define SIGPROF		27
#define SIGWINCH	28
#define SIGIO		29
#define SIGPOLL		SIGIO
#define SIGPWR		30
#define SIGSYS		31
#define SIGUNUSED	31

#define SIGRTMIN	32
#define SIGRTMAX	_NSIG

#include <asm-generic/signal-defs.h>

struct siginfo;

struct sigaction {
	union {
		__sighandler_t _sa_handler;
		void (*_sa_sigaction)(int, struct siginfo *, void *);
	} _u;
	unsigned int	sa_flags;
	__sigrestore_t	sa_restorer;
	sigset_t	sa_mask;        /* mask last for extensibility */
};

#define sa_handler	_u._sa_handler
#define sa_sigaction	_u._sa_sigaction

#endif
