// set data structure:
// count() function time complexity: log(n)(Balanced Binary Search Tree)
class TaskManager {
public:
    // priority_queue<pair<int,int>> pq_task_pri;
    set<pair<int,int>> pri_task_set;
    unordered_map<int,int> task_user;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0;i < tasks.size();i++)
        {
            pri_task_set.insert({-tasks[i][2],-tasks[i][1]});
            task_user[-tasks[i][1]] = tasks[i][0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pri_task_set.insert({-priority,-taskId});
        task_user[-taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        for(auto it = pri_task_set.begin();it!=pri_task_set.end();it++)
        {
            if(it->second == -taskId){
                pri_task_set.erase(it);
                pri_task_set.insert({-newPriority,-taskId});
                // it->first = newPriority;
                break;
            }
        }
    }
    
    void rmv(int taskId) {
        // for(int i = 0;i < pri_task_set.size();i++)
        // {
        //     if(pri_task_set[i][1] == taskId){
        //         pri_task_set.erase(pri_task_set.begin() + i);
        //         task_user.erase(taskId);
        //         break;
        //     }
        // }

        for(auto it = pri_task_set.begin();it!= pri_task_set.end();it++)
        {
            if(it->second == -taskId){
                task_user.erase(-taskId);
                pri_task_set.erase(it);
                break;
            }
        }
    }
    
    int execTop() {
        if(pri_task_set.size()!=0)
        {
            int output = task_user[pri_task_set.begin()->second];
            task_user.erase(pri_task_set.begin()->second);
            pri_task_set.erase(pri_task_set.begin());
            return output;
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

#include <vector>
#include <set>
#include <unordered_map>
#include <utility>

using namespace std;

class TaskManager {
public:
    // pair<priority, taskId>
    set<pair<int, int>> pri_task_set;
    // taskId -> {priority, userId}
    unordered_map<int, pair<int, int>> task_user_info;

    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            add(userId, taskId, priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        pri_task_set.insert({-priority, -taskId});
        task_user_info[taskId] = {priority, userId};
    }

    void edit(int taskId, int newPriority) {
        if (task_user_info.count(taskId)) {
            int oldPriority = task_user_info[taskId].first;
            int userId = task_user_info[taskId].second;

            // 1. 從 set 中移除舊的元素 (O(log n))
            pri_task_set.erase({-oldPriority, -taskId});

            // 2. 更新 map 中的資訊
            task_user_info[taskId].first = newPriority;

            // 3. 插入新的元素 (O(log n))
            pri_task_set.insert({-newPriority, -taskId});
        }
    }

    void rmv(int taskId) {
        if (task_user_info.count(taskId)) {
            int priority = task_user_info[taskId].first;

            // 1. 從 set 中移除 (O(log n))
            pri_task_set.erase({-priority, -taskId});

            // 2. 從 map 中移除 (O(1))
            task_user_info.erase(taskId);
        }
    }

    int execTop() {
        if (pri_task_set.empty()) {
            return -1;
        }

        // 取得最高優先級的任務資訊
        auto top_task = *pri_task_set.begin();
        int taskId = -top_task.second;
        int userId = task_user_info[taskId].second;

        // 移除最高優先級的任務
        pri_task_set.erase(pri_task_set.begin());
        task_user_info.erase(taskId);

        return userId;
    }
};
