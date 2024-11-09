#include <QDebug>
#include <QApplication>
#include <QMainWindow>
#include <QTranslator>

#include <QFontDatabase>
#include <QFont>

#include "mainwindow.h"

// 这个数组的内容来自 CMakeLists.txt 中对于支持的语言的设置
const char *supportedLocales[] = { LOCALES_NAME_ARRAY };

// 入口 main 函数
int main(int argc, char* argv[]) {
    // QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    // qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "0");
    // QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);


#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#else
    //根据实际屏幕缩放比例更改
    qputenv("QT_SCALE_FACTOR", "1.5");
#endif
#endif
    QApplication app(argc, argv);
    // 获取字体数据库实例
    // 加载第一个自定义字体并获取其家族名称
    int fontIdA = QFontDatabase::addApplicationFont(":/include/Font/思源黑体-Medium.otf");  // 使用资源路径
    QStringList fontFamiliesA = QFontDatabase::applicationFontFamilies(fontIdA);
    if (fontFamiliesA.isEmpty()) {
        qWarning() << "无法加载 CustomFontA.ttf";
    }

    // 加载第二个自定义字体并获取其家族名称
    int fontIdB = QFontDatabase::addApplicationFont(":/include/Font/ElaAwesome.ttf");
    QStringList fontFamiliesB = QFontDatabase::applicationFontFamilies(fontIdB);
    if (fontFamiliesB.isEmpty()) {
        qWarning() << "无法加载 CustomFontB.ttf";
    }

    // 创建字体，并将两个自定义字体的家族名称作为系列
    QFont customFont;
    if (!fontFamiliesA.isEmpty() && !fontFamiliesB.isEmpty()) {
        customFont.setFamily(fontFamiliesA.at(0) + ", " + fontFamiliesB.at(0));  // 设置优先级
    } else {
        customFont.setFamily("Arial");  // 默认字体
    }
    customFont.setPointSize(14);

    app.setFont(customFont);

    // 获取默认 QLocale 对象
    QLocale defaultLocale = []() -> QString {
        QString systemLocale = QLocale::system().name();
        for (const char* local : supportedLocales) {
            if (systemLocale == local) {
                return systemLocale;
            }
        }
        return supportedLocales[0];
    }();

    // 设置 Translator 对象
    QTranslator translator;
    translator.load(defaultLocale, LOCALE_PREFIX, "_", "./");
    QApplication::installTranslator(&translator);

    // 运行主窗口
    MainWindow mv;
    // mv.setWindowIcon(QIcon(":/Qt_48x48.ico"));
    mv.show();

    return QApplication::exec();
}
