#pragma once

#include <vector>
#include <QtWidgets/QGraphicsPixmapItem>
#include <Qtwidgets/QGraphicsScene>
#include <random>
#include <QtWidgets/QGraphicsRectItem>
#include "Item.h"
#include <set>

using MatchPair = std::pair<int, int>; // 엘리어싱
using MatchSet = std::set<MatchPair>;

class Board : public Item::EventListener
{

private:
	QGraphicsScene* _scene;
	QGraphicsRectItem _root;
	std::vector<std::vector<Item*>> _items;
	std::random_device _device; // 운영체제에서 제공하는 랜덤함수, 결과 seed(씨앗) : 난수 알고리즘 실행하기 위해 쓰는 수
	std::mt19937 _gen; //mt19937엔진 알고리즘에 device 결과 넣기

	int _moveCount;

public:
	Board(QGraphicsScene* scene);
	~Board();
	void addItem(int row, int column);
	void removeItem(int row, int column);
	void moveItem(int fromRow, int fromColumn, int toRow, int toColumn);
	void moveItem(Item* item, int toRow, int toColumn);
	void exchangeItems(int row0, int column0, int row1, int column1, bool canRevert);
	bool refresh();
	MatchSet matchedItems() const; // set은 중복을 허용하지않음, multiset은 중복허용
	MatchSet matchedItems(int row, int column) const;
	MatchSet matchedItemsHorizontal(int row, int column) const;
	MatchSet matchedItemsVertical(int row, int column) const;


	virtual void itemDragEvent(Item* item, Item::Direction dir) override;
	virtual void itemMoveFinished(Item* item0, Item* item1, bool canRevert) override;
	
};