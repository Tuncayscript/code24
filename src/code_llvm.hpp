/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip Code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

/* About:
  Filename: code_llvm.hpp
  Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
  Date: Tuesday, May 14, 2024
*/

#ifndef Code_Code_LLVM_HPP
#define Code_Code_LLVM_HPP

#include <stdbool.h>
#include <stddef.h>
#include <llvm-c/Core.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/Target.h>
#include <llvm-c/TargetMachine.h>

#ifdef __cplusplus
#define Code_EXTERN_C extern "C"
#else
#define Code_EXTERN_C
#endif

// ATTENTION: If you modify this file, be sure to update the corresponding
// extern function declarations in the self-hosted compiler.

Code_EXTERN_C bool CodeLLVMTargetMachineEmitToFile(LLVMTargetMachineRef targ_machine_ref, LLVMModuleRef module_ref,
        char **error_message, bool is_debug,
        bool is_small, bool time_report, bool tsan, bool lto,
        const char *asm_filename, const char *bin_filename,
        const char *llvm_ir_filename, const char *bitcode_filename);


enum CodeLLVMABIType {
    CodeLLVMABITypeDefault, // Target-specific (either soft or hard depending on triple, etc).
    CodeLLVMABITypeSoft,    // Soft float.
    CodeLLVMABITypeHard     // Hard float.
};

Code_EXTERN_C LLVMTargetMachineRef CodeLLVMCreateTargetMachine(LLVMTargetRef T, const char *Triple,
    const char *CPU, const char *Features, LLVMCodeGenOptLevel Level, LLVMRelocMode Reloc,
    LLVMCodeModel CodeModel, bool function_sections, bool data_sections, enum CodeLLVMABIType float_abi, 
    const char *abi_name);

Code_EXTERN_C void CodeLLVMSetOptBisectLimit(LLVMContextRef context_ref, int limit);

Code_EXTERN_C void CodeLLVMEnableBrokenDebugInfoCheck(LLVMContextRef context_ref);
Code_EXTERN_C bool CodeLLVMGetBrokenDebugInfo(LLVMContextRef context_ref);

enum CodeLLVMTailCallKind {
    CodeLLVMTailCallKindNone,
    CodeLLVMTailCallKindTail,
    CodeLLVMTailCallKindMustTail,
    CodeLLVMTailCallKindNoTail,
};

