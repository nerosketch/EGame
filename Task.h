/* 
 * File:   Task.h
 * Author: ns
 *
 * Created on January 13, 2019, 10:36 PM
 */

#ifndef TASK_H
#define TASK_H

#include <vector>
#include <string>
#include <oxygine-framework.h>


using namespace std;


DECLARE_SMART(Task, spTask);

typedef vector<spTask> task_list;


class Task : public oxygine::Object
{
private:
    string _title;
    string _description;
    //uint _uid;
    static task_list _tasks;

public:
    Task();
    Task(const Task&);
    virtual ~Task();


    inline void setTitle(const string& title){ _title = title; }
    inline const string& getTitle() const { return _title; }
    inline void setDescription(const string& descr){ _description = descr; }
    inline const string& getDescription() const { return _description; }
    //inline void setUid(const uint uid){ _uid = uid; }
    //inline const uint getUid() const { return _uid; }

    //static void saveAll();
    static bool loadAll();
    static task_list& getTasks()
    {
        return _tasks;
    }
    static const spTask& getRandom();
};



#endif /* TASK_H */
