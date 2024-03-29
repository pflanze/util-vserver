dnl $Id$

dnl Copyright (C) 2003,2004 Enrico Scholz <enrico.scholz@informatik.tu-chemnitz.de>
dnl
dnl This program is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 2, or (at your option)
dnl any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program; if not, write to the Free Software
dnl Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
dnl
dnl
dnl As a special exception to the GNU General Public License, if you
dnl distribute this file as part of a program that contains a configuration
dnl script generated by Autoconf, you may include it under the same
dnl distribution terms that you use for the rest of that program.
dnl

AC_PREREQ(2.57)
AC_INIT(util-vserver, 0.30.215, vserver@list.linux-vserver.org)
AC_CONFIG_SRCDIR([src/capchroot.c])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.9 gnits dist-bzip2 subdir-objects])
AM_MAINTAINER_MODE

AC_CANONICAL_BUILD
AC_CANONICAL_HOST

AC_SUBST(GPG_KEY, "0xFFD316AC53ACA43A!")

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AM_PROG_CC_C_O
PKG_PROG_PKG_CONFIG
ENSC_CXXCOMPILER
ENSC_C99COMPILER
AM_PROG_MKDIR_P

ENSC_SET_SEARCHPATH([$PATH:/sbin:/usr/sbin:/usr/local/sbin])
ENSC_PATHPROG_STANDARD_TOOLS

