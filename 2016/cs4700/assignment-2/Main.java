import java.io.FileReader;

import org.antlr.v4.runtime.*; 
import org.antlr.v4.gui.Trees; 

public class Main{ 
  public static void main(String[] args) throws Exception { 
    ANTLRInputStream input = new ANTLRInputStream(new FileReader(args[0])); 
    // Construct a lexer 
    CalcLexer lexer = new CalcLexer(input); 
    // Obtain the token stream from the lexer 
    CommonTokenStream tokens = new CommonTokenStream(lexer); 
    // Parse the token stream using the parser
    CalcParser parser = new CalcParser(tokens);
    // Start parsing, starting with the `r` rule. 
    Trees.inspect(parser.program(), parser); 
  }
}
