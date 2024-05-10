/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#ifndef AUTO_DUMP_H_
#define AUTO_DUMP_H_

/*
 *  Raw file format definitions
 */
 
// must be unique in first letter...
// RAW FORMAT
#define HEADER      "dumpster"
#define THREAD      't'
#define LOCAL       'l'
#define NODE        'n'
#define REGISTER    'r'
#define ROOT        'g'
#define WEAK        'w'
#define CLASS       'c'
#define END         'e'

#define SixtyFour 1
#define Little    2

/*

Raw format, not that anyone should really care.  Most programs should use the cooked file reader.

<rawfile := <header> <arch> <middle>* <end>
<header> :=  'd' 'u' 'm' 'p' 's' 't' 'e' 'r'                    ; the HEADER string
<arch>   :=  SixtyFour? + Little?                               ; architecture
<middle> := <thread> | <root> | <node> | <weak> | <class>
<thread> := <register> <stack> <local>*                         ; the triple
<register>      := 'r' longLength [bytes]                       ; the register bank
<stack>         := 't' longLength [bytes]                       ; the stack
<local>         := 'l' [long]                                   ; a thread local node
<root>          := 'g' longAddress longValue
<node>          := 'n' longAddress longSize intLayout longRefcount longIsa?
<weak>          := 'w' longAddress longValue
<class>         := 'c' longAddress <name> <strongLayout> <weakLayout>
<name>          := intLength [bytes]                            ; no null byte
<strongLayout>  := intLength [bytes]                            ; including 0 byte at end
<weakLayout>    := intLength [bytes]                            ; including 0 byte at end
<end>           := 'e'

 */

#endif
