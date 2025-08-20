#include "config.h"
#include "projectaliases.h"

#if APPNAME_USE_QML
#   include <QQmlApplicationEngine>
#   include <QQmlContext>
#else
#   include "ui/widgets/mainwindow.h"
#endif

#include <QApplication>
#include <QStyleHints>

#include "base/appname_global.h"
#include "qlogger/qloggerfactory.h"

/*****************************/
/* Macro definitions         */
/*****************************/
#define QML_MODULE_URI          APPNAME_INFO_NAME

#define APP_LOG_FILE            "logs/log.txt"
#define APP_LOG_NB_FILES        3
#define APP_LOG_SIZE            (1024 * 1024 * 5) // Equals 5 megabytes (Mb)
#define APP_LOG_ENABLE_CONSOLE  true

/*****************************/
/* Main method               */
/*****************************/

int main(int argc, char *argv[])
{
    /* Initialize logs */
    QLogger::QLoggerFactory::instance().initLoggerRotating(QFileInfo(APP_LOG_FILE), APP_LOG_NB_FILES, APP_LOG_SIZE, APP_LOG_ENABLE_CONSOLE);
    qInfo("Application %s is started [version: %s]", APPNAME_INFO_NAME, APPNAME_VERSION_STR);

    /* Choose between QML or widget app */
#if APPNAME_USE_QML
    QGuiApplication app(argc, argv);

    /* Load engine */
    QQmlApplicationEngine engine;
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
#endif

    /* Set context properties */
    std::unique_ptr<ExampleManager> exManager = std::make_unique<ExampleManager>();
    engine.rootContext()->setContextProperty("exManager", exManager.get());

    /* Load QML modules */
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    engine.loadFromModule(QML_MODULE_URI, "Main");
#else
    engine.load(QUrl(QStringLiteral("qrc:/qml/Main")));
#endif

#else
    QApplication app(argc, argv);

    MainWindow window;
    window.show();
#endif

    /* Set application properties */
    app.setWindowIcon(QIcon(":/logo/main"));
    app.setApplicationName(APPNAME_INFO_NAME);
    app.setApplicationVersion(APPNAME_VERSION_STR);
    app.addLibraryPath(":/plugins/imageformats");

    /* Manage theme */
    // Set ressources theme path
    QStringList themePathsList = QIcon::themeSearchPaths();
    themePathsList << ":/assets/icons";
    QIcon::setThemeSearchPaths(themePathsList);
    QIcon::setFallbackThemeName(QIcon::themeName());

    // Force theme to light (since dark is not supported on our app)
#if QT_VERSION >= QT_VERSION_CHECK(6, 8, 0)
    app.styleHints()->setColorScheme(Qt::ColorScheme::Light);
#endif
    QIcon::setThemeName("light");

    /* Start the application */
    return app.exec();
}
