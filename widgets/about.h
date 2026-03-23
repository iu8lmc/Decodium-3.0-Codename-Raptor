// -*- Mode: C++ -*-
#ifndef ABOUTDLG_H
#define ABOUTDLG_H

#include <QDialog>
#include <QScopedPointer>
#include <QSettings>
#include <QCloseEvent>

namespace Ui {
  class CAboutDlg;
}

class CAboutDlg
  : public QDialog
{
public:
	explicit CAboutDlg(QWidget *parent = nullptr);
  ~CAboutDlg ();

protected:
  void showEvent (QShowEvent *) override;
  void closeEvent (QCloseEvent *) override;

private:
	QScopedPointer<Ui::CAboutDlg> ui;
};

#endif // ABOUTDLG_H
