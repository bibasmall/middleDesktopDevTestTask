#pragma once
#include <QFileInfo>

class IconValidator final
{
public:
    static bool Init(const char* s)
    {
        QFileInfo info(s);
        if(!(info.exists() && info.isFile()))
            return false;
        auto ext = info.completeSuffix();
        if(!(ext == "png" || ext == "ico"))
            return false;
        return true;
    }
};
