#ifndef VIDEO_WIDGET_X_H
#define VIDEO_WIDGET_X_H

#include <Phonon>

class QKeyEvent;
class Player;

class VideoWidgetX : public Phonon::VideoWidget
{
    Q_OBJECT

    public:
	VideoWidgetX(Player *player, QWidget *parent=0);

    protected:
	void keyPressEvent(QKeyEvent *e);

    private:
	Player *m_player;

    signals:
	void pausePressed();
};

#endif // VIDEO_WIDGET_X_H
