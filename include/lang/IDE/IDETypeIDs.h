//===--- IDETypeIDs.h - IDE Type Ids ----------------------------*- C++ -*-===//
//
// This source file is part of the Code Programming Language open source project
//
// Copyright (c) 2019 ITGSS Technologies and the Code project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See code/LICENSE.txt for license information
// See code/CONTRIBUTORS.txt for the list of Code project authors
//
//===----------------------------------------------------------------------===//
//
//  This file defines TypeID support for IDE types.
//
//===----------------------------------------------------------------------===//

#ifndef CODE_IDE_IDETYPEIDS_H
#define CODE_IDE_IDETYPEIDS_H

#include "code/Basic/TypeID.h"
namespace code {

#define CODE_TYPEID_ZONE IDETypes
#define CODE_TYPEID_HEADER "code/IDE/IDETypeIDZone.def"
#include "code/Basic/DefineTypeIDZone.h"

} // end namespace code

#endif // CODE_IDE_IDETYPEIDS_H
