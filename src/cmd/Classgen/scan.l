%{
#include "Classgen.h"
#include "gram.tab.h"

int depth = 0;
%}

%option reentrant
%option noyywrap
%option stack
%option yylineno
%option extra-type = "Classgen *"

%{

#define RVAL yyextra->lexResult

#define YY_USER_INIT \
    yyextra->last_line = 0; \
    yyextra->last_col = 0;

#define YY_USER_ACTION \
    yyextra->first_line = yyextra->last_line; \
    yyextra->first_col = yyextra->last_col; \
    \
    for(int i = 0; yytext[i] != '\0'; i++) \
    { \
        if(yytext[i] == '\n') \
        { \
            yyextra->last_line++; \
            yyextra->last_col = 0; \
        } \
        else \
            yyextra->last_col++; \
    }
%}

DECIMAL_INTEGER [1-9][0-9]*
ST   ([a-zA-Z\x80-\xf3])*
SYM  [^ \t\v\n\r\f:/.\(\)/+-/*//;.{@<>]
NL \n

 /* shuts up codelite */

KEYW {ST}({SYM}{ST}|{ST}?)+":"
SYML {ST}({SYM}{ST}|{ST}?)+

/* Type. */
%x T
/* Multi-line comment. */
%x MLC
/* C code. */
%x CC

%%

[ \t\r\n]+

"/*"            { BEGIN(MLC); }
<MLC>"*/"       { BEGIN(INITIAL); }
<MLC>\n
<MLC>.

"<"             { BEGIN(T); RVAL = new std::string; depth = 1; }
<T>"<"          { depth++; RVAL->append(yytext); }
<T>">"          {
    if (--depth == 0)
    {
        BEGIN(INITIAL);
        return TK_TYPE;
    }
    else RVAL->append(yytext);
}
<T>.            { RVAL->append(yytext); }

"{"             { BEGIN(CC); RVAL = new std::string; depth = 1; }
<CC>"{"         { depth++; RVAL->append(yytext); }
<CC>"}"         {
    if (--depth == 0)
    {
        BEGIN(INITIAL);
        return TK_C_CODE;
    }
    else RVAL->append(yytext);
}
<CC>\n         { RVAL->append(yytext); }
<CC>.          { RVAL->append(yytext); }

"("             return TK_BRACKET_OPEN;
")"             return TK_BRACKET_CLOSE;
":"             return TK_COLON;
";"             return TK_SEMICOLON;
","             return TK_COMMA;
"constructor"   return TK_CONSTRUCTOR;
"class"         return TK_CLASS;
"end"           return TK_END;
"desc_intf_requires"   return TK_DESC_INTF_REQUIRES;
"desc_impl_requires"   return TK_DESC_IMPL_REQUIRES;
"klass_intf_requires"   return TK_KLASS_INTF_REQUIRES;
"klass_impl_requires"   return TK_KLASS_IMPL_REQUIRES;

{SYML} {
           RVAL = new std::string(yytext);
           return TK_SYM;
       }