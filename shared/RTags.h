#ifndef RTags_h
#define RTags_h

#include <QByteArray>
#include <Path.h>
#include <Log.h>
#include <stdio.h>
#include <assert.h>
#include <getopt.h>

namespace RTags {
enum UnitType { CompileC, CompileCPlusPlus, PchC, PchCPlusPlus };

static inline int digits(int len)
{
    int ret = 1;
    while (len >= 10) {
        len /= 10;
        ++ret;
    }
    return ret;
}

QByteArray shortOptions(const option *longOptions);
int readLine(FILE *f, char *buf = 0, int max = -1);
bool removeDirectory(const char *path);
int canonicalizePath(char *path, int len);
QByteArray unescape(QByteArray command);
QByteArray join(const QList<QByteArray> &list, const QByteArray &sep = QByteArray());
}

#endif
