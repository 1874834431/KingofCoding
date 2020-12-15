#include "ui_mainWidget.h"

#include <qdir.h>
#include <qdebug.h>

void Ui_mainWidgetClass::setupUi(QWidget* mainWidgetClass) {
  if (mainWidgetClass->objectName().isEmpty())
    mainWidgetClass->setObjectName(QString::fromUtf8("mainWidgetClass"));
  mainWidgetClass->setWindowIcon(QIcon("./icons/ico.png"));
  /**************settings***************/
  QSettings* settings = new QSettings("./settings.ini", QSettings::IniFormat);
  int width = settings->value("/mainWidget/width").toInt();
  int height = settings->value("/mainWidget/height").toInt();
  delete settings;
  /**************settings***************/
  mainWidgetClass->resize(width, height);
  /**********************************/
  QHBoxLayout* stackedWidgetLayout = new QHBoxLayout;
  stackedWidget = new QStackedWidget;
  stackedWidgetLayout->addWidget(stackedWidget);
  mainWidgetClass->setLayout(stackedWidgetLayout);

  //menu
  QWidget* menu = new QWidget;
  QHBoxLayout* menu_title = new QHBoxLayout;
  title = new QLabel;
  menu_title->addStretch();
  menu_title->addWidget(title);
  menu_title->addStretch();
  aboutbtn = new QPushButton;
  tutorialbtn = new QPushButton;
  startbtn = new QPushButton;
  QHBoxLayout* menu_btn = new QHBoxLayout;
  menu_btn->addStretch();
  menu_btn->addWidget(aboutbtn);
  menu_btn->addStretch();
  menu_btn->addWidget(tutorialbtn);
  menu_btn->addStretch();
  menu_btn->addWidget(startbtn);
  menu_btn->addStretch();
  QVBoxLayout* menulayout = new QVBoxLayout;
  menulayout->addLayout(menu_title);
  menulayout->addLayout(menu_btn);
  menu->setLayout(menulayout);
  stackedWidget->addWidget(menu);

  //mode select
  QWidget* mode_select = new QWidget;
  QHBoxLayout* selectm_title_layout = new QHBoxLayout;
  selectm_title = new QLabel;
  selectm_title_layout->addStretch();
  selectm_title_layout->addWidget(selectm_title);
  selectm_title_layout->addStretch();
  QHBoxLayout* selectbtn_layout = new QHBoxLayout;
  stagebtn = new QPushButton;
  endlessbtn = new QPushButton;
  backToMenu = new QPushButton;
  selectbtn_layout->addStretch();
  selectbtn_layout->addWidget(stagebtn);
  selectbtn_layout->addStretch();
  selectbtn_layout->addWidget(endlessbtn);
  selectbtn_layout->addStretch();
  selectbtn_layout->addWidget(backToMenu);
  selectbtn_layout->addStretch();
  QVBoxLayout* mode_select_layout = new QVBoxLayout;
  mode_select_layout->addLayout(selectm_title_layout);
  mode_select_layout->addLayout(selectbtn_layout);
  mode_select->setLayout(mode_select_layout);
  stackedWidget->addWidget(mode_select);

  //stage select
  QWidget* stage_select = new QWidget;
  QVBoxLayout* stage_select_layout = new QVBoxLayout;
  stage_select_title = new QLabel;
  stage_list_widget = new QListWidget;
  stage_select_layout->addWidget(stage_select_title);
  stage_select_layout->addWidget(stage_list_widget);
  //button
  QHBoxLayout* btn_layout = new QHBoxLayout;
  btn_layout->addStretch();
  backToMode = new QPushButton;
  btn_layout->addWidget(backToMode);
  stage_select_layout->addLayout(btn_layout);
  stage_select->setLayout(stage_select_layout);
  stackedWidget->addWidget(stage_select);

  //game
  QWidget* game = new QWidget;
  QVBoxLayout* game_layout = new QVBoxLayout;
  //stage
  QHBoxLayout* stage_layouts[3];
  for (int i = 0; i < 3; ++i) {
    stage_layouts[i] = new QHBoxLayout;
    textZone[i] = new QLabel;
    stage_layouts[i]->addWidget(textZone[i]);
    stage_layouts[i]->addStretch();
    game_layout->addLayout(stage_layouts[i]);
  }
  //scoreboard
  QHBoxLayout* scoreboard_layout = new QHBoxLayout;
  health_label = new QLabel;
  score_label = new QLabel;
  time_label = new QLabel;
  scoreboard_layout->addWidget(health_label);
  scoreboard_layout->addStretch();
  scoreboard_layout->addWidget(score_label);
  scoreboard_layout->addStretch();
  scoreboard_layout->addWidget(time_label);
  game_layout->addLayout(scoreboard_layout);
  //keyboard
  keyboard_ = new keyboard;
  game_layout->addLayout(keyboard_->keyboard_layout);
  //apply
  game->setLayout(game_layout);
  stackedWidget->addWidget(game);

  //about
  QWidget* about = new QWidget;
  QVBoxLayout* about_layout = new QVBoxLayout;
  about_layout->addStretch();
  aboutTitle = new QLabel;
  about_layout->addWidget(aboutTitle);
  aboutInfo = new QLabel;
  about_layout->addWidget(aboutInfo);
  about_layout->addStretch();
  QHBoxLayout* about_btn_layout = new QHBoxLayout;
  aboutToMenu = new QPushButton;
  about_btn_layout->addStretch();
  about_btn_layout->addWidget(aboutToMenu);
  about_layout->addLayout(about_btn_layout);
  about->setLayout(about_layout);
  stackedWidget->addWidget(about);
  /**********************************/
  retranslateUi(mainWidgetClass);

  QMetaObject::connectSlotsByName(mainWidgetClass);
}

