/* 
 * File:   Task.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 10:36 PM
 */

#include <ox/pugixml.hpp>
#include "Task.h"


#define FNAME          "res/data.xml"


using namespace pugi;


task_list Task::_tasks;


Task::Task() : _title(), _description()
{
}


Task::Task(const Task& o) : _title(o._title),
_description(o._description)
{
}


Task::~Task()
{
}


/*bool check_node_exist(const uint uid, const task_list& arr_p)
{
    for(const spTask& i : arr_p)
    {
        if(i->getUid() == uid)
            return true;
    }
    return false;
}*/


/*void Task::saveAll()
{
    xml_document doc;

    const char* root_chr = "egame";

    if(!doc.load_file(FNAME))
    {
        // создадим root ноду
        doc.append_child(root_chr);
    }

    xml_node root = doc.child(root_chr);

    for(const spTask& t : _tasks)
    {
        if(check_node_exist(t->getUid(), _tasks))
        {
            continue;
        }

        xml_node node_task = root.append_child("task");
        node_task.text() = t->_description.c_str();
        node_task.append_attribute("title") = t->_title.c_str();
        //node_task.append_attribute("id") = t->getUid();
    }

    doc.save_file(FNAME);
}*/


bool Task::loadAll()
{
    xml_document doc;

    xml_parse_result result = doc.load_file(FNAME);

    if(!result)
        return false;

    for(const xml_node& nd : doc.child("egame").children())
    {
        /*if(check_node_exist(uid, _tasks))
        {
            //cout << "task with uid=" << uid << " exists, continue" << endl;
            continue;
        }*/

        spTask t = new Task;
        //t->setUid(uid);
        t->_title = nd.attribute("title").as_string();
        t->_description = nd.text().as_string();

        _tasks.push_back(t);
    }

    return true;
}
