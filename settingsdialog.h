#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
    class SettingsDialog;
}

class SettingsDialog : public QDialog {
    Q_OBJECT
public:
    SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();
	void loadSettings();
protected:
    void changeEvent(QEvent *e);
private slots:
	void saveSettings();
private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
