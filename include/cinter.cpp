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
// Filename: cinter.cpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Tuesday, May 14, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 
// Purpose: Internal C++20 Support

#include <iostream>
#include <string>
#include <cstdio>
#include <ctype.h>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <typeinfo>
#include <functional>

using namespace std;

enum type_of_lex {
    LEX_NULL,                                                                                   /* 0*/
    LEX_AND, LEX_NOT, LEX_OR, LEX_ELSE, LEX_IF, LEX_INT,        /*6*/
    LEX_PROGRAM, LEX_READ, LEX_STRING, LEX_WHILE, LEX_WRITE,  /*11*/
    LEX_FIN,                                                                                    /*12*/
    LEX_LBRACE, LEX_RBRACE, LEX_SEMICOLON, LEX_COMMA, LEX_COLON, LEX_ASSIGN, LEX_LPAREN, LEX_RPAREN, LEX_EQ, LEX_LSS,   /*22*/
    LEX_GTR, LEX_PLUS, LEX_MINUS, LEX_TIMES, LEX_SLASH, LEX_LEQ, LEX_NEQ, LEX_GEQ, LEX_MARK,             /*30*/
    LEX_NUM,
    LEX_STR,
    LEX_BOOL,                                                                                    /*31*/
    LEX_ID,                                                                                     /*32*/
    POLIZ_LABEL,                                                                                /*33*/
    POLIZ_ADDRESS,                                                                              /*34*/
    POLIZ_GO,                                                                                   /*35*/
    POLIZ_FGO                                                                                   /*36*/
};

///////////////////////// Lexer  //////////////////////////
int numberstr = 1;
class Lex {

    string        s_lex;
    int           v_lex;
public:
    type_of_lex  t_lex;
    Lex ( type_of_lex t = LEX_NULL, int v=0, string sss=""): t_lex (t), v_lex (v), s_lex (sss)  { }
    type_of_lex  get_type () const {
    	  return t_lex;
    }
    int get_value () const {
    	  return v_lex;
    }
    string get_value_s () const {
    	  return s_lex;
    }
  friend ostream & operator<< ( ostream &s, Lex l );
  void operator= (Lex lexx)
  {
  	(*this).t_lex=lexx.get_type();
  	(*this).s_lex=lexx.get_value_s();
  	(*this).v_lex=lexx.get_value();
  }
  bool operator ==(Lex lexx) {
    return ((*this).t_lex==lexx.get_type()&& (*this).s_lex==lexx.get_value_s()&&(*this).v_lex==lexx.get_value());
  }



};
///////////////////// Identifiers  ////////////////////////////
class Ident {
    string      name;
    bool        declare;
    type_of_lex type;
    bool        assign;
    int         value;
    string      value_s;
public:
    Ident() {
        declare = false;
        assign  = false;
    }
    bool operator== ( const string& s ) const {
        return name == s;
    }
    Ident ( const string n ) {
        name    = n;
        declare = false;
        assign  = false;
    }
    string get_name () const {
      return name;
    }
    bool get_declare () const {
      return declare;
    }
    void put_declare () {
      declare   = true;
    }
    type_of_lex get_type () const {
      return type;
    }
    void put_type ( type_of_lex t ) {
      type      = t;
    }
    bool get_assign () const {
      return assign;
    }
    void put_assign () {
      assign    = true;
    }
    int  get_value () const {
      return value;
    }
    string  get_value_s () const {
      return value_s;
    }
    void put_value ( int v ) {
      value     = v;
    }
    void put_value ( string sss ) {
      value_s     = sss;
    }
};
//////////////////////  TID  ///////////////////////
vector<Ident> TID;
int put ( const string & buf ) {
    vector<Ident>::iterator k;

    if ( ( k = find ( TID.begin (), TID.end (), buf ) ) != TID.end () )
        return k - TID.begin();
    TID.push_back ( Ident(buf) );
    return TID.size () - 1;
}

vector<Lex> Lexems;

/////////////////////////////////////////////////////////////////

