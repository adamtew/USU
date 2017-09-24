import java.io.FileReader;

import org.antlr.v4.runtime.*; 
import org.antlr.v4.gui.Trees; 

public class Main{ 
  public static void main(String[] args) throws Exception { 
    ANTLRInputStream input = new ANTLRInputStream(new FileReader(args[0])); 
    // Construct a lexer 
    HelloLexer lexer = new HelloLexer(input); 
    // Obtain the token stream from the lexer 
    CommonTokenStream tokens = new CommonTokenStream(lexer); 
    // Parse the token stream using the parser
    HelloParser parser = new HelloParser(tokens);
    // Start parsing, starting with the `r` rule. 
    Trees.inspect(parser.r(), parser); 
  }
}
