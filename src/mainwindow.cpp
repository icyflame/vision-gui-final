#include "mainwindow.h"
#include "ui_mainwindow.h"

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int time = 100;
    colorLabel = new MyLabel();
    colorLabel->setMinimumSize(QSize(320, 240));
    colorLabel->setMaximumSize(QSize(320, 240));
    colorLabel->setAlignment(Qt::AlignCenter);
    ui->verticalLayout->addWidget(colorLabel);
    ui->openCamera->setEnabled(true);
    ui->startCamera->setEnabled(false);
    ui->pauseCamera->setEnabled(false);
    ui->closeCamera->setEnabled(false);
    ui->openFile->setEnabled(true);
    ui->writeFile->setEnabled(false);
    ui->closeFile->setEnabled(false);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_updateImages()));
    connect(colorLabel,SIGNAL(on_mouseDoubleClickEvent(QMouseEvent* )),this,SLOT(on_colorImage_mouseDoubleClickEvent(QMouseEvent*)));
    timer->start(time);
    video_being_processed = false;
    camera_opend = false;

    mblurVal = 1;
    gblurVal = 1;
    blurVal = 1;

    dilate_b = false;
    erode_b = false;

    kernelSizeVal = 3;
    kernelShape = 0;

    //    mblurVal = 5;

}

void MyWindow::setThresh()
{
    int H_max = ui->HValue_slider->value()+ui->HThreshValue_slider->value();
    int S_max = ui->SValue_slider->value()+ui->SThreshValue_slider->value();
    int V_max = ui->VValue_slider->value()+ui->VThreshValue_slider->value();
    int H_min = ui->HValue_slider->value()-ui->HThreshValue_slider->value();
    int S_min = ui->SValue_slider->value()-ui->SThreshValue_slider->value();
    int V_min = ui->VValue_slider->value()-ui->VThreshValue_slider->value();
    if(H_max>255)
    {
        H_max=255;
    }
    if(H_min<0)
    {
        H_min=0;
    }
    if(S_max>255)
    {
        S_max=255;
    }
    if(S_min<0)
    {
        S_min=0;
    }
    if(V_max>255)
    {
        V_max=255;
    }
    if(V_min<0)
    {
        V_min=0;
    }
    start = cv::Scalar(H_min,S_min,V_min);
    end = cv::Scalar(H_max,S_max,V_max);
}

void MyWindow::on_openFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "/home/","*.th");
    if(!filename.isEmpty())
    {
        fileName = filename.toStdString();
        std::cout<<fileName<<std::endl;
        std::ifstream file(fileName.c_str());
        if(file.is_open())
        {
            file.close();
            ui->openFile->setEnabled(false);
            ui->writeFile->setEnabled(true);
            ui->closeFile->setEnabled(true);
        }
        else
        {
            QString name(fileName.c_str());
            QMessageBox::question(  this,
                                    tr("Error"),
                                    tr("Cannot open file \"%1\"?").arg(name),
                                    QMessageBox::Ok);
        }
    }
}

void MyWindow::on_writeFile_clicked()
{
    std::ofstream file(fileName.c_str());
    if(file.is_open())
    {
        int H_max = ui->HValue_slider->value()+ui->HThreshValue_slider->value();
        int S_max = ui->SValue_slider->value()+ui->SThreshValue_slider->value();
        int V_max = ui->VValue_slider->value()+ui->VThreshValue_slider->value();
        int H_min = ui->HValue_slider->value()-ui->HThreshValue_slider->value();
        int S_min = ui->SValue_slider->value()-ui->SThreshValue_slider->value();
        int V_min = ui->VValue_slider->value()-ui->VThreshValue_slider->value();
        if(H_max>255)
        {
            H_max=255;
        }
        if(H_min<0)
        {
            H_min=0;
        }
        if(S_max>255)
        {
            S_max=255;
        }
        if(S_min<0)
        {
            S_min=0;
        }
        if(V_max>255)
        {
            V_max=255;
        }
        if(V_min<0)
        {
            V_min=0;
        }
        file<<H_min<<std::endl;
        file<<S_min<<std::endl;
        file<<V_min<<std::endl;
        file<<H_max<<std::endl;
        file<<S_max<<std::endl;
        file<<V_max<<std::endl;
        file<<ui->BlobValue_slider->value()<<std::endl;
        file.close();
    }
    else
    {
        QString name(fileName.c_str());
        QMessageBox::question(  this,
                                tr("Error"),
                                tr("Cannot open file \"%1\"?").arg(name),
                                QMessageBox::Ok);
        ui->openFile->setEnabled(true);
        ui->writeFile->setEnabled(false);
        ui->closeFile->setEnabled(false);
    }
}