class Scanner {
    FILE * fp;
    char   c;
    int look ( const string buf, const char ** list ) {
        int i = 0;
        while ( list[i] ) {
            if ( buf == list[i] )
                return i;
            ++i;
        }
        return 0;
    }
    void gc () {
        c = fgetc (fp);
    }
public:
    static const char * TW [], * TD [];
    Scanner ( const char *program):
    	fp(fopen ( program, "r" ))
    	{
        if ( !(fp) )
            throw  "can’t open file\0" ;
    }
    Scanner() { }
    Lex get_lex ();
};
const char *
Scanner::TW    [] = { "", "and", "not", "or", "else", "if", "int", "program", "read", "string", "while", "write", NULL };
const char *
Scanner::TD    [] = { "@", "{", "}", ";", ",", ":", "=", "(", ")", "==", "<", ">", "+", "-", "*", "/", "<=", "!=", ">=", "\"", NULL };

Lex Scanner::get_lex () {
    enum    state { H, IDENT, NUMB, COM, ALE, NEQ, STR};
    int     d, j;
    string  buf;
    state   CS = H;
    do {
        gc ();
        switch ( CS ) {
            case H:
                if (c =='\n') numberstr+=1;
                if ( c==' ' || c == '\n' || c== '\r' || c == '\t' );
                    else
                    if (c=='"')
                    {
                    	CS=STR;
                    }
                    else if ( c== '\\') {
                        CS  = COM;
                    }
                    else if ( isalpha (c) ) {
                        buf.push_back (c);
                        CS  = IDENT;
                    }
                    else if ( isdigit (c) ) {
                        d   = c - '0';
                        CS  = NUMB;
                    }
                    else if ( c == '=' || c == '<' || c == '>' ) {
                        buf.push_back (c);
                        CS  = ALE;
                    }
                    else if (c == '@')
                        return Lex ( LEX_FIN);
                    else if (c == '!') {
                        buf.push_back (c);
                        CS  = NEQ;
                    }
                    else {
                        buf.push_back (c);
                        if ( ( j = look ( buf, TD) ) ){
                          Lexems.push_back(Lex ( (type_of_lex)( j + (int) LEX_FIN ), j ));
                            return Lex ( (type_of_lex)( j + (int) LEX_FIN ), j );
                        }
                        else {
                            cout << "string of ERROR "<< numberstr<<"\n";
                            throw c;

                    }}
                    break;
            case IDENT:
                if ( isalpha (c) || isdigit (c) ) {
                    buf.push_back (c);
                    if (buf.size()>25)
                    	cout << "loo long id";
                }
                else {
                    ungetc ( c, fp );
                    if ( (j = look ( buf, TW) ) ) {
                      Lexems.push_back(Lex ( (type_of_lex) j, j ));
                        return Lex ( (type_of_lex) j, j );
                        }
                        else {
                        j   = put ( buf );
                        Lexems.push_back(Lex ( LEX_ID, j ));
                        return Lex ( LEX_ID, j );
                    }
                }
                break;
            case STR:
            if (c =='\n') numberstr+=1;
            	if (c=='"')
            	{Lexems.push_back(Lex(LEX_STR, 0, buf));
            		return Lex(LEX_STR, 0, buf);
            	}
            	buf.push_back(c);
            	break;

              case COM:
              if (c !='*'){
                  cout << "expected * after \\ in "<< numberstr<<"\n";
                  throw "COM ERR";}
                  gc();
                  while(c!='*'&&c!='@'){ if(c=='\n') numberstr+=1;

                   gc();}
                   if ( c=='@') throw "ERROR expected end of com";
                  gc();
                  if (c!='\\'){
                      cout << "expected \\ after * in "<< numberstr<<"\n";
                      throw "COM ERR";}
                      else CS = H;



break;
            case NUMB:
                if ( isdigit (c) ) {
                    d = d * 10 + ( c - '0' );
                }
                else {
                    ungetc ( c, fp );
                    Lexems.push_back(Lex(LEX_STR, 0, buf));
                    return Lex ( LEX_NUM, d );
                }
                break;
            case ALE:
                if ( c == '=' ) {
                    buf.push_back ( c );
                    j   = look ( buf, TD );
                    Lexems.push_back(Lex ( (type_of_lex) ( j + (int) LEX_FIN ), j ));
                    return Lex ( (type_of_lex) ( j + (int) LEX_FIN ), j );
                }
                else {
                    ungetc ( c, fp );
                    j   = look ( buf, TD );
                    Lexems.push_back(Lex ( (type_of_lex) ( j + (int) LEX_FIN ), j ));
                    return Lex ( (type_of_lex) ( j + (int) LEX_FIN ), j );
                }
                break;
            case NEQ:
                if ( c == '=' ) {
                    buf.push_back(c);
                    j   = look ( buf, TD );
                    Lexems.push_back(Lex ( LEX_NEQ, j ));
                    return Lex ( LEX_NEQ, j );
                }
                else{
                    cout << "string of ERROR "<< numberstr<<"\n";
                    throw '!';

                  }

                break;
    } //end switch
  } while (true);
  return Lex();
}
ostream & operator<< ( ostream &s, Lex l ) {
    string t;
    if ( l.t_lex <= LEX_WRITE )
        t = Scanner::TW[l.t_lex];
    else if ( l.t_lex >= LEX_FIN && l.t_lex <= LEX_GEQ )
        t = Scanner::TD[ l.t_lex - LEX_FIN ];
    else if ( l.t_lex == LEX_NUM )
        t = "NUMB";
    else if ( l.t_lex == LEX_ID )
        t = TID[l.v_lex].get_name ();
    else if ( l.t_lex == POLIZ_LABEL )
        t = "Label";
    else if ( l.t_lex == POLIZ_ADDRESS )
        t = "Addr";
    else if ( l.t_lex == POLIZ_GO )
        t = "!";
    else if ( l.t_lex == POLIZ_FGO )
        t = "!F";
    else if (l.t_lex==LEX_STR)
    	t="STR";
    else{
      cout << "string of ERROR "<< numberstr<<"\n";
        throw l;
    }
    s << '(' << t << ',' << l.v_lex << ");"<<l.t_lex << endl;
    return s;
  }

