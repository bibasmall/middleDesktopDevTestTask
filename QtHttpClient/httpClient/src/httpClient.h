#pragma once
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QUrl>


class HttpClient : public QObject
{
     Q_OBJECT
    
public:
     enum class RequestType {GET = 0, POST = 1};
     struct HttpRequest
     {
         QUrl url                                                 = {};
         RequestType rtype                                        = RequestType::GET;
         std::vector<std::pair<QByteArray, QByteArray>> headers   = {};
         QByteArray body                                          = {};
         QString authToken                                        = {};
         QString user                                             = {};
         QString pass                                             = {};
     };
    
public:
    HttpClient(QUrl host);
    
    void sendRequest(QUrl, RequestType = RequestType::GET, QByteArray = {});
    void sendRequest(HttpRequest&&);
    
    void setHost();
    
public:
    virtual void processResponse(QByteArray) {}
    virtual ~HttpClient() = default;
    
private slots:
    void processReply(QNetworkReply* reply);
    
private:
    QUrl host;
    inline static QNetworkAccessManager manager = QNetworkAccessManager{};
};
