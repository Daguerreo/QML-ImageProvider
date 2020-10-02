#include "image_sender.h"

#include <QDir>
#include <QDebug>

ImageSender::ImageSender(QObject* parent)
   : QObject(parent)
{
   QDir dir(":/images/");
   _imagesList = dir.entryList(QStringList("*.png"));

   connect(&_timer, &QTimer::timeout, this, [this, dir](){
      _currentImage.load(dir.path() + "/" + _imagesList.at(_currentIndex));
      emit imageReady(_currentImage);

      ++_currentIndex;
      if(_currentIndex >= _imagesList.count()){
         _currentIndex = 0;
      }
   });
}

void ImageSender::start(int ms)
{
   _timer.start(ms);
}

QImage ImageSender::currentImage() const
{
   return _currentImage;
}
