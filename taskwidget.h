#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "Task.h"

class TaskWidget : public QWidget {
    Q_OBJECT
public:
    explicit TaskWidget(Task* task, QWidget* parent = nullptr);

private:
    Task* task;
    QLabel* titleLabel;
    QLabel* descriptionLabel;
    QLabel* dueDateLabel;
    QLabel* priorityLabel;
    QLabel* statusLabel;
};

#endif // TASKWIDGET_H
