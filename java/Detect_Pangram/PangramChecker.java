import java.awt.List;
import java.util.ArrayList;

public class PangramChecker {
    public static void main(String[] args) {
        String pangram1 = "The quick brown fox jumps over the lazy dog.";
        check(pangram1);
    }

    static String dedup(String str) {
        ArrayList<Character> t = new ArrayList<Character>();
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < str.length(); i++) {
            if (!Character.isLetter(str.charAt(i)))
                continue;
            char ch = Character.toLowerCase(str.charAt(i));
            if (!t.contains(ch)) {
                sb.append(ch);
                t.add(ch);
            }
        }
        return sb.toString();
    }

    public static boolean check(String sentence) {
        return dedup(sentence).length() == 26;
    }
}