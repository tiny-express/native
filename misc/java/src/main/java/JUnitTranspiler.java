import com.github.javaparser.JavaParser;
import com.github.javaparser.ast.CompilationUnit;
import com.github.javaparser.ast.NodeList;
import com.github.javaparser.ast.body.MethodDeclaration;
import com.github.javaparser.ast.body.VariableDeclarator;
import com.github.javaparser.ast.expr.AssignExpr;
import com.github.javaparser.ast.expr.Expression;
import com.github.javaparser.ast.expr.VariableDeclarationExpr;
import com.github.javaparser.ast.stmt.BlockStmt;
import com.github.javaparser.ast.stmt.ExpressionStmt;
import com.github.javaparser.ast.stmt.ForStmt;
import com.github.javaparser.ast.stmt.Statement;
import com.github.javaparser.ast.visitor.VoidVisitorAdapter;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Optional;

public class JUnitTranspiler {
    private static class Converter extends VoidVisitorAdapter<Void> {
        private PrintWriter writer;

        public Converter(PrintWriter w) {
            writer = w;
        }

        @Override
        public void visit(MethodDeclaration n, Void arg) {
            Optional<BlockStmt> block = n.getBody();
            BlockStmtHandler(block.orElse(null));
            super.visit(n, arg);
        }

        private void BlockStmtHandler(BlockStmt blockStmt) {
            if (blockStmt == null) {
                return;
            }

            for (Statement statement : blockStmt.getStatements()) {
                switch (statement.getMetaModel().getTypeName()) {
                    case "BlockStmt":
                        BlockStmtHandler(statement.asBlockStmt());
                        break;
                    case "DoStmt":
                        break;
                    case "ExpressionStmt":
                        ExpressionStmtHandler(statement.asExpressionStmt());

                        // write ';'
                        writer.println(";");
                        break;
                    case "ForeachStmt":
                        break;
                    case "ForStmt":
                        ForStmtHandler(statement.asForStmt());
                        break;
                    case "SwitchStmt":
                        /*
                        SwitchEntryStmt
                         */
                        break;
                    case "TryStmt":
                        /*
                        CatchClause
                        ThrowStmt
                         */
                        break;
                    case "WhileStmt":
                        break;
                    default:
                        /*
                        AssertStmt
                        BreakStmt
                        ContinueStmt
                        ReturnStmt
                         */
                        break;
                }
            }
        }

        private void ExpressionStmtHandler(ExpressionStmt expressionStmt) {
            if (expressionStmt == null) {
                return;
            }

            ExpressionHandler(expressionStmt.getExpression());
        }

        private void ForStmtHandler(ForStmt forStmt) {
            if (forStmt == null) {
                return;
            }

            // write 'for' keyword
            writer.print("for ");

            // write '('
            writer.print("(");

            // extract initializer of forstatement
            NodeList<Expression> inits = forStmt.getInitialization();
            for (int i = 0; i < inits.size(); i++) {
                // write expression
                ExpressionHandler(inits.get(i));

                // write ','
                if (i < inits.size() - 1) {
                    writer.print(", ");
                }
            }

            // write ';'
            writer.print("; ");

            // extract compare expression
            ExpressionHandler(forStmt.getCompare().orElse(null));
            // write ';'
            writer.print("; ");

            // extract update
            NodeList<Expression> updates = forStmt.getUpdate();
            for (int i = 0; i < updates.size(); i++) {
                // write expression
                ExpressionHandler(updates.get(i));

                // write ','
                if (i < updates.size() - 1) {
                    writer.print(", ");
                }
            }

            // write ')'
            writer.print(") ");

            // write '{'
            writer.println("{");

            // extract body
            BlockStmtHandler(forStmt.getBody().asBlockStmt());

            // write '}'
            writer.println();
            writer.println("}");
        }

        private void ExpressionHandler(Expression expression) {
            if (expression == null) {
                return;
            }

            switch (expression.getMetaModel().getTypeName()) {
                case "ArrayCreationExpr":
                    break;
                case "NullLiteralExpr":
                    break;
                case "ObjectCreationExpr":
                    break;
                case "VariableDeclarationExpr":
                    VariableDeclarationExprHandler(expression.asVariableDeclarationExpr());
                    break;
                default:
                    /*
                        AssignExpr
                        ArrayAccessExpr
                        BinaryExpr
                        BooleanLiteralExpr
                        CastExpr
                        CharLiteralExpr
                        ConditionalExpr
                        DoubleLiteralExpr
                        EnclosedExpr
                        IntegerLiteralExpr
                        LongLiteralExpr
                        MethodCallExpr
                        NameExpr
                        StringLiteralExpr
                        ThisExpr
                        UnaryExpr
                     */
                    writer.print(expression);
                    break;
            }
        }

        private void VariableDeclarationExprHandler(VariableDeclarationExpr variableDeclarationExpr) {
            if (variableDeclarationExpr == null) {
                return;
            }

            for (VariableDeclarator var : variableDeclarationExpr.getVariables()) {
                // re-write variable declare statement
                writer.print(var.getType() + " " + var.getName() + " = " + var.getType() + "()");
            }
        }
    }

    public static void convert(String srcFilePath, String dstFilePath) throws IOException {
        try {
            // create io
            FileInputStream inputStream = new FileInputStream(srcFilePath);
//            PrintWriter writer = new PrintWriter(dstFilePath);
            PrintWriter writer = new PrintWriter(System.out);

            try {
                // create parser
                CompilationUnit cu = JavaParser.parse(inputStream);

                // traversal source file
                cu.accept(new Converter(writer), null);
            } finally {
                inputStream.close();
                writer.flush();
                writer.close();
            }
        } catch (Exception e) {
            throw e;
        }
    }
}