enum CodeLLVM_CallingConv {
    CodeLLVM_C = 0,
    CodeLLVM_Fast = 8,
    CodeLLVM_Cold = 9,
    CodeLLVM_GHC = 10,
    CodeLLVM_HiPE = 11,
    CodeLLVM_AnyReg = 13,
    CodeLLVM_PreserveMost = 14,
    CodeLLVM_PreserveAll = 15,
    CodeLLVM_Swift = 16,
    CodeLLVM_CXX_FAST_TLS = 17,
    CodeLLVM_Tail = 18,
    CodeLLVM_CFGuard_Check = 19,
    CodeLLVM_SwiftTail = 20,
    CodeLLVM_FirstTargetCC = 64,
    CodeLLVM_X86_StdCall = 64,
    CodeLLVM_X86_FastCall = 65,
    CodeLLVM_ARM_APCS = 66,
    CodeLLVM_ARM_AAPCS = 67,
    CodeLLVM_ARM_AAPCS_VFP = 68,
    CodeLLVM_MSP430_INTR = 69,
    CodeLLVM_X86_ThisCall = 70,
    CodeLLVM_PTX_Kernel = 71,
    CodeLLVM_PTX_Device = 72,
    CodeLLVM_SPIR_FUNC = 75,
    CodeLLVM_SPIR_KERNEL = 76,
    CodeLLVM_Intel_OCL_BI = 77,
    CodeLLVM_X86_64_SysV = 78,
    CodeLLVM_Win64 = 79,
    CodeLLVM_X86_VectorCall = 80,
    CodeLLVM_DUMMY_HHVM = 81,
    CodeLLVM_DUMMY_HHVM_C = 82,
    CodeLLVM_X86_INTR = 83,
    CodeLLVM_AVR_INTR = 84,
    CodeLLVM_AVR_SIGNAL = 85,
    CodeLLVM_AVR_BUILTIN = 86,
    CodeLLVM_AMDGPU_VS = 87,
    CodeLLVM_AMDGPU_GS = 88,
    CodeLLVM_AMDGPU_PS = 89,
    CodeLLVM_AMDGPU_CS = 90,
    CodeLLVM_AMDGPU_KERNEL = 91,
    CodeLLVM_X86_RegCall = 92,
    CodeLLVM_AMDGPU_HS = 93,
    CodeLLVM_MSP430_BUILTIN = 94,
    CodeLLVM_AMDGPU_LS = 95,
    CodeLLVM_AMDGPU_ES = 96,
    CodeLLVM_AArch64_VectorCall = 97,
    CodeLLVM_AArch64_SVE_VectorCall = 98,
    CodeLLVM_WASM_EmscriptenInvoke = 99,
    CodeLLVM_AMDGPU_Gfx = 100,
    CodeLLVM_M68k_INTR = 101,
    CodeLLVM_AArch64_SME_ABI_Support_Routines_PreserveMost_From_X0 = 102,
    CodeLLVM_AArch64_SME_ABI_Support_Routines_PreserveMost_From_X2 = 103,
    CodeLLVM_AMDGPU_CS_Chain = 104,
    CodeLLVM_AMDGPU_CS_ChainPreserve = 105,
    CodeLLVM_M68k_RTD = 106,
    CodeLLVM_GRAAL = 107,
    CodeLLVM_ARM64EC_Thunk_X64 = 108,
    CodeLLVM_ARM64EC_Thunk_Native = 109,
    CodeLLVM_MaxID = 1023,
};

Code_EXTERN_C void CodeLLVMSetModulePICLevel(LLVMModuleRef module);
Code_EXTERN_C void CodeLLVMSetModulePIELevel(LLVMModuleRef module);
Code_EXTERN_C void CodeLLVMSetModuleCodeModel(LLVMModuleRef module, LLVMCodeModel code_model);

Code_EXTERN_C void CodeLLVMParseCommandLineOptions(size_t argc, const char *const *argv);

// synchronize with llvm/include/ADT/Triple.h::ArchType
// synchronize with std.Target.Cpu.Arch
// synchronize with codegen/llvm/bindings.Code::ArchType
enum CodeLLVM_ArchType {
    CodeLLVM_UnknownArch,

