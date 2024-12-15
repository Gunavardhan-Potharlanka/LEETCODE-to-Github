class Solution {
    private double gain(int passi, int totali) {
        return (double) (passi + 1) / (totali + 1) - (double) passi / totali;
    }
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            double ratio1 = gain(a[0], a[1]);
            double ratio2 = gain(b[0], b[1]);
            return Double.compare(ratio2, ratio1);
        });
        for(int[] arr : classes) pq.offer(arr);
        for(int i = 0 ; i < extraStudents ; i++) {
            int[] arr = pq.poll();
            arr[0]++;
            arr[1]++;
            pq.offer(arr);
        }
        double db = 0, len = 0;
        while(!pq.isEmpty()) {
            int[] arr = pq.poll();
            db += (double) arr[0] / arr[1];
        }
        return (double) (db / (double) classes.length);
    }
}