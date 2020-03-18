
class Persist {
    public static void main(String[] args) {
        int  n  = persistence(4);
        System.out.println(n);
    }

    static boolean isOneDigit(long n) {
        return n / 10 == 0;
    }

    static int[] IntToArray(long n) {
        String num = Long.toString(n);
        int[] ret = new int[num.length()];
        for (int i = 0; i < num.length(); i++) {
            ret[i] = Character.getNumericValue(num.charAt(i));
        }
        return ret;
    }

    static long GetSum(int[] nums) {
        long sum = 1;
        for (int i = 0; i < nums.length; i++) {
            sum *= nums[i];
        }
        return sum;
    }

    public static int persistence(long n) {
        int count = 0;
        while (isOneDigit(n) == false) {
            int[] ret = IntToArray(n);
            n = GetSum(ret);
            count++;
        }

        return count;
    }
}