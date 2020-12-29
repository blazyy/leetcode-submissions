// I honestly don't understand this question.
// I'm not going to care about efficiency here.
// I don't want to optimize code for a question that's so badly written.
// Time Complexity  - O(n)
// Space Complexity - O(n)
​
class RecentCounter {
public:
    
    int num_requests;
    vector <int> ping_times;
    
    RecentCounter() {
        num_requests = 0;
    }
    
    int ping(int t) {
        int diff, counter = 0, duration = 0, i;
        ping_times.push_back(t);
        i = ping_times.size() - 1;
        while(duration <= 3000 and i >= 0){
            if(i > 0) diff = ping_times[i] - ping_times[i - 1];
            else diff = ping_times[i];
            i--;
            duration += diff;
            counter++; 
        }
        return counter;
    }
};
​
/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
