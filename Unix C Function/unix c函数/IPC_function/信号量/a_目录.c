
Posix IPC函数汇总：
		     消息队列　　	     信号量　　　　   共享内存区
头文件　　   <mqueue.h>       <semaphore.h>       <sys/mman.h>

创建，		  mq_open			sem_open			shm_open
打开，删除    mq_close			sem_close			shm_unlink
			  mq_unlink			sem_unlink
								sem_init
								sem_destroy
								
控制IPC		　　mq_getattr							ftruncate
操作		  mq_setattr							fstat
			  
IPC操作		　　mq_send			sem_wait			mmap
			  mq_receive		sem_trywait			munmap
			  mq_notify			sem_post
			  					sem_getvalue
			  					
System V　IPC函数汇总：
		     消息队列　　	     信号量　　　　   共享内存区
头文件　　   <mqueue.h>       <semaphore.h>       <sys/mman.h>

创建，		  msgget			semget				shmget
打开，删除    
			  
								
控制IPC		　 msgctl			semctl				shmctl			
操作		 
			  
IPC操作		　　msgsnd			semop				shmat
			  msgrcv								shmdt
		
		
		
		
		
		
		
		