////////////////////////// Parser  /////////////////////////////////
template <class T, class T_EL>
void popstack( T & st, T_EL & i ) {
    i = st.top(); st.pop();
}

class Parser {
    Lex          curr_lex;
    type_of_lex  c_type;
    int          c_val;
    string s_val;
    Scanner      scan;
    stack < int >           st_int;
    stack < type_of_lex >   st_lex;

    void  P();
    void  D1();
    void  D(type_of_lex);
    void  B();
    void  S();
    void  E();
    void  E1();
    void  T();
    void  F();
    void  dec ( type_of_lex type);
    void  check_id ();
    void  check_op ();
    void  check_not ();
    void  eq_type ();
    void  eq_bool ();
    void  check_id_in_read ();
    void  gl () {
        curr_lex  = scan.get_lex ();
        c_type    = curr_lex.get_type ();
        s_val=curr_lex.get_value_s();
        c_val     = curr_lex.get_value ();
    }
public:
    vector <Lex> poliz;
    Parser ( const char *program ):
    scan (program)
    { }
    void  analyze();
};
void Parser::analyze () {
    gl ();
    P ();
    /*if (c_type != LEX_FIN)
        throw curr_lex; */
    //for_each( poliz.begin(), poliz.end(), [](Lex l){ cout << l; });
//    for ( Lex l : poliz )
//        cout << l;
    cout << endl << "Correct" << endl;
}
void Parser::P () {
    if ( c_type == LEX_PROGRAM ) {
       gl ();
    }
    else{
        throw curr_lex;
        cout << "string of ERROR "<< numberstr<<"\n";
    }B ();
}
void Parser::D (type_of_lex type) {
    if ( c_type != LEX_ID ){
      cout << "string of ERROR "<< numberstr<<"\n";
        throw curr_lex;
        }
    else {
        st_int.push ( c_val );
        int i=c_val;
        gl ();
        if ( c_type == LEX_ASSIGN )
        {
			gl();
    		if ((type==LEX_INT)&&(c_type!=LEX_NUM)){
cout << "string of ERROR "<< numberstr<<"\n";
          throw curr_lex;}
    		if ((type==LEX_STRING)&&(c_type!=LEX_STR)){
          cout << "string of ERROR "<< numberstr<<"\n";
    			throw curr_lex;}
    		if (type==LEX_INT)
    		{
    			TID[i].put_value (c_val);
    			TID[i].put_assign();
    		}
    		else
    		{
    			TID[i].put_value (s_val);
    			TID[i].put_assign();
    		}
    		gl();
    	}
        while ( c_type == LEX_COMMA )
        {
            gl ();
            if ( c_type != LEX_ID ){
              cout << "string of ERROR "<< numberstr<<"\n";
                throw curr_lex;}
            else {
                st_int.push ( c_val );
                int j=c_val;
                gl ();
                if ( c_type == LEX_ASSIGN )
				{
					gl();
					if ((type==LEX_INT)&&(c_type!=LEX_NUM)){
    					throw curr_lex;
              cout << "string of ERROR "<< numberstr<<"\n";}
    				if ((type==LEX_STRING)&&(c_type!=LEX_STR)){
              cout << "string of ERROR "<< numberstr<<"\n";
    					throw curr_lex;}
					if (type==LEX_INT)
					{
						TID[j].put_value (c_val);
						TID[j].put_assign();
					}
					else
					{
						TID[j].put_value(s_val);
						TID[j].put_assign();
					}
					gl();
				}
            }
        }
        if ( c_type != LEX_SEMICOLON )
        {cout << "string of ERROR "<< numberstr<<"\n";
            throw curr_lex;}
        else {
            if ( type==LEX_INT ) {
                dec ( LEX_INT );
                //gl ();
            }
            else
                if ( type == LEX_STRING ) {
                    dec ( LEX_STRING );
                    //gl ();
                }
                else{cout << "string of ERROR "<< numberstr<<"\n";
                    throw curr_lex;}
        }
    }
}
void Parser::B (){
	if ( c_type == LEX_LBRACE )
	{
		gl ();
		S ();
		while ( c_type == LEX_SEMICOLON ) {
			gl ();
			S ();
		}
	}
	else
		throw curr_lex;
	if ( c_type != LEX_RBRACE ){
  cout << "string of ERROR "<< numberstr<<"\n";
	    throw curr_lex;}
}
void Parser::S () {
    int pl0, pl1, pl2, pl3;
    if (c_type == LEX_INT)
	{
		gl();
		D(LEX_INT);
	}
	if (c_type==LEX_STRING)
	{
		gl();
		D(LEX_STRING);
	}
    if ( c_type == LEX_IF ) {
        gl ();
        if (c_type==LEX_LPAREN)
        {
        	gl();
        	E ();
        }
        else
        {cout << "string of ERROR "<< numberstr<<"\n";
        	throw curr_lex;}
        eq_bool ();
        if (c_type!=LEX_RPAREN)
        {cout << "string of ERROR "<< numberstr<<"\n";
        	throw curr_lex;}
        else
        	gl();
        pl2 = poliz.size();
        poliz.push_back ( Lex() );
        poliz.push_back ( Lex(POLIZ_FGO) );
        if ( c_type == LEX_LBRACE )
        	B();
        else
        {
        	S ();
	}
	pl3 = poliz.size ();
	poliz.push_back ( Lex () );
	poliz.push_back ( Lex ( POLIZ_GO ) );
	poliz[pl2] = Lex ( POLIZ_LABEL, poliz.size() );
        gl();
        if ( c_type == LEX_ELSE ) {
        	gl();
               if ( c_type == LEX_LBRACE )
			B();
		else
		{
			S ();
		}
            }
            /*else
                throw curr_lex; */
        poliz[pl3] = Lex ( POLIZ_LABEL, poliz.size() );

	S();
    }//end if
    	else if ( c_type == LEX_WHILE ) {
        pl0 = poliz.size ();
        gl ();
        E ();
        eq_bool ();
        pl1 = poliz.size ();
        poliz.push_back ( Lex () );
        poliz.push_back ( Lex (POLIZ_FGO) );
        /* if ( c_type == LEX_DO ) {
            gl();
            S(); */
            //poliz.push_back ( Lex ( POLIZ_LABEL, pl0 ) );
            //poliz.push_back ( Lex ( POLIZ_GO) );
            //poliz[pl1] = Lex ( POLIZ_LABEL, poliz.size() );


	if ( c_type == LEX_LBRACE )
        	B();
	else
	{
		S ();
	}
	gl();
	poliz.push_back ( Lex ( POLIZ_LABEL, pl0 ) );
        poliz.push_back ( Lex ( POLIZ_GO) );
        poliz[pl1] = Lex ( POLIZ_LABEL, poliz.size() );
        cout << "in while " << curr_lex;
        S();
        }
        /*else
            throw curr_lex; */
        //end while
        else if ( c_type == LEX_READ ) {
            gl ();
            if ( c_type == LEX_LPAREN ) {
                gl ();
                if ( c_type == LEX_ID ) {
                    check_id_in_read ();
                    poliz.push_back ( Lex( POLIZ_ADDRESS, c_val) );
                    gl();
                }
                else{cout << "string of ERROR "<< numberstr<<"\n";
                    throw curr_lex;}
                if ( c_type == LEX_RPAREN ) {
                    gl ();
                    poliz.push_back ( Lex (LEX_READ) );
                }
                else{cout << "string of ERROR "<< numberstr<<"\n";
                    throw curr_lex;}
            }
            else {cout << "string of ERROR "<< numberstr<<"\n";
                throw curr_lex;}
        }//end read
        else if ( c_type == LEX_WRITE ) {
            gl ();
            if ( c_type == LEX_LPAREN ) {
                gl ();
                cout << "in write " << curr_lex;
                E ();
                while (c_type==LEX_COMMA)
                {
                	poliz.push_back ( Lex ( LEX_WRITE ) );
                	gl();
                	E();
                }
                if ( c_type == LEX_RPAREN ) {
                    gl ();
                    poliz.push_back ( Lex ( LEX_WRITE ) );
                }
                else{cout << "string of ERROR "<< numberstr<<"\n";
                    throw curr_lex;}
            }
            else{cout << "string of ERROR "<< numberstr<<"\n";
                throw curr_lex;}
        }//end write */
        else if ( c_type == LEX_ID ) {
            check_id ();
            poliz.push_back (Lex ( POLIZ_ADDRESS, c_val ) );
            gl();
            if ( c_type == LEX_ASSIGN ) {
                gl ();
                E ();
                eq_type ();
                poliz.push_back ( Lex ( LEX_ASSIGN ) );
            }
            else{cout << "string of ERROR "<< numberstr<<"\n";
                throw curr_lex;}
        }//assign-end
        //else
            //B();
       //B();
}
void Parser::E () {
	/*if (c_type!=LEX_LPAREN)
		throw curr_lex;
	gl(); */
    E1 ();
    if ( c_type == LEX_EQ  || c_type == LEX_LSS || c_type == LEX_GTR ||
         c_type == LEX_LEQ || c_type == LEX_GEQ || c_type == LEX_NEQ ) {
        st_lex.push ( c_type );
        gl ();
        E1 ();
        check_op ();
    }
    /*if (c_type!=LEX_RPAREN)
		throw curr_lex;
	gl(); */
}
void Parser::E1 () {
    T ();
    while ( c_type == LEX_PLUS || c_type == LEX_MINUS || c_type==LEX_OR) {
        st_lex.push ( c_type );
        gl ();
        T ();
        check_op ();
    }
}
void Parser::T () {
    F ();
    while ( c_type == LEX_TIMES || c_type == LEX_SLASH || c_type==LEX_AND) {
        st_lex.push ( c_type );
        gl ();
        F ();
        check_op ();
    }
}
void Parser::F () {
    if ( c_type == LEX_ID ) {
        check_id ();
        poliz.push_back ( Lex ( LEX_ID, c_val ) );
        gl ();
    }
    else if ( c_type == LEX_NUM ) {
        st_lex.push ( LEX_INT );
        poliz.push_back ( curr_lex );
        gl ();
    }
    /*else if ( c_type == LEX_TRUE ) {
        st_lex.push ( LEX_BOOL );
        poliz.push_back ( Lex (LEX_TRUE, 1) );
        gl ();
    }
    else if ( c_type == LEX_FALSE) {
        st_lex.push ( LEX_BOOL );
        poliz.push_back ( Lex (LEX_FALSE, 0) );
        gl ();
    } */
    else if ( c_type == LEX_STR ) {
        st_lex.push ( LEX_STRING );
        poliz.push_back ( curr_lex );
        gl ();
    }
    else if ( c_type == LEX_NOT ) {
        gl ();
        F ();
        check_not ();
    }
    else if ( c_type == LEX_LPAREN ) {
        gl ();
        E ();
        if ( c_type == LEX_RPAREN)
            gl ();
        else
            throw curr_lex;
    }
    else
        throw curr_lex;
}

