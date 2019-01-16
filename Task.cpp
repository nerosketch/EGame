/* 
 * File:   Task.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 10:36 PM
 */

#include <ox/pugixml.hpp>
#include "Task.h"


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


void Task::saveToFile(const string& fname, const task_list&)
{
    /*pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("root");

    pugi::xml_node tasks = root.append_child("description");

    doc.save_file(fname);*/
}


task_list Task::loadFromFile(const string& fname)
{
    //load file to buffer
    /*ox::file::buffer bf;
    ox::file::read(fname, bf);

    pugi::xml_document doc;
    doc.load_buffer(&bf.data[0], bf.size());
    
    doc.*/
}
