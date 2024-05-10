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

#include <cctype> // for character classification functions
#include <vector>
#include <string>

// Define token types (assuming an enum or similar)
enum TokenType {
  IntegerLiteral,
  FloatLiteral,
  StringLiteral,
  DateLiteral,
  Identifier,
  Keyword, // for reserved keywords
  Symbol,
  // ... other token types (e.g., EOF)
};

// Helper functions for matching characters and sequences
bool IsLetter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool IsDigit(char c) {
  return c >= '0' && c <= '9';
}

bool IsWhitespace(char c) {
  return c == ' ' || c == '\t';
}

bool IsHexDigit(char c) {
  return IsDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

// Lexical analysis functions for different token types
TokenType LexIntegerLiteral() {
  // Check for leading sign (optional)
  bool isNegative = *yytext == '-';
  ++yytext;

  // Check for decimal, hexadecimal, or octal integer
  if (*yytext == '0') {
    ++yytext;
    if (*yytext == 'x' || *yytext == 'X') {
      // Hexadecimal integer
      ++yytext;
      while (IsHexDigit(*yytext)) {
        ++yytext;
      }
    } else if (*yytext == 'o' || *yytext == 'O') {
      // Octal integer
      ++yytext;
      while (IsDigit(*yytext) && *yytext < '8') {
        ++yytext;
      }
    } else {
      // Decimal integer (0 or starting with 0)
      while (IsDigit(*yytext)) {
        ++yytext;
      }
    }
  } else {
    // Decimal integer (not starting with 0)
    while (IsDigit(*yytext)) {
      ++yytext;
    }
  }

  // Check for size suffix (optional)
  if (*yytext == '%') {
    ++yytext;
  } else if (*yytext == '&') {
    ++yytext;
  } else if (*yytext == '^') {
    ++yytext;
  }

  return IntegerLiteral;
}

TokenType LexFloatLiteral() {
  // Check for leading sign (optional)
  bool isNegative = *yytext == '-';
  ++yytext;

  // Check for integer part
  while (IsDigit(*yytext)) {
    ++yytext;
  }

  // Check for decimal point
  if (*yytext == '.') {
    ++yytext;
    // Check for digits after decimal point
    while (IsDigit(*yytext)) {
      ++yytext;
    }
  }

  // Check for exponent (optional)
  if (*yytext == 'e' || *yytext == 'E') {
    ++yytext;
    // Check for sign after exponent (optional)
    if (*yytext == '-' || *yytext == '+') {
      ++yytext;
    }
    // Check for digits after exponent
    while (IsDigit(*yytext)) {
      ++yytext;
    }
  }

  // Check for float suffix (optional)
  if (*yytext == '!') {
    ++yytext;
  } else if (*yytext == '#') {
    ++yytext;
  } else if (*yytext == '@') {
    ++yytext;
  }

  return FloatLiteral;
}

TokenType LexStringLiteral() {
  // Check for opening double quote
  if (*yytext != '"') {
    return Symbol; // Not a string literal
  }
  ++yytext;

  // Read characters until closing double quote or end of input
  while (*yytext != '"' && *yytext != '\0') {
    // Handle escape sequences (e.g., \n, \t)
    if (*yytext == '\\') {
      ++yytext;
      // Handle different escape characters
      switch (*yytext) {
        case 'n':
          ++yytext;
          break;
        case 't':
          ++yytext;
          break;
        // ... handle other escape sequences
        default:
          // Handle unrecognized escape sequence (or literal backslash)
          ++yytext;
          break;
      }
    } else {
      ++yytext;
    }
  }

  // Check for closing double quote
  if (*yytext != '"') {
    // Error: unterminated string literal
    // Handle error appropriately
    return -1; // Or throw an exception
  }
  ++yytext;

  return StringLiteral;
}

TokenType LexDateLiteral() {
  // Implement logic to handle date literals based on the grammar rules
  // (check for '#', date components, separators, etc.)
  // ...

  return DateLiteral;
}

TokenType LexIdentifier() {
  // Check for leading letter
  if (!IsLetter(*yytext)) {
    return Symbol; // Not an identifier
  }

  // Consume letters, digits, and underscores
  while (IsLetter(*yytext) || IsDigit(*yytext) || *yytext == '_') {
    ++yytext;
  }

  // Check for reserved keywords
  // ... (implement keyword matching)
  if (isKeyword(*yytext)) {
    return Keyword;
  }

  return Identifier;
}

TokenType LexSymbol() {
  // Check for single-character symbols
  switch (*yytext) {
    case '[':
    case ']':
    case '(':
    case ')':
    case '%':
    case '&':
    case '^':
    case '!':
    case '@':
    case '$':
    case ',':
    case '-':
    case '*':
    case '=':
    case ';':
    case ':':
    case '<':
    case '>':
    case '\\':
    case '/':
    case '+':
      ++yytext;
      return Symbol;
    default:
      // Handle unrecognized characters (error or extended symbols)
      // ...
      return -1; // Or throw an exception
  }
}
struct TrieNode {
  bool isWord;
  std::vector<TrieNode*> children;

  TrieNode() : isWord(false), children(26, nullptr) {}
};

struct TrieNode {
  bool isWord;
  std::vector<TrieNode*> children;

  TrieNode() : isWord(false), children(26, nullptr) {}
};

class Trie {
 private:
  TrieNode* root;

 public:
  Trie() : root(new TrieNode()) {}

  void insert(const std::string& word) {
    TrieNode* current = root;
    for (char c : word) {
      int index = c - 'a';
      if (!current->children[index]) {
        current->children[index] = new TrieNode();
      }
      current = current->children[index];
    }
    current->isWord = true;
  }

  bool isKeyword(const char* word) {
    TrieNode* current = root;
    for (char c : word) {
      int index = c - 'a';
      if (!current->children[index]) {
        return false;
      }
      current = current->children[index];
    }
    return current->isWord;
  }
};

Trie reservedKeywords; // Global trie object

void initializeKeywords() {
  reservedKeywords.insert("Abs");
  reservedKeywords.insert("Access");
  reservedKeywords.insert("AddressOf");
  reservedKeywords.insert("Alias");
  reservedKeywords.insert("And");
  reservedKeywords.insert("Any");
  reservedKeywords.insert("Append");
  reservedKeywords.insert("Array");
  reservedKeywords.insert("As");
  reservedKeywords.insert("Attribute");
  reservedKeywords.insert("Base");
  reservedKeywords.insert("Binary");
  reservedKeywords.insert("Boolean");
  reservedKeywords.insert("ByRef");
  reservedKeywords.insert("Byte");
  reservedKeywords.insert("ByVal");
  reservedKeywords.insert("Call");
  reservedKeywords.insert("Case");
  reservedKeywords.insert("CBool");
  reservedKeywords.insert("CByte");
  reservedKeywords.insert("CCur");
  reservedKeywords.insert("CDate");
  reservedKeywords.insert("CDbl");
  reservedKeywords.insert("CDec");
  reservedKeywords.insert("CDecl");
  reservedKeywords.insert("CInt");
  reservedKeywords.insert("Circle");
  reservedKeywords.insert("CLng");
  reservedKeywords.insert("CLngLng");
  reservedKeywords.insert("CLngPtr");
  reservedKeywords.insert("Class_Initialize");
  reservedKeywords.insert("Class_Terminate");
  reservedKeywords.insert("Close");
  reservedKeywords.insert("Compare");
  reservedKeywords.insert("Const");
  reservedKeywords.insert("CSng");
  reservedKeywords.insert("CStr");
  reservedKeywords.insert("Currency");
  reservedKeywords.insert("CVar");
  reservedKeywords.insert("CVErr");
  reservedKeywords.insert("Data");
  reservedKeywords.insert("Database");
  reservedKeywords.insert("Date");
  reservedKeywords.insert("Debug");
  reservedKeywords.insert("Decimal");
  reservedKeywords.insert("Declare");
  reservedKeywords.insert("DefBool");
  reservedKeywords.insert("DefByte");
  reservedKeywords.insert("DefCur");
  reservedKeywords.insert("DefDate");
  reservedKeywords.insert("DefDbl");
  reservedKeywords.insert("DefInt");
  reservedKeywords.insert("DefLng");
  reservedKeywords.insert("DefLngLng");
  reservedKeywords.insert("DefLngPtr");
  reservedKeywords.insert("DefObj");
  reservedKeywords.insert("DefSng");
  reservedKeywords.insert("DefStr");
  reservedKeywords.insert("DefVar");
  reservedKeywords.insert("DefDec");
  reservedKeywords.insert("Dim");
  reservedKeywords.insert("Do");
  reservedKeywords.insert("DoEvents");
  reservedKeywords.insert("Double");
  reservedKeywords.insert("Each");
  reservedKeywords.insert("Else");
  reservedKeywords.insert("ElseIf");
  reservedKeywords.insert("Empty");
  reservedKeywords.insert("End");
  reservedKeywords.insert("EndIf");
  reservedKeywords.insert("Enum");
  reservedKeywords.insert("Eqv");
  reservedKeywords.insert("Erase");
  reservedKeywords.insert("Error");
    reservedKeywords.insert("Eqv");
  reservedKeywords.insert("Erase");
  reservedKeywords.insert("Error");
  reservedKeywords.insert("Event");
  reservedKeywords.insert("Exit");
  reservedKeywords.insert("Explicit");
  reservedKeywords.insert("False");
  reservedKeywords.insert("Fix");
  reservedKeywords.insert("For");
  reservedKeywords.insert("Friend");
  reservedKeywords.insert("Function");
  reservedKeywords.insert("Get");
  reservedKeywords.insert("Global");
  reservedKeywords.insert("GoSub");
  reservedKeywords.insert("GoTo");
  reservedKeywords.insert("If");
  reservedKeywords.insert("Imp");
  reservedKeywords.insert("Implements");
  reservedKeywords.insert("In");
  reservedKeywords.insert("Input");
  reservedKeywords.insert("InputB");
  reservedKeywords.insert("Int");
  reservedKeywords.insert("Integer");
  reservedKeywords.insert("Is");
  reservedKeywords.insert("LBound");
  reservedKeywords.insert("Len");
  reservedKeywords.insert("LenB");
  reservedKeywords.insert("Let");
  reservedKeywords.insert("Lib");
  reservedKeywords.insert("Like");
  reservedKeywords.insert("Line");
  reservedKeywords.insert("LINEINPUT");
  reservedKeywords.insert("Lock");
  reservedKeywords.insert("Long");
  reservedKeywords.insert("LongLong");
  reservedKeywords.insert("LongPtr");
  reservedKeywords.insert("Loop");
  reservedKeywords.insert("LSet");
  reservedKeywords.insert("Me");
  reservedKeywords.insert("Mid");
  reservedKeywords.insert("MidB");
  reservedKeywords.insert("Mod");
  reservedKeywords.insert("Module");
  reservedKeywords.insert("New");
  reservedKeywords.insert("Next");
  reservedKeywords.insert("Not");
  reservedKeywords.insert("Nothing");
  reservedKeywords.insert("Null");
  reservedKeywords.insert("Object");
  reservedKeywords.insert("On");
  reservedKeywords.insert("Open");
  reservedKeywords.insert("Option");
  reservedKeywords.insert("Optional");
  reservedKeywords.insert("Or");
  reservedKeywords.insert("Output");
  reservedKeywords.insert("ParamArray");
  reservedKeywords.insert("Preserve");
  reservedKeywords.insert("Print");
  reservedKeywords.insert("Private");
  reservedKeywords.insert("Property");
  reservedKeywords.insert("PSet");
  reservedKeywords.insert("PtrSafe");
  reservedKeywords.insert("Public");
  reservedKeywords.insert("Put");
  reservedKeywords.insert("RaiseEvent");
  reservedKeywords.insert("Random");
  reservedKeywords.insert("Read");
  reservedKeywords.insert("ReDim");
  reservedKeywords.insert("Rem");
  reservedKeywords.insert("Reset");
  reservedKeywords.insert("Resume");
  reservedKeywords.insert("Return");
  reservedKeywords.insert("RSet");
  reservedKeywords.insert("Scale");
  reservedKeywords.insert("Seek");
  reservedKeywords.insert("Select");
  reservedKeywords.insert("Set");
  reservedKeywords.insert("Sgn");
  reservedKeywords.insert("Shared");
  reservedKeywords.insert("Single");
  reservedKeywords.insert("Spc");
  reservedKeywords.insert("Static");
  reservedKeywords.insert("Stop");
  reservedKeywords.insert("Step");
  reservedKeywords.insert("String");
  reservedKeywords.insert("Sub");
  reservedKeywords.insert("Tab");
  reservedKeywords.insert("Text");
  reservedKeywords.insert("Then");
  reservedKeywords.insert("To");
  reservedKeywords.insert("True");
  reservedKeywords.insert("Type");
  reservedKeywords.insert("TypeOf");
  reservedKeywords.insert("UBound");
  reservedKeywords.insert("Unlock");
  reservedKeywords.insert("Until");
  reservedKeywords.insert("Variant");
  reservedKeywords.insert("Base");
  reservedKeywords.insert("Control");
  reservedKeywords.insert("Creatable");
  reservedKeywords.insert("Customizable");
  reservedKeywords.insert("Description");
  reservedKeywords.insert("Exposed");
  reservedKeywords.insert("ExtKEY");
  reservedKeywords.insert("GlobalNameSpace");
  reservedKeywords.insert("HelpID");
  reservedKeywords.insert("InvokeFunction");
  reservedKeywords.insert("InvokeProperty");
  reservedKeywords.insert("InvokePropertyPut");
  reservedKeywords.insert("InvokePropertyPutRef");
  reservedKeywords.insert("MemberFlags");
  reservedKeywords.insert("Name");
  reservedKeywords.insert("PredeclaredId");
  reservedKeywords.insert("ProcData");
  reservedKeywords.insert("TemplateDerived");
  reservedKeywords.insert("UserMemId");
  reservedKeywords.insert("VarDescription");
  reservedKeywords.insert("VarHelpID");
  reservedKeywords.insert("VarMemberFlags");
  reservedKeywords.insert("VarProcData");
  reservedKeywords.insert("VarUserMemId");
  reservedKeywords.insert("Wend");
  reservedKeywords.insert("While");
  reservedKeywords.insert("Width");
  reservedKeywords.insert("With");
  reservedKeywords.insert("WithEvents");
  reservedKeywords.insert("Write");
  reservedKeywords.insert("Xor");
  

  // English month names
  reservedKeywords.insert("january");
  reservedKeywords.insert("february");
  reservedKeywords.insert("march");
  reservedKeywords.insert("april");
  reservedKeywords.insert("may");
  reservedKeywords.insert("june");
  reservedKeywords.insert("july");
  reservedKeywords.insert("august");
  reservedKeywords.insert("september");
  reservedKeywords.insert("october");
  reservedKeywords.insert("november");
  reservedKeywords.insert("december");

  // English month abbreviations
  reservedKeywords.insert("jan");
  reservedKeywords.insert("feb");
  reservedKeywords.insert("mar");
  reservedKeywords.insert("apr");
  reservedKeywords.insert("may");
  reservedKeywords.insert("jun");
  reservedKeywords.insert("jul");
  reservedKeywords.insert("aug");
  reservedKeywords.insert("sep");
  reservedKeywords.insert("oct");
  reservedKeywords.insert("nov");
  reservedKeywords.insert("dec");
}

bool isKeyword(const char* word) {
  return reservedKeywords.isKeyword(word);
}