void MyWindow::on_closeFile_clicked()
{
    fileName.clear();
    ui->openFile->setEnabled(true);
    ui->writeFile->setEnabled(false);
    ui->closeFile->setEnabled(false);
}

void MyWindow::on_openCamera_clicked()
{
    video_being_processed = false;
    camera_opend = false;
    std::cout<<ui->cameraNo->currentIndex()<<std::endl;
    if(cam.open(ui->cameraNo->currentIndex()))
    {
        camera_opend = true;
        ui->openCamera->setEnabled(false);
        ui->startCamera->setEnabled(true);
        ui->pauseCamera->setEnabled(false);
        ui->closeCamera->setEnabled(false);
    }
    else
    {
        
    }
}

void MyWindow::on_startCamera_clicked()
{
    if(camera_opend)
    {
        video_being_processed = true;
        ui->openCamera->setEnabled(false);
        ui->startCamera->setEnabled(false);
        ui->pauseCamera->setEnabled(true);
        ui->closeCamera->setEnabled(true);
        setThresh();
    }
    else
    {
        
    }
}

void MyWindow::on_pauseCamera_clicked()
{
    if(video_being_processed)
    {
        video_being_processed = false;
    }
    else
    {
        video_being_processed = true;
    }
}

void MyWindow::on_closeCamera_clicked()
{
    video_being_processed = false;
    camera_opend = false;
    cam.release();
    ui->openCamera->setEnabled(true);
    ui->startCamera->setEnabled(false);
    ui->pauseCamera->setEnabled(false);
    ui->closeCamera->setEnabled(false);
}

void MyWindow::on_HValue_slider_valueChanged(int value)
{
    std::ostringstream str;
    str<<value;
    ui->HValue_text->setText(QString(str.str().c_str()));
    setThresh();
}

void MyWindow::on_SValue_slider_valueChanged(int value)
{
    std::ostringstream str;
    str<<value;
    ui->SValue_text->setText(QString(str.str().c_str()));
    setThresh();
}

void MyWindow::on_VValue_slider_valueChanged(int value)
{
    std::ostringstream str;
    str<<value;
    ui->VValue_text->setText(QString(str.str().c_str()));
    setThresh();
}

void MyWindow::on_HThreshValue_slider_valueChanged(int value)
{
    std::ostringstream str;
    str<<value;
    ui->HThreshValue_text->setText(QString(str.str().c_str()));
    setThresh();
}

void MyWindow::on_SThreshValue_slider_valueChanged(int value)
{
    std::ostringstream str;
    str<<value;
    ui->SThreshValue_text->setText(QString(str.str().c_str()));
    setThresh();
}

void MyWindow::on_VThreshValue_slider_valueChanged(int value)
{
    std::ostringstream str;
    str<<value;
    ui->VThreshValue_text->setText(QString(str.str().c_str()));
    setThresh();
}

void MyWindow::on_blurSlider_valueChanged(int value){
    blurVal = value;
    std::cout << "The value of blur is :- " << blurVal << "\n";
    //    std::cout << "value changed!";
    std::ostringstream str;
    str << blurVal;
    ui->blurValLineEdit->setText(QString(str.str().c_str()));
    return;
}

void MyWindow::on_mblurSlider_valueChanged(int value){
    mblurVal = 2 * value + 1;
    std::cout << "The value of median is :- " << mblurVal << "\n";
    //    std::cout << "value changed!";
    std::ostringstream str;
    str << mblurVal;
    ui->mblurValLineEdit->setText(QString(str.str().c_str()));
    return;
}

void MyWindow::on_gblurSlider_valueChanged(int value){
    gblurVal = 2 * value + 1;
    std::cout << "The value of gblur is :- " << gblurVal << "\n";
    //    std::cout << "value changed!";
    std::ostringstream str;
    str << gblurVal;
    ui->gblurValLineEdit->setText(QString(str.str().c_str()));
    return;
}

void MyWindow::on_dilateCheck_clicked(){
    dilate_b = !dilate_b;

    std::cout << dilate_b;
}

