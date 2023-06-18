/**
 * \file isr.h
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#ifndef __ISR_H
#define __ISR_H

#define ISR_DIVERR 0
#define ISR_DEBUG 1
#define ISR_NMI 2
#define ISR_BREAK 3
#define ISR_OVERFLOW 4
#define ISR_BNDRNG 5
#define ISR_INVOP 6
#define ISR_NODEV 7
#define ISR_DOUBLE 8
#define UNUSED_ISR_COPROC 9
#define ISR_INVTSS 10
#define ISR_SEGPRES 11
#define ISR_SSF 12
#define ISR_GPF 13
#define ISR_PAGE_FAULT 14
#define ISR_FLOATEXCEP_X86 16
#define ISR_ALIGNMENT 17
#define ISR_MACHINE 18
#define ISR_FLOATEXCEP_SIMD 19
#define ISR_VIRTUALISATION 20
#define ISR_CONTROLPROC 21
#define ISR_HVINJECTION 28
#define ISR_VMMCOMMS 29
#define ISR_SECURITY 30
#define ISR_RESERVED 15 | 22 | 23 | 24 | 25 | 26 | 27 | 31

void exception_handler(void);

#endif /* __ISR_H */