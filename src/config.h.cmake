/*
    CMake autogenerated config.h file. Do not edit!
*/

/* Package details */
#define LIGHTTPD_VERSION_ID ${LIGHTTPD_VERSION_ID}
#define PACKAGE_NAME "${PACKAGE_NAME}"
#define PACKAGE_VERSION "${PACKAGE_VERSION}"
#define LIBRARY_DIR "${LIGHTTPD_LIBRARY_DIR}"

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

/* System */
#cmakedefine  HAVE_DLFCN_H
#cmakedefine  HAVE_GETOPT_H
#cmakedefine  HAVE_INTTYPES_H
#cmakedefine  HAVE_LINUX_RANDOM_H
#cmakedefine  HAVE_MALLOC_H
#cmakedefine  HAVE_POLL_H
#cmakedefine  HAVE_PORT_H
#cmakedefine  HAVE_PRIV_H
#cmakedefine  HAVE_PWD_H
#cmakedefine  HAVE_STDINT_H
#cmakedefine  HAVE_STDLIB_H
#cmakedefine  HAVE_STRINGS_H
#cmakedefine  HAVE_SYSLOG_H
#cmakedefine  HAVE_SYS_DEVPOLL_H
#cmakedefine  HAVE_SYS_EPOLL_H
#cmakedefine  HAVE_SYS_EVENT_H
#cmakedefine  HAVE_SYS_FILIO_H
#cmakedefine  HAVE_SYS_LOADAVG_H
#cmakedefine  HAVE_SYS_MMAN_H
#cmakedefine  HAVE_SYS_POLL_H
#cmakedefine  HAVE_SYS_PRCTL_H
#cmakedefine  HAVE_SYS_PROCCTL_H
#cmakedefine  HAVE_SYS_RESOURCE_H
#cmakedefine  HAVE_SYS_SENDFILE_H
#cmakedefine  HAVE_SYS_SELECT_H
#cmakedefine  HAVE_SYS_TYPES_H
#cmakedefine  HAVE_SYS_UIO_H
#cmakedefine  HAVE_SYS_UN_H
#cmakedefine  HAVE_SYS_WAIT_H
#cmakedefine  HAVE_SYS_TIME_H
#cmakedefine  HAVE_UNISTD_H

#cmakedefine HAVE_IPV6
#cmakedefine HAVE_STRUCT_TM_GMTOFF
#cmakedefine HAVE_WEAK_SYMBOLS

/* XATTR */
#cmakedefine HAVE_ATTR_ATTRIBUTES_H
#cmakedefine HAVE_SYS_XATTR_H
#cmakedefine HAVE_XATTR
#cmakedefine HAVE_SYS_EXTATTR_H
#cmakedefine HAVE_EXTATTR

/* xxHash */
#cmakedefine  HAVE_XXHASH_H

/* DBI */
#cmakedefine  HAVE_DBI

/* mySQL */
#cmakedefine  HAVE_MYSQL

/* PostreSQL */
#cmakedefine  HAVE_PGSQL

/* GnuTLS */
#cmakedefine  HAVE_GNUTLS_CRYPTO_H

/* mbedTLS */
#cmakedefine  HAVE_MBEDCRYPTO

/* Nettle */
#cmakedefine  HAVE_NETTLE_NETTLE_TYPES_H

/* NSS */
#cmakedefine  HAVE_NSS_NSS_H
#cmakedefine  HAVE_NSS3_NSS_H

/* OpenSSL */
#cmakedefine  HAVE_OPENSSL_SSL_H
#cmakedefine  HAVE_LIBSSL

/* wolfSSL */
#cmakedefine  HAVE_WOLFSSL_SSL_H

/* Brotli */
#cmakedefine  HAVE_BROTLI
#cmakedefine  HAVE_BROTLI_ENCODE_H

/* BZip */
#cmakedefine  HAVE_BZLIB_H
#cmakedefine  HAVE_LIBBZ2

/* ZStd */
#cmakedefine  HAVE_ZSTD
#cmakedefine  HAVE_ZSTD_H

/* FAM */
#cmakedefine  HAVE_FAM_H
#cmakedefine  HAVE_FAMNOEXISTS

/* Kerberos5 */
#cmakedefine  HAVE_KRB5

/* LDAP */
#cmakedefine  HAVE_LDAP_H
#cmakedefine  HAVE_LIBLDAP
#cmakedefine  HAVE_LBER_H
#cmakedefine  HAVE_LIBLBER

