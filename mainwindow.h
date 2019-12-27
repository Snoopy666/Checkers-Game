#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "ui_mainwindow.h"
//#include "state.h"
#include "settingsdialog.h"
#include "checkersgame.h"
#include "checkersstate.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
	void open();
	void save();
	void startNewGame();
	void endGame();
	void settings();
	void about();
    void gameEnded(int status);
//	void setCounts(State * state);
//	void winned (bool color);
private:
	CheckersGame * game;
	SettingsDialog * dialog;
};

#endif // MAINWINDOW_H
