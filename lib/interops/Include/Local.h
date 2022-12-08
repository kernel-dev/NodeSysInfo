#ifndef LOCAL_H
#define LOCAL_H

#include <stdio.h>
#include <stdlib.h>

/**
 *  Defines the "structure" of bits
 *  when using the EAX=1h function
 *  for CPUID.
 */
typedef struct {
    //
    //  Stepping (revision) identifier (4 bits)
    //
    uint8_t     stepping_id: 4;

    //
    //  Base model identifier (4 bits)
    //
    uint8_t     base_model: 4;

    //
    //  Base family identifier (4 bits)
    //
    uint8_t     base_family: 4;

    //
    //  Processor type (2 bits)
    //
    uint8_t     processor_type: 2;

    //
    //  Reserved field (2 bits)
    //
    uint8_t     reserved1: 2;

    //
    //  Extended model identifier (4 bits)
    //
    uint8_t     extended_model_id: 4;

    //
    //  Extended family identifier (8 bits)
    //
    uint8_t     extended_family_id;

    //
    //  Reserved field (4 bits)
    //
    uint8_t     reserved2: 4;
} CPU_VERSION_INFORMATION;

void format_cpuid_data( CPU_VERSION_INFORMATION *Buffer );

#endif /* Local.h */