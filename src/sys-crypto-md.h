/* sys-crypto-md.h - message digest (MD) wrapper
 *
 * message digest (MD) algorithms are not necessarily cryptographically secure
 * (often provided by crypto libraries, hence this file named sys-crypto-md.h)
 *
 * Copyright(c) 2020 Glenn Strauss gstrauss()gluelogic.com  All rights reserved
 * License: BSD 3-clause (same as lighttpd)
 */
#ifndef LI_SYS_CRYPTO_MD_H
#define LI_SYS_CRYPTO_MD_H
#include "first.h"

#include "sys-crypto.h" /* USE_LIB_CRYPTO */
#ifdef USE_LIB_CRYPTO

#if defined(USE_NETTLE_CRYPTO)

#include <nettle/md4.h>
#include <nettle/md5.h>
#include <nettle/sha.h>

#define USE_LIB_CRYPTO_MD4
typedef struct md4_ctx MD4_CTX;
#define MD4_Init(ctx) \
        (nettle_md4_init(ctx), 1)
#define MD4_Final(digest, ctx) \
        (nettle_md4_digest((ctx),MD4_DIGEST_SIZE,(digest)), 1)
static inline int
MD4_Update(MD4_CTX *ctx, const void *data, size_t length)
{
    nettle_md4_update(ctx, length, data);
    return 1;
}

#define USE_LIB_CRYPTO_MD5
typedef struct md5_ctx MD5_CTX;
#define MD5_Init(ctx) \
        (nettle_md5_init(ctx), 1)
#define MD5_Final(digest, ctx) \
        (nettle_md5_digest((ctx),MD5_DIGEST_SIZE,(digest)), 1)
static inline int
MD5_Update(MD5_CTX *ctx, const void *data, size_t length)
{
    nettle_md5_update(ctx, length, data);
    return 1;
}

#define USE_LIB_CRYPTO_SHA1
typedef struct sha1_ctx SHA_CTX;
#define SHA1_Init(ctx) \
        (nettle_sha1_init(ctx), 1)
#define SHA1_Final(digest, ctx) \
        (nettle_sha1_digest((ctx),SHA1_DIGEST_SIZE,(digest)), 1)
static inline int
SHA1_Update(SHA_CTX *ctx, const void *data, size_t length)
{
    nettle_sha1_update(ctx, length, data);
    return 1;
}

#define USE_LIB_CRYPTO_SHA256
typedef struct sha256_ctx SHA256_CTX;
#define SHA256_Init(ctx) \
        (nettle_sha256_init(ctx), 1)
#define SHA256_Final(digest, ctx) \
        (nettle_sha256_digest((ctx),SHA256_DIGEST_SIZE,(digest)), 1)
static inline int
SHA256_Update(SHA256_CTX *ctx, const void *data, size_t length)
{
    nettle_sha256_update(ctx, length, data);
    return 1;
}

#define USE_LIB_CRYPTO_SHA512_256
#ifndef SHA512_256_DIGEST_LENGTH
#define SHA512_256_DIGEST_LENGTH 32
#endif
typedef struct sha512_256_ctx SHA512_CTX;    /*(yes, SHA512_CTX)*/
#define SHA512_256_Init(ctx) \
        (nettle_sha512_256_init(ctx), 1)
#define SHA512_256_Final(digest, ctx) \
        (nettle_sha512_256_digest((ctx),SHA256_DIGEST_SIZE,(digest)), 1)
static inline int
SHA512_256_Update(SHA512_CTX *ctx, const void *data, size_t length)
{
    nettle_sha512_update(ctx, length, data); /*(yes, nettle_sha512_update())*/
    return 1;
}

#elif defined(USE_MBEDTLS_CRYPTO)

#ifdef MBEDTLS_MD4_C
#define USE_LIB_CRYPTO_MD4
#include <mbedtls/md4.h>
typedef struct mbedtls_md4_context MD4_CTX;
#define MD4_Init(ctx) \
        (mbedtls_md4_init(ctx), 0 == mbedtls_md4_starts_ret(ctx))
