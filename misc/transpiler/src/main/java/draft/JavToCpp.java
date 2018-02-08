package main.java.draft;

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

public class JavToCpp {
    private static class Converter extends VoidVisitorAdapter<Void> {
        private PrintWriter writer;

        public Converter(PrintWriter w) {
            writer = w;
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
