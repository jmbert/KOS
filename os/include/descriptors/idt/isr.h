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

typedef enum __ISR_INTERRUPTS {
    /**
     * \brief Division Error 
    */
    ISR_DIVERR, 
    /**
     * \brief Debug exception
    */
    ISR_DEBUG,  
    /**
     * \brief Non-maskable Interrupt
    */ 
    ISR_NMI,   
    /**
     * \brief Breakpoint
    */          
    ISR_BREAK,    
    /**
     * \brief INT0 with overflow bit of RFLAGS set
    */       
    ISR_OVERFLOW,        
    /**
     * \brief BOUND index out of range
    */
    ISR_BNDRNG,          
    /**
     * \brief Invalid operation
    */
    ISR_INVOP,           
    /**
     * \brief FPU instruction attempted without FPU
    */
    ISR_NODEV,           
    /**
     * \brief Double Fault
    */
    ISR_DOUBLE,          
    /**
     * \brief FPU segment overrun 
     * \warning Unused since the 486, handled by a GPF
    */
    UNUSED_ISR_COPROC, 
    /**
     * \brief Invalid TSS segment referenced
    */  
    ISR_INVTSS,          
    /**
     * \brief Accessed segment with present bit set to 0
    */
    ISR_SEGPRES,         
    /**
     * \brief Stack segment fault
    */
    ISR_SSF,             
    /**
     * \brief General Protection fault
    */
    ISR_GPF,             
    /**
     * \brief Page fault - when the page being accessed has present set to 0
    */
    ISR_PAGE_FAULT,  
    // 15 is reserved
    /**
     * \brief Floating point exception on the x86
    */
    ISR_FLOATEXCEP_X86 = 16, 
    /**
     * \brief Alignment checking enabled : unaligned memory address referenced
    */
    ISR_ALIGNMENT, 
    /**
     * \brief Model specific, processor internal errors
    */
    ISR_MACHINE, 
    /**
     * \brief SIMD floating point exception
    */
    ISR_FLOATEXCEP_SIMD,
    /**
     * \brief Virtualisation exception
    */
    ISR_VIRTUALISATION,  
    /**
     * \brief Control protection exception
    */
    ISR_CONTROLPROC,
    // 22-27 Are reserved
    /**
     * \brief Hypervisor injection exception
    */
    ISR_HVINJECTION = 28,   
    /**
     * \brief VMM communication exception
    */  
    ISR_VMMCOMMS,        
    /**
     * \brief Security exception
    */
    ISR_SECURITY  
    // 31 is reserved    
}interrupts_e;

void interrupt_handler(uint8_t error, uint8_t irq);

#endif /* __ISR_H */