void Ui_mainWidgetClass::retranslateUi(QWidget* mainWidgetClass) {
  mainWidgetClass->setWindowTitle(QCoreApplication::translate("mainWidgetClass", "King of Coding-v1.0.0-Beta", nullptr));
  //menu
  QFont titleft;
  titleft.setPointSize(60);
  titleft.setFamily("Curlz MT");
  this->title->setFont(titleft);
  this->title->setText("<font color=pink>King</font>\t<font color=blue>of</font>\t<font color=indigo>Coding</font>");
  this->title->setAlignment(Qt::AlignCenter);
  QFont btnft;
  btnft.setPointSize(20);
  btnft.setFamily("Bauhaus 93");
  this->tutorialbtn->setFont(btnft);
  this->tutorialbtn->setText("Tutorials");
  this->startbtn->setFont(btnft);
  this->startbtn->setText("Start");
  this->aboutbtn->setFont(btnft);
  this->aboutbtn->setText("About");
  
  //mode select
  QFont selectmTitleFt;
  selectmTitleFt.setPointSize(50);
  selectmTitleFt.setFamily("Berlin Sans FB Demi");
  this->selectm_title->setFont(selectmTitleFt);
  this->selectm_title->setText("select mode");
  this->stagebtn->setFont(btnft);
  this->stagebtn->setText("Stage mode");
  this->endlessbtn->setFont(btnft);
  this->endlessbtn->setText("Endless mode");
  this->backToMenu->setFont(btnft);
  this->backToMenu->setText("Back");
  
  //stage select
  QFont stageSelectTitleFt;
  stageSelectTitleFt.setPointSize(20);
  stageSelectTitleFt.setFamily("Berlin Sans FB Demi");
  this->stage_select_title->setFont(stageSelectTitleFt);
  this->stage_select_title->setText("Select Stage");
  QDir dir("./stages");
  dir.setNameFilters(QStringList("*.stg"));
  QFileInfoList stages = dir.entryInfoList();
  QFont stageListFt;
  stageListFt.setPointSize(15);
  stageListFt.setFamily("Consolas");
  this->stage_list_widget->setFont(stageListFt);
  for (auto&& i : stages)
    this->stage_list_widget->addItem(i.fileName().split('.')[0]);

  this->backToMode->setFont(btnft);
  this->backToMode->setText("Back");

  //game
  QFont scoreBoardFt;
  scoreBoardFt.setPointSize(15);
  scoreBoardFt.setFamily("Comic Sans MS");
  this->health_label->setFont(scoreBoardFt);
  this->health_label->setAlignment(Qt::AlignCenter);
  this->health_label->setText("<img src=\"./icons/health.png\">Health: ");
  this->time_label->setFont(scoreBoardFt);
  this->time_label->setText("<img src=\"./icons/time.png\">Time Used: 0.00");
  //this->time_label->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
  this->time_label->setMinimumWidth(270);
  this->score_label->setFont(scoreBoardFt);
  this->score_label->setText("<img src=\"./icons/score.png\">Score: 0.00");
  QFont textZoneFt;
  textZoneFt.setPointSize(12);
  for (auto&& i : this->textZone)
    i->setFont(textZoneFt);

  //about
  this->aboutToMenu->setFont(btnft);
  this->aboutToMenu->setText("Back");
  this->aboutbtn->setFont(btnft);
  this->aboutbtn->setText("About");
  QFont aboutTitleFt;
  aboutTitleFt.setPointSize(40);
  aboutTitleFt.setFamily("Curlz MT");
  aboutTitleFt.setBold(true);
  this->aboutTitle->setFont(aboutTitleFt);
  this->aboutTitle->setAlignment(Qt::AlignCenter);
  this->aboutTitle->setText("<font color=pink>King</font>\t<font color=blue>of</font>\t<font color=indigo>Coding</font>");
  QFont aboutInfoFt;
  aboutInfoFt.setPointSize(25);
  aboutInfoFt.setFamily("Consolas");
  this->aboutInfo->setFont(aboutInfoFt);
  this->aboutInfo->setText("<font>Version: 1.0.0-Beta<br>Author: Chen Yiming<br>Other: This program is only for personal use.</font><br><font color=red>Any actions of plagiarism is prohibitted.</font>");

  this->stackedWidget->setCurrentIndex(0);
}