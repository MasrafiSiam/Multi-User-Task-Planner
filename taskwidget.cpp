#include "TaskWidget.h"
#include <QFont>
#include <QPalette>

TaskWidget::TaskWidget(Task* t, QWidget* parent)
    : QWidget(parent), task(t)
{
    // Set different background color for completed tasks
    QString backgroundColor = "rgba(255, 255, 255, 240)"; // Default white
    QString borderColor = "#3498db"; // Default blue

    if (task->status == "Completed") {
        backgroundColor = "rgba(230, 245, 230, 240)"; // Light green for completed
        borderColor = "#27ae60"; // Green border for completed
    }

    QString style = QString("QWidget { "
                            "border: 2px solid %1; "
                            "border-radius: 10px; "
                            "padding: 10px; "
                            "margin: 5px; "
                            "background-color: %2; "
                            "}").arg(borderColor).arg(backgroundColor);

    setStyleSheet(style);

    // Create title label with task ID included
    QString titleWithId = QString::fromStdString("<b>" + std::to_string(task->taskID) + ". " + task->title + "</b>");
    titleLabel = new QLabel(titleWithId, this);
    descriptionLabel = new QLabel(QString::fromStdString("<b>Description:</b> " + task->description), this);
    dueDateLabel = new QLabel(QString::fromStdString("<b>Due Date:</b> " + task->dueDate), this);
    priorityLabel = new QLabel(QString::fromStdString("<b>Priority:</b> " + task->priority), this);
    statusLabel = new QLabel(QString::fromStdString("<b>Status:</b> " + task->status), this);

    // Set text color to black/dark for all labels
    QString labelStyle = "QLabel { color: #2c3e50; font-size: 12px; background: transparent; }";
    titleLabel->setStyleSheet(labelStyle);
    descriptionLabel->setStyleSheet(labelStyle);
    dueDateLabel->setStyleSheet(labelStyle);
    priorityLabel->setStyleSheet(labelStyle);
    statusLabel->setStyleSheet(labelStyle);

    // Make title bold and larger
    titleLabel->setStyleSheet("QLabel { color: #2c3e50; font-size: 14px; font-weight: bold; background: transparent; }");

    // Set text formatting
    titleLabel->setTextFormat(Qt::RichText);
    descriptionLabel->setTextFormat(Qt::RichText);
    dueDateLabel->setTextFormat(Qt::RichText);
    priorityLabel->setTextFormat(Qt::RichText);
    statusLabel->setTextFormat(Qt::RichText);

    // Enable word wrap for longer text
    descriptionLabel->setWordWrap(true);
    descriptionLabel->setMaximumWidth(780);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(descriptionLabel);
    layout->addWidget(dueDateLabel);
    layout->addWidget(priorityLabel);
    layout->addWidget(statusLabel);

    // Add some spacing
    layout->setSpacing(8);
    layout->setContentsMargins(15, 15, 15, 15);

    setLayout(layout);

    // Set fixed size for better appearance
    setMinimumHeight(180);
    setMinimumWidth(350);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
