import java.io.FileReader;

import org.antlr.v4.runtime.*; 
import org.antlr.v4.gui.Trees; 

public class Main{ 
  public static void main(String[] args) throws Exception { 
    ANTLRInputStream input = new ANTLRInputStream(new FileReader(args[0])); 
    // Construct a lexer 
    CSVLexer lexer = new CSVLexer(input); 
    // Obtain the token stream from the lexer 
    CommonTokenStream tokens = new CommonTokenStream(lexer); 
    // Parse the token stream using the parser
    CSVParser parser = new CSVParser(tokens);
    // Start parsing, starting with the `r` rule. 
    Trees.inspect(parser.r(), parser); 
  }
}
