class TaskManager {
public:

    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> taskPriority; 
    unordered_map<int, int> taskUser; 

    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks) {
            pq.push({task[2], task[1]});
            taskPriority[task[1]] = task[2];
            taskUser[task[1]] = task[0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        taskPriority[taskId] = priority;
        taskUser[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        pq.push({newPriority, taskId});
        taskPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        taskPriority[taskId] = -1;
        taskUser[taskId] = -1;
    }
    
    int execTop() {
        bool exec = true;
        while (!pq.empty() && exec) {
            auto tp = pq.top();
            pq.pop();
            if (taskPriority[tp.second] == tp.first) {
                exec = false;
                taskPriority[tp.second] = -1;
                int userId = taskUser[tp.second];
                taskUser[tp.second] = -1;
                return userId;
            }
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */