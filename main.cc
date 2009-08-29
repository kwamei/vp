#include <QApplication>
#include "player.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Player player;

    QStringList args = app.arguments();
    for (int i = 1; i < args.size(); ++i)
	player.add(args.at(i));

    player.show();
    player.play();
    return app.exec();
}
