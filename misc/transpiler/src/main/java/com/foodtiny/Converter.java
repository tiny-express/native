/*
 * Copyright 2017 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

package com.foodtiny;

import com.github.javaparser.JavaParser;
import com.github.javaparser.ast.CompilationUnit;
import com.github.javaparser.ast.NodeList;
import com.github.javaparser.ast.body.MethodDeclaration;
import com.github.javaparser.ast.body.VariableDeclarator;
import com.github.javaparser.ast.expr.Expression;
import com.github.javaparser.ast.expr.VariableDeclarationExpr;
import com.github.javaparser.ast.stmt.BlockStmt;
import com.github.javaparser.ast.stmt.ExpressionStmt;
import com.github.javaparser.ast.stmt.ForStmt;
import com.github.javaparser.ast.stmt.Statement;
import com.github.javaparser.ast.visitor.VoidVisitorAdapter;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Optional;
import java.util.function.Consumer;

/**
 * J2CPP Converter
 * <p>
 * This is a simple converter translate Java - JUnit test cases
 * to C++ to ensure Native Library comply Oracle documentation.
 * We expect a technical interoperable, consistency and standardization
 *
 * @author Loi Nguyen <loint@foodtiny.com>
 * @author Son Duong <sonda@foodtiny.com>
 */
public class Converter {

    /**
     * Visit Adapter
     */
    private class VisitAdapter extends VoidVisitorAdapter<Void> {

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

    /**
     * Convert file
     * Convert single java test case source path to cpp destination path
     *
     * @param srcPath  String
     * @return String
     */
    private String convertFile(String srcPath) {
        try {
            FileInputStream inputStream = new FileInputStream(srcPath);
            CompilationUnit cu = JavaParser.parse(inputStream);
            cu.accept(new VisitAdapter(writer), null);
        } catch (Exception e) {
        }
        return "";
    }


    /**
     * Convert all java files in folder path
     * This method will scan recursively to retrieve all java test files
     * and convert each file to corresponding cpp test case
     *
     * @param folderPath String
     */
    private void convertFolder(String folderPath) {
        try {
            Files.walk(Paths.get(folderPath))
                    .filter(Files::isRegularFile)
                    .forEach(new Consumer<Path>() {
                        @Override
                        public void accept(Path path) {
                            if (path.toAbsolutePath().toString().endsWith("Test.java")) {
                                File javaTestFile = new File(path.toAbsolutePath().toString());
                                String fileName = javaTestFile.getName().split("Test.java")[0];
                                File cppTestFile = new File(path.getParent().toAbsolutePath() + "/" + fileName + "_Test.cpp");

                                if (!cppTestFile.exists()) {
                                    try {
                                        cppTestFile.createNewFile();
                                    } catch (IOException exception) {
                                        exception.printStackTrace();
                                    }
                                }

                                String cppTestContent = convertFile(javaTestFile.getAbsolutePath());

                                // Write generated content
                                Writer writer = null;
                                try {
                                    writer = new BufferedWriter(
                                            new OutputStreamWriter(
                                                    new FileOutputStream(cppTestFile.getAbsoluteFile()),
                                                    "UTF-8")
                                    );
                                    writer.write(cppTestContent);
                                    writer.close();
                                } catch (IOException exception) {
                                    exception.printStackTrace();
                                }
                            }
                        }
                    });
        } catch (IOException exception) {
            System.out.println(exception.getMessage());
        }
    }

    /**
     * Converter staring point
     *
     * @param args String[]
     */
    public static void main(String[] args) {
        String currentDirectory = System.getProperty("user.dir");
        currentDirectory += "/library";
        Converter converter = new Converter();
        converter.convertFolder(currentDirectory + "/Java");
        converter.convertFolder(currentDirectory + "/Javax");
    }
}