static inline int
MD4_Final(unsigned char *digest, MD4_CTX *ctx)
{
    int rc = mbedtls_md4_finish_ret(ctx, digest);
    mbedtls_md4_free(ctx);
    return (0 == rc);
}
static inline int
MD4_Update(MD4_CTX *ctx, const void *data, size_t length)
{
    return (0 == mbedtls_md4_update_ret(ctx, data, length));
}
#endif

#ifdef MBEDTLS_MD5_C
#define USE_LIB_CRYPTO_MD5
#include <mbedtls/md5.h>
typedef struct mbedtls_md5_context MD5_CTX;
#define MD5_Init(ctx) \
        (mbedtls_md5_init(ctx), 0 == mbedtls_md5_starts_ret(ctx))
static inline int
MD5_Final(unsigned char *digest, MD5_CTX *ctx)
{
    int rc = mbedtls_md5_finish_ret(ctx, digest);
    mbedtls_md5_free(ctx);
    return (0 == rc);
}
static inline int
MD5_Update(MD5_CTX *ctx, const void *data, size_t length)
{
    return (0 == mbedtls_md5_update_ret(ctx, data, length));
}
#endif

#ifdef MBEDTLS_SHA1_C
#define USE_LIB_CRYPTO_SHA1
#include <mbedtls/sha1.h>
typedef struct mbedtls_sha1_context SHA_CTX;
#define SHA1_Init(ctx) \
        (mbedtls_sha1_init(ctx), 0 == mbedtls_sha1_starts_ret(ctx))
static inline int
SHA1_Final(unsigned char *digest, SHA_CTX *ctx)
{
    int rc = mbedtls_sha1_finish_ret(ctx, digest);
    mbedtls_sha1_free(ctx);
    return (0 == rc);
}
static inline int
SHA1_Update(SHA_CTX *ctx, const void *data, size_t length)
{
    return (0 == mbedtls_sha1_update_ret(ctx, data, length));
}
#endif

#ifdef MBEDTLS_SHA256_C
#define USE_LIB_CRYPTO_SHA256
#include <mbedtls/sha256.h>
typedef struct mbedtls_sha256_context SHA256_CTX;
#define SHA256_Init(ctx) \
        (mbedtls_sha256_init(ctx), 0 == mbedtls_sha256_starts_ret((ctx),0))
static inline int
SHA256_Final(unsigned char *digest, SHA256_CTX *ctx)
{
    int rc = mbedtls_sha256_finish_ret(ctx, digest);
    mbedtls_sha256_free(ctx);
    return (0 == rc);
}
static inline int
SHA256_Update(SHA256_CTX *ctx, const void *data, size_t length)
{
    return (0 == mbedtls_sha256_update_ret(ctx, data, length));
}
#endif

#elif defined(USE_WOLFSSL_CRYPTO) && !defined(USE_OPENSSL_CRYPTO)

/* WolfSSL compatibility API for OpenSSL unnecessarily bounces through an extra
 * layer of indirection.  However, to avoid conflicting typedefs when includers
 * also include headers from the WolfSSL compatibility API for OpenSSL, we
 * include those headers here, as well, and use the compatibility API typedefs.
 * (undef of OPENSSL_EXTRA and NO_OLD_WC_NAMES not sufficient, and not friendly
 *  to do in a header when others might rely on them) */

#ifndef NO_MD4
#include <wolfssl/wolfcrypt/md4.h>
#include <wolfssl/openssl/md4.h>
#undef MD4_Init
#undef MD4_Final
#undef MD4_Update
#define USE_LIB_CRYPTO_MD4
/*typedef Md4 MD4_CTX;*/
static inline int
MD4_Init(MD4_CTX *ctx)
{
    wc_InitMd4((Md4 *)ctx);
    return 1;
}
static inline int
MD4_Final(unsigned char *digest, MD4_CTX *ctx)
{
    wc_Md4Final((Md4 *)ctx, digest);
    return 1;
}
static inline int
MD4_Update(MD4_CTX *ctx, const void *data, size_t length)
{
    wc_Md4Update((Md4 *)ctx, data, length);
    return 1;
}
#endif

