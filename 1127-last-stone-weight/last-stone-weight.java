import java.util.PriorityQueue;

class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(java.util.Collections.reverseOrder());
        for (int stone : stones) {
            pq.offer(stone);
        }
        while (pq.size() > 1) {
            int a = pq.poll();
            int b = pq.poll();
            int c = a - b;
            if (c != 0) {
                pq.offer(c);
            }
        }
        return pq.isEmpty() ? 0 : pq.peek();
    }
}
