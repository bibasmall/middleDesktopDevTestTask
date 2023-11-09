#include <QTextStream>
#include "textStreamHttpClient.h"


TextStreamHttpClient::TextStreamHttpClient(QUrl host) : HttpClient(std::move(host))
{
    
}

void TextStreamHttpClient::processResponse(QByteArray replyText)
{
    QTextStream out(stdout);
    out << replyText;
}