#ifndef NO_MD5
#include <wolfssl/wolfcrypt/md5.h>
#include <wolfssl/openssl/md5.h>
#undef MD5_Init
#undef MD5_Final
#undef MD5_Update
#define USE_LIB_CRYPTO_MD5
/*typedef wc_Md5 MD5_CTX;*/
static inline int
MD5_Init(MD5_CTX *ctx)
{
    return (0 == wc_InitMd5((wc_Md5 *)ctx));
}
static inline int
MD5_Final(unsigned char *digest, MD5_CTX *ctx)
{
    return (0 == wc_Md5Final((wc_Md5 *)ctx, digest));
}
static inline int
MD5_Update(MD5_CTX *ctx, const void *data, size_t length)
{
    wc_Md5Update((wc_Md5 *)ctx, data, length);
    return 1;
}
#endif

#ifndef NO_SHA
#include <wolfssl/wolfcrypt/sha.h>
#include <wolfssl/openssl/sha.h>
#undef SHA1_Init
#undef SHA1_Final
#undef SHA1_Update
#define USE_LIB_CRYPTO_SHA1
/*typedef wc_Sha SHA_CTX;*/
static inline int
SHA1_Init(SHA_CTX *ctx)
{
    return (0 == wc_InitSha((wc_Sha *)ctx));
}
static inline int
SHA1_Final(unsigned char *digest, SHA_CTX *ctx)
{
    return (0 == wc_ShaFinal((wc_Sha *)ctx, digest));
}
static inline int
SHA1_Update(SHA_CTX *ctx, const void *data, size_t length)
{
    wc_ShaUpdate((wc_Sha *)ctx, data, length);
    return 1;
}
#endif

#ifndef NO_SHA256
#include <wolfssl/wolfcrypt/sha256.h>
#include <wolfssl/openssl/sha.h>
#undef SHA256_Init
#undef SHA256_Final
#undef SHA256_Update
#define USE_LIB_CRYPTO_SHA256
/*typedef wc_Sha256 SHA256_CTX;*/
static inline int
SHA256_Init(SHA256_CTX *ctx)
{
    return (0 == wc_InitSha256((wc_Sha256 *)ctx));
}
static inline int
SHA256_Final(unsigned char *digest, SHA256_CTX *ctx)
{
    return (0 == wc_Sha256Final((wc_Sha256 *)ctx, digest));
}
static inline int
SHA256_Update(SHA256_CTX *ctx, const void *data, size_t length)
{
    wc_Sha256Update((wc_Sha256 *)ctx, data, length);
    return 1;
}
#endif

#elif defined(USE_OPENSSL_CRYPTO)

#include <openssl/md4.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#ifndef OPENSSL_NO_MD4
#define USE_LIB_CRYPTO_MD4
#endif
#ifndef OPENSSL_NO_MD5
#define USE_LIB_CRYPTO_MD5
#endif
#define USE_LIB_CRYPTO_SHA1
#define USE_LIB_CRYPTO_SHA256
#ifdef SHA512_256_DIGEST_LENGTH
#define USE_LIB_CRYPTO_SHA512_256
#endif

#include <openssl/opensslv.h>
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
#include <openssl/evp.h>

#ifdef USE_LIB_CRYPTO_MD4
#define MD4_CTX EVP_MD4_CTX
#define MD4_Init EVP_MD4_Init
#define MD4_Final EVP_MD4_Final
#define MD4_Update EVP_MD4_Update
typedef EVP_MD_CTX * MD4_CTX;
static inline int
EVP_MD4_Init(EVP_MD4_CTX *ctx)
{
    return ((*ctx = EVP_MD_CTX_new()) != NULL
            && 1 == EVP_DigestInit_ex(*ctx, EVP_md4(), NULL));
}
static inline int
EVP_MD4_Final(unsigned char *digest, EVP_MD4_CTX *ctx)
{
    /* MD4_DIGEST_LENGTH; EVP_MD_size(EVP_md4()) */
    int rc = EVP_DigestFinal_ex(*ctx, digest, NULL);
    EVP_MD_CTX_free(*ctx);
    return (1 == rc);
}
static inline int
EVP_MD4_Update(EVP_MD4_CTX *ctx, const void *data, size_t length)
{
    return (1 == EVP_DigestUpdate(*ctx, data, length));
}
#endif

