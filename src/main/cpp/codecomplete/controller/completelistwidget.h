#ifndef COMPLETELISTWIDGET_H
#define COMPLETELISTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QPlainTextEdit>
#include <QApplication>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::min;

class CompleteListWidget : public QListWidget {
public:
    CompleteListWidget(QWidget *parent = 0);

    static int ldistance(const std::string source, const std::string target);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QPlainTextEdit *p;
    QColor backgroundColor;
    QColor highlightColor;
};

#endif // COMPLETELISTWIDGET_H
