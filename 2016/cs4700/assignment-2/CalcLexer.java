// Generated from Calc.g4 by ANTLR 4.5.3
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class CalcLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.5.3", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, PLUS=3, MINUS=4, MULT=5, DIV=6, ASSIGN=7, INTEGER=8, IDENTIFIER=9, 
		NUMBER=10, WHITESPACE=11, DIGIT=12, LETTER=13, LOWER=14, UPPER=15;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "PLUS", "MINUS", "MULT", "DIV", "ASSIGN", "INTEGER", "IDENTIFIER", 
		"NUMBER", "WHITESPACE", "DIGIT", "LETTER", "LOWER", "UPPER"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'('", "')'", "'+'", "'-'", "'*'", "'/'", "'='", "'integer'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, "PLUS", "MINUS", "MULT", "DIV", "ASSIGN", "INTEGER", 
		"IDENTIFIER", "NUMBER", "WHITESPACE", "DIGIT", "LETTER", "LOWER", "UPPER"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public CalcLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Calc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\21U\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\3\2\3\2\3\3\3\3\3\4"+
		"\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3"+
		"\n\3\n\3\n\7\n;\n\n\f\n\16\n>\13\n\3\13\6\13A\n\13\r\13\16\13B\3\f\6\f"+
		"F\n\f\r\f\16\fG\3\f\3\f\3\r\3\r\3\16\3\16\5\16P\n\16\3\17\3\17\3\20\3"+
		"\20\2\2\21\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33"+
		"\17\35\20\37\21\3\2\3\7\2\13\f\17\17\"\"))==Y\2\3\3\2\2\2\2\5\3\2\2\2"+
		"\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3"+
		"\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2"+
		"\2\2\35\3\2\2\2\2\37\3\2\2\2\3!\3\2\2\2\5#\3\2\2\2\7%\3\2\2\2\t\'\3\2"+
		"\2\2\13)\3\2\2\2\r+\3\2\2\2\17-\3\2\2\2\21/\3\2\2\2\23\67\3\2\2\2\25@"+
		"\3\2\2\2\27E\3\2\2\2\31K\3\2\2\2\33O\3\2\2\2\35Q\3\2\2\2\37S\3\2\2\2!"+
		"\"\7*\2\2\"\4\3\2\2\2#$\7+\2\2$\6\3\2\2\2%&\7-\2\2&\b\3\2\2\2\'(\7/\2"+
		"\2(\n\3\2\2\2)*\7,\2\2*\f\3\2\2\2+,\7\61\2\2,\16\3\2\2\2-.\7?\2\2.\20"+
		"\3\2\2\2/\60\7k\2\2\60\61\7p\2\2\61\62\7v\2\2\62\63\7g\2\2\63\64\7i\2"+
		"\2\64\65\7g\2\2\65\66\7t\2\2\66\22\3\2\2\2\67<\5\33\16\28;\5\33\16\29"+
		";\5\31\r\2:8\3\2\2\2:9\3\2\2\2;>\3\2\2\2<:\3\2\2\2<=\3\2\2\2=\24\3\2\2"+
		"\2><\3\2\2\2?A\5\31\r\2@?\3\2\2\2AB\3\2\2\2B@\3\2\2\2BC\3\2\2\2C\26\3"+
		"\2\2\2DF\t\2\2\2ED\3\2\2\2FG\3\2\2\2GE\3\2\2\2GH\3\2\2\2HI\3\2\2\2IJ\b"+
		"\f\2\2J\30\3\2\2\2KL\4\62;\2L\32\3\2\2\2MP\5\35\17\2NP\5\37\20\2OM\3\2"+
		"\2\2ON\3\2\2\2P\34\3\2\2\2QR\4c|\2R\36\3\2\2\2ST\4C\\\2T \3\2\2\2\b\2"+
		":<BGO\3\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}