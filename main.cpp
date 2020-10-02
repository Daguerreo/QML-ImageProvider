#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "image_provider.h"
#include "image_sender.h"

int main(int argc, char *argv[])
{
   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
   QGuiApplication app(argc, argv);

   ImageSender sender;
   ImageProvider* provider = new ImageProvider;

   QQmlApplicationEngine engine;
   engine.rootContext()->setContextProperty("imageProvider", provider);
   engine.addImageProvider("stream", provider);

   const QUrl url(QStringLiteral("qrc:/main.qml"));
   QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
      &app, [url](QObject *obj, const QUrl &objUrl) {
         if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
      }, Qt::QueuedConnection);

   QObject::connect(&sender, &ImageSender::imageReady, provider, &ImageProvider::setImage);
   sender.start(60);
   engine.load(url);

   return app.exec();
}
