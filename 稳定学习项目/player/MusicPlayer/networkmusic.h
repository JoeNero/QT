#ifndef NETWORKMUSIC_H
#define NETWORKMUSIC_H
#include <QObject>
#include "http.h"
#include "analysisjson.h"

class NetworkMusic : public QObject
{
    Q_OBJECT
public:
    explicit NetworkMusic(QObject *parent = 0);

signals:
    void searchMusic(const QString &music);
    void musicReady(const MusicInformation &music);

public slots:
    void analysisNetworkMusic(void);

private:
    Http *http;
    AnalysisJson *analysis;
};

#endif // NETWORKMUSIC_H
