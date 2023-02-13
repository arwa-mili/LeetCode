class Solution {
   public static int reverse(int x){
        int j = x;
        int s;
        if (j < 0){
            j = -j;
        }
        String str = String.valueOf(j);
        char[] c = str.toCharArray();
        String result = "";
        for (int m = c.length-1; m >= 0; m--){
                result += c[m];
        }
        try {
            s = Integer.parseInt(result);
            if (x < 0)
                s = -s;
        }catch (NumberFormatException e){
            s = 0;
        }
        return s;
    }
}