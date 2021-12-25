#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
#include <QWidget>
#include <QPlainTextEdit>
#include <QDebug>
#include <QTextBlock>
#include "src/main/cpp/menu/controller/mainwindow.h"

class Console : public QPlainTextEdit {
Q_OBJECT
public:
    explicit Console(QWidget *parent = nullptr);

    MainWindow *parentWindow;

protected:
    void keyPressEvent(QKeyEvent *event) override;

protected slots:

    void resetCursorPosition();
};

#endif // CONSOLE_H