/* PAM */
#cmakedefine  HAVE_PAM

/* XML */
#cmakedefine  HAVE_LIBXML_H
#cmakedefine  HAVE_LIBXML2

/* PCRE */
#cmakedefine  HAVE_PCRE
#cmakedefine  HAVE_PCRE_H
#cmakedefine  HAVE_PCRE2_H

/* sqlite3 */
#cmakedefine  HAVE_SQLITE3_H

/* UUID */
#cmakedefine  HAVE_UUID_UUID_H
#cmakedefine  HAVE_LIBUUID

/* ZLIB */
#cmakedefine  HAVE_ZLIB_H
#cmakedefine  HAVE_LIBZ

/* lua */
#cmakedefine  HAVE_LUA_H

/* inotify */
#cmakedefine  HAVE_INOTIFY_INIT
#cmakedefine  HAVE_SYS_INOTIFY_H

/* Types */
#cmakedefine  HAVE_SOCKLEN_T
#cmakedefine  SIZEOF_LONG ${SIZEOF_LONG}
#cmakedefine  SIZEOF_OFF_T ${SIZEOF_OFF_T}

/* Functions */
#cmakedefine  HAVE_ARC4RANDOM_BUF
#cmakedefine  HAVE_CHROOT
#cmakedefine  HAVE_CLOCK_GETTIME
#cmakedefine  HAVE_ELFTC_COPYFILE
#cmakedefine  HAVE_EPOLL_CTL
#cmakedefine  HAVE_FORK
#cmakedefine  HAVE_GETENTROPY
#cmakedefine  HAVE_GETLOADAVG
#cmakedefine  HAVE_GETRANDOM
#cmakedefine  HAVE_GETRLIMIT
#cmakedefine  HAVE_GETUID
#cmakedefine  HAVE_GMTIME_R
#cmakedefine  HAVE_INET_ATON
#cmakedefine  HAVE_INET_PTON
#cmakedefine  HAVE_JRAND48
#cmakedefine  HAVE_KQUEUE
#cmakedefine  HAVE_LOCALTIME_R
#cmakedefine  HAVE_LSTAT
#cmakedefine  HAVE_MADVISE
#cmakedefine  HAVE_MALLOC_TRIM
#cmakedefine  HAVE_MALLOPT
#cmakedefine  HAVE_MEMCPY
#cmakedefine  HAVE_MEMPCPY
#cmakedefine  HAVE_MEMSET
#cmakedefine  HAVE_MKOSTEMP
#cmakedefine  HAVE_MMAP
#cmakedefine  HAVE_PIPE2
#cmakedefine  HAVE_POLL
#cmakedefine  HAVE_PORT_CREATE
#cmakedefine  HAVE_PREAD
#cmakedefine  HAVE_PREADV
#cmakedefine  HAVE_PWRITE
#cmakedefine  HAVE_PWRITEV
#cmakedefine  HAVE_SELECT
#cmakedefine  HAVE_SENDFILE
#cmakedefine  HAVE_SEND_FILE
#cmakedefine  HAVE_SENDFILE64
#cmakedefine  HAVE_SENDFILEV
#cmakedefine  HAVE_SETPFLAGS
#cmakedefine  HAVE_SIGACTION
#cmakedefine  HAVE_SIGNAL
#cmakedefine  HAVE_SIGTIMEDWAIT
#cmakedefine  HAVE_SPLICE
#cmakedefine  HAVE_SRANDOM
#cmakedefine  HAVE_STRERROR_R
#cmakedefine  HAVE_TIMEGM
#cmakedefine  HAVE_WRITEV
#cmakedefine  HAVE_ISSETUGID
#cmakedefine  HAVE_MEMSET_S
#cmakedefine  HAVE_EXPLICIT_BZERO
#cmakedefine  HAVE_EXPLICIT_MEMSET
#cmakedefine  HAVE_COPY_FILE_RANGE

/* libcrypt */
#cmakedefine  HAVE_CRYPT_H
#cmakedefine  HAVE_CRYPT
#cmakedefine  HAVE_CRYPT_R

/* libev */
#cmakedefine HAVE_LIBEV

/* libunwind */
#cmakedefine HAVE_LIBUNWIND

#cmakedefine LIGHTTPD_STATIC
