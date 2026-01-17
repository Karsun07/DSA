class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b) {
		return a[1] < b[1];
	}
    
	int scheduleCourse(vector<vector<int>>& courses) {
		int n = courses.size();
		sort(courses.begin(), courses.end(), comp);
		priority_queue<int>pq;
		int sum = 0;
		for(auto it : courses) {
			int duration  = it[0];
			int deadline = it[1];	
			if(sum + duration <= deadline) {
				sum += duration;
				pq.push(duration);
			}
			else if(pq.size() && pq.top() > duration){ 
				sum += duration - pq.top();
				pq.pop();
				pq.push(duration);
			}
		}

		return pq.size();
	}
};