////////////////////////////////////////////////////////////////

void Parser::dec ( type_of_lex type ) {
    int i;
    while ( !st_int.empty () ) {
        popstack( st_int, i );
        if ( TID[i].get_declare () )
        {cout << "string of ERROR "<< numberstr<<"\n";
            throw "twice";}
        else {
            TID[i].put_declare ();
            TID[i].put_type ( type );
        }
    }
}
void Parser::check_id () {
    if ( TID[c_val].get_declare() )
    {
        st_lex.push ( TID[c_val].get_type () );
    }
    else{cout << "string of ERROR "<< numberstr<<"\n";
        throw "not declared";}
}
void Parser::check_op () {
    type_of_lex t1, t2, op, t = LEX_INT, r = LEX_BOOL;

    popstack ( st_lex, t2 );
    popstack ( st_lex, op );
    popstack ( st_lex, t1 );

    if (op == LEX_MINUS || op == LEX_TIMES || op == LEX_SLASH )
        r = LEX_INT;
    if (op == LEX_PLUS)
    	if (t1==LEX_STRING)
    	{
    		r=LEX_STRING;
    		t=LEX_STRING;
    	}
    	else
    		r=LEX_INT;
    if ( op == LEX_OR || op == LEX_AND )
        t = LEX_BOOL;
    if (op == LEX_EQ  || op == LEX_LSS || op == LEX_GTR || op==LEX_NEQ)
    	if (t1==LEX_STRING)
    		t=LEX_STRING;
    if ( t1 == t2  &&  t1 == t )
        st_lex.push (r);
    else{cout << "string of ERROR "<< numberstr<<"\n";
    	throw "wrong types are in operation";}
    poliz.push_back (Lex (op) );
}
void Parser::check_not () {
    if (st_lex.top() != LEX_BOOL){cout << "string of ERROR "<< numberstr<<"\n";
        throw "wrong type is in not";}
    else
        poliz.push_back ( Lex (LEX_NOT) );
}
void Parser::eq_type () {
    type_of_lex t;
    popstack( st_lex, t );
    if ( t != st_lex.top () ){cout << "string of ERROR "<< numberstr<<"\n";
        throw "wrong types are in :=";}
    st_lex.pop();
}
void Parser::eq_bool () {
    if ( st_lex.top () != LEX_BOOL ){cout << "string of ERROR "<< numberstr<<"\n";
        throw "expression is not boolean";}
    st_lex.pop ();
  }
