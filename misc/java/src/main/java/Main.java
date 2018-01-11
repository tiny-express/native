import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        try {
            JUnitTranspiler.convert(
                "/home/home/Desktop/projects/Java/Temp/test.java",
                "/home/home/Desktop/projects/Java/Temp/test.tmp"
            );
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
