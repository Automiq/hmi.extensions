#include "stdafx.h"

#include "ZOrderHelper.h"

static void StackBeforeHelper(QList<QGraphicsItem *> const &siblings, int start, int stop)
{
	Q_ASSERT(start < stop);

	// QGraphicsItem::stackBefore работает только в том случае если перемещаемый элемент
	// находится после элемента, перед которым его нужно поместить. Поэтому для случая,
	// когда перемещаемый элемент находится до, необходимо выполнить последовательное
	// перемещение через все элементы, находящиеся между ними.

	// Перемещаемый элемент
	auto itemBeingMoved = siblings[start];

	// Последовательно перемещаем все элементы
	for (int idx = start + 1; idx <= stop; ++idx)
	{
		auto current = siblings[idx];
		current->stackBefore(itemBeingMoved);
	}
}

void ZOrderAfter(QGraphicsItem *movedItem, QGraphicsItem *fixedItem)
{
	if (!fixedItem || !movedItem || (fixedItem == movedItem))
		return;

	if (movedItem->parentItem() != fixedItem->parentItem())
		return;

	auto siblings = movedItem->parentItem()->childItems();
	auto thisIdx = siblings.indexOf(movedItem);
	auto itemIdx = siblings.indexOf(fixedItem);

	// Если данный элемент лежит ниже опорного
	if (thisIdx >= itemIdx)
	{
		// То просто указываем ему, где он должен лежать
		movedItem->stackBefore(fixedItem);
		fixedItem->stackBefore(movedItem);
	}
	else
	{
		// В противном случае его нужно опустить:)
		StackBeforeHelper(siblings, thisIdx, itemIdx);
	}

	movedItem->update();
}

void ZOrderBefore(QGraphicsItem *movedItem, QGraphicsItem *fixedItem)
{
	if (!fixedItem || !movedItem || (fixedItem == movedItem))
		return;

	if (movedItem->parentItem() != fixedItem->parentItem())
		return;

	auto siblings = movedItem->parentItem()->childItems();
	auto thisIdx = siblings.indexOf(movedItem);
	auto itemIdx = siblings.indexOf(fixedItem);

	// Если данный элемент лежит ниже опорного
	if (thisIdx >= itemIdx)
		// Всё просто
		movedItem->stackBefore(fixedItem);
	else
		// Надо опускать:)
		StackBeforeHelper(siblings, thisIdx, itemIdx - 1);

	movedItem->update();
}

void ZOrderChange(QGraphicsItem *movedItem, bool bBringToFront, bool bUtterly)
{
	// Получим список элементов на одном уровне
	QList<QGraphicsItem *> siblings;
	if (movedItem->parentItem())
		siblings = movedItem->parentItem()->childItems();
	else
	{
		// Если данный элемент - верхнего уровня
		auto scene = movedItem->scene();
		if (scene)
		{
			// Придётся запросить все элементы у сцены
			auto allItems = scene->items(Qt::AscendingOrder);
			for (auto const &item : allItems)
			{
				// И отсеять все, кроме элементов верхнего уровня
				if (!item->parentItem())
					siblings.push_back(item);
			}
		}
		else
			return;
	}

	// Найдём себя
	auto idx = siblings.indexOf(movedItem);
	if (idx == -1)
		return;

	if (bBringToFront)
	{
		idx++;
		if (idx >= siblings.count())
			return;

		if (bUtterly)
			idx = siblings.count() - 1;
	}
	else
	{
		idx--;
		if (idx < 0)
			return;

		if (bUtterly)
			idx = 0;
	}

	// Осуществим перемещение
	movedItem->stackBefore(siblings[idx]);
	if (bBringToFront)
		siblings[idx]->stackBefore(movedItem);
}