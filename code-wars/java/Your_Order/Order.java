import java.util.ArrayList;
import java.util.Arrays;

public class Order {
    public static void main(String[] args) {
       String s = order("4of Fo1r pe6ople g3ood th5e the2");
       System.out.println(s); 
    }

    static int GetNum(String num) {
        for (int i = 0; i < num.length(); i++) {
            char ch = num.charAt(i);
            if (Character.isDigit(ch) == true)
                return Character.getNumericValue(ch);
        }
        return -1;
    }

    public static String order(String words) {
        if(words == null || words.isEmpty() == true) return "";
        ArrayList<String> list_words = new ArrayList<String>(Arrays.asList(words.split(" ")));
        list_words.sort((String str1, String str2) -> {
            return GetNum(str1) - GetNum(str2);
        });
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < list_words.size(); i++) {
            sb.append(list_words.get(i));
            if(i != list_words.size() -1 )
                sb.append(" ");
        }
        return sb.toString();
    }
}