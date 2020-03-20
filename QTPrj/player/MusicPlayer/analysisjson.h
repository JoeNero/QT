#ifndef ANALYSISJSON_H
#define ANALYSISJSON_H

#include <QObject>
#include "musicinformation.h"

class AnalysisJson : public QObject
{
    Q_OBJECT
public:
    explicit AnalysisJson(const QString &fileName,QObject *parent = 0);
    QByteArray readJsonFile(void);
    QString getFileName() const;
    void setFileName(const QString &value);
    QString analysisMp3Url(void);
    QString analysisLyric(void);
    QString analysisPicUrl(void);

signals:

public slots:
    QList<MusicInformation> analysisMusic(void);


private:
    QString fileName;
};

#endif // ANALYSISJSON_H