    CodeLLVM_arm,            // ARM (little endian): arm, armv.*, xscale
    CodeLLVM_armeb,          // ARM (big endian): armeb
    CodeLLVM_aarch64,        // AArch64 (little endian): aarch64
    CodeLLVM_aarch64_be,     // AArch64 (big endian): aarch64_be
    CodeLLVM_aarch64_32,     // AArch64 (little endian) ILP32: aarch64_32
    CodeLLVM_arc,            // ARC: Synopsys ARC
    CodeLLVM_avr,            // AVR: Atmel AVR microcontroller
    CodeLLVM_bpfel,          // eBPF or extended BPF or 64-bit BPF (little endian)
    CodeLLVM_bpfeb,          // eBPF or extended BPF or 64-bit BPF (big endian)
    CodeLLVM_csky,           // CSKY: csky
    CodeLLVM_dxil,           // DXIL 32-bit DirectX bytecode
    CodeLLVM_hexagon,        // Hexagon: hexagon
    CodeLLVM_loongarch32,    // LoongArch (32-bit): loongarch32
    CodeLLVM_loongarch64,    // LoongArch (64-bit): loongarch64
    CodeLLVM_m68k,           // M68k: Motorola 680x0 family
    CodeLLVM_mips,           // MIPS: mips, mipsallegrex, mipsr6
    CodeLLVM_mipsel,         // MIPSEL: mipsel, mipsallegrexe, mipsr6el
    CodeLLVM_mips64,         // MIPS64: mips64, mips64r6, mipsn32, mipsn32r6
    CodeLLVM_mips64el,       // MIPS64EL: mips64el, mips64r6el, mipsn32el, mipsn32r6el
    CodeLLVM_msp430,         // MSP430: msp430
    CodeLLVM_ppc,            // PPC: powerpc
    CodeLLVM_ppcle,          // PPCLE: powerpc (little endian)
    CodeLLVM_ppc64,          // PPC64: powerpc64, ppu
    CodeLLVM_ppc64le,        // PPC64LE: powerpc64le
    CodeLLVM_r600,           // R600: AMD GPUs HD2XXX - HD6XXX
    CodeLLVM_amdgcn,         // AMDGCN: AMD GCN GPUs
    CodeLLVM_riscv32,        // RISC-V (32-bit): riscv32
    CodeLLVM_riscv64,        // RISC-V (64-bit): riscv64
    CodeLLVM_sparc,          // Sparc: sparc
    CodeLLVM_sparcv9,        // Sparcv9: Sparcv9
    CodeLLVM_sparcel,        // Sparc: (endianness = little). NB: 'Sparcle' is a CPU variant
    CodeLLVM_systemz,        // SystemZ: s390x
    CodeLLVM_tce,            // TCE (http://tce.cs.tut.fi/): tce
    CodeLLVM_tcele,          // TCE little endian (http://tce.cs.tut.fi/): tcele
    CodeLLVM_thumb,          // Thumb (little endian): thumb, thumbv.*
    CodeLLVM_thumbeb,        // Thumb (big endian): thumbeb
    CodeLLVM_x86,            // X86: i[3-9]86
    CodeLLVM_x86_64,         // X86-64: amd64, x86_64
    CodeLLVM_xcore,          // XCore: xcore
    CodeLLVM_xtensa,         // Tensilica: Xtensa
    CodeLLVM_nvptx,          // NVPTX: 32-bit
    CodeLLVM_nvptx64,        // NVPTX: 64-bit
    CodeLLVM_le32,           // le32: generic little-endian 32-bit CPU (PNaCl)
    CodeLLVM_le64,           // le64: generic little-endian 64-bit CPU (PNaCl)
    CodeLLVM_amdil,          // AMDIL
    CodeLLVM_amdil64,        // AMDIL with 64-bit pointers
    CodeLLVM_hsail,          // AMD HSAIL
    CodeLLVM_hsail64,        // AMD HSAIL with 64-bit pointers
    CodeLLVM_spir,           // SPIR: standard portable IR for OpenCL 32-bit version
    CodeLLVM_spir64,         // SPIR: standard portable IR for OpenCL 64-bit version
    CodeLLVM_spirv,          // SPIR-V with logical memory layout.
    CodeLLVM_spirv32,        // SPIR-V with 32-bit pointers
    CodeLLVM_spirv64,        // SPIR-V with 64-bit pointers
    CodeLLVM_kalimba,        // Kalimba: generic kalimba
    CodeLLVM_shave,          // SHAVE: Movidius vector VLIW processors
    CodeLLVM_lanai,          // Lanai: Lanai 32-bit
    CodeLLVM_wasm32,         // WebAssembly with 32-bit pointers
    CodeLLVM_wasm64,         // WebAssembly with 64-bit pointers
    CodeLLVM_renderscript32, // 32-bit RenderScript
    CodeLLVM_renderscript64, // 64-bit RenderScript
    CodeLLVM_ve,             // NEC SX-Aurora Vector Engine
    CodeLLVM_LastArchType = CodeLLVM_ve
};

enum CodeLLVM_VendorType {
    CodeLLVM_UnknownVendor,

    CodeLLVM_Apple,
    CodeLLVM_PC,
    CodeLLVM_SCEI,
    CodeLLVM_Freescale,
    CodeLLVM_IBM,
    CodeLLVM_ImaginationTechnologies,
    CodeLLVM_MipsTechnologies,
    CodeLLVM_NVIDIA,
    CodeLLVM_CSR,
    CodeLLVM_AMD,
    CodeLLVM_Mesa,
    CodeLLVM_SUSE,
    CodeLLVM_OpenEmbedded,

