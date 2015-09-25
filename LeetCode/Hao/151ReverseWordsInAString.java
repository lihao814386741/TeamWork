public class Solution {
    public String reverseWords(String s) {
        String[] stringList = s.split("\\s+");
        StringBuilder sb = new StringBuilder();
        for (int i = stringList.length - 1; i >= 0; i --) {
            sb.append(stringList[i] + " ");
        }
        
        return sb.toString().trim();
    }
}
