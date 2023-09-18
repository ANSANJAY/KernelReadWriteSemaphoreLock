Header File: <linux/rwsem.h>

Data Structure: struct rw_semaphore

Implementation : kernel/locking/rwsem.c

Initialization:
================

	Static: 	DECLARE_RWSEM(name)

	Dynamic:	init_rwsem(struct rw_semaphore *sem)

All reader-writer semaphores are mutexes—that is, their usage count is one

they enforce mutual exclusion only for writers, not readers.



