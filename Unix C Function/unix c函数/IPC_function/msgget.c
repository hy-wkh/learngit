#include<sys/msg.h>
int msgget(key_t key,int msgflg);
----该函数返回与参数key相关的消息队列标识符。如果键值为IPC_ORIVATE或者semflg&IPC_CTEAT非０而且没有消息队列或标识符关联key,那么msgget函数就创建这个标识符.

----返回一个对应于消息队列标识符的非负整数，否则返回-1并设置errno

NAME
       msgget - get a System V message queue identifier

SYNOPSIS
       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>

       int msgget(key_t key, int msgflg);

DESCRIPTION
       The  msgget()  system  call  returns the System V message queue identifier
       associated with the value of the key argument.  A  new  message  queue  is
       created if key has the value IPC_PRIVATE or key isn't IPC_PRIVATE, no mes‐
       sage queue with the given key key exists, and IPC_CREAT  is  specified  in
       msgflg.

       If  msgflg  specifies  both  IPC_CREAT  and  IPC_EXCL  and a message queue
       already exists for key, then msgget() fails  with  errno  set  to  EEXIST.
       (This  is  analogous to the effect of the combination O_CREAT | O_EXCL for
       open(2).)

       Upon creation, the least significant bits of the  argument  msgflg  define
       the permissions of the message queue.  These permission bits have the same
       format and semantics as the permissions specified for the mode argument of
       open(2).  (The execute permissions are not used.)
       If  a  new  message  queue  is created, then its associated data structure
       msqid_ds (see msgctl(2)) is initialized as follows:

              msg_perm.cuid and msg_perm.uid are set to the effective user ID  of
              the calling process.

              msg_perm.cgid and msg_perm.gid are set to the effective group ID of
              the calling process.

              The least significant 9 bits of msg_perm.mode are set to the  least
              significant 9 bits of msgflg.

              msg_qnum, msg_lspid, msg_lrpid, msg_stime, and msg_rtime are set to
              0.

              msg_ctime is set to the current time.

              msg_qbytes is set to the system limit MSGMNB.

       If the message queue already exists the permissions are  verified,  and  a
       check is made to see if it is marked for destruction.

RETURN VALUE
       If  successful,  the  return value will be the message queue identifier (a
       nonnegative integer), otherwise -1 with errno indicating the error.


