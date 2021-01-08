#include<sstream>
#include <QString>

namespace ACV
{
    QString toQString(unsigned val)
    {
        std::stringstream ss;
        ss<<val;
        std::string s;
        ss>>s;
        return QString::fromStdString(s);
    }

    QString toQString(char val)
    {
        QString ans{"1"};
        ans[0] = val;
        return ans;
    }

    QString toQString(double val)
    {
        std::stringstream ss;
        ss << val;
        std::string s;
        ss>>s;
        return QString::fromStdString(s);
    }


}
