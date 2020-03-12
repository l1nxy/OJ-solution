class Diamond {
    public static void main(String[] args) {
        System.out.println(print(7));
    }

    public static String print(int n) {
        if(n < 0 || n % 2 == 0){
           return null;
        }
        int size = n / 2;
        StringBuilder ret = new StringBuilder();
        for (int i = 0 - size; i <= size; i++) {
            for (int j = 0 - size; j <= size; j++) {
                if (Math.abs(i) + Math.abs(j) <= size) {
                    if (Math.abs(i) + Math.abs(j) == size && j >= 0) {
                        ret.append("*\n");
                    } else {
                        ret.append("*");
                    }
                } else {
                    if(j < 0)
                        ret.append(" ");
                }
            }
        }
        return ret.toString();
    }
}