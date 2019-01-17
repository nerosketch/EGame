/* 
 * File:   AddTask.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 9:37 PM
 */

#include "resources.h"
#include "AddTask.h"
#include "Task.h"


AddTask::AddTask() : Dialog(), _text_question_title(new TextInput),
_text_question_descr(new TextInput)
{
}


AddTask::AddTask(const AddTask&)
{}


AddTask::~AddTask()
{}


void AddTask::init()
{
    Dialog::init();

    // Текст заголовок
    spTextField title = new TextField;
    title->setText("Добавить вопрос");
    title->setPosition(getWidth() / 2.f - 80.f, 65.f);
    title->setFontSize(24);
    title->setColor(Color::Crimson);
    addChild(title);
    
    const float x_pos = 145.f;

    // Ввод названия вопроса
    spTextField text_input_name = new TextField;
    text_input_name->setText("Впиши заголовок вопроса");
    text_input_name->setPosition(x_pos, 180.f);
    text_input_name->setFontSize(21);
    text_input_name->setColor(Color::BlanchedAlmond);
    addChild(text_input_name);
    // Тут хранится текст
    _text_question_title->init();
    _text_question_title->setPosition(
        text_input_name->getX() + 225.f,
        text_input_name->getY() - 5.f
    );
    addChild(_text_question_title);

    // Ввод описания вопроса
    spTextField text_input_descr = new TextField;
    text_input_descr->setText("Впиши текст вопроса");
    text_input_descr->setPosition(x_pos, 230.f);
    text_input_descr->setFontSize(21);
    text_input_descr->setColor(Color::BlanchedAlmond);
    addChild(text_input_descr);
    // Тут хранится текст
    _text_question_descr->init();
    _text_question_descr->setPosition(
        text_input_descr->getX() + 225.f,
        text_input_descr->getY() - 5.f
    );
    _text_question_descr->setWidth(350.f);
    spTextField tf = _text_question_descr->getTextField();
    tf->setMultiline(true);
    tf->setWidth(_text_question_descr->getWidth());
    addChild(_text_question_descr);
}


void AddTask::on_ok_click(Event* ev)
{
#ifdef DBG
    logs::messageln("AddTask::_on_ok_click");
#endif

    spTask task = new Task;
    task->setName(_text_question_title->getText());
    task->setDescription(_text_question_descr->getText());

    detach();

    ev->userData = task.get();
    Dialog::on_ok_click(ev);
}
