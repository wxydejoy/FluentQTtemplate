#include <QDebug>
#include <QApplication>
#include <QMainWindow>
#include <QTranslator>

#include <QFontDatabase>
#include <QFont>
#include <QScreen>
#include "mainwindow.h"

// 这个数组的内容来自 CMakeLists.txt 中对于支持的语言的设置
const char *supportedLocales[] = { LOCALES_NAME_ARRAY };

// 入口 main 函数
int main(int argc, char* argv[]) {

#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
        QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    #else
        //根据实际屏幕缩放比例更改
        qputenv("QT_SCALE_FACTOR", "1");
    #endif
#endif

    QApplication app(argc, argv);
    QFontDatabase::addApplicationFont(":/include/Font/ElaAwesome.ttf");
    // QFontDatabase::addApplicationFont(":/include/Font/AA.ttf");

    QLocale defaultLocale = []() -> QLocale {
        QLocale systemLocale = QLocale::system();
        for (const char* locale : supportedLocales) {
            if (systemLocale.name() == locale) {
                return systemLocale;
            }
        }
        return QLocale(supportedLocales[0]);
    }();

    QTranslator translator;


#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    // Qt6 中的加载方式
    if (translator.load(defaultLocale, QString::fromUtf8(LOCALE_PREFIX), QStringLiteral("_"), QStringLiteral("./"))) {
        qApp->installTranslator(&translator);
    } else {
        qWarning() << "Failed to load translation for locale:" << defaultLocale.name();
    }
#else
    // Qt5 中的加载方式
    if (translator.load(defaultLocale.name(), QString::fromUtf8(LOCALE_PREFIX), QStringLiteral("_"), QStringLiteral("./"))) {
        qApp->installTranslator(&translator);
    } else {
        qWarning() << "Failed to load translation for locale:" << defaultLocale.name();
    }
#endif


    QFont font("最像素体");
    // qt 6 必须
    font.setHintingPreference(QFont::PreferNoHinting);

    app.setFont(font);


    // 运行主窗口
    MainWindow mv;
    mv.show();

    return QApplication::exec();
}
