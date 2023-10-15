int down_read_trylock(struct rw_semaphore *sem);

int down_write_trylock(struct rw_semaphore *sem);

Note: Both return 1 if the lock is successfully acquired and 0 if it is currently contended.

this is the opposite of normal semaphore behavior!
