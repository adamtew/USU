grammar CSV; 
// must be stored in a file called CSV.g4 
r: INT (',' INT)*; 

INT : '0'..'9'+ ; 
WS : (' '|'\n'|'\t'|'\r')+ {skip();} ; 
