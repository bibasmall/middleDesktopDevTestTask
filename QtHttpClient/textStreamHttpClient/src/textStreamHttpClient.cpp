#include <QJsonDocument>
#include <QTextStream>
#include <QJsonArray>
#include "textStreamHttpClient.h"


TextStreamHttpClient& TextStreamHttpClient::instance(QUrl root)
{
    static TextStreamHttpClient i{root};
    return i;
}

void TextStreamHttpClient::processResponse(QByteArray replyText)
{
    QTextStream out(stdout);
    out << replyText;
}

TextStreamHttpClient::TextStreamHttpClient(QUrl host) : HttpClient(std::move(host))
{
    
}
