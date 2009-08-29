#include <Phonon>
#include "player.h"
#include "videowidgetx.h"

Player::Player() : QMainWindow()
{
    setWindowTitle("Video Player");

    m_videoWidget = (Phonon::VideoWidget *)(new VideoWidgetX(this, this));
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

void Player::togglePause()
{
    if (m_mediaObject->state() == Phonon::PausedState) {
	m_mediaObject->play();
    } else if (m_mediaObject->state() == Phonon::PlayingState) {
	m_mediaObject->pause();
    }
}
