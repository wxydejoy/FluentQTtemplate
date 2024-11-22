#include "ihbConnect.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>
#include <QIntValidator>

#include "ElaToggleButton.h"
// #include "rostopicconnect.h"
#include "ElaLineEdit.h"
#include "ElaPushButton.h"
#include "ElaToggleSwitch.h"
// #include "ElaLineEdit.h"

IhbConnect::IhbConnect(QWidget *parent)
    : IhbBasePage(parent)
{

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setSpacing(0);
    // 设置layout的边距 0
    layout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->setSpacing(0);
    // 设置layout的边距 0
    hlayout->setContentsMargins(0, 0, 0, 0);
    ElaToggleButton *butt1 = new ElaToggleButton(this);
    ElaLineEdit *domainID = new ElaLineEdit(this);
    domainID->setText("14");
    domainID->setPlaceholderText("请输入DomainID");
    domainID->setMaxLength(2);
    domainID->setValidator(new QIntValidator(0, 99, this));
    domainID->setFixedWidth(80);
    domainID->setFixedHeight(30);

    // butt1
    // ElaToggleButton* butt2 = new ElaToggleButton(this);
    butt1->setText("ROS");
    butt1->setIsToggled(true);
    // 添加label
    QLabel *label = new QLabel("连接方式");
    hlayout->addWidget(label);
    hlayout->addStretch();
    hlayout->addWidget(butt1);
    hlayout->addWidget(domainID);
    layout->addLayout(hlayout);
    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->setSpacing(0);
    // 设置layout的边距 0
    vlayout->setContentsMargins(0, 0, 0, 0);
    RosTopicConnect *rosTopicStatus = new RosTopicConnect(this, "/ihbStatus");
    RosTopicConnect *rosTopicTest = new RosTopicConnect(this, "/test");
    RosTopicConnect *rosTopicImage = new RosTopicConnect(this, "/camera/image_raw");
    RosTopicConnect *rosTopicDepth = new RosTopicConnect(this, "/camera/depth/image_rect_raw");
    RosTopicConnect *rosTopicInfo = new RosTopicConnect(this, "/camera/depth/camera_info");
    RosTopicConnect *rosTopicImu = new RosTopicConnect(this, "/imu/data_raw");
    RosTopicConnect *rosTopicPose = new RosTopicConnect(this, "/pose");
    RosTopicConnect *rosTopicCmd = new RosTopicConnect(this, "/cmd_vel");
    RosTopicConnect *rosTopicCmdPose = new RosTopicConnect(this, "/cmd_pose");
    RosTopicConnect *rosTopicCmdPoseStamped = new RosTopicConnect(this, "/cmd_pose_stamped");
    RosTopicConnect *rosTopicCmdVel = new RosTopicConnect(this, "/cmd_vel");
    RosTopicConnect *rosTopicCmdVelStamped = new RosTopicConnect(this, "/cmd_vel_stamped");
    RosTopicConnect *rosTopicCmdTwist = new RosTopicConnect(this, "/cmd_twist");
    // RosTopicConnect* rosTopicCmdTwistStamped = new RosTopicConnect(this, "/cmd_twist_stamped");
    // RosTopicConnect* rosTopicCmdPoseTwist = new RosTopicConnect(this, "/cmd_pose_twist");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped = new RosTopicConnect(this, "/cmd_pose_twist_stamped");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped2 = new RosTopicConnect(this, "/cmd_pose_twist_stamped2");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped3 = new RosTopicConnect(this, "/cmd_pose_twist_stamped3");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped4 = new RosTopicConnect(this, "/cmd_pose_twist_stamped4");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped5 = new RosTopicConnect(this, "/cmd_pose_twist_stamped5");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped6 = new RosTopicConnect(this, "/cmd_pose_twist_stamped6");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped7 = new RosTopicConnect(this, "/cmd_pose_twist_stamped7");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped8 = new RosTopicConnect(this, "/cmd_pose_twist_stamped8");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped9 = new RosTopicConnect(this, "/cmd_pose_twist_stamped9");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped10 = new RosTopicConnect(this, "/cmd_pose_twist_stamped10");
    // RosTopicConnect* rosTopicCmdPoseTwistStamped11 = new RosTopicConnect(this, "/cmd_pose_twist_stamped11");

    vlayout->addWidget(rosTopicStatus);
    vlayout->addWidget(rosTopicTest);
    vlayout->addWidget(rosTopicImage);
    vlayout->addWidget(rosTopicDepth);
    vlayout->addWidget(rosTopicInfo);
    vlayout->addWidget(rosTopicImu);
    vlayout->addWidget(rosTopicPose);
    vlayout->addWidget(rosTopicCmd);
    vlayout->addWidget(rosTopicCmdPose);
    vlayout->addWidget(rosTopicCmdPoseStamped);
    vlayout->addWidget(rosTopicCmdVel);
    vlayout->addWidget(rosTopicCmdVelStamped);
    vlayout->addWidget(rosTopicCmdTwist);
    // vlayout->addWidget(rosTopicCmdTwistStamped);
    // vlayout->addWidget(rosTopicCmdPoseTwist);
    // vlayout->addWidget(rosTopicCmdPoseTwistStamped);
    // vlayout->addWidget(rosTopicCmdPoseTwistStamped2);
    // vlayout->addWidget(rosTopicCmdPoseTwistStamped2);

    QWidget *container = new QWidget;
    container->setLayout(vlayout);

    // 设置容器的可见性
    // container->setVisible(true);  // 显示容器及其布局中的所有窗口部件
    // container->setVisible(false); // 隐藏容器及其布局中的所有窗口部件

    layout->addWidget(container);

    // butt1 按下 隐藏 vlayout
    connect(butt1, &ElaToggleButton::toggled, [=](bool checked)
            { container->setVisible(checked); });

    QWidget *mainWidget = new QWidget(this);
    mainWidget->setWindowTitle("连接配置");

    // 将布局设置到主容器
    mainWidget->setLayout(layout);

    // qDebug() << "初始化成功";
    // QWidget* centralWidget = new QWidget(this);
    // centralWidget->setWindowTitle("aaa");
    addCentralWidget(mainWidget);
}