void Parser::check_id_in_read () {
    if ( !TID [c_val].get_declare() ){
      cout << "string of ERROR "<< numberstr<<"\n";

        throw "not declared";}
}

////////////////////////////////////////////////////////////////

class Executer {
public:

    void execute ( vector<Lex> & poliz );

};

void Executer::execute ( vector<Lex> & poliz ) {
  for (auto it: poliz ){
    cout<<it<<' ';
  }

    Lex pc_el;
    stack <Lex> arglex;
    string stt;
    int isstr=0;
    Lex i, j;
    int index = 0, size = poliz.size();
    cout << "Size of poliz: " << size << endl;
    while ( index < size ) {
        pc_el = poliz [ index ];
        switch ( pc_el.get_type () ) {
            case POLIZ_ADDRESS: case POLIZ_LABEL:
                arglex.push ( pc_el );
                break;
            case LEX_NUM:
                arglex.push( Lex(LEX_INT, pc_el.get_value()));
                break;

            case LEX_STR:
                arglex.push ( Lex(LEX_STRING, 0, pc_el.get_value_s()));
                break;

            case LEX_ID:
            	//if (pc_el.get_type()==LEX_INT)
            	//{
            		int p;
				    p = pc_el.get_value ();
				    if ( TID[p].get_assign () ) {
				    	arglex.push ( Lex(TID[p].get_type(), TID[p].get_value(), TID[p].get_value_s() ));
				      break;
				    }
				    else
				      throw "POLIZ: indefinite identifier";
				//}
				/*else
				{
					isstr=1;
					i = pc_el.get_value ();
				    if ( TID[i].get_assign () ) {
				      argss.push ( TID[i].get_value_s () );
				      break;
				    }
				    else
				      throw "POLIZ: indefinite identifier";
				} */

            case LEX_NOT:
                popstack ( arglex, i);
                arglex.push( Lex(LEX_INT, !(i.get_value())) );
                break;

            case LEX_OR:
              popstack( arglex, i);
                popstack ( arglex, j);
                arglex.push ( Lex(LEX_INT, j.get_value() || i.get_value()) );
                break;

            case LEX_AND:
                  popstack ( arglex, i );
                  popstack( arglex, j );
                arglex.push ( Lex(LEX_INT, j.get_value() && i.get_value()) );
                break;

            case POLIZ_GO:
                  popstack ( arglex, i );
                index = i.get_value() - 1;
                break;

            case POLIZ_FGO:
                  popstack ( arglex, i );
                  popstack( arglex, j );
                if ( !(j.get_value()) ) index = i.get_value() - 1;
                break;

            case LEX_WRITE:
                  popstack ( arglex, j );
                if (j.get_type()==LEX_INT)
                	cout << j.get_value() << endl;
                else
                	cout << j.get_value_s() << endl;
                break;

            case LEX_READ:
                int k;
                  popstack ( arglex, i );
                if ( TID[i.get_value()].get_type () == LEX_INT ) {
                    cout << "Input int value for " << TID[i.get_value()].get_name () << endl;
                    cin >> k;
                    TID[i.get_value()].put_value (k);
                	TID[i.get_value()].put_assign ();
                }
                else {
                    while (1) {
                        cout << "Input string value for " << TID[i.get_value()].get_name() << endl;
                        cin >> stt;
                        /*if ( j != "true" && j != "false" ) {
                            cout << "Error in input:true/false" << endl;
                            continue;
                        } */
                        //k = ( j == "true" ) ? 1 : 0;
                        break;
                    }
                    TID[i.get_value()].put_value (stt);
                	TID[i.get_value()].put_assign ();
                }
                break;

            case LEX_PLUS:
                  popstack ( arglex, i );
                  popstack ( arglex, j );
                if (i.get_type()==LEX_INT)
                	arglex.push ( Lex(LEX_INT, i.get_value() + j.get_value()) );
                else
                	arglex.push ( Lex(LEX_STRING, 0, j.get_value_s() + i.get_value_s()) );
                break;

            case LEX_TIMES:
                  popstack ( arglex, i );
                  popstack( arglex, j );
                arglex.push ( Lex(LEX_INT, i.get_value() * j.get_value()) );
                break;

            case LEX_MINUS:
                  popstack ( arglex, i );
                  popstack ( arglex, j );
                arglex.push ( Lex(LEX_INT, j.get_value() - i.get_value()) );
                break;

            case LEX_SLASH:
               popstack ( arglex, i );
                  popstack ( arglex, j );
                if (i.get_value()!=0) {
                    arglex.push ( Lex(LEX_INT, j.get_value() / i.get_value()) );
                    break;
                }
                else
                    throw "POLIZ:divide by zero";

            case LEX_EQ:
                  popstack ( arglex, i );
                  popstack ( arglex, j );
                if (i.get_type()==LEX_INT)
                	arglex.push ( Lex(LEX_INT, i.get_value() == j.get_value()) );
                else
                	arglex.push ( Lex(LEX_INT, i.get_value_s() == j.get_value_s()) );
                break;

            case LEX_LSS:
                  popstack ( arglex, i );
                popstack ( arglex, j );
                if (i.get_type()==LEX_INT)
                	arglex.push ( Lex(LEX_INT, j.get_value() < i.get_value()) );
                else
                	arglex.push ( Lex(LEX_INT, j.get_value_s() < i.get_value_s()) );
                break;

            case LEX_GTR:
                  popstack ( arglex, i );
                  popstack ( arglex, j );
                if (i.get_type()==LEX_INT)
                	arglex.push ( Lex(LEX_INT, j.get_value() > i.get_value()) );
                else
                	arglex.push ( Lex(LEX_INT, j.get_value_s() > i.get_value_s()) );
                break;

            case LEX_LEQ:
                  popstack ( arglex, i );
                  popstack ( arglex, j );
                arglex.push ( Lex(LEX_INT, j.get_value() <= i.get_value()) );
                break;

            case LEX_GEQ:
                popstack ( arglex, i );
                popstack ( arglex, j );
                arglex.push ( Lex(LEX_INT, j.get_value() >= i.get_value()) );
                break;

            case LEX_NEQ:
                popstack ( arglex, i );
                popstack ( arglex, j );
                if (i.get_type()==LEX_INT)
                	arglex.push ( Lex(LEX_INT, j.get_value() != i.get_value()) );
                else
                	arglex.push ( Lex(LEX_INT, j.get_value_s() != i.get_value_s()) );
                break;

            case LEX_ASSIGN:
                popstack ( arglex, i );
                popstack ( arglex, j );
                if (i.get_type()==LEX_INT)
                {
                	TID[j.get_value()].put_value (i.get_value());
                	TID[j.get_value()].put_assign ();
                }
                else
                {
                	TID[j.get_value()].put_value (i.get_value_s());
                	TID[j.get_value()].put_assign ();
                }
                break;

            default:
                throw "POLIZ: unexpected elem";
        }//end of switch
        ++index;
    };//end of while
    cout << "Finish of executing!!!" << endl;
}

