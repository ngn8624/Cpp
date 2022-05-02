#include <QtWidgets/QApplication>
#include <Qtwidgets/QGraphicsScene>
//#include <Qtwidgets/QGraphicsRectItem>
#include <Qtwidgets/QGraphicsView>
#include <Qtwidgets/QDesktopWidget>
//#include <Qtwidgets/QGraphicsPixmapItem>
#include "Board.h"


#include "Consts.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // ���ø����̼� ��ü
    QRect geometry = QApplication::desktop()->geometry(); // ��ü ������� �»���� 0,0���� �ϴ� �簢���� ���´�.
    
    // ��� ����͸� ����� ��� x,y ��ǥ�� �̻��ϰ� �����Ƿ� �Ʒ��� ���� geomery�� ����
    geometry.setX(0);
    geometry.setY(0);
    //geometry.setHeight(geometry.height()*0.5);


    QGraphicsScene scene; // app ���
    scene.setSceneRect(geometry); // ��ü geometry �簢���� scene�� set�Ѵ�.

    Board board(&scene);
    
    //scene.addItem(&item); //scene��QGraphicsPixmapItem�� ���ε� �� �߰�
    //QGraphicsRectItem rect(0,0,200,100); // �簢��
    //scene.addItem(&rect);  // �簢���� ��鿡 �߰�
    //rect.setPos(0,0);

    QGraphicsView view(&scene); // �簢���� �׷��� ����� view�� �Ű������� �ְ� view �ν��Ͻ�ȭ
    view.showFullScreen(); // view�� ūȭ�鿡 �����ֱ�
    return a.exec();
}
