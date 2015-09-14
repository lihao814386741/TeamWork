public int jump(int[] nums) {
      int last =0;
      int cur = 0;
      int step = 0;
      int size = nums.length;
      for(int i=0;i<size;i++){
          if(i>last){
              last = cur;
              ++step;
          }
          cur = Math.max(cur,i+nums[i]);
      }
      return step; 
    }