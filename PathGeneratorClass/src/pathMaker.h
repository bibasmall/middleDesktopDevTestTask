#pragma once
#include <QTextStream>
#include <QString>
#include <QDate>
#include <QTime>


class PathMaker
{
public:
    virtual ~PathMaker() = default;

protected:
    QString getPath()
    {
       return getFileName() + getExtention();
    }

private:
    QString getFileName()
    {
        return QDate::currentDate().toString("dd-MM-yyyy") + "/" + QTime::currentTime().toString("hh-mm-ss");
    }
    virtual QString getExtention() = 0;
};

class Screenshot final : private PathMaker
{
public:
    void save()
    {
        QTextStream out(stdout);
        out << getPath();
    }

private:
    QString getExtention() override
    {
        return ".png";
    }
};

class WindowCapture final : private PathMaker
{
public:
    void save()
    {
        QTextStream out(stdout);
        out << getPath();
    }

private:
    QString getExtention() override
    {
        return ".mp4";
    }
};