#ifdef USE_LIB_CRYPTO_MD5
#define MD5_CTX EVP_MD5_CTX
#define MD5_Init EVP_MD5_Init
#define MD5_Final EVP_MD5_Final
#define MD5_Update EVP_MD5_Update
typedef EVP_MD_CTX * EVP_MD5_CTX;
static inline int
EVP_MD5_Init(EVP_MD5_CTX *ctx)
{
    return ((*ctx = EVP_MD_CTX_new()) != NULL
            && 1 == EVP_DigestInit_ex(*ctx, EVP_md5(), NULL));
}
static inline int
EVP_MD5_Final(unsigned char *digest, EVP_MD5_CTX *ctx)
{
    /* MD5_DIGEST_LENGTH; EVP_MD_size(EVP_md5()) */
    int rc = EVP_DigestFinal_ex(*ctx, digest, NULL);
    EVP_MD_CTX_free(*ctx);
    return (1 == rc);
}
static inline int
EVP_MD5_Update(EVP_MD5_CTX *ctx, const void *data, size_t length)
{
    return (1 == EVP_DigestUpdate(*ctx, data, length));
}
#endif

#ifdef USE_LIB_CRYPTO_SHA1
#define SHA_CTX EVP_SHA1_CTX
#define SHA1_Init EVP_SHA1_Init
#define SHA1_Final EVP_SHA1_Final
#define SHA1_Update EVP_SHA1_Update
typedef EVP_MD_CTX * EVP_SHA1_CTX;
static inline int
EVP_SHA1_Init(EVP_SHA1_CTX *ctx)
{
    return ((*ctx = EVP_MD_CTX_new()) != NULL
            && 1 == EVP_DigestInit_ex(*ctx, EVP_sha1(), NULL));
}
static inline int
EVP_SHA1_Final(unsigned char *digest, EVP_SHA1_CTX *ctx)
{
    /* SHA_DIGEST_LENGTH; EVP_MD_size(EVP_sha1()) */
    int rc = EVP_DigestFinal_ex(*ctx, digest, NULL);
    EVP_MD_CTX_free(*ctx);
    return (1 == rc);
}
static inline int
EVP_SHA1_Update(EVP_SHA1_CTX *ctx, const void *data, size_t length)
{
    return (1 == EVP_DigestUpdate(*ctx, data, length));
}
#endif

#ifdef USE_LIB_CRYPTO_SHA256
#define SHA256_CTX EVP_SHA256_CTX
#define SHA256_Init EVP_SHA256_Init
#define SHA256_Final EVP_SHA256_Final
#define SHA256_Update EVP_SHA256_Update
typedef EVP_MD_CTX * EVP_SHA256_CTX;
static inline int
EVP_SHA256_Init(EVP_SHA256_CTX *ctx)
{
    return ((*ctx = EVP_MD_CTX_new()) != NULL
            && 1 == EVP_DigestInit_ex(*ctx, EVP_sha256(), NULL));
}
static inline int
EVP_SHA256_Final(unsigned char *digest, EVP_SHA256_CTX *ctx)
{
    /* SHA256_DIGEST_LENGTH; EVP_MD_size(EVP_sha256()) */
    int rc = EVP_DigestFinal_ex(*ctx, digest, NULL);
    EVP_MD_CTX_free(*ctx);
    return (1 == rc);
}
static inline int
EVP_SHA256_Update(EVP_SHA256_CTX *ctx, const void *data, size_t length)
{
    return (1 == EVP_DigestUpdate(*ctx, data, length));
}
#endif

