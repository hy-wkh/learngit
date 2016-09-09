SYNOPSIS
       #include <string.h>

       int strcmp(const char *s1, const char *s2);

       int strncmp(const char *s1, const char *s2, size_t n);

DESCRIPTION
       The  strcmp()  function compares the two strings s1 and s2.  It returns an integer less than,equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or begreater than s2.

       The  strncmp() function is similar, except it compares the only first (at most) n bytes of s1
       and s2.







