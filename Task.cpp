/* 
 * File:   Task.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 10:36 PM
 */

#include <ox/pugixml.hpp>
#include "Task.h"


list<spTask> Task::_global_tasks;


Task::Task() : _name(), _description()
{
}


Task::Task(const Task& o) : _name(o._name),
_description(o._description)
{
}


Task::~Task()
{
}


void Task::addTaskGlobal(const spTask& t)
{
    for(const spTask& ct : _global_tasks)
    {
        if(ct == t)
            return;
    }
    _global_tasks.push_back(t);
}


void Task::removeTaskGlobal(const spTask& t)
{
    _global_tasks.remove(t);
}



void Task::saveToFile(const string& fname)
{
    /*pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("root");

    pugi::xml_node tasks = root.append_child("description");

    doc.save_file(fname);*/
}


void Task::loadFromFile(const string& fname)
{
    //load file to buffer
    /*ox::file::buffer bf;
    ox::file::read(fname, bf);

    pugi::xml_document doc;
    doc.load_buffer(&bf.data[0], bf.size());
    
    doc.*/
}
