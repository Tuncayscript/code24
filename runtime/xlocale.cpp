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
 * Contact with ITGSS, 640 N McCarvy Blvd. , in the
 * city of Milpitas, zip Code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 24, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 


// class locale exotic char member functions

#include <istream>
#include <locale>
_STD_BEGIN

#pragma warning(disable : 4074)
#pragma init_seg(compiler)

// facets associated with C categories
#define ADDFAC(Facet, cat, ptrimp, ptrloc)                                                                  \
    if ((_CATMASK(Facet::_Getcat()) & cat) == 0) {                                                          \
        ;                                                                                                   \
    } else if (ptrloc == nullptr) {                                                                         \
        ptrimp->_Addfac(new Facet(lobj), Facet::id);                                                        \
    } else {                                                                                                \
        ptrimp->_Addfac(                                                                                    \
            const_cast<locale::facet*>(static_cast<const locale::facet*>(&_STD use_facet<Facet>(*ptrloc))), \
            Facet::id);                                                                                     \
    }

// moved from locale to ease subsetting
using _Tx1 = collate<char>;
using _Tx2 = messages<char>;
using _Tx3 = money_get<char>;
using _Tx4 = money_put<char>;
using _Tx5 = moneypunct<char, false>;
using _Tx6 = moneypunct<char, true>;
using _Tx7 = time_get<char>;
using _Tx8 = time_put<char>;

void __CLRCALL_OR_CDECL locale::_Locimp::_Makexloc(const _Locinfo& lobj, locale::category cat, _Locimp* ptrimp,
    const locale* ptrloc) { // setup exotic char part of a new locale
    ADDFAC(_Tx1, cat, ptrimp, ptrloc);
    ADDFAC(_Tx2, cat, ptrimp, ptrloc);
    ADDFAC(_Tx3, cat, ptrimp, ptrloc);
    ADDFAC(_Tx4, cat, ptrimp, ptrloc);
    ADDFAC(_Tx5, cat, ptrimp, ptrloc);
    ADDFAC(_Tx6, cat, ptrimp, ptrloc);
    ADDFAC(_Tx7, cat, ptrimp, ptrloc);
    ADDFAC(_Tx8, cat, ptrimp, ptrloc);
}
_STD_END
