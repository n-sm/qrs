#ifndef TEST_AUX_INCLUDED_H
#define TEST_AUX_INCLUDED_H
#include <unistd.h>
#include <setjmp.h>
#include <signal.h>

static jmp_buf jmp_env;

static void catch_alarm(int sig)
{
    longjmp(jmp_env, 1);
}

#define ASSERT_SECS(fn, secs, fn_str, hint) { \
    const auto val = setjmp(jmp_env); \
    if (val == 0) { \
        signal(SIGALRM, catch_alarm); \
        alarm((secs)); \
        { fn; }; \
        alarm(0); \
    } else { \
        GTEST_FATAL_FAILURE_("Pasaron " #secs "s y tu implementación no terminó de evaluar " fn_str ". Necesitás hacerlo más eficiente. HINT: " hint "...?"); \
    } }

#endif //TEST_AUX_INCLUDED_H