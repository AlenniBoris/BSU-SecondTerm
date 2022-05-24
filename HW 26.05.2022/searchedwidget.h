#ifndef HW_26_05_2022_SEARCHEDWIDGET_H
#define HW_26_05_2022_SEARCHEDWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class searchedWidget; }
QT_END_NAMESPACE

class searchedWidget : public QWidget {
Q_OBJECT

public:
    explicit searchedWidget(QWidget *parent = nullptr);

    ~searchedWidget() override;

    void addFinded(const QString& qString);

private:
    Ui::searchedWidget *ui;
    QListWidget* searchedList;

};


#endif //HW_26_05_2022_SEARCHEDWIDGET_H
