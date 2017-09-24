grammar Calc;

/*------------------------------------------------------------------
 * PARSER RULES
 *------------------------------------------------------------------*/
program : (declaration | assignment | expr)+;
declaration:  type IDENTIFIER;
assignment : lvalue ASSIGN rvalue;
lvalue : IDENTIFIER;
rvalue : expr;
type : INTEGER;
expr : term ( ( PLUS | MINUS ) term )* ;
term : factor ( ( MULT | DIV ) factor )* ;
factor : NUMBER | IDENTIFIER| '(' expr ')'  ;

/*------------------------------------------------------------------
 * LEXER RULES
 *------------------------------------------------------------------*/
PLUS : '+';
MINUS : '-';
MULT : '*';
DIV : '/';
ASSIGN : '=';
INTEGER : 'integer' ;

IDENTIFIER : LETTER (LETTER | DIGIT)* ;

NUMBER : (DIGIT)+ ;

WHITESPACE : [ \r\n\t';'] + -> channel (HIDDEN);

DIGIT : '0'..'9';

LETTER : LOWER | UPPER ;

LOWER : ('a'..'z') ;
UPPER : ('A'..'Z') ;
