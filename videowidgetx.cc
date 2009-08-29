#include <iostream>
#include <QKeyEvent>
#include "player.h"
#include "videowidgetx.h"

VideoWidgetX::VideoWidgetX(Player *player, QWidget *parent) : 
    Phonon::VideoWidget(parent)
{
    m_player = player;
    connect(this, SIGNAL(pausePressed()), m_player, SLOT(togglePause()));
    setFocusPolicy(Qt::StrongFocus);
}

void VideoWidgetX::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_P) {
	e->accept();
	emit pausePressed();
    }

    Phonon::VideoWidget::keyPressEvent(e);
}
