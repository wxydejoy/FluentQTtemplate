#include "ihbDebug.h"

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QDial>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "ElaPushButton.h"
#include "ElaLineEdit.h"



IhbDebug::IhbDebug(QWidget* parent)
    : IhbBasePage(parent) {


    QGridLayout* layout = new QGridLayout(this);
    // 设置layout的间距 0
    layout->setSpacing(0);
    // 设置layout的边距 0
    layout->setContentsMargins(0, 0, 0, 0);



    // grid 2x2
    // for (int i = 0; i < 2; i++) {
        
    //     for (int j = 0; j < 2; j++) {
    //         layout->addWidget(new ElaPushButton(QString("按钮%1%2").arg(i).arg(j)), i, j);
    //     }
    // }
    // 0-0 Label IMAGE
    QLabel * imageLabel = new QLabel(this);
    // label 设置图片背景
    imageLabel->setStyleSheet("background-image:url(:/include/Image/Moon.jpg);");

    layout->addWidget(imageLabel, 0, 0);

    QLabel * openGLLabel = new QLabel(this);
    // label 设置图片背景
    openGLLabel->setStyleSheet("background-image:url(:/include/Image/shoreKeeper.png);");

    layout->addWidget(openGLLabel, 1, 0);
    QWidget* mainWidget = new QWidget(this);
    mainWidget->setWindowTitle("功能导航");

    // 4电机布局 0,1
    MotorDebug* motorDebug1 = new MotorDebug(this, 1);
    MotorDebug* motorDebug2 = new MotorDebug(this, 2);
    MotorDebug* motorDebug3 = new MotorDebug(this, 3);
    MotorDebug* motorDebug4 = new MotorDebug(this, 4);
    QHBoxLayout* motorLayout = new QHBoxLayout(this);
    motorLayout->addWidget(motorDebug1);
    motorLayout->addWidget(motorDebug2);
    motorLayout->addWidget(motorDebug3);
    motorLayout->addWidget(motorDebug4);
    layout->addLayout(motorLayout, 0, 1);

    ARMDebug* armDebug1 = new ARMDebug(this);
    ARMDebug* armDebug2 = new ARMDebug(this);
    QHBoxLayout* armLayout = new QHBoxLayout(this);
    armLayout->addWidget(armDebug1);
    armLayout->addWidget(armDebug2);
    layout->addLayout(armLayout, 1, 1);



    // 将布局设置到主容器
    mainWidget->setLayout(layout);

    // qDebug() << "初始化成功";
    // QWidget* centralWidget = new QWidget(this);
    // centralWidget->setWindowTitle("aaa");
    addCentralWidget(mainWidget);
}





MotorDebug::MotorDebug(QWidget* parent, int motorIndex){

    // 整体宽度 100
    setFixedWidth(150);

    // 整体高度 200
    // setFixedHeight(300);

    // 电机转盘
    QDial* dial = new QDial(this);
    dial->setNotchesVisible(true);
    dial->setWrapping(true);
    dial->setMinimum(0);
    dial->setMaximum(100);
    dial->setValue(50);
    dial->setSingleStep(10);
    dial->setPageStep(10);
    dial->setNotchTarget(10);

    // dial 大小 100x100
    // dial->setFixedSize(100, 100);

    // 电机角度 lineEdit
    ElaLineEdit* angleLineEdit = new ElaLineEdit(parent);
    angleLineEdit->setPlaceholderText("角度");
    angleLineEdit->setMaxLength(3);
    angleLineEdit->setFixedWidth(60);
    angleLineEdit->setFixedHeight(30);
    // angleLineEdit->setAlignment(Qt::AlignCenter);
    angleLineEdit->setText("50");
    // 电机速度 lineEdit
    ElaLineEdit* speedLineEdit = new ElaLineEdit(parent);
    speedLineEdit->setPlaceholderText("速度");
    speedLineEdit->setMaxLength(3);
    speedLineEdit->setFixedWidth(60);
    speedLineEdit->setFixedHeight(30);
    // speedLineEdit->setAlignment(Qt::AlignCenter);
    speedLineEdit->setText("50");
    // 电机角度 label
    QLabel* angleLabel = new QLabel(parent);
    angleLabel->setText("角度");
    // 电机速度 label
    QLabel* speedLabel = new QLabel(parent);
    speedLabel->setText("速度");
    // 电机控制按钮
    ElaPushButton* controlButton = new ElaPushButton(parent);
    controlButton->setText("停止");
    
    // 添加到布局
    QHBoxLayout* anglcelayout = new QHBoxLayout();
    // layout 边框
    anglcelayout->setContentsMargins(0, 0, 0, 0);
    // layout 间距
    anglcelayout->setSpacing(0);
    anglcelayout->addWidget(angleLabel);
    anglcelayout->addWidget(angleLineEdit);
    QHBoxLayout* speedlayout = new QHBoxLayout();
    // layout 边框
    speedlayout->setContentsMargins(0, 0, 0, 0);
    // layout 间距
    speedlayout->setSpacing(0);
    speedlayout->addWidget(speedLabel);
    speedlayout->addWidget(speedLineEdit);


    QVBoxLayout* layout = new QVBoxLayout();
    // layout 边框
    layout->setContentsMargins(4, 4, 4, 4);
    // layout 间距
    layout->setSpacing(0);
    layout->addWidget(dial);
    layout->addLayout(anglcelayout);
    layout->addLayout(speedlayout);
    layout->addWidget(controlButton);
    this->setLayout(layout);
}

