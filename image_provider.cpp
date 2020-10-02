#include "image_provider.h"


ImageProvider::ImageProvider(QObject* parent)
   : QObject(parent), QQuickImageProvider(QQuickImageProvider::Image)
{
}

QImage ImageProvider::requestImage(const QString& /*id*/, QSize* size, const QSize& requestedSize)
{
   if(size) *size = _image.size();

   if(requestedSize.width() > 0 && requestedSize.height() > 0 ){
      _image = _image.scaled(requestedSize.width(), requestedSize.height(), Qt::KeepAspectRatio);
   }

   return _image;
}

void ImageProvider::setImage(const QImage& image)
{
   if(!image.isNull()){
      _image = image;
      emit imageUpdated();
   }
}
