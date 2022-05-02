#include "Board.h"
#include "Consts.h"
#include "Item.h"
#include <qdebug.h>

Board::Board(QGraphicsScene* scene)
	: _scene(scene)
	, _gen(_device())
	, _moveCount(0)
{
	_scene->addItem(&_root);
	_root.setX(_scene->sceneRect().width() / 2 - Consts::BOARD_ITEM_SIZE * Consts::BOARD_LENGTH / 2);
	_root.setY(_scene->sceneRect().height() / 2 - Consts::BOARD_ITEM_SIZE * Consts::BOARD_LENGTH / 2);
	for (int row = 0; row < Consts::BOARD_LENGTH; ++row)
	{
		std::vector<Item*> rowItems(Consts::BOARD_LENGTH);
		_items.push_back(rowItems);
		for (int column = 0; column < Consts::BOARD_LENGTH; ++column)
		{
			addItem(row,column);
		}
	}

	refresh();
}

Board::~Board()
{
	for (int row = 0; row < _items.size(); ++row)
	{
		for (int column = 0; column < _items[row].size(); ++column)
		{
			removeItem(row, column);
		}
	}
}

void Board::addItem(int row, int column)
{
	std::uniform_int_distribution<int> dis(0, 10);
	const std::string& path = Consts::paths[dis(_gen)];
	//auto& path = Consts::paths[dis(_gen)];


	//QPixmap pixmap(Consts::paths[dis(_gen)].c_str()); // 가져오기만 한다. // R"(C:\PNG\3.png)" : \때문에 R(row string)을 써야지만 \가 제대로 인식, // 두번해도 가능
	//QPixmap scaled(pixmap.scaled(Consts::BOARD_ITEM_SIZE, Consts::BOARD_ITEM_SIZE));
	//QGraphicsPixmapItem* item = new QGraphicsPixmapItem(scaled, &_root) ; //QGraphicsPixmapItem에 맵핑

	Item* item = new Item(this,path, row, column, &_root);
	item->setPos(row * Consts::BOARD_ITEM_SIZE, column * Consts::BOARD_ITEM_SIZE);

	_items[row][column] = item;

}

void Board::removeItem(int row, int column)
{
	auto* item = _items[row][column];
	if (item == nullptr)
		return;
	_items[row][column] = nullptr;
	item->setParentItem(nullptr);
	_scene->removeItem(item);

	delete item;

}

void Board::moveItem(int fromRow, int fromColumn, int toRow, int toColumn)
{
	Item* item = _items[fromRow][fromColumn];
	if (item == nullptr)
		return;
	moveItem(item, toRow, toColumn);
}

void Board::moveItem(Item* item, int toRow, int toColumn)
{
	item->setRow(toRow);
	item->setColumn(toColumn);
	item->moveTo(toColumn * Consts::BOARD_ITEM_SIZE, toRow * Consts::BOARD_ITEM_SIZE);
	_items[toRow][toColumn] = item;
	_moveCount++;
}

void Board::exchangeItems(int row0, int column0, int row1, int column1, bool canRevert)
{
	Item* item0 = _items[row0][column0];
	Item* item1 = _items[row1][column1];

	item0->setRow(row1);
	item1->setRow(row0);

	item0->setColumn(column1);
	item1->setColumn(column0);

	_items[row0][column0] = item1;
	_items[row1][column1] = item0;

	item0->moveTo(item1, canRevert);
	item1->moveTo(item0, canRevert);

	_moveCount += 2;
}

bool Board::refresh()
{
	MatchSet matched = matchedItems();

	if (matched.size() < 3)
		return false;

	for (const auto& pair : matched)
	{
		removeItem(pair.first, pair.second);
	}

	std::vector<int> emptyCounts;

	//fill with existing items;
	for (int column = 0; column < _items[0].size(); ++column)
	{
		for (int row = _items.size() - 1; row >= 0; --row)
		{
			if (_items[row][column] != nullptr)
			{
				continue;
			}
 
			for (int i = row - 1; i >= 0; --i)
			{
				if (_items[i][column] != nullptr)
				{
					emptyCounts[column]--;
					moveItem(i, column, row, column);
					_items[i][column] = nullptr;
					break;
				}
			}
		}
	}
	
	for (int column = 0; column < _items[0].size(); ++column)
	{
		int emptyCount = 0;
		for (int row = 0; row < _items.size(); ++row)
		{
			if (_items[row][column] == nullptr)
				emptyCount++;
			else
				break;
		}
		emptyCounts.push_back(emptyCount);
	}

	//fill with new items
	for (int column = 0; column < _items[0].size(); ++column)
	{
		for (int row = 0; row < _items.size(); ++row)
		{
			if (_items[row][column] == nullptr)
			{
				addItem( row, column); 

				Item* item = _items[row][column];
				item->setY(item->y() - emptyCounts[column] * Consts::BOARD_ITEM_SIZE);
				moveItem(row, column, row, column);

			}
			else
			{
				break;
			}
		}
	}
	return true;
}

