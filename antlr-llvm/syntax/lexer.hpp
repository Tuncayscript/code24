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

// About:
// Filename: lexer.hpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 9, 2024
// Purpose: Creating lexer for the language
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef LEXER_HPP
#define LEXER_HPP

// Define token types (assuming an enum or similar)
enum class TokenType {
  IntegerLiteral,
  FloatLiteral,
  StringLiteral,
  DateLiteral,
  Identifier,
  Keyword,
  Symbol,
};

// Function prototypes for lexical analysis functions
TokenType LexToken();
TokenType LexIntegerLiteral();
TokenType LexFloatLiteral();
TokenType LexStringLiteral();
TokenType LexDateLiteral(); // Placeholder for future implementation
TokenType LexIdentifier();
TokenType LexSymbol();

// Forward declaration for functions potentially implemented elsewhere
bool isKeyword(const char* word); // Prototype for keyword checking

// Global pointer to the current input text (if applicable)
extern char* yytext; // Assuming a global variable in lexer.cpp

#endif // LEXER_HPP