    CodeLLVM_LastVendorType = CodeLLVM_OpenEmbedded
};

// synchronize with llvm/include/ADT/Triple.h::OsType
// synchronize with std.Target.Os.Tag
// synchronize with codegen/llvm/bindings.Code::OsType
enum CodeLLVM_OSType {
    CodeLLVM_UnknownOS,

    CodeLLVM_Darwin,
    CodeLLVM_DragonFly,
    CodeLLVM_FreeBSD,
    CodeLLVM_Fuchsia,
    CodeLLVM_IOS,
    CodeLLVM_KFreeBSD,
    CodeLLVM_Linux,
    CodeLLVM_Lv2,        // PS3
    CodeLLVM_MacOSX,
    CodeLLVM_NetBSD,
    CodeLLVM_OpenBSD,
    CodeLLVM_Solaris,
    CodeLLVM_UEFI,
    CodeLLVM_Win32,
    CodeLLVM_ZOS,
    CodeLLVM_Haiku,
    CodeLLVM_RTEMS,
    CodeLLVM_NaCl,       // Native Client
    CodeLLVM_AIX,
    CodeLLVM_CUDA,       // NVIDIA CUDA
    CodeLLVM_NVCL,       // NVIDIA OpenCL
    CodeLLVM_AMDHSA,     // AMD HSA Runtime
    CodeLLVM_PS4,
    CodeLLVM_PS5,
    CodeLLVM_ELFIAMCU,
    CodeLLVM_TvOS,       // Apple tvOS
    CodeLLVM_WatchOS,    // Apple watchOS
    CodeLLVM_DriverKit,  // Apple DriverKit
    CodeLLVM_XROS,       // Apple XROS
    CodeLLVM_Mesa3D,
    CodeLLVM_AMDPAL,     // AMD PAL Runtime
    CodeLLVM_HermitCore, // HermitCore Unikernel/Multikernel
    CodeLLVM_Hurd,       // GNU/Hurd
    CodeLLVM_WASI,       // Experimental WebAssembly OS
    CodeLLVM_Emscripten,
    CodeLLVM_ShaderModel, // DirectX ShaderModel
    CodeLLVM_LiteOS,
    CodeLLVM_Serenity,
    CodeLLVM_Vulkan,      // Vulkan SPIR-V
    CodeLLVM_LastOSType = CodeLLVM_Vulkan
};

// Synchronize with target.cpp::abi_list
enum CodeLLVM_EnvironmentType {
    CodeLLVM_UnknownEnvironment,

    CodeLLVM_GNU,
    CodeLLVM_GNUABIN32,
    CodeLLVM_GNUABI64,
    CodeLLVM_GNUEABI,
    CodeLLVM_GNUEABIHF,
    CodeLLVM_GNUF32,
    CodeLLVM_GNUF64,
    CodeLLVM_GNUSF,
    CodeLLVM_GNUX32,
    CodeLLVM_GNUILP32,
    CodeLLVM_CODE16,
    CodeLLVM_EABI,
    CodeLLVM_EABIHF,
    CodeLLVM_Android,
    CodeLLVM_Musl,
    CodeLLVM_MuslEABI,
    CodeLLVM_MuslEABIHF,
    CodeLLVM_MuslX32,

    CodeLLVM_MSVC,
    CodeLLVM_Itanium,
    CodeLLVM_Cygnus,
    CodeLLVM_CoreCLR,
    CodeLLVM_Simulator, // Simulator variants of other systems, e.g., Apple's iOS
    CodeLLVM_MacABI, // Mac Catalyst variant of Apple's iOS deployment target.

