#include "idt.h"
#include "config.h"
#include "memory/memory.h"

struct idt_desc idt_descriptors[SHEAROS_TOTAL_INTERRUPTS];
struct idt_desc idtr_descriptor;

void idt_init(void)
{
    memset(idt_descriptors, 0, sizeof(idt_descriptors));
}