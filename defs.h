/*
 * defs.h: initial definitions for PuTTY.
 *
 * The rule about this header file is that it can't depend on any
 * other header file in this code base. This is where we define
 * things, as much as we can, that other headers will want to refer
 * to, such as opaque structure types and their associated typedefs,
 * or macros that are used by other headers.
 */

#ifndef PUTTY_DEFS_H
#define PUTTY_DEFS_H

typedef struct conf_tag Conf;
typedef struct backend_tag Backend;
typedef struct terminal_tag Terminal;

typedef struct Filename Filename;
typedef struct FontSpec FontSpec;

typedef struct bufchain_tag bufchain;

typedef struct strbuf strbuf;

struct RSAKey;

#include <stdint.h>
typedef uint32_t uint32;

/* Do a compile-time type-check of 'to_check' (without evaluating it),
 * as a side effect of returning the value 'to_return'. Note that
 * although this macro double-*expands* to_return, it always
 * *evaluates* exactly one copy of it, so it's side-effect safe. */
#define TYPECHECK(to_check, to_return)                  \
    (sizeof(to_check) ? (to_return) : (to_return))

#endif /* PUTTY_DEFS_H */