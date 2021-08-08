#pragma once

#include "lets_split.h"

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

/*  ---------- LEFT HAND -----------   ---------- RIGHT HAND ----------     */
#define LAYOUT_ergodox_pretty(                                              \
    L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,     \
    L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,     \
    L20,L21,L22,L23,L24,L25,                   R20,R21,R22,R23,R24,R25,     \
    L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,     \
    L40,L41,L42,L43,L44,                           R40,R41,R42,R43,R44,     \
                            L55,L56,   R55,R56,                             \
                                L54,   R54,                                 \
                        L53,L52,L51,   R53,R52,R51 )                        \
                                                                            \
    /* matrix positions */                                                  \
    /*     F4  F5  F6  F7  B1  B3  B2  B6  */                               \
    /* C6  x   x   x   x   x   x   x   x   */                               \
    /* D7  x   x   x   x   x   x   x   x   */                               \
    /* E6  x   x   x   x   x   x   x   x   */                               \
    /* B4  x   x   x   x   x   x   x   x   */                               \
    /* B5  x   x   x   x   x   x   x   x   */                               \
    {   { KC_NO,  R00,    R01,    R02,    R03,    R04,    R05,    R06   },  \
        { KC_NO,  R10,    R11,    R12,    R13,    R14,    R15,    R16   },  \
        { R56,    R30,    R20,    R21,    R22,    R23,    R24,    R25   },  \
        { R55,    R54,    R31,    R32,    R33,    R34,    R35,    R36   },  \
        { R52,    R53,    R51,    R40,    R41,    R42,    R43,    R44   },  \
                                                                            \
        { L00,    L01,    L02,    L03,    L04,    L05,    L06,    KC_NO },  \
        { L10,    L11,    L12,    L13,    L14,    L15,    L16,    KC_NO },  \
        { L20,    L21,    L22,    L23,    L24,    L25,    L36,    L55   },  \
        { L30,    L31,    L32,    L33,    L34,    L35,    L54,    L56   },  \
        { L40,    L41,    L42,    L43,    L44,    L53,    L51,    L52   },  \
    }

