#ifndef IMAGE_SENDER_H
#define IMAGE_SENDER_H

#include <QImage>
#include <QTimer>

class ImageSender : public QObject
{
   Q_OBJECT

public:
   ImageSender(QObject* parent = nullptr);

   void start(int ms);

   QImage currentImage() const;

signals:
   void imageReady(const QImage& image);

private:
   QStringList _imagesList;
   int _currentIndex{0};
   QImage _currentImage;
   QTimer _timer;
};

#endif // IMAGE_SENDER_H
