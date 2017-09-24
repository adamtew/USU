grammar CSV; 
// must be stored in a file called CSV.g4 

// Syntax rules
r: INT (',' INT)*; 

//Lexical rules
INT : '0'..'9'+ ; 
WS : (' '|'\n'|'\t'|'\r')+ {skip();} ; 

// eg 1 + 2 * 3 / 4 - 5
// operators are terminal - (+ | - | * | /)
// expressions
// <expr> -> <term> + <term>
//          | <term> - <term>
//          | <term> * <term>
//          | <term> / <term>
// <expr> -> <term><OP><expr>
//          | <term>
// ### EBNF
// <expr> -> <term>((+, -, *, /)<term>)+
// <term>

// Calculator grammar
grammar Calc;

expr: term (( PLUS | MINUS | MULT | DIV ) term )* ;
term : NUMBER ;

PLUS : '+';
MINUS : '-';
MULT : '*';
DIV : '/';

NUMBER : (DIGIT)+;

WHITESPACE : [ \r\n\t] + -> channel (HIDDEN);

DIGIT : '0'..'9';