#ifndef THREADS_SYNCH_H
#define THREADS_SYNCH_H

#include <list.h>
#include <stdbool.h>

// A counting semaphore
struct semaphore {

  // Current value
  unsigned value;

  // List of waiting threads
  struct list waiters;

};

void sema_init(struct semaphore *, unsigned value);
void sema_down(struct semaphore *);
bool sema_try_down(struct semaphore *);
void sema_up(struct semaphore *);
void sema_self_test(void);

// Lock
struct lock {

  // Thread holding lock (for debugging)
  struct thread *holder;

  // Binary semaphore controlling access
  struct semaphore semaphore;

  // List element
  struct list_elem elem;

};

void lock_init(struct lock *);
void lock_acquire(struct lock *);
bool lock_try_acquire(struct lock *);
void lock_release(struct lock *);
bool lock_held_by_current_thread(const struct lock *);
void donation(struct lock *);

// Condition variable
struct condition {

  // List of waiting threads
  struct list waiters;

};

void cond_init(struct condition *);
void cond_wait(struct condition *, struct lock *);
void cond_signal(struct condition *, struct lock *);
void cond_broadcast(struct condition *, struct lock *);

/* Optimization barrier.

   The compiler will not reorder operations across an
   optimization barrier.  See "Optimization Barriers" in the
   reference guide for more information.*/
#define barrier() asm volatile ("" : : : "memory")

#endif /* threads/synch.h */
