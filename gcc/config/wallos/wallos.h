#ifndef GCC_WALLOS_H
#define GCC_WALLOS_H

#define TARGET_WALLOS 1

/* Additional predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()        \
  do {                                  \
    builtin_define("__wallos__");       \
    builtin_define("__unix__");         \
    builtin_define("__ELF__");          \
    builtin_assert("system=wallos");    \
    builtin_assert("system=unix");      \
    builtin_assert("system=posix");     \
  } while (0)

/* Where startup files are searched for. */
#undef STARTFILE_PREFIX_SPEC
#define STARTFILE_PREFIX_SPEC "/lib/"

#undef STANDARD_STARTFILE_PREFIX_1
#define STANDARD_STARTFILE_PREFIX_1 "/lib/"

#undef STANDARD_STARTFILE_PREFIX_2
#define STANDARD_STARTFILE_PREFIX_2 "/usr/lib/"

/* Startup objects. */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC \
  "crt1.o%s crti.o%s crtbegin.o%s"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC \
  "crtend.o%s crtn.o%s"

/* Default libraries. */
#undef LIB_SPEC
#define LIB_SPEC "-lc"

/*
 * WallOS currently supports only statically linked ELF executables.
 */
#undef LINK_SPEC
#define LINK_SPEC \
  "%{shared:%eWallOS does not support shared libraries} " \
  "%{pie:%eWallOS does not support PIE executables} " \
  "%{static-pie:%eWallOS does not support static PIE}"

/*
 * Force GCC to add the '.section .note.GNU-stack,"",@progbits' at the end of assembly outputs
 */
#undef TARGET_ASM_FILE_END
#define TARGET_ASM_FILE_END file_end_indicate_exec_stack

#endif /* GCC_WALLOS_H */
