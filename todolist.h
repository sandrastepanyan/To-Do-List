#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class ToDoList;
}
QT_END_NAMESPACE

class ToDoList : public QMainWindow
{
    Q_OBJECT

public:
    ToDoList(QWidget *parent = nullptr);
    ~ToDoList();

private:
    void design();

public slots:
    void onAddButtonClicked();
    void onResetButtonClicked();
    void onRemoveButtonClicked();

private:
    QWidget* widget;
    QListWidget* m_list;
    QLineEdit* m_inputLine;
    QLabel* m_title;
    QPushButton* addButton;
    QPushButton* removeButton;
    QPushButton* resetButton;
};

#endif // TODOLIST_H
