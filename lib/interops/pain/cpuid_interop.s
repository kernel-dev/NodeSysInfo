bits 32
global _cpuid_data

_cpuid_data:
    mov eax, 1
    cpuid

    ret