#ifdef USE_LIB_CRYPTO_SHA512_256
#define SHA512_256_CTX EVP_SHA512_256_CTX
#define SHA512_256_Init EVP_SHA512_256_Init
#define SHA512_256_Final EVP_SHA512_256_Final
#define SHA512_256_Update EVP_SHA512_256_Update
typedef EVP_MD_CTX * EVP_SHA512_256_CTX;
static inline int
EVP_SHA512_256_Init(EVP_SHA512_256_CTX *ctx)
{
    return ((*ctx = EVP_MD_CTX_new()) != NULL
            && 1 == EVP_DigestInit_ex(*ctx, EVP_sha512_256(), NULL));
}
static inline int
EVP_SHA512_256_Final(unsigned char *digest, EVP_SHA512_256_CTX *ctx)
{
    /* SHA256_DIGEST_LENGTH; EVP_MD_size(EVP_sha512_256()) */
    int rc = EVP_DigestFinal_ex(*ctx, digest, NULL);
    EVP_MD_CTX_free(*ctx);
    return (1 == rc);
}
static inline int
EVP_SHA512_256_Update(EVP_SHA512_256_CTX *ctx, const void *data, size_t length)
{
    return (1 == EVP_DigestUpdate(*ctx, data, length));
}
#endif

#endif /* OPENSSL_VERSION_NUMBER >= 0x30000000L */

#elif defined(USE_GNUTLS_CRYPTO)

#include <gnutls/crypto.h>
#include "buffer.h"     /* SEGFAULT() */

#define USE_LIB_CRYPTO_MD5
typedef gnutls_hash_hd_t MD5_CTX;
static inline int
MD5_Init(MD5_CTX *ctx)
{
    if (gnutls_hash_init(ctx, GNUTLS_DIG_MD5) < 0)
        SEGFAULT();
    return 1;
}
static inline int
MD5_Final(unsigned char *digest, MD5_CTX *ctx)
{
    gnutls_hash_deinit(*ctx, digest);
    return 1;
}
static inline int
MD5_Update(MD5_CTX *ctx, const void *data, size_t length)
{
    gnutls_hash(*ctx, data, length);
    return 1;
}

#define USE_LIB_CRYPTO_SHA1
typedef gnutls_hash_hd_t SHA_CTX;
static inline int
SHA1_Init(SHA_CTX *ctx)
{
    if (gnutls_hash_init(ctx, GNUTLS_DIG_SHA1) < 0)
        SEGFAULT();
    return 1;
}
static inline int
SHA1_Final(unsigned char *digest, SHA_CTX *ctx)
{
    gnutls_hash_deinit(*ctx, digest);
    return 1;
}
static inline int
SHA1_Update(SHA_CTX *ctx, const void *data, size_t length)
{
    gnutls_hash(*ctx, data, length);
    return 1;
}

#define USE_LIB_CRYPTO_SHA256
typedef gnutls_hash_hd_t SHA256_CTX;
static inline int
SHA256_Init(SHA256_CTX *ctx)
{
    if (gnutls_hash_init(ctx, GNUTLS_DIG_SHA256) < 0)
        SEGFAULT();
    return 1;
}
static inline int
SHA256_Final(unsigned char *digest, SHA256_CTX *ctx)
{
    gnutls_hash_deinit(*ctx, digest);
    return 1;
}
static inline int
SHA256_Update(SHA256_CTX *ctx, const void *data, size_t length)
{
    gnutls_hash(*ctx, data, length);
    return 1;
}

#endif

#endif /* USE_LIB_CRYPTO */


#ifdef USE_LIB_CRYPTO_MD5
#ifndef MD5_DIGEST_LENGTH
#define MD5_DIGEST_LENGTH 16
#endif
#include "algo_md5.h" /*(for legacy li_MD5_*() name mangling)*/
#else
#include "algo_md5.h"
#endif


#ifdef USE_LIB_CRYPTO_SHA1
#ifndef SHA_DIGEST_LENGTH
#define SHA_DIGEST_LENGTH 20
#endif
#else
#include "algo_sha1.h"
#endif


#endif /* LI_SYS_CRYPTO_MD_H */
