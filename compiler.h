/*
 * compiler.h - compiler specific macros
 *
 * This software is distributed under a BSD-style license. See the
 * file "COPYING" in the toop-level directory of the distribution for details.
 */
#ifndef _GPSD_COMPILER_H_
#define _GPSD_COMPILER_H_

/* Macro for declaring function with printf-like arguments. */
# if __GNUC__ >= 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)
#define PRINTF_FUNC(format_index, arg_index) \
    __attribute__((__format__(__printf__, format_index, arg_index)))
# else
#define PRINTF_FUNC(format_index, arg_indx)
#endif

/* Macro for declaring function arguments unused. */
#if defined(__GNUC__)
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif

/* Needed because 4.x versions of GCC are really annoying */
#define ignore_return(funcall) \
    do { \
        ssize_t locresult = (funcall); \
        assert(locresult != -23); \
    } while (0)

static /*@unused@*/ inline void memory_barrier(void)
{
#ifndef S_SPLINT_S
#if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)
       __atomic_thread_fence(__ATOMIC_SEQ_CST);
#elif (__GNUC__ == 4 && __GNUC_MINOR__ >= 4)
       __sync_synchronize();
#endif
#endif /* S_SPLINT_S */
}

#endif /* _GPSD_COMPILER_H_ */
