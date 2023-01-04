#ifndef _KLIBC_ARCHSTAT_H
#define _KLIBC_ARCHSTAT_H

#include <sys/types.h>

struct stat {
	unsigned int		st_dev;
	unsigned int		st_pad0[3]; /* Reserved for st_dev expansion */

	unsigned long		st_ino;

	mode_t			st_mode;
	__u32			st_nlink;

	uid_t			st_uid;
	gid_t			st_gid;

	unsigned int		st_rdev;
	unsigned int		st_pad1[3]; /* Reserved for st_rdev expansion */

	off_t			st_size;

	unsigned int		st_atime;
	unsigned int		st_atimensec;

	unsigned int		st_mtime;
	unsigned int		st_mtimensec;

	unsigned int		st_ctime;
	unsigned int		st_ctimensec;

	unsigned int		st_blksize;
	unsigned int		st_pad2;

	unsigned long		st_blocks;
};

#endif
