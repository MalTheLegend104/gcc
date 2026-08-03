#ifndef GCC_WALLOS_H
#define GCC_WALLOS_H

#define TARGET_WALLOS 1

#undef TARGET_OS_CPP_BUILTINS
/* Additional predefined macros. */
#define TARGET_OS_CPP_BUILTINS()      \
  do {                                \
    builtin_define ("__unix__");      \
    builtin_define ("__wallos__");      \
    builtin_assert ("system=unix");   \
    builtin_assert ("system=wallos");   \
    builtin_assert ("system=posix");   \
  } while(0);


/* Where startup files (crt0, crti, etc.) are found */
#undef STARTFILE_PREFIX_SPEC
#define STARTFILE_PREFIX_SPEC "/lib/"

/* Default dynamic linker */
#define STANDARD_STARTFILE_PREFIX_1 "/lib/"
#define STANDARD_STARTFILE_PREFIX_2 "/usr/lib/"

#endif /* GCC_WALLOS_H */