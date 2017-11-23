#include "stdafx.h"

#include "ZOrderHelper.h"

static void StackBeforeHelper(QList<QGraphicsItem *> const &siblings, int start, int stop)
{
	Q_ASSERT(start < stop);

	// QGraphicsItem::stackBefore �������� ������ � ��� ������ ���� ������������ �������
	// ��������� ����� ��������, ����� ������� ��� ����� ���������. ������� ��� ������,
	// ����� ������������ ������� ��������� ��, ���������� ��������� ����������������
	// ����������� ����� ��� ��������, ����������� ����� ����.

	// ������������ �������
	auto itemBeingMoved = siblings[start];

	// ��������������� ���������� ��� ��������
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

	// ���� ������ ������� ����� ���� ��������
	if (thisIdx >= itemIdx)
	{
		// �� ������ ��������� ���, ��� �� ������ ������
		movedItem->stackBefore(fixedItem);
		fixedItem->stackBefore(movedItem);
	}
	else
	{
		// � ��������� ������ ��� ����� ��������:)
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

	// ���� ������ ������� ����� ���� ��������
	if (thisIdx >= itemIdx)
		// �� ������
		movedItem->stackBefore(fixedItem);
	else
		// ���� ��������:)
		StackBeforeHelper(siblings, thisIdx, itemIdx - 1);

	movedItem->update();
}

void ZOrderChange(QGraphicsItem *movedItem, bool bBringToFront, bool bUtterly)
{
	// ������� ������ ��������� �� ����� ������
	QList<QGraphicsItem *> siblings;
	if (movedItem->parentItem())
		siblings = movedItem->parentItem()->childItems();
	else
	{
		// ���� ������ ������� - �������� ������
		auto scene = movedItem->scene();
		if (scene)
		{
			// ������� ��������� ��� �������� � �����
			auto allItems = scene->items(Qt::AscendingOrder);
			for (auto const &item : allItems)
			{
				// � ������� ���, ����� ��������� �������� ������
				if (!item->parentItem())
					siblings.push_back(item);
			}
		}
		else
			return;
	}

	// ����� ����
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

	// ���������� �����������
	movedItem->stackBefore(siblings[idx]);
	if (bBringToFront)
		siblings[idx]->stackBefore(movedItem);
}