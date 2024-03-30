
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    
    int n = A.size();
        if(n == 0)
            return {};
        deque<int> deq;

        vector<int> result;
        
        for(int i = 0; i<n; i++) {
            // 1) remove the max elements from front which are out of window size
            while(!deq.empty() && deq.front() <= i-B)
            deq.pop_front();
            
            // 2) we maintain the deque in descending order
            while(!deq.empty() && A[i] > A[deq.back()])
            deq.pop_back();
            
            deq.push_back(i);

            if(i >= B-1) // 3) Only when the window size first gets equal or greater than k
            result.push_back(A[deq.front()]); // 4) front will have the max element (dequeue is maintained in descending order)
        }
        return result;
}
