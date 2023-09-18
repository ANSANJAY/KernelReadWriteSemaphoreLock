downgrade_write():

Reader-writer semaphores have a unique method which is not present in reader-writer spinlocks

void downgrade_write(struct rw_semaphore *sem);

This function atomically converts an acquired write lock to a read lock.

Where can i use this?
=========================

Used in situation where writer lock is needed for a quick change, followed by longer period of read-only access