void MyWindow::on_erodeCheck_clicked(){
    erode_b = !erode_b;

    std::cout << erode_b;
}

void MyWindow::on_morphellipse_clicked(){
    kernelShape = 0;
    std::cout << kernelShape;
}

void MyWindow::on_morphrect_clicked(){
    kernelShape = 1;
    std::cout << kernelShape;
}

void MyWindow::on_morphcross_clicked(){
    kernelShape = 2;
    std::cout << kernelShape;
}

void MyWindow::on_kernelSizeSlider_valueChanged(int value){
    kernelSizeVal = value;
    std::ostringstream str;
    str << value;
    ui->kernelSizeLineEdit->setText(QString(str.str().c_str()));
}

void MyWindow::on_BlobValue_slider_valueChanged(int value)
{
    std::ostringstream str;
    str<<value;
    ui->BlobValue_text->setText(QString(str.str().c_str()));
    setThresh();
}

void MyWindow::on_colorImage_mouseDoubleClickEvent(QMouseEvent *ev)
{
    std::cout<<ev->x()<<" : "<<ev->y()<<std::endl;
    //uchar* data = colorImage.data;
    vec = thImage.at<cv::Vec3b>(ev->y(),ev->x());
    //    int H = data[ev->y()*colorImage.step1+ev->x()];
    //    int S = data[ev->y()*colorImage.step1+ev->x()+1];
    //    int V = data[ev->y()*colorImage.step1+ev->x()+2];
    ui->HValue_slider->setValue(vec[0]);
    ui->SValue_slider->setValue(vec[1]);
    ui->VValue_slider->setValue(vec[2]);
    std::cout<<"H:"<<(int)vec[0]<<"S:"<<(int)vec[1]<<"V:"<<(int)vec[2]<<std::endl;
    setThresh();
}

void MyWindow::on_updateImages()
{
    if(video_being_processed)
    {
        cam>>camImage;
        cv::resize(camImage,colorImage,cv::Size(320,240));
        cv::cvtColor(colorImage,thImage,CV_RGB2HSV_FULL);

        using namespace cv;

        blur(thImage, thImage, Size(blurVal,blurVal));
        medianBlur(thImage,thImage,mblurVal);
        GaussianBlur(thImage, thImage, Size(gblurVal,gblurVal), 0);

        using namespace cv;

        Mat dilatekernel;

        if(kernelShape == 0)

            dilatekernel = getStructuringElement(MORPH_ELLIPSE, Size(kernelSizeVal, kernelSizeVal));

        if(kernelShape == 1)

            dilatekernel = getStructuringElement(MORPH_RECT, Size(kernelSizeVal, kernelSizeVal));

        if(kernelShape == 2)

            dilatekernel = getStructuringElement(MORPH_CROSS, Size(kernelSizeVal, kernelSizeVal));

        // First and second both argument selectable

        if(dilate_b)

            dilate(thImage, thImage, dilatekernel);

        if(erode_b)

            erode(thImage, thImage, dilatekernel);

        cv::inRange(thImage,start,end,binaryImage);
        displayImages();
    }
    else
    {
        
    }
}

void MyWindow::displayImages()
{
    /////////////////////////////////////////////////////////////////
    //cv::resize(image_raw,image_Qimage,cv::Size(400,275));
    cv::cvtColor(colorImage,displayImage,CV_BGR2RGB);
    QImage display1((uchar *)displayImage.data,displayImage.cols,
                    displayImage.rows,QImage::Format_RGB888);
    colorLabel->setPixmap(QPixmap::fromImage(display1));
    //////////////////////////////////////////////////////////////////
    //images[2].matrixToMat(image_processed);
    //cv::resize(image_processed,image_Qimage,cv::Size(400,275));
    //cv::cvtColor(image_Qimage,image_Qimage,CV_BGRA2RGB);
    QImage display2((uchar *)binaryImage.data,binaryImage.cols,
                    binaryImage.rows,QImage::Format_Indexed8);
    ui->binaryImage->setPixmap(QPixmap::fromImage(display2));
    //////////////////////////////////////////////////////////////////
}

MyWindow::~MyWindow()
{
    std::cout<<"deleting "<<std::endl;
}

void MyWindow::closeEvent(QCloseEvent *)
{
    std::cout<<"closing"<<std::endl;
    if(video_being_processed)
    {
        //on_Stop_clicked();
    }
    else
    {
    }
}

