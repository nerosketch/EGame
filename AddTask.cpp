/* 
 * File:   AddTask.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 9:37 PM
 */

#include "resources.h"
#include "TextButton.h"
#include "AddTask.h"
#include "Task.h"


AddTask::AddTask() : _text_question_title(new TextInput),
_text_question_descr(new TextInput)
{
    // Текст заголовок
    spTextField title = new TextField;
    title->setText("Добавить вопрос");
    title->setPosition(getWidth() / 2.f - 80.f, 15.f);
    title->setFontSize(24);
    title->setColor(Color::Crimson);
    addChild(title);
    
    const float x_pos = 300.f;

    // Ввод названия вопроса
    spTextField text_input_name = new TextField;
    text_input_name->setText("Впиши заголовок вопроса");
    text_input_name->setPosition(25.f, 70.f);
    text_input_name->setFontSize(21);
    text_input_name->setColor(Color::BlanchedAlmond);
    addChild(text_input_name);
    // Тут хранится текст
    _text_question_title->setPosition(x_pos, 67.f);
    addChild(_text_question_title);

    // Ввод описания вопроса
    spTextField text_input_descr = new TextField;
    text_input_descr->setText("Впиши текст вопроса");
    text_input_descr->setPosition(25.f, 125.f);
    text_input_descr->setFontSize(21);
    text_input_descr->setColor(Color::BlanchedAlmond);
    addChild(text_input_descr);
    // Тут хранится текст
    _text_question_descr->setPosition(x_pos, 122.f);
    _text_question_descr->setWidth(350.f);
    spTextField tf = _text_question_descr->getTextField();
    tf->setMultiline(true);
    tf->setWidth(_text_question_descr->getWidth());
    addChild(_text_question_descr);

    // Кнопка ОК
    spTextButton ok_btn = new TextButton("Сохранить");
    ok_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &AddTask::_on_ok_click));
    ok_btn->setAnchor(0.5f, 0.5f);
    ok_btn->setPosition(getWidth() / 2.f, getHeight() - ok_btn->getHeight());
    addChild(ok_btn);
}


AddTask::AddTask(const AddTask&)
{}


AddTask::~AddTask()
{}


void AddTask::_on_ok_click(Event*)
{
    logs::messageln("AddTask::_on_ok_click");

    spTask task(new Task);
    task->setName(_text_question_title->getText());
    task->setDescription(_text_question_descr->getText());
    Task::addTaskGlobal(task);

    detach();
}