ARMDebug::ARMDebug(QWidget* parent){
    // 整体宽度 100
    setFixedWidth(300);
    


    // 每个ARM 8个关节
    QVBoxLayout* jointLayout = new QVBoxLayout();
    // layout 边框
    jointLayout->setContentsMargins(4, 4, 4, 4);
    // layout 间距
    jointLayout->setSpacing(0);

    // 添加说明行
    QLabel* indexlabel = new QLabel(parent);
    indexlabel->setText("编号");
    indexlabel->setFixedWidth(30);
    QLabel* anglelabel = new QLabel(parent);
    anglelabel->setText("当前角度");
    anglelabel->setFixedWidth(50);
    QLabel* stiffnesslabel = new QLabel(parent);
    stiffnesslabel->setText("当前变刚度");
    stiffnesslabel->setFixedWidth(50);
    QLabel* anglelabel2 = new QLabel(parent);
    anglelabel2->setText("目标角度");
    anglelabel2->setFixedWidth(70);
    QLabel* stiffnesslabel2 = new QLabel(parent);
    stiffnesslabel2->setText("目标变刚度");
    stiffnesslabel2->setFixedWidth(70);


    QHBoxLayout* headLayout = new QHBoxLayout();
    headLayout->addWidget(indexlabel);
    headLayout->addWidget(anglelabel);
    headLayout->addWidget(stiffnesslabel);
    headLayout->addWidget(anglelabel2);
    headLayout->addWidget(stiffnesslabel2);
    jointLayout->addLayout(headLayout);
    

    for (int i = 0; i < 8; i++){
        JointDebug* jointDebug = new JointDebug(parent, i);
        jointLayout->addWidget(jointDebug);
    }

    this->setLayout(jointLayout);

    // 整体高度 200
    // setFixedHeight(300);
}


JointDebug::JointDebug(QWidget* parent, int jointIndex){
    // 整体宽度 100
    setFixedWidth(300);

    // 整体高度 200
    // setFixedHeight(300);
    // 编号 角度 变钢度 
    QLabel* indexlabel = new QLabel(parent);
    indexlabel->setFixedWidth(30);
    QLabel* anglelabel = new QLabel(parent);
    anglelabel->setFixedWidth(50);
    QLabel* stiffnesslabel = new QLabel(parent);
    stiffnesslabel->setFixedWidth(50);
    indexlabel->setText(QString::number(jointIndex));
    anglelabel->setText(0);
    stiffnesslabel->setText(0);
    ElaLineEdit* angleLineEdit = new ElaLineEdit(parent);
    angleLineEdit->setPlaceholderText("角度");
    angleLineEdit->setMaxLength(3);
    angleLineEdit->setFixedWidth(70);
    angleLineEdit->setFixedHeight(30);

    ElaLineEdit* stiffnessLineEdit = new ElaLineEdit(parent);
    stiffnessLineEdit->setPlaceholderText("变钢度");
    stiffnessLineEdit->setMaxLength(3);
    stiffnessLineEdit->setFixedWidth(70);
    stiffnessLineEdit->setFixedHeight(30);

    QHBoxLayout* layout = new QHBoxLayout();
    // layout 边框
    layout->setContentsMargins(4, 4, 4, 4);
    // layout 间距
    layout->setSpacing(0);
    layout->addWidget(indexlabel);
    layout->addWidget(anglelabel);
    layout->addWidget(stiffnesslabel);
    layout->addWidget(angleLineEdit);
    layout->addWidget(stiffnessLineEdit);
    this->setLayout(layout);
    

}