class Interpretator1 {
    Parser   pars;
    Executer E;
Executer B;
public:
    Interpretator1 ( const char* program ):
    pars (program)
    {}
    void     interpretation1 ();

};
class Interpretator2{
    Parser   pars;
    Executer E;
Executer B;
public:
    Interpretator2 ( const char* program ):
    pars (program)
    {}
    void     interpretation2 ();

};

void Interpretator2::interpretation2 () {
	pars.analyze ();

vector<Lex> Lexems3 = pars.poliz ;

for (auto &it:Lexems3){
 if (it.t_lex == 25) { it.t_lex = (type_of_lex )24;
  }
 else
 if (it.t_lex == 24) it.t_lex = (type_of_lex ) 25  ;
}
 E.execute (Lexems3   );


}
void Interpretator1::interpretation1 () {
	pars.analyze ();

vector<Lex> Lexems3 = pars.poliz ;
 E.execute (Lexems3   );


}

int main () {
    try {
        Interpretator1 I ( "text.txt" );
        I.interpretation1 ();
        FILE* f=fopen("text.txt","r");
rewind(f);
/*Interpretator2 B ("text.txt");
B.interpretation2 ();
*/

vector<Lex> Lexems2;

        for (auto it:Lexems){
          if (find(Lexems2.begin(),Lexems2.end(),it)==Lexems2.end()) Lexems2.push_back(it);
        }
 cout<< Lexems2.size()<<"\n" ;

      //  unordered_set<Lex> set_lex(Lexems.begin(), Lexems.end());
        //int x >
      //  cout<< set_lex.size()<<"\n" ;
        return 0;
    }
    catch ( char c ) {
        cout << "unexpected symbol " << c << endl;
        return 1;
    }
    catch ( Lex l ) {
        cout << "unexpected lexeme" << l << endl;
        return 2;
    }
    catch ( const char *source ) {
        cout << source << endl;
        return 3;
    }
}
