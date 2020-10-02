#ifndef IMAGE_PROVIDER_H
#define IMAGE_PROVIDER_H

#include <QObject>
#include <QImage>
#include <QQuickImageProvider>

class ImageProvider : public QObject, public QQuickImageProvider
{
   Q_OBJECT

public:
   ImageProvider(QObject* parent = nullptr);

   QImage requestImage(const QString& id, QSize* size, const QSize& requestedSize) override;

   void setImage(const QImage& image);

signals:
   void imageUpdated();

private:
   QImage _image;
};

#endif // IMAGE_PROVIDER_H
