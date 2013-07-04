#include "extension_qt/qwebviewext.h"
#include "webdriver_server.h"
#include <QtCore/QVariant>
#include <QtCore/QTime>
#include <QtCore/QDebug>
#include <QtNetwork/QNetworkProxy>
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif

QWebViewExt::QWebViewExt(QWidget *parent) :
    QWebView(parent)
{
    connect(page(), SIGNAL(windowCloseRequested()), this, SLOT(close()));
}

QWebViewExt::~QWebViewExt()
{
}

QWebView* QWebViewExt::createWindow(QWebPage::WebWindowType type)
{
    QWebViewExt* newView = new QWebViewExt;
    newView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    CommandLine cmdLine = webdriver::Server::GetInstance()->GetCommandLine();

    if (cmdLine.HasSwitch("wi-server"))
    {
        if (cmdLine.HasSwitch("wi-port"))
        {
            std::string wiPort = cmdLine.GetSwitchValueASCII("wi-port");
            int port = QString(wiPort.c_str()).toInt();
            newView->page()->setProperty("_q_webInspectorServerPort", port);
        }
        else
        {
            newView->page()->setProperty("_q_webInspectorServerPort", 9222);
        }
    }

    newView->show();
    newView->setAttribute(Qt::WA_DeleteOnClose, true);
    return newView;
}

