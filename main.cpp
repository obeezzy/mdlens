#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QQmlContext>

void printHelp(const char *appName)
{
    qDebug() << "Usage:" << QFileInfo(appName).baseName().toStdString().c_str() << "MD_FILE";
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    if (argc != 2) {
        printHelp(argv[0]);
        exit(1);
    }

    const QString &filename = QFileInfo(argv[1]).absoluteFilePath();
    QFile mdFile(filename);
    if (!mdFile.open(QFile::ReadOnly)) {
        qDebug() << "ERROR:" << mdFile.errorString();
        exit(1);
    }
    const QString MD_CONTENT = mdFile.readAll();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("MD_CONTENT", MD_CONTENT);
    engine.load(url);

    return app.exec();
}
