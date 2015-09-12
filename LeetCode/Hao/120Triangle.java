public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        
        if (triangle.size() == 1) {
            return triangle.get(triangle.size() - 1).get(0);
        }
        
        int rowMax = triangle.size();
        int colMax = triangle.get(rowMax - 1).size();
        int[] d = new int[rowMax];
        
        
        ListIterator<List<Integer>> rowIterator = triangle.listIterator(rowMax);
        // initialize the dp 
        int i = 0;
        for (Integer data: rowIterator.previous()) {
            d[i] = data;
            i ++;
        }
        
        while (rowIterator.hasPrevious() == true) {
            List<Integer> rowList = rowIterator.previous();
            i = 0;
            
            for (Integer data:rowList) {
                d[i] = data + Math.min(d[i], d[i + 1]);
                i ++;
            }
        }
        
        return d[0];
    }
}
