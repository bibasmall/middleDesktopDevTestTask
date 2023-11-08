#include <QJsonDocument>
#include <QTextStream>
#include <QJsonArray>
#include "textStreamHttpClient.h"


void TextStreamHttpClient::processResponse(QByteArray replyText)
{
    QTextStream out(stdout);
    out << replyText;
}

TextStreamHttpClient::TextStreamHttpClient(QUrl host) : HttpClient(std::move(host))
{
    
}