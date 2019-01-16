/* 
 * File:   Task.h
 * Author: ns
 *
 * Created on January 13, 2019, 10:36 PM
 */

#ifndef TASK_H
#define TASK_H

#include <list>
#include <string>
#include <oxygine-framework.h>


using namespace std;


DECLARE_SMART(Task, spTask);

typedef list<spTask> task_list;


class Task : public oxygine::Object
{
private:
    string _name;
    string _description;

public:
    Task();
    Task(const Task&);
    virtual ~Task();

    static void saveToFile(const string& fname, const task_list&);
    static task_list loadFromFile(const string& fname);

    inline void setName(const string& name){ _name = name; }
    inline const string& getName() const { return _name; }
    inline void setDescription(const string& descr){ _description = descr; }
    inline const string& getDescription() const { return _description; }

};



#endif /* TASK_H */
