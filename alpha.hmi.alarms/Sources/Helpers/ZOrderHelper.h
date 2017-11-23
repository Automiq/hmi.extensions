#pragma once

void ZOrderAfter(QGraphicsItem *movedItem, QGraphicsItem *fixedItem);
void ZOrderBefore(QGraphicsItem *movedItem, QGraphicsItem *fixedItem);
void ZOrderChange(QGraphicsItem *movedItem, bool bBringToFront, bool bUtterly);