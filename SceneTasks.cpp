/* 
 * File:   SceneTasks.cpp
 * Author: ns
 * 
 * Created on January 18, 2019, 6:24 PM
 */
#include <cstdlib>
#include "resources.h"
#include "Task.h"
#include "SceneTasks.h"


DECLARE_SMART(TaskListItem, spTaskListItem);


class TaskListItem : public Actor
{
public:
    TaskListItem(const char* t, const char* d) : title(new TextField), descr(new TextField)
    {
        const ResFont *p_font = res::resources.getResFont("SanasoftHermes");
        title->setFont(p_font);
        title->setFontSize(24);
        title->setText(t);
        title->setColor(Color::BlueViolet);
        addChild(title);

        descr->setFont(p_font);
        descr->setFontSize(18);
        descr->setText(d);
        descr->setColor(Color::WhiteSmoke);
        descr->setMultiline(true);
        descr->setWidth(850.f);
        descr->setX(15.f);
        addChild(descr);

        RectF sz;
        title->getBounds(sz);
        float tw = sz.size.x;
        float th = sz.size.y;
        descr->getBounds(sz);
        float dw = sz.size.x;
        float dh = sz.size.y;
        setSize(
            max(tw, dw),
            th + dh
        );

        descr->setY(th + 3.f);
    }

    TaskListItem(const TaskListItem& o) : title(o.title), descr(o.descr){}
    virtual ~TaskListItem(){}

    /*void sizeChanged(const Vector2& size) override
    {
        descr->setWidth(size.x * 0.65);
    }*/

    spTextField title;
    spTextField descr;
};



SceneTasks::SceneTasks()
{
}


SceneTasks::SceneTasks(const SceneTasks&)
{
}


SceneTasks::~SceneTasks()
{
}


void SceneTasks::init()
{
    Dialog::init();

    // Текст заголовок
    spTextField title = new TextField;
    title->setText("Добавить вопрос");
    title->setPosition(getWidth() / 2.f - 80.f, 65.f);
    title->setFontSize(24);
    title->setColor(Color::Crimson);
    addChild(title);
    
    // Загруж
    const char txt[] = "Lore o iasoi asd oiadoi asiouasduiyasdoiaspodPIODAOUIPd A O iASOI AOi ASOI UsioUASPO UAsPOA ISAPO sASOI UAOsiu ASPOUI Aspo APOUDPOI D And again";
    std::vector<spTaskListItem> tsks = {
        new TaskListItem("Первый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Новый", txt),
        new TaskListItem("Последний", txt)
    };

    // контейнер, содержащий список вопросов
    //spColorRectSprite task_list_container = new ColorRectSprite;
    //task_list_container->setColor(0xff0000ab);
    spActor task_list_container = new Actor;
    float max_h = 0.f;
    float max_w = 0.f;
    for(spTaskListItem& tl : tsks)
    {
        if(tl->getWidth() > max_w)
            max_w = tl->getWidth();
        max_h += tl->getHeight();
    }
    task_list_container->setSize(max_w + 50.f, max(
        max_h + 50 * tsks.size(),
        getHeight()
    ));

    // настраиваем элементы контейнера
    float h_pos = 20.f;
    for(spTaskListItem& tl : tsks)
    {
        tl->setY(h_pos);
        tl->setX(10.f);
        h_pos += tl->getHeight() + 50;
        task_list_container->addChild(tl);
    }

    // Слайдер с контейнером списка вопросов
    spBox9Sprite slider_decor = new Box9Sprite;
    slider_decor->setResAnim(res::resources.getResAnim("box"));
    slider_decor->setGuides(12.f, 13.f, 19.f, 22.f);
    slider_decor->setWidth(task_list_container->getWidth());
    slider_decor->setAnchor(0.5f, 0.5f);
    slider_decor->setHeight(min(
        task_list_container->getHeight() - 55.f,
        getHeight() * 0.80f
    ));
    slider_decor->setPosition(getSize() / 2);

    spSlidingActor slider = new SlidingActor;
    slider->setSize(
        slider_decor->getWidth(),
        slider_decor->getHeight() - 14.f
    );
    slider->setContent(task_list_container);
    slider_decor->addChild(slider);
    addChild(slider_decor);
}
