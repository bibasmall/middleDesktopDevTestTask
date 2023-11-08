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
    static HttpClient& instance(QUrl host);
    
    void request(QUrl url, RequestType = RequestType::GET, QByteArray&& body = {});
    void request(const HttpRequest&);
    
public:
    virtual void processResponse(QByteArray data) {}
    virtual ~HttpClient() = default;
    
private slots:
    void processReply(QNetworkReply* reply);
    
protected:
    HttpClient(QUrl host);
    
private:
    QNetworkAccessManager manager;
    QUrl                  host;
};
