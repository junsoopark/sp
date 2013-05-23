AC_INIT(sp, 0.0.1, junsoo81.park@lge.com)

AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX

AC_CHECK_LIB([libc], [memcpy])
AC_CHECK_LIB([glib], [g_init])

#AC_CHECK_HEADERS([~~.h ~~.h])
#AC_HEADER_DIRENT

#AC_TYPE_SIZE_T
#AC_STRUCT_TM

#AC_CHECK_FUNC([strchr strdup strstr])
#AC_FUNC_MALLOC


PKG_CHECK_MODULES(GLIB, [glib-2.0 >=  2.2.0])
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GLIB_LIBS)


AC_CONFIG_FILES(
Makefile
src/Makefile
hls/Makefile
tests/Makefile
)
AC_OUTPUT

