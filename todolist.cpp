#include "todolist.h"
#include "ui_todolist.h"

ToDoList::ToDoList(QWidget *parent)
    : QMainWindow(parent)
    , widget(new QWidget(this))
    , m_list(new QListWidget(widget))
    , m_inputLine(new QLineEdit(widget))
    , m_title(new QLabel("ToDo List", widget))
{
    this->setCentralWidget(widget);
    addButton = new QPushButton("Add", widget);
    removeButton = new QPushButton("Remove", widget);
    resetButton = new QPushButton("Reset", widget);

    design();
    connect(addButton, &QPushButton::clicked, this, &ToDoList::onAddButtonClicked);
    connect(resetButton, &QPushButton::clicked, this, &ToDoList::onResetButtonClicked);
    connect(removeButton, &QPushButton::clicked, this, &ToDoList::onRemoveButtonClicked);
}

ToDoList::~ToDoList() {}

void ToDoList::design()
{
    this->setFixedSize(800, 600);
    this->setStyleSheet("border: 1px solid black");

    m_inputLine->setPlaceholderText("add a new task...");
    m_inputLine->setStyleSheet("border-radius: 10px");
    m_inputLine->setGeometry(200, 505, 400, 50);
    m_inputLine->setFocus();

    m_title->setGeometry(350, 30, 100, 30);
    m_title->setAlignment(Qt::AlignCenter);
    m_title->setStyleSheet("background-color: lightBlue; border: none; border-radius: 10px");

    m_list->setGeometry(130, 80, 600, 400);


    addButton->setGeometry(650, 515, 70, 30);
    addButton->setStyleSheet("background-color: lightBlue; border: none; color: black; text-align: center; border-radius: 4px;");

    removeButton->setGeometry(30, 130, 70, 30);
    removeButton->setStyleSheet("background-color: lightBlue; border: none; color: black; text-align: center; border-radius: 4px;");

    resetButton->setGeometry(30, 80, 70, 30);
    resetButton->setStyleSheet("background-color: lightBlue; border: none; color: black; text-align: center; border-radius: 4px;");
}

void ToDoList::onAddButtonClicked()
{
    QString newTask = m_inputLine->text();
    QListWidgetItem* item = new QListWidgetItem(newTask, m_list);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    m_list->addItem(item);
    m_inputLine->clear();
    m_inputLine->setPlaceholderText("add a new task...");
    m_inputLine->setFocus();
}

void ToDoList::onResetButtonClicked()
{
    m_list->clear();
    m_inputLine->setFocus();
}

void ToDoList::onRemoveButtonClicked()
{
    QListWidgetItem* item = m_list->takeItem(m_list->currentRow());
    m_list->removeItemWidget(item);
}