ENSC_PATHPROG(IP,        ip,,      [Usually, this tool is shipped in the 'iproute' or 'iproute2' package of your distribution])
ENSC_PATHPROG(IPTABLES,  iptables)
ENSC_PATHPROG(MODPROBE,  modprobe)
ENSC_PATHPROG(NAMEIF,    nameif)
ENSC_PATHPROG(NOHUP,     nohup)
ENSC_PATHPROG(RMMOD,     rmmod)
ENSC_PATHPROG(VCONFIG,   vconfig,, [See http://www.candelatech.com/~greear/vlan.html; usually this tool is shipped in the 'vconfig' or 'vlan' package of your distribution])
ENSC_PATHPROG(WGET,      wget)
ENSC_PATHPROG(IONICE,    ionice,  [],  [This is usually shipped in the 'util-linux(-ng)' or 'schedutils' package])
ENSC_PATHPROG(FILE,      file,    [file])
ENSC_PATHPROG(GZIP,      gzip,    [gzip])
ENSC_PATHPROG(BZIP2,     bzip2,   [bzip2])
ENSC_PATHPROG(CPIO,      cpio,    [cpio])
ENSC_PATHPROG(RESTORE,   restore, [restore])
ENSC_PATHPROG(RSYNC,     rsync,   [rsync])
ENSC_PATHPROG(STRACE,    strace,  [strace])
ENSC_PATHPROG(FSCK,      fsck)
ENSC_PATHPROG(FIND,      find)

ENSC_PATHPROG(DOXYGEN,   doxygen,  [:])
ENSC_PATHPROG(XSLTP,     xsltp,    [:])
ENSC_PATHPROG(XSLTPROC,  xsltproc, [:])


AM_CONDITIONAL(HAVE_XSLTP,    test "$XSLTP"    != ':')
AM_CONDITIONAL(HAVE_XSLTPROC, test "$XSLTPROC" != ':')

if test x"$prefix" = x/; then
	prefix=
fi

ENSC_CHECK_CC_FLAG([-std=c99 -Wall -pedantic -W])
ENSC_CHECK_CXX_FLAG([-ansi   -Wall -pedantic -W -fmessage-length=0])

AC_MSG_CHECKING([whether to enable extra optimizations])
AC_ARG_ENABLE([extra-optimizations],
	      [AC_HELP_STRING([--disable-extra-optimizations],
			      [disable certain extra optimizations (default: no)])],
	      [case "$enableval" in
		  (yes) use_extra_optimizations=1;;
		  (no)  use_extra_optimizations=;;
                  (*)   AC_MSG_ERROR(['$enableval' is not a valid value for '--disable-extra-optimizations']);;
               esac],
              [use_extra_optimizations=1])

if test x"$use_extra_optimizations" = x; then
	AC_MSG_RESULT(no)
else
	AC_MSG_RESULT(yes)
	ENSC_CHECK_CC_FLAG([-funit-at-a-time])
	ENSC_CHECK_CXX_FLAG([-funit-at-a-time])
fi

AC_MSG_CHECKING([whether to enable debug-code in library])
AC_ARG_ENABLE([lib-debug],
	      [AC_HELP_STRING([--enable-lib-debug],
                              [enable additional debug code in library (default: no)])],
              [case "$enableval" in
		  (yes) use_lib_debug=1;;
                  (no)  use_lib_debug=;;
                  (*)   AC_MSG_ERROR(['$enableval' is not a valid value for '--enable-lib-debug']);;
               esac],
              [ use_lib_debug= ])

if test x"$use_lib_debug" = x; then
	AC_SUBST(LIB_DEBUG_CPPFLAGS, [-DNDEBUG])
	AC_MSG_RESULT(no)
else
	AC_SUBST(LIB_DEBUG_CPPFLAGS, [])
	AC_MSG_RESULT(yes)
fi

AC_MSG_CHECKING([whether to enable expensive tests])
AC_ARG_ENABLE([expensive-tests],
	      [AC_HELP_STRING([--enable-expensive-tests],
			      [disable tests which might be expensive on some systems (default: no)])],
	      [case "$enableval" in
		 (yes|no)  use_expensive_tests=$enableval;;
		 (*)       AC_MSG_ERROR(['$enableval' is not a valid value for '--enable-expensive-tests']);;
	       esac],
              [ use_expensive_tests=no ])
AC_MSG_RESULT($use_expensive_tests)

AC_SUBST(ENSC_USE_EXPENSIVE_TESTS, "$use_expensive_tests")


ENSC_CHECK_PERSONALITY_FLAGS

AC_ARG_VAR(CC, [The C compiler])

ENSC_INITRDDIR(initrddir)
ENSC_RELEASE(RELEASE_CPPFLAGS)

# HACK: This needs to be before ENSC_DIETLIBC_NEED_COMPAT, or the alternative
# syscalls will never be enabled for glibc.
ENSC_SYSCALLNR(vserver,273,[lib/syscall-fallback.h])
ENSC_SYSCALL

dnl ###########################
dnl
dnl {some dietlibc related tests
dnl

case $host_cpu in
	(i*86|athlon)	min_diet_ver=0.25;;
	(ia64|hppa*)	min_diet_ver=0.29;;
	(sparc*)	min_diet_ver=0.30;;
	(x86_64)	min_diet_ver=0.27;;
	(*)		min_diet_ver=0.28;;
esac

ENSC_ENABLE_DIETLIBC(USE_DIETLIBC, [$min_diet_ver])

if test x"$ensc_have_dietlibc" = xno; then
	AC_MSG_WARN([***                                                         ***])
	AC_MSG_WARN([*** it is strongly recommended to link util-vserver against ***])
	AC_MSG_WARN([*** dietlibc;  glibc's NSS functions are very unreliable in ***])
	AC_MSG_WARN([*** chroot() environments,  so you have to  expect problems ***])
	AC_MSG_WARN([*** there.                                                  ***])
	AC_MSG_WARN([***                                                         ***])
	AM_CONDITIONAL(USE_DIETLIBC_COMPAT, false)
else
	# HACK: libtool does not have cmdline options to build only
	# dynamic libraries; this can be done with the
	# '--disable-static' ./configure option only.  As our static
	# libraries will be build with dietlibc, we have to do set
	# this option which is evaluated by 'AC_PROG_LIBTOOL'
 	# below.  Therefore, this macro must not be called earlier.
	enable_static=no

	ENSC_DIETLIBC_NEED_COMPAT(USE_DIETLIBC_COMPAT)
fi

AM_CONDITIONAL(ENSC_USE_DIETLIBC, test x"$ensc_have_dietlibc" = xyes)
AM_CONDITIONAL(ENSC_USE_GLIBC,    true)

# HACK: see comments at 'enable_static' above
AC_PROG_LIBTOOL
dnl
dnl dietlibc stuff ends here}
dnl
dnl ##########################


ENSC_UV_VROOTDIR(vserverdir)
ENSC_CHANGELOG


dnl ##########################
dnl
dnl {Check whether to use external kernel headers
dnl
AC_MSG_CHECKING([whether to use internal kernel headers])
AC_ARG_ENABLE([internal-headers],
              [AC_HELP_STRING([--disable-internal-headers],
                              [use vserver specific headers from the kernel instead of the shipped versions (default: no)])],
              [case "$enableval" in
		  (yes|no) ;;
		  (*)      AC_MSG_ERROR(['$i' is not a supported value for '--disable-internal-headers']);;
	       esac],
              [enable_internal_headers=yes])

AM_CONDITIONAL(ENSC_ENABLE_INTERNAL_HEADERS, [test x"$enable_internal_headers" = xyes])
AC_MSG_RESULT([$enable_internal_headers])
dnl
dnl the check regarding external kernel headers ends here}
dnl
dnl ##########################

dnl ##########################
dnl
dnl {Check for the APIs to be used
dnl
AH_TEMPLATE(VC_ENABLE_API_COMPAT,   [Enable support for compatibility syscall API])
AH_TEMPLATE(VC_ENABLE_API_LEGACY,   [Enable support for old, /proc parsing API])
AH_TEMPLATE(VC_ENABLE_API_V11,      [Enable support for API of vserver 1.1.x])
AH_TEMPLATE(VC_ENABLE_API_FSCOMPAT, [Enable support for filesystem compatibility API])
AH_TEMPLATE(VC_ENABLE_API_V13OBS,   [Enable support for some obsoleted API of vserver 1.3.x])
AH_TEMPLATE(VC_ENABLE_API_V13,      [Enable support for API of vserver 1.3.x])
AH_TEMPLATE(VC_ENABLE_API_NET,      [Enable support for network context API])
AH_TEMPLATE(VC_ENABLE_API_V21,      [Enable support for API of vserver 2.1.x])
AH_TEMPLATE(VC_ENABLE_API_V22,      [Enable support for API of vserver 2.2.x])
AH_TEMPLATE(VC_ENABLE_API_V23,      [Enable support for API of vserver 2.3.x])
AH_TEMPLATE(VC_ENABLE_API_NETV2,    [Enable support for new networking API])
AH_TEMPLATE(VC_ENABLE_API_OLDPROC,  [Enable API for a backward compatible /proc parsing])
AH_TEMPLATE(VC_ENABLE_API_OLDUTS,   [Enable API for a backward compatible uts handling])

AC_MSG_CHECKING([for supported APIs])
AC_ARG_ENABLE([apis],
	      [AC_HELP_STRING([--enable-apis=APIS],
			      [enable support for the given apis; possible values are: legacy,compat,v11,fscompat,v13obs,v13,net,v21,v22,v23,netv2 ALL,NOLEGACY (default: v13,net,v21,v22,v23,netv2)])],
              [],
	      [enable_apis=v13,net,v21,v22,v23,netv2])

test x"$enable_apis" != xALL      || enable_apis='legacy,compat,v11,fscompat,v13obs,v13,net,v21,v22,v23,netv2'
test x"$enable_apis" != xNOLEGACY || enable_apis='compat,v11,fscompat,v13,net,v21,v22,v23,netv2'
enable_api_oldproc=
enable_api_olduts=

echo $enable_apis | sed 's/,/\n/g' | while read i; do
	case "$i" in
		(compat)	AC_DEFINE(VC_ENABLE_API_COMPAT,   1)
				enable_api_oldproc=${enable_api_oldproc:-1}
				enable_api_olduts=${enable_api_olduts:-1}
				;;
		(legacy) 	AC_DEFINE(VC_ENABLE_API_LEGACY,   1)
				enable_api_oldproc=${enable_api_oldproc:-1}
				enable_api_olduts=${enable_api_olduts:-1}
				;;
		(v11)	 	AC_DEFINE(VC_ENABLE_API_V11,      1)
				enable_api_oldproc=${enable_api_oldproc:-1}
				enable_api_olduts=${enable_api_olduts:-1}
				;;
		(fscompat)	AC_DEFINE(VC_ENABLE_API_FSCOMPAT, 1);;
		(v13obs)    	AC_DEFINE(VC_ENABLE_API_V13OBS,   1)
				AC_DEFINE(VC_ENABLE_API_V13,      1);;
		(v13)	 	AC_DEFINE(VC_ENABLE_API_V13,      1);;
		(net)		AC_DEFINE(VC_ENABLE_API_NET,      1);;
		(v21)		AC_DEFINE(VC_ENABLE_API_V21,      1);;
		(v22)		AC_DEFINE(VC_ENABLE_API_V22,      1);;
		(v23)		AC_DEFINE(VC_ENABLE_API_V23,      1);;
		(netv2)		AC_DEFINE(VC_ENABLE_API_NETV2,    1);;
		(oldproc)	enable_api_oldproc=2;;
		(olduts)	enable_api_olduts=2;;
		(*)		AC_MSG_ERROR(['$i' is not a supported API]);;
	esac
done
if test x"$enable_api_oldproc" != x; then
	AC_DEFINE(VC_ENABLE_API_OLDPROC, 1)
	test x"$enable_api_oldproc" != x2 && enable_apis="$enable_apis,oldproc"
fi
if test x"$enable_api_olduts" != x; then
	AC_DEFINE(VC_ENABLE_API_OLDUTS, 1)
	test x"$enable_api_olduts" != x2 && enable_apis="$enable_apis,olduts"
fi
AC_MSG_RESULT([$enable_apis])
dnl
dnl the check for used APIs ends here}
dnl
dnl ##########################


ENSC_CHECK_EXT2FS_HEADER
AC_CHECK_FUNCS([vserver])
AC_CHECK_DECLS(MS_MOVE,,,[#include <linux/fs.h>])
AC_CHECK_TYPES(xid_t,,,[#include <sys/types.h>])
AC_CHECK_TYPES(nid_t,,,[#include <sys/types.h>])
AC_CHECK_TYPES(tag_t,,,[#include <sys/types.h>])

AC_CHECK_HEADERS([sys/capability.h])

dnl vlogin might need -lutil
if test x"$ensc_have_dietlibc" = xno; then
	AC_CHECK_FUNC([openpty],, [AC_CHECK_LIB([util], [openpty],, [AC_MSG_ERROR([
****
**** openpty could not be found
****])])])
fi


dnl ########################
dnl
dnl {crypto stuff
dnl
AC_ARG_WITH(crypto-api,
            AC_HELP_STRING([--with-crypto-api=API],
                           [select crypto api to be used; possible values are `none', `nss', `beecrypt', `auto' (default:auto)]),
	    [case $withval in
		(none|nss|beecrypt|auto)	ensc_crypto_api=$withval;;
		(yes)				ensc_crypto_api=auto;;
		(no)				ensc_crypto_api=none;;
		(*)	AC_MSG_ERROR([invalid crypto-api value, only none,nss,beecrypt,auto are supported]);;
	     esac],[ensc_crypto_api=auto])


dnl Now, check for matching crypto api. When selected 'auto', the
dnl first matching one wins

dnl ########################
dnl
dnl {check for beecrypt
dnl
case $ensc_crypto_api in
(auto|beecrypt)
if test x"$ensc_cv_c99_c99compiler" = xyes; then
	ensc_have_beecrypt=yes

	if test x"$ensc_have_beecrypt" = xyes; then
		AC_CHECK_HEADER([beecrypt/beecrypt.h], [ : ],
				[ ensc_have_beecrypt=no ])
	fi

	if test x"$ensc_have_beecrypt" = xyes; then
		AC_CHECK_LIB(beecrypt, hashFunctionContextInit, [ : ],
			     [ ensc_have_beecrypt=no ])
	fi
else
	ensc_have_beecrypt=no
fi;;
esac

case $ensc_crypto_api in
(auto)		if test x"$ensc_have_beecrypt"  = xyes; then
			AC_MSG_NOTICE([using beecrypt as crypto api])
			ensc_crypto_api=beecrypt
		fi;;
(beecrypt)	if test x"$ensc_have_beecrypt" != xyes; then
			AC_MSG_ERROR([beecrypt crypto api not found])
		fi;;
esac

AM_CONDITIONAL(ENSC_HAVE_BEECRYPT, test x"$ensc_have_beecrypt" = xyes)
AM_CONDITIONAL(ENSC_CAN_BEECRYPT_WITH_DIETLIBC, false)
dnl
dnl beecrypt stuff ends here}
dnl
dnl ########################


dnl ########################
dnl
dnl {check for nss
dnl

case $ensc_crypto_api in
(nss)	PKG_CHECK_MODULES(NSS, nss);;
(auto)	PKG_CHECK_MODULES(NSS, nss, [
		AC_MSG_NOTICE([using NSS as crypto api])
		ensc_crypto_api=nss]);;
esac

dnl
dnl nss stuff ends here}
dnl
dnl ########################

case $ensc_crypto_api in
(beecrypt)
	ENSC_HAVE_CRYPTO=true
	ENSC_CRYPTO_API=ENSC_CRYPTO_API_BEECRYPT
	ENSC_CRYPTO_CFLAGS=
	ENSC_CRYPTO_LIB=-lbeecrypt
	ENSC_CAN_CRYPTO_WITH_DIETLIBC=false
	;;

(nss)
	ENSC_HAVE_CRYPTO=true
	ENSC_CRYPTO_API=ENSC_CRYPTO_API_NSS
	ENSC_CRYPTO_CFLAGS=$NSS_CFLAGS
	ENSC_CRYPTO_LIB=$NSS_LIBS
	ENSC_CAN_CRYPTO_WITH_DIETLIBC=false
	;;

(none|auto)
	ENSC_HAVE_CRYPTO=false
	ENSC_CRYPTO_API=ENSC_CRYPTO_API_NONE
	ENSC_CRYPTO_CFLAGS=
	ENSC_CRYPTO_LIB=
	ENSC_CAN_CRYPTO_WITH_DIETLIBC=false

	AC_MSG_WARN([No crypto api found/select. This will disable the build of 'vhashify'])
	;;

(*)	AC_MSG_ERROR([internal error])
esac

AM_CONDITIONAL(ENSC_HAVE_CRYPTO, $ENSC_HAVE_CRYPTO)
AM_CONDITIONAL(ENSC_CAN_CRYPTO_WITH_DIETLIBC, $ENSC_CAN_CRYPTO_WITH_DIETLIBC)
AC_SUBST(ENSC_CRYPTO_CFLAGS, $ENSC_CRYPTO_CFLAGS)
AC_SUBST(ENSC_CRYPTO_LIB,    $ENSC_CRYPTO_LIB)
AC_DEFINE_UNQUOTED(ENSC_CRYPTO_API, $ENSC_CRYPTO_API, [Used crypto API])

dnl
dnl crypto stuff ends here}
dnl
dnl ########################


dnl Check what distro this is, use Gentoo initscripts if appropriate
AC_MSG_CHECKING([for host initscripts])
AC_ARG_WITH(initscripts, AC_HELP_STRING([--with-initscripts=TYPE], [force host initscripts; valid values are 'gentoo' and 'sysv' (default: guess)]), [
	case "$withval" in
	gentoo)	ensc_with_init=gentoo;;
	sysv)	ensc_with_init=sysv;;
	*)	AC_MSG_ERROR([invalid initscripts value, only gentoo and sysv are supported]);;
	esac
	], [
	if test -e /etc/gentoo-release; then
		ensc_with_init=gentoo
	else
		ensc_with_init=sysv
	fi
	])
AC_MSG_RESULT([$ensc_with_init])
AM_CONDITIONAL(HAVE_GENTOO_INIT, test x"$ensc_with_init" = xgentoo)
AM_CONDITIONAL(HAVE_SYSV_INIT, test x"$ensc_with_init" = xsysv)


dnl ########################
dnl Check for Python

ensc_have_python=yes
AM_PATH_PYTHON([2.4],, [:])
if test "x$PYTHON" = x:; then
	ensc_have_python=no
fi
if test x$ensc_have_python = xyes; then
	PYTHON_CFLAGS=-I`$PYTHON -c 'from distutils.sysconfig import get_python_inc; print(get_python_inc(1))'`
	PYTHON_LDFLAGS=-L`$PYTHON -c 'from distutils.sysconfig import get_python_lib; print(get_python_lib(1))'`
	AC_SUBST(PYTHON_CFLAGS)
	AC_SUBST(PYTHON_LDFLAGS)
else
	ensc_have_python=no
fi
AC_PATH_PROG([CTAGS], [ctags], [no])
if test "x$CTAGS" = xno; then
	ensc_have_python=no
fi
AM_CONDITIONAL([HAVE_PYTHON], [test x$ensc_have_python = xyes])

dnl Python stuff ends here
dnl ########################


dnl ########################
dnl Library versioning

ensc_have_versioning=yes
AC_ARG_ENABLE(versioning, AC_HELP_STRING([--disable-versioning], [Disable library versioning]), [ensc_have_versioning="$enableval"])
AM_CONDITIONAL([HAVE_VERSIONING], [test "x$ensc_have_versioning" = xyes])
if test "x$ensc_have_versioning" = xyes; then
	AC_DEFINE([HAVE_VERSIONING], [1], [Define this to use library versioning])
fi

dnl /Library versioning
dnl ########################


dnl BIG HACK! Do some autodetection here!
AC_DEFINE(UTMP_GID, [22], [The utmp gid-number])

if false; then
	AC_DEFINE(HAVE_GROWING_STACK, [1], [Define to 1 if the stack is on growing addresses])
fi

AC_DEFINE(_FILE_OFFSET_BITS, [64], [Use 64bit interface for filesystem operations])

dnl ########################
dnl
dnl {The final info-page
dnl
ensc_cxx_affected=" (affected: vbuild, vcheck)"
ensc_c99_affected=" (affected: vunify, vcopy, vhashify, vdlimit)"
ensc_diet_msg=" (you have been warned)"
ensc_diet_version_msg=" ($ensc_version_dietlibc)"
ensc_diet_compat_msg=" (using -lcompat)"
test x"$ensc_cv_cxx_cxxcompiler"    = xno || ensc_cxx_affected=
test x"$ensc_cv_c99_c99compiler"    = xno || ensc_c99_affected=
test x"$ensc_have_dietlibc"         = xno || ensc_diet_msg=
test x"$ensc_version_dietlibc"     != x   || ensc_diet_version_msg=
test x"$ensc_have_dietlibc$ensc_cv_c_dietlibc_compat" = xyesyes || ensc_diet_compat_msg=

AH_BOTTOM([#include "compat.h"
])
AC_CONFIG_COMMANDS_PRE([
			FEATURES_TXT="\
Features:
		       CC: $CC, $($CC   --version | sed -e '1p;d')
                      CXX: $CXX, $($CXX --version | sed -e '1p;d')
                 CPPFLAGS: '$CPPFLAGS'
                   CFLAGS: '$CFLAGS'
                 CXXFLAGS: '$CXXFLAGS'
               build/host: $build/$host
             Use dietlibc: $ensc_have_dietlibc$ensc_diet_version_msg$ensc_diet_msg$ensc_diet_compat_msg
       Build C++ programs: $ensc_cv_cxx_cxxcompiler$ensc_cxx_affected
       Build C99 programs: $ensc_cv_c99_c99compiler$ensc_c99_affected
           Available APIs: $enable_apis
            ext2fs Source: $ensc_cv_test_ext2fs_header
    syscall(2) invocation: $with_syscall
      vserver(2) syscall#: $ensc_cv_value_syscall_vserver
               crypto api: $ensc_crypto_api
          python bindings: $ensc_have_python
   use library versioning: $ensc_have_versioning

Paths:
                   prefix: $prefix
        sysconf-Directory: $sysconfdir
            cfg-Directory: $sysconfdir/vservers
         initrd-Directory: $initrddir
       pkgstate-Directory: $localstatedir/run/vservers
          vserver-Rootdir: $vserverdir
"
			echo "$FEATURES_TXT" >FEATURES.txt
			])
dnl
dnl final info-page ends here}
dnl
dnl ########################

AC_CONFIG_FILES([util-vserver.spec Makefile distrib/Makefile lib/apidoc/Doxyfile])
AC_OUTPUT

AC_MSG_NOTICE([

$PACKAGE_STRING

$FEATURES_TXT])