RosTopicConnect::RosTopicConnect(QWidget *parent , const QString topicName)
    : QWidget{parent}
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    ElaLineEdit *topicNameEdit = new ElaLineEdit(this);
    topicNameEdit->setText(topicName);
    ElaPushButton *push = new ElaPushButton("STOP");
    ElaToggleSwitch *sw = new ElaToggleSwitch();
    // 修改push背景颜色
    push->setDisabled(true);

    // horizon spacer
    topicNameEdit->setFixedWidth(400);
    topicNameEdit->setFixedHeight(30);

    QLabel *label1 = new QLabel("Topic Class:");
    QLabel *classlabel = new QLabel("None");
    QLabel *label2 = new QLabel("Topic HZ:");
    QLabel *hzlabel = new QLabel("0");

    layout->addWidget(topicNameEdit);
    layout->addStretch(); // 水平方向弹簧

    layout->addWidget(label1);
    layout->addWidget(classlabel);
    layout->addStretch(); // 水平方向弹簧

    layout->addWidget(label2);
    layout->addWidget(hzlabel);
    layout->addStretch(); // 水平方向弹簧
    layout->addWidget(push);
    layout->addWidget(sw);

    this->setLayout(layout);

    // connect
    // sw 切换 改变push背景颜色
    connect(sw, &ElaToggleSwitch::toggled, this, [=](bool checked)
            {
    if(checked){
        push->setDisabled(false);
        push->setText("RUNNING");
        // push
    }else{
        push->setDisabled(true);
        push->setText("STOP");
    } });
}
