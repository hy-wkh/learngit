#include <signal.h>
#include <time.h>
int timer_create(clockid_t clockid, 
				 struct sigevent *sevp,
				 timer_t *timerid);

 struct sigevent{
    int  sigev_notify; /* Notification method 说明了定时器到期时应采取的行动*/
    int  sigev_signo;  /* Notification signal */
    union sigval sigev_value;  /* Data passed with notification */
    void  (*sigev_notify_function) (union sigval);  /* Function used for thread notification (SIGEV_THREAD) */
    void  *sigev_notify_attributes;  /* Attributes for notification thread (SIGEV_THREAD) */
    pid_t sigev_notify_thread_id;   /* ID of thread to signal (SIGEV_THREA D_ID) */
};

union sigval {          /* Data passed with notification */
    int  sival_int;     /* Integer value */
    void  *sival_ptr;    /* Pointer value */
};
----返回：成功返回０，失败返回-1，并设置errno









