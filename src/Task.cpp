/* 
 * File:   Task.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 10:36 PM
 */
#include <ox/pugixml.hpp>
#include "Task.h"


#define FNAME                   "res/data.xml"


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


bool Task::loadAll()
{
    xml_document doc;

    xml_parse_result result = doc.load_file(FNAME);

    if(!result)
        return false;

    _tasks.clear();

    for(const xml_node& nd : doc.child("egame").children())
    {
        spTask t = new Task;
        t->_title = nd.attribute("title").as_string();
        t->_description = nd.text().as_string();

        _tasks.push_back(t);
    }

    return true;
}


const spTask& Task::getRandom()
{
    const int rk = RANDOM_RANGE(0, _tasks.size() - 1);

    return _tasks[rk];
}
