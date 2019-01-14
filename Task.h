/* 
 * File:   Task.h
 * Author: ns
 *
 * Created on January 13, 2019, 10:36 PM
 */

#ifndef TASK_H
#define TASK_H

#include <memory>
#include <list>
#include <string>


using namespace std;

class Task;
typedef shared_ptr<Task> spTask;



class Task
{
private:
    static list<spTask> _global_tasks;
    string _name;
    string _description;

public:
    Task();
    Task(const Task&);
    virtual ~Task();

    inline static list<spTask>& getTasks(){ return _global_tasks; }
    static void addTaskGlobal(const spTask&);
    static void removeTaskGlobal(const spTask&);

    static void saveToFile(const string& fname = "tasks.q");
    static void loadFromFile(const string& fname = "tasks.q");

    inline void setName(const string& name){ _name = name; }
    inline const string& getName() const { return _name; }
    inline void setDescription(const string& descr){ _description = descr; }
    inline const string& getDescription() const { return _description; }

};



#endif /* TASK_H */
