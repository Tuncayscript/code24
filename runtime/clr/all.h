/***
*all.h
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:   Header file to include all MSL functionality
*
*       [Public]
*
****/

#pragma once

#if !defined (_INC_MSCLR_ALL)

#ifndef __cplusplus_cli
#error ERROR: msclr libraries are not compatible with /clr:oldSyntax
#endif  /* __cplusplus_cli */

#include <clr/appdomain.h>
#include <clr/auto_gcroot.h>
#include <clr/auto_handle.h>
#include <clr/event.h>
#include <clr/lock.h>
#include <clr/gcroot.h>
#include <clr/com/ptr.h>

#define _INC_MSCLR_ALL

#endif  /* !defined (_INC_MSCLR_ALL) */
