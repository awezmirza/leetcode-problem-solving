class Solution {
public:
    double angleClock(double hour, double minutes) {
        double angleAtHour = hour == 12 ? (minutes/2) : 30*hour + (minutes/2);
        cout<<angleAtHour<<" ";
        double angleAtMin = minutes * 6;
        double ans = abs(angleAtHour - angleAtMin);
        return min(ans,360-ans);
    }
};