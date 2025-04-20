class Solution {
    public int numRabbits(int[] answers) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int ans = 0;
        for(int i =  0 ; i < answers.length ; i++) {
            map.putIfAbsent(answers[i] , 0);
            map.put(answers[i], map.get(answers[i]) + 1);
        }
        for(int i : map.keySet()) {
            int pnum = (i + 1);
            ans += (map.get(i) / pnum) * pnum;
            if(map.get(i) % pnum > 0) ans += pnum;
        }
        return ans;
    }
}