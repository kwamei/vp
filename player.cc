#include <Phonon>

#include "player.h"

Player::Player() : QMainWindow()
{
    setWindowTitle("Video Player");

    m_videoWidget = new Phonon::VideoWidget(this);
    m_audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory, this);
    m_mediaObject = new Phonon::MediaObject(this);
    Phonon::createPath(m_mediaObject, m_videoWidget);
    Phonon::createPath(m_mediaObject, m_audioOutput);

    setCentralWidget(m_videoWidget);
}

void Player::add(QString file)
{
    Phonon::MediaSource source(file);
    m_mediaObject->enqueue(source);
}

void Player::play()
{
   m_mediaObject->play(); 
}
