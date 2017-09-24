// Generated from Calc.g4 by ANTLR 4.5.3
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link CalcParser}.
 */
public interface CalcListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link CalcParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(CalcParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalcParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(CalcParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalcParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration(CalcParser.DeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalcParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration(CalcParser.DeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalcParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(CalcParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalcParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(CalcParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalcParser#lvalue}.
	 * @param ctx the parse tree
	 */
	void enterLvalue(CalcParser.LvalueContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalcParser#lvalue}.
	 * @param ctx the parse tree
	 */
	void exitLvalue(CalcParser.LvalueContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalcParser#rvalue}.
	 * @param ctx the parse tree
	 */
	void enterRvalue(CalcParser.RvalueContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalcParser#rvalue}.
	 * @param ctx the parse tree
	 */
	void exitRvalue(CalcParser.RvalueContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalcParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(CalcParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalcParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(CalcParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalcParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(CalcParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalcParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(CalcParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalcParser#term}.
	 * @param ctx the parse tree
	 */
	void enterTerm(CalcParser.TermContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalcParser#term}.
	 * @param ctx the parse tree
	 */
	void exitTerm(CalcParser.TermContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalcParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactor(CalcParser.FactorContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalcParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactor(CalcParser.FactorContext ctx);
}