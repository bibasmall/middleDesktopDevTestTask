#include "httpClient.h"
#include <QBitArray>
#include <QString>


HttpClient& HttpClient::instance(QUrl url)
{
    static HttpClient i{std::move(url)};
    return i;
}

void HttpClient::request(QUrl url, RequestType rtype, QByteArray&& body)
{
    if(rtype == RequestType::GET)
        manager.get(QNetworkRequest(this->host.resolved(url)));
    else if(rtype == RequestType::POST)
        manager.post(QNetworkRequest(this->host.resolved(url)), body);    
}

void HttpClient::request(const HttpRequest& r)
{
    QNetworkRequest nr(this->host.resolved(r.url));
    for(auto& p : r.headers)
        nr.setRawHeader(p.first, p.second);
    if(!r.authToken.isEmpty())
        nr.setRawHeader("Authorization: Bearer", r.authToken.toUtf8().toBase64());
    else if(!(r.pass.isEmpty() || !r.user.isEmpty()))
        nr.setRawHeader("Authorization: Basic", (r.user + ":" +r.pass).toUtf8().toBase64());
    
    if(r.rtype == RequestType::GET)
        manager.get(nr);
    else if(r.rtype == RequestType::POST)
        manager.post(nr, r.body);
}

void HttpClient::processReply(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError )
    {
        int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (code >= 200 && code < 300)
        {
            processResponse(reply->readAll());
            reply->close();
            reply->deleteLater();
            return;
        }
    }
    reply->close();
    reply->deleteLater();
    qDebug() << "Failure: error code" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() << " " << reply->errorString();
}

HttpClient::HttpClient(QUrl url) : manager{}, host(std::move(url))
{
    manager.setTransferTimeout();
    connect(&manager, &QNetworkAccessManager::finished, this, &HttpClient::processReply);
}