    CodeLLVM_Pixel,
    CodeLLVM_Vertex,
    CodeLLVM_Geometry,
    CodeLLVM_Hull,
    CodeLLVM_Domain,
    CodeLLVM_Compute,
    CodeLLVM_Library,
    CodeLLVM_RayGeneration,
    CodeLLVM_Intersection,
    CodeLLVM_AnyHit,
    CodeLLVM_ClosestHit,
    CodeLLVM_Miss,
    CodeLLVM_Callable,
    CodeLLVM_Mesh,
    CodeLLVM_Amplification,
    CodeLLVM_OpenHOS,

    CodeLLVM_LastEnvironmentType = CodeLLVM_OpenHOS
};

enum CodeLLVM_ObjectFormatType {
    CodeLLVM_UnknownObjectFormat,

    CodeLLVM_COFF,
    CodeLLVM_DXContainer,
    CodeLLVM_ELF,
    CodeLLVM_GOFF,
    CodeLLVM_MachO,
    CodeLLVM_SPIRV,
    CodeLLVM_Wasm,
    CodeLLVM_XCOFF,
};

#define CodeLLVM_DIFlags_Zero 0U
#define CodeLLVM_DIFlags_Private 1U
#define CodeLLVM_DIFlags_Protected 2U
#define CodeLLVM_DIFlags_Public 3U
#define CodeLLVM_DIFlags_FwdDecl (1U << 2)
#define CodeLLVM_DIFlags_AppleBlock (1U << 3)
#define CodeLLVM_DIFlags_BlockByrefStruct (1U << 4)
#define CodeLLVM_DIFlags_Virtual (1U << 5)
#define CodeLLVM_DIFlags_Artificial (1U << 6)
#define CodeLLVM_DIFlags_Explicit (1U << 7)
#define CodeLLVM_DIFlags_Prototyped (1U << 8)
#define CodeLLVM_DIFlags_ObjcClassComplete (1U << 9)
#define CodeLLVM_DIFlags_ObjectPointer (1U << 10)
#define CodeLLVM_DIFlags_Vector (1U << 11)
#define CodeLLVM_DIFlags_StaticMember (1U << 12)
#define CodeLLVM_DIFlags_LValueReference (1U << 13)
#define CodeLLVM_DIFlags_RValueReference (1U << 14)
#define CodeLLVM_DIFlags_Reserved (1U << 15)
#define CodeLLVM_DIFlags_SingleInheritance (1U << 16)
#define CodeLLVM_DIFlags_MultipleInheritance (2 << 16)
#define CodeLLVM_DIFlags_VirtualInheritance (3 << 16)
#define CodeLLVM_DIFlags_IntroducedVirtual (1U << 18)
#define CodeLLVM_DIFlags_BitField (1U << 19)
#define CodeLLVM_DIFlags_NoReturn (1U << 20)
#define CodeLLVM_DIFlags_TypePassByValue (1U << 22)
#define CodeLLVM_DIFlags_TypePassByReference (1U << 23)
#define CodeLLVM_DIFlags_EnumClass (1U << 24)
#define CodeLLVM_DIFlags_Thunk (1U << 25)
#define CodeLLVM_DIFlags_NonTrivial (1U << 26)
#define CodeLLVM_DIFlags_BigEndian (1U << 27)
#define CodeLLVM_DIFlags_LittleEndian (1U << 28)
#define CodeLLVM_DIFlags_AllCallsDescribed (1U << 29)

Code_EXTERN_C bool CodeLLDLinkCOFF(int argc, const char **argv, bool can_exit_early, bool disable_output);
Code_EXTERN_C bool CodeLLDLinkELF(int argc, const char **argv, bool can_exit_early, bool disable_output);
Code_EXTERN_C bool CodeLLDLinkWasm(int argc, const char **argv, bool can_exit_early, bool disable_output);

Code_EXTERN_C bool CodeLLVMWriteArchive(const char *archive_name, const char **file_names, size_t file_name_count,
        enum CodeLLVM_OSType os_type);

Code_EXTERN_C bool CodeLLVMWriteImportLibrary(const char *def_path, const enum CodeLLVM_ArchType arch,
                               const char *output_lib_path, bool kill_at);

#endif
