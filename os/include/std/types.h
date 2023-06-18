/**
 * \file types.h
 * \author AUTHOR
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#ifndef __TYPES_H
#define __TYPES_H


/*****************************************************************************************************
                                        INT TYPES 
******************************************************************************************************/

/**
 * \brief 8-bit signed integer
 * 
 * \typedef int8_t 
 * 
 */
typedef char int8_t;
/**
 * \brief 8-bit unsigned signed integer
 * 
 * \typedef uint8_t 
 * 
 */
typedef unsigned char uint8_t;

/**
 * \brief 16-bit signed integer
 * 
 * \typedef int16_t 
 * 
 */
typedef short int16_t;
/**
 * \brief 16-bit unsigned signed integer
 * 
 * \typedef uint16_t 
 * 
 */
typedef unsigned short uint16_t;

/**
 * \brief 32-bit signed integer
 * 
 * \typedef int32_t 
 * 
 */
typedef long int32_t;
/**
 * \brief 32-bit unsigned signed integer
 * 
 * \typedef uint32_t 
 * 
 */
typedef unsigned long uint32_t;

/**
 * \brief 64-bit signed integer
 * 
 * \typedef int64_t 
 * 
 */
typedef long long int64_t;
/**
 * \brief 64-bit unsigned signed integer
 * 
 * \typedef uint64_t 
 * 
 */
typedef unsigned long long uint64_t;

typedef uint32_t uintpaddr_t;

typedef uint32_t uintvaddr_t;

/*****************************************************************************************************
                                        INT TYPES (SIZES)
******************************************************************************************************/

/**
 * \def INT8_MAX
 * 
 * \brief The maximum value an int8_t can hold
 */
#define INT8_MAX 128
/**
 * \def INT8_MIN
 * 
 * \brief The minimum value an int8_t can hold
 */
#define INT8_MIN -127

/**
 * \def UINT8_MAX
 * 
 * \brief The maximum value a uint8_t can hold
 */
#define UINT8_MAX 255
/**
 * \def UINT8_MIN
 * 
 * \brief The minimum value a uint8_t can hold
 */
#define UINT8_MIN 0

/**
 * \def INT16_MAX
 * 
 * \brief The maximum value an int16_t can hold
 */
#define INT16_MAX 32768
/**
 * \def INT16_MIN
 * 
 * \brief The minimum value an int16_t can hold
 */
#define INT16_MIN -32767

/**
 * \def UINT16_MAX
 * 
 * \brief The maximum value a uint16_t can hold
 */
#define UINT16_MAX 65535
/**
 * \def UINT16_MIN
 * 
 * \brief The minimum value a uint16_t can hold
 */
#define UINT16_MIN 0

/**
 * \def INT32_MAX
 * 
 * \brief The maximum value an int32_t can hold
 */
#define INT32_MAX 2147483647
/**
 * \def INT32_MIN
 * 
 * \brief The minimum value an int32_t can hold
 */
#define INT32_MIN -2147483648

/**
 * \def UINT32_MAX
 * 
 * \brief The maximum value a uint32_t can hold
 */
#define UINT32_MAX 4294967295
/**
 * \def UINT32_MIN
 * 
 * \brief The minimum value a uint32_t can hold
 */
#define UINT32_MIN 0

/**
 * \def INT64_MAX
 * 
 * \brief The maximum value an int64_t can hold
 */
#define INT64_MAX 9223372036854775807
/**
 * \def INT64_MIN
 * 
 * \brief The minimum value an int64_t can hold
 */
#define INT64_MIN -9223372036854775808

/**
 * \def UINT64_MAX
 * 
 * \brief The maximum value a uint64_t can hold
 */
#define UINT64_MAX 18446744073709551615
/**
 * \def UINT64_MIN
 * 
 * \brief The minimum value a uint64_t can hold
 */
#define UINT64_MIN 0

/**
 * \def UINTPHYSADDR_MAX
 * 
 * \brief The maximum valu uintphysaddr_t can hold
 */
#define UINTPHYSADDR_MAX 4294967295
/**
 * \def UINTPHYSADDR_MIN
 * 
 * \brief The minimum valu uintphysaddr_t can hold
 */
#define UINTPHYSADDR_MIN 0

/**
 * \def UINTVADDR_MAX
 * 
 * \brief The maximum value a uintvaddr_t can hold
 */
#define UINTVADDR_MAX 4294967295
/**
 * \def UINTVADDR_MIN
 * 
 * \brief The minimum value a uintvaddr_t can hold
 */
#define UINTVADDR_MIN 0

#endif /* __TYPES_H */