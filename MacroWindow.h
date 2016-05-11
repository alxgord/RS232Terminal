#ifndef MACROWINDOW_H
#define MACROWINDOW_H

#include "Macros.h"
#include <QWidget>
#include <QList>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>
#include <QSettings>

class MacroWindow : public QWidget
{
    Q_OBJECT
    QPushButton *bAddMacros;
    QVBoxLayout *mainLayout;
    QSettings *settings;
    int id;

    void connections();

protected:
    virtual void closeEvent(QCloseEvent *e);

public slots:
    void addMacros();
    void delMacros(int index);
    void macrosRecieved(const QString &str){ emit WriteMacros(str); }
    void tick();

signals:
        WriteMacros(const QString &str);
public:
    QTimer *tMacro;
    QString path;
    int macrosCount;
    bool portOpen;
    QMap<int, Macros *> MacrosList;
    int sendingIndex;

    void start();
    void stop();
    void loadPrevSession();
    void saveSession();
    MacroWindow(QString title, QWidget *parent = 0);
};

#endif // MACROWINDOW_H
