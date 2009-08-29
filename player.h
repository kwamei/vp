#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>

namespace Phonon
{
    class AudioOutput;
    class MediaObject;
    class VideoWidget;
};

class Player : public QMainWindow
{
    Q_OBJECT

    public:
	Player();
	void add(QString file);
	void play();
    
    private:
	Phonon::VideoWidget *m_videoWidget;
	Phonon::AudioOutput *m_audioOutput;
	Phonon::MediaObject *m_mediaObject;

    public slots:
	void togglePause();
};

#endif // PLAYER_H
