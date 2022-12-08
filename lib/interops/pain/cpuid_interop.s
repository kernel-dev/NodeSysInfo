bits 32
global _cpuid_eax

_cpuid_eax:
    mov eax, edi
    cpuid

    ret