       #include <unistd.h>

       int gethostname(char *name, size_t len);
       int sethostname(const char *name, size_t len);

DESCRIPTION
       These system calls are used to access or  to  change  the
       hostname of the current processor.

       sethostname() sets the hostname to the value given in the
       character array name.  The  len  argument  specifies  the
       number  of bytes in name.  (Thus, name does not require a
       terminating null byte.)

       gethostname() returns the null-terminated hostname in the
       character  array  name,  which has a length of len bytes.
       If the null-terminated hostname is too large to fit, then
       the  name is truncated, and no error is returned (but see
       NOTES below).  POSIX.1-2001 says that if such  truncation
       occurs,  then it is unspecified whether the returned buf‐
       fer includes a terminating null byte.

RETURN VALUE
       On success, zero is returned.  On error, -1 is  returned,
       and errno is set appropriately.

