#include "serial.h"
#include "ui_serial.h"
#include "setting.h"

serial::serial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serial)
{
    ui->setupUi(this);
    ui->retranslateUi(this);

    // 初始化串口
    m_serial = new Uartcore;

    // 寻找可用串口
    QStringList serialStrList;
    serialStrList = m_serial->scanSerial();
    for (int i=0; i<serialStrList.size(); i++)
    {
        ui->portComboBox->addItem(serialStrList[i]); // 在comboBox那添加串口号
    }

    // 默认设置波特率为115200（第5项）
    ui->baudComboBox->setCurrentIndex(5);
    // 当下位机中有数据发送过来时就会响应这个槽函数
    connect(m_serial, SIGNAL(readSignal()), this, SLOT(readSerialData()));

    QStatusBar* bar = ui->statusBar; //获取状态栏
    rx_label = new QLabel; //新建标签
    rx_label->setMinimumSize(300,20); //设置标签最小尺寸
    rx_label->setFrameShape(QFrame::NoFrame); //设置标签形状
    rx_label->setFrameShadow(QFrame::Plain); //设置标签阴影
    rx_label->setText(tr("RX: ")+"0");
    rx_label->setStyleSheet("QLabel { color : black; }");

    tx_label = new QLabel; //新建标签
    tx_label->setMinimumSize(300,20); //设置标签最小尺寸
    tx_label->setFrameShape(QFrame::NoFrame); //设置标签形状
    tx_label->setFrameShadow(QFrame::Plain); //设置标签阴影
    tx_label->setText((tr("TX: ") + "0"));
    tx_label->setStyleSheet("QLabel { color : black; }");

    connect_label = new QLabel; //新建标签
    connect_label->setMinimumSize(300,20); //设置标签最小尺寸
    connect_label->setFrameShape(QFrame::NoFrame); //设置标签形状
    connect_label->setFrameShadow(QFrame::Plain); //设置标签阴影
    connect_label->setText(tr("Serial Port not connect"));
    connect_label->setStyleSheet("QLabel { color : black; }");

    bar->addWidget(connect_label);
    bar->addWidget(rx_label);
    bar->addWidget(tx_label);
}

serial::~serial()
{
    delete ui;
}

void serial::on_refreshButton_clicked()
{
    // 寻找可用串口
    QStringList serialStrList;
    serialStrList = m_serial->scanSerial();
    ui->portComboBox->clear(); //清空当前的串口显示
    for (int i=0; i<serialStrList.size(); i++)
    {
        ui->portComboBox->addItem(serialStrList[i]); // 在comboBox那添加串口号
    }
}

void serial::on_openPortButton_clicked()
{
    if(ui->openPortButton->text() == tr("Open Port"))
    {
        if(m_serial->open(ui->portComboBox->currentText(), ui->baudComboBox->currentText().toInt()))
        {
            // 关闭下拉列表使能
            ui->portComboBox->setEnabled(false);
            ui->baudComboBox->setEnabled(false);
            // 修改按钮名称
            ui->openPortButton->setText(tr("Close Port"));
            connect_label->setText(tr("Port already opended"));
            connect_label->setStyleSheet("QLabel { color : green; }");
        }
    }
    else
    {
        // 关闭串口
        m_serial->close();
        // 重新开启下拉列表使能
        ui->portComboBox->setEnabled(true);
        ui->baudComboBox->setEnabled(true);
        // 恢复按钮名称
        ui->openPortButton->setText(tr("Open Port"));
        connect_label->setText(tr("Port already Closed"));
        connect_label->setStyleSheet("QLabel { color : black; }");
    }
}

void serial::on_sendButton_clicked()
{
    QByteArray sendData;
    if(ui->hexSendCheckBox->checkState() == false){
        sendData = ui->sendTextEdit->toPlainText().toLatin1();
    }else{
        sendData = m_serial->hexStringToByteArray(ui->sendTextEdit->toPlainText());
    }

    if (sendData <= 0) {
        ui->recvTextEdit->append(tr("Please Send Input Commands"));
        return;
    }

    tx_count += sendData.length();
    tx_label->setText("TX:"+QString::number(tx_count,10));
    m_serial->sendData(sendData);
}

// 读取从自定义串口类获得的数据
void serial::readSerialData()
{
    QString originStr = ui->recvTextEdit->toPlainText(); // 保存接收文本框原本的数据
    ui->recvTextEdit->clear();
    ui->recvTextEdit->setText(originStr);
    ui->recvTextEdit->moveCursor(QTextCursor::End); // 在末尾移动光标一格

    if(ui->hexRecvCheckBox->checkState()){
        ui->recvTextEdit->insertPlainText(m_serial->getReadBuf().toHex()); //转换成HEX
    }else{
        ui->recvTextEdit->insertPlainText(m_serial->getReadBuf());
    }
    rx_count += m_serial->getReadBuf().length();
    rx_label->setText("RX:"+QString::number(tx_count,10));
    //ui->recvTextEdit->moveCursor(QTextCursor::End); // 在末尾移动光标一格
    ui->recvTextEdit->insertPlainText("\n");

    m_serial->clearReadBuf(); // 读取完后，清空数据缓冲区
}

void serial::on_clearTextButton_clicked()
{
    ui->recvTextEdit->clear();
    ui->recvTextEdit->moveCursor(QTextCursor::Start);
    ui->sendTextEdit->clear();
}

void serial::on_actionExit_triggered()
{
    QApplication* app;
    app->exit(0);
}

void serial::on_openPortButton_3_clicked()
{
    setting param;
    param.set_serial_core_obj(m_serial);
    param.exec();
}
