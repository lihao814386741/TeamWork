/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
 
 
public class Solution {

    private void put(Map<Slope, Integer> m, Slope key) {
        if (m.containsKey(key) == true) {
            m.put(key, m.get(key) + 1);
        } else {
            m.put(key, 1);
        }
    }
    class Slope{
        double slope;
        public Slope(double s) {
            this.slope = s;
        }
		@Override
		public boolean equals(Object obj) {
			Slope s = (Slope)obj;
            if (Math.abs(s.slope - this.slope) < 1e-4) {
                return true;
            }
			return super.equals(obj);
		}
        @Override
        public int hashCode(){
            return (int)slope;
        }
    }
    public int maxPoints(Point[] points) {
        if (points.length == 0) {
            return 0; 
        }
        int result = 0;
        
        for (int i = 0; i < points.length; i ++) {
            Map <Slope, Integer> hmap = new HashMap<Slope, Integer>();
            int samePoints = 1;
            for (int j = i + 1; j < points.length; j ++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    samePoints ++;
                } else if (points[i].x == points[j].x) {
                    put(hmap, new Slope(Integer.MAX_VALUE));
                } else {
                    double slope = (double) (points[i].y - points[j].y) / (double) (points[i].x - points[j].x);
                    Slope s = new Slope(slope);
                    put(hmap, s);
                }
            }
            int local = 0;
            for (Map.Entry<Slope, Integer> e : hmap.entrySet()) {
                local = Math.max(local, e.getValue());
            }
            local += samePoints;
            result = Math.max(local, result);
        }
        
        return result;
    }
}
