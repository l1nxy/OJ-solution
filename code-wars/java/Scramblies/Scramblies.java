import java.util.Arrays;

public class Scramblies {
    public static void main(String[] args) {
        System.out.println("HelloWorld!");
        if (scramble("scriptingjava","javascript") == true)
            System.out.println("true");
    }

    public static boolean scramble(String str1, String str2) {
        if (str1 == null || str2 == null)
            return false;
        for (int i = 0; i < str2.length(); i++) {
            int index = str1.indexOf(str2.charAt(i));
            if (index == -1)
                return false;
            else{
                StringBuilder sb = new StringBuilder(str1);
                sb.deleteCharAt(index);
                str1 = sb.toString();
            }

        }
        return true;

    }
}
