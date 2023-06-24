/**
 * \file attributes.h
 * \author AUTHOR 
 * \brief Defines macros to easily assign attributes to declarations
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#ifndef __COMMON_ATTRIBUTES_H
#define __COMMON_ATTRIBUTES_H

/**
 * \def __ATTR
 * 
 * \brief Gives a declaration attribute a, with argument b
 * 
 */
#define __ATTR(a, b) __attribute__((#a(#b)))

/**
 * \def __ALIGN
 * 
 * \brief Aligns the declaration to the nearest a bytes.
 * 
 */
#define __ALIGN(a) __ATTR(align, #a)

/**
 * \def __SECTION
 * 
 * \brief Places the declaration in section a.
 * 
 */
#define __SECTION(a) __ATTR(section, #a)

#endif /* __COMMON_ATTRIBUTES_H */