#include "Include/Local.h"

#include <stdio.h>
#include <stdlib.h>
#include <IOKit/IOKitLib.h>

extern uint32_t cpuid_eax(uint32_t function_id);

void format_cpuid_data(CPU_VERSION_INFORMATION *Buffer)
{
    uint32_t extracted = cpuid_eax(0x1);

    if (extracted > 0)
    {
        Buffer->stepping_id           = (extracted >> 0)   &  ((1 << 4) - 1);
        Buffer->base_model            = (extracted >> 4)   &  ((1 << 4) - 1);
        Buffer->base_family           = (extracted >> 8)   &  ((1 << 4) - 1);
        Buffer->processor_type        = (extracted >> 12)  &  ((1 << 2) - 1);
        Buffer->reserved1             = (extracted >> 14)  &  ((1 << 2) - 1);
        Buffer->extended_model_id     = (extracted >> 16)  &  ((1 << 4) - 1);
        Buffer->extended_family_id    = (extracted >> 20)  &  ((1 << 8) - 1);
        Buffer->reserved2             = (extracted >> 28)  &  ((1 << 4) - 1);
    }
}

int main()
{
    CPU_VERSION_INFORMATION *Data = malloc(sizeof(CPU_VERSION_INFORMATION));

    format_cpuid_data(Data);

    printf("Stepping ID: 0x%X\n", Data->stepping_id);
    printf("Model: 0x%X\n", Data->base_model + (Data->extended_model_id << 4));
    printf("Family: 0x%X\n\n", Data->base_family + Data->extended_family_id);
    printf("Processor Type: 0x%X\n", Data->processor_type);
    printf("Reserved1: 0x%X\n\n", Data->reserved1);
    printf("Base Model ID: 0x%X\n", Data->base_model);
    printf("Extended Model ID: 0x%X\n\n", Data->extended_model_id);
    printf("Base Family ID: 0x%X\n", Data->base_family);
    printf("Extended Family ID: 0x%X\n\n", Data->extended_family_id);
    printf("Reserved2: 0x%X\n", Data->reserved2);

    return 0;
}