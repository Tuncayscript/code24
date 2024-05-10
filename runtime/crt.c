#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "codert.h"

// Boundary symbols for metadata sections

#pragma section(".code_module_info$A",long,read,write)
#pragma data_seg(".code_module_info$A")
static uintptr_t __code_modStart = 0;
#pragma section(".code_module_info$C",long,read,write)
#pragma data_seg(".code_module_info$C")
static uintptr_t __code_modEnd = 0;

#pragma section(".code_protocol$A",long,read,write)
#pragma data_seg(".code_protocol$A")
static uintptr_t __code_protoStart = 0;
#pragma section(".code_protocol$C",long,read,write)
#pragma data_seg(".code_protocol$C")
static uintptr_t __code_protoEnd = 0;

#pragma section(".code_image_info$A",long,read,write)
#pragma data_seg(".code_image_info$A")
static uintptr_t __code_iiStart = 0;
#pragma section(".code_image_info$C",long,read,write)
#pragma data_seg(".code_image_info$C")
static uintptr_t __code_iiEnd = 0;

#pragma section(".code_message_refs$A",long,read,write)
#pragma data_seg(".code_message_refs$A")
static uintptr_t __code_selrefsStart = 0;
#pragma section(".code_message_refs$C",long,read,write)
#pragma data_seg(".code_message_refs$C")
static uintptr_t __code_selrefsEnd = 0;

#pragma section(".code_class_refs$A",long,read,write)
#pragma data_seg(".code_class_refs$A")
static uintptr_t __code_clsrefsStart = 0;
#pragma section(".code_class_refs$C",long,read,write)
#pragma data_seg(".code_class_refs$C")
static uintptr_t __code_clsrefsEnd = 0;

#pragma data_seg()

// Merge all metadata into .data
// fixme order these by usage?
#pragma comment(linker, "/MERGE:.code_module_info=.data")
#pragma comment(linker, "/MERGE:.code_protocol=.data")
#pragma comment(linker, "/MERGE:.code_image_info=.data")
#pragma comment(linker, "/MERGE:.code_message_refs=.data")
#pragma comment(linker, "/MERGE:.code_class_refs=.data")


// Image initializers

static void *__hinfo = NULL;  // cookie from runtime
extern IMAGE_DOS_HEADER __ImageBase;  // this image's header

static int __code_init(void)
{
    code_sections sections = {
        5, 
        &__code_modStart, &__code_modEnd, 
        &__code_protoStart, &__code_protoEnd, 
        &__code_iiStart, &__code_iiEnd, 
        &__code_selrefsStart, &__code_selrefsEnd, 
        &__code_clsrefsStart, &__code_clsrefsEnd, 
    };
    __hinfo = _code_init_image((HMODULE)&__ImageBase, &sections);
    return 0;
}

static void __code_unload(void)
{
    _code_unload_image((HMODULE)&__ImageBase, __hinfo);
}

static int __code_load(void)
{
    _code_load_image((HMODULE)&__ImageBase, __hinfo);
    return 0;
}

// run _code_init_image ASAP
#pragma section(".CRT$XIAA",long,read,write)
#pragma data_seg(".CRT$XIAA")
static void *__code_init_fn = &__code_init;

// run _code_load_image (+load methods) after all other initializers; 
// otherwise constant NSStrings are not initialized yet
#pragma section(".CRT$XCUO",long,read,write)
#pragma data_seg(".CRT$XCUO")
static void *__code_load_fn = &__code_load;

// _code_unload_image is called by atexit(), not by an image terminator

#pragma data_seg()