MatchSet Board::matchedItems() const
{
	MatchSet matched;
	for (int row = 0; row < _items.size(); ++ row)
	{
		for (int column = 0; column < _items[row].size(); ++ column)
		{
			MatchSet m = matchedItems(row, column);
			if (m.size() >= 3)
			{
				matched.insert(m.begin(), m.end());
			} 
		}
	}
	return matched;
}

MatchSet Board::matchedItems(int row, int column) const
{
	MatchSet horizontalMatched = matchedItemsHorizontal(row, column);
	MatchSet verticalMatched = matchedItemsVertical(row, column);

	MatchSet matched;
	if (horizontalMatched.size() >=3)
		matched.insert(horizontalMatched.begin(), horizontalMatched.end());
	if (verticalMatched.size() >= 3)
		matched.insert(verticalMatched.begin(), verticalMatched.end());
	return matched;
}
MatchSet Board::matchedItemsHorizontal(int row, int column) const
{
	Item* item = _items[row][column];
	if (item == nullptr)
		return {};
	MatchSet leftMatched;
	for (int i = column - 1; i >= 0; --i)
	{
		if (_items[row][i] && _items[row][i]->path() == item->path())
		{
			leftMatched.insert({ row, i });
		}
		else
		{
			break;
		}
			
	}

	MatchSet rightMatched;
	for (int i = column + 1; _items.size(); ++i)
	{
		if (_items[row][i] && _items[row][i]->path() == item->path())
		{
			rightMatched.insert({ row, i });
		}
		else
		{
			break;
		}
	}

	if (leftMatched.size() + rightMatched.size() + 1 >= 3)
	{
		leftMatched.insert(rightMatched.begin(), rightMatched.end());
		leftMatched.insert({ row,column });
		return leftMatched;
	}
	else
	{
		return {};
	}

}

MatchSet Board::matchedItemsVertical(int row, int column) const
{
	Item* item = _items[row][column];
	if (item == nullptr)
		return {};
	MatchSet upMatched;
	for (int i = row - 1; i >= 0; --i)
	{
		if (_items[i][column] && _items[i][column]->path() == item->path())
		{
			upMatched.insert({ i, column });
		}
		else
		{
			break;
		}

	}

	MatchSet downMatched;
	for (int i = row + 1; _items.size(); ++i)
	{
		if (_items[i][column] && _items[i][column]->path() == item->path())
		{
			downMatched.insert({ i, column });
		}
		else
		{
			break;
		}
	}

	if (upMatched.size() + downMatched.size() + 1 >= 3)
	{
		upMatched.insert(downMatched.begin(), downMatched.end());
		upMatched.insert({ row,column });
		return upMatched;
	}
	else
	{
		return {};
	}
}

void Board::itemDragEvent(Item* item, Item::Direction dir)
{
	int row0 = item->row();
	int column0 = item->column();
	int row1 = row0;
	int column1 = column0;

	switch (dir)
	{
	case Item::Direction::Left:
		column1--;
		break;
	case Item::Direction::Right:
		column1++;
		break;
	case Item::Direction::Up:
		row1--;
		break;
	case Item::Direction::Down:
		row1++;
		break;
	}
	if (row1 < 0 || column1 < 0)
		return;
	if (row1 >= Consts::BOARD_LENGTH || column1 >= Consts::BOARD_LENGTH)
		return;

	//Item* item0 = item;
	Item* item1 = _items[row1][column1];
	if (item1 == nullptr)
		return;

	exchangeItems(row0, column0, row1, column1, true);
	
	//qDebug() << item << " : " << static_cast<int>(dir);
}

void Board::itemMoveFinished(Item* item0, Item* item1, bool canRevert)
{
	if(--_moveCount > 0)
		return;

	if (refresh())
		return;

	if (!canRevert)
		return;

	if (item0 == nullptr || item1 == nullptr)
		return;
	exchangeItems(item0->row(), item0->column(), item1->row(), item1->column(), false);
}
