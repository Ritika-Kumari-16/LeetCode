class TaskManager {
public:
unordered_map<int,int>tasktopri;
unordered_map<int,int>tasktouser;
set<pair<int,pair<int,int>>>ptu;
    TaskManager(vector<vector<int>>& tasks) {
        int n= tasks.size();
        for(int i=0;i<n;i++){
            int userid=tasks[i][0];
            int taskid=tasks[i][1];
            int priority= tasks[i][2];
            ptu.insert({priority,{taskid,userid}});
            tasktopri[taskid]=priority;
            tasktouser[taskid]=userid;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        ptu.insert({priority,{taskId,userId}});
        tasktopri[taskId]=priority;
        tasktouser[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        int oldpri=tasktopri[taskId];
        int userid=tasktouser[taskId];
        ptu.erase({oldpri,{taskId,userid}});
        ptu.insert({newPriority,{taskId,userid}});
        tasktopri[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        int userid= tasktouser[taskId];
        int pri=tasktopri[taskId];
        ptu.erase({pri,{taskId,userid}});
    }
    
    int execTop() {
        int userid= ptu.rbegin()->second.second;
        int pri= ptu.rbegin()->first;
        int taskid=ptu.rbegin()->second.first;
        ptu.erase({pri,{taskid,userid}});
        return userid;
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