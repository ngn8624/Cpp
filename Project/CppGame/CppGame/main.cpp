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
    QApplication a(argc, argv); // 어플리케이션 자체
    QRect geometry = QApplication::desktop()->geometry(); // 전체 모니터의 좌상단을 0,0으로 하는 사각형이 나온다.
    
    // 듀얼 모니터를 사용할 경우 x,y 좌표가 이상하게 나오므로 아래와 같이 geomery를 고정
    geometry.setX(0);
    geometry.setY(0);
    //geometry.setHeight(geometry.height()*0.5);


    QGraphicsScene scene; // app 장면
    scene.setSceneRect(geometry); // 전체 geometry 사각형을 scene에 set한다.

    Board board(&scene);
    
    //scene.addItem(&item); //scene에QGraphicsPixmapItem에 맵핑된 것 추가
    //QGraphicsRectItem rect(0,0,200,100); // 사각형
    //scene.addItem(&rect);  // 사각형을 장면에 추가
    //rect.setPos(0,0);

    QGraphicsView view(&scene); // 사각형이 그려진 장면을 view에 매개변수로 넣고 view 인스턴스화
    view.showFullScreen(); // view를 큰화면에 보여주기
    return a.exec();
}
