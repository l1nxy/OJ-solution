import java.util.Arrays;
import java.util.List;

public class Kata {

    public static void main(String[] args) {
        high("man i need a taxi up to ubud");
        high("what time are we climbing up to the volcano");
        high("take me to semynak");
    }

    public static String high(String s) {
        List<String> words = Arrays.asList(s.split(" "));
        words.sort((String s1, String s2) -> {
            if (util(s2) == util(s1)) {
                return words.indexOf(s2) - words.indexOf(s1);
            } else {
                return util(s2) - util(s1);
            }
        });
        System.out.println(words.get(0));
        System.out.println(words.get(1));
        return words.get(0);
    }

    static int util(String s) {
        int res = 0;
        for (char c : s.toCharArray()) {
            res += (c - 'a');
        }
        return res;
    }
}