/* -*- Mode: C; c-basic-offset: 3 -*-
 *
 * intr.h - Interrupt vector management and interrupt routing.
 *
 * This file is part of Metalkit, a simple collection of modules for
 * writing software that runs on the bare metal. Get the latest code
 * at http://svn.navi.cx/misc/trunk/metalkit/
 *
 * Copyright (c) 2008 Micah Dowty
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __INTR_H__
#define __INTR_H__

#include "types.h"

#define NUM_INTR_VECTORS    256
#define NUM_FAULT_VECTORS   0x20
#define IRQ_VECTOR_BASE     NUM_FAULT_VECTORS
#define IRQ_TO_VECTOR(irq)  ((irq) + IRQ_VECTOR_BASE)

typedef void (*IntrHandler)(int vector);

void Intr_Init(void);
void Intr_SetFaultHandlers(IntrHandler handler);
void Intr_SetHandler(int vector, IntrHandler handler);
void Intr_SetMask(int irq, Bool enable);

static inline void
Intr_Enable(void) {
   __asm__ __volatile__ ("sti");
}

static inline void
Intr_Disable(void) {
   __asm__ __volatile__ ("cli");
}

#endif /* __INTR_H__ */
