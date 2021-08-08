#include "../../config.h"

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C
/* Select hand configuration */

// #define MASTER_LEFT
#define _MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_TOGGLE 2
#undef TAPPING_TERM
#define TAPPING_TERM 200 //At 500 some bad logic takes hold