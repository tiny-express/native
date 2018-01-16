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

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.function.Consumer;

/**
 * J2CPP Converter
 * <p>
 * This is a simple converter translate Java - JUnit test cases
 * to C++ to ensure Native Library comply Oracle documentation.
 * We expect a technical interoperable,consistency and standardization
 *
 * @author Loi Nguyen <loint@foodtiny.com>
 */
public class Converter {

    /**
     * Convert file
     * Convert single java test case source path to cpp destination path
     *
     * @param srcPath  String
     * @param destPath String
     * @return String
     */
    private String convertFile(String srcPath, String destPath) {
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

                                String cppTestContent = convertFile(
                                        javaTestFile.getAbsolutePath(),
                                        cppTestFile.getAbsolutePath()
                                );

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