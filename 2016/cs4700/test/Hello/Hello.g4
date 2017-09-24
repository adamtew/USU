// Hello.g4 file 
grammar Hello; 
r: 'hello' ID;
// match hello followed by an ID 
ID: [a-z]+; 
// match lower-case identifiers 
WS: [ \t\r\n]+ -> skip; 
