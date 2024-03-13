class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }
        int a = gcd(jug1Capacity, jug2Capacity);
        return targetCapacity % a == 0;
    }

private:
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
};