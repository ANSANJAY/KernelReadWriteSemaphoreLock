
Lock/Unlock:
================

Readers

	void down_read(struct rw_semaphore *sem);
		critical section
		....
	void up_read(struct rw_semaphore *sem);

Writers

	void down_write(struct rw_semaphore *sem);
		critical section
		....
	void up_write(struct rw_semaphore *sem);


Note: down_read/down_write may put the calling process into an uninterruptible sleep
