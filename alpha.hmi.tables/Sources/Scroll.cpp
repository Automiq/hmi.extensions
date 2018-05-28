#include "stdafx.h"

#include "Scroll.h"

namespace Alpha {
	namespace Hmi {
		namespace Tables {
			namespace Scrolls {

				class CEmptyGraphicsItem : public QGraphicsItem
				{
				public:

					CEmptyGraphicsItem()
					{
					}

					~CEmptyGraphicsItem()
					{
					}

					QRectF boundingRect() const Q_DECL_OVERRIDE
					{
						return QRectF();
					}

					void paint(QPainter *pPainter, const QStyleOptionGraphicsItem *pOption, QWidget *pWidget = 0) Q_DECL_OVERRIDE
					{
					}
				};


				CQtGraphicsScrollArea::CQtGraphicsScrollArea()
					: m_HScrollBar(Qt::Horizontal)
					, m_VScrollBar(Qt::Vertical)
					, m_pRoot(nullptr)
				{
					// Clip content to frame size
					setFlag(QGraphicsItem::ItemClipsChildrenToShape);

					// Содержимое фрейма всегда снизу
					m_pRoot = new CEmptyGraphicsItem();
					m_pRoot->setParentItem(this);

					// Заполнитель правого нижнего угла
					m_pCorner = new QGraphicsProxyWidget();
					m_pCorner->setParentItem(this);
					m_pCorner->setWidget(&m_CornerWidget);

					// Создаём скроллбары
					m_pHScroll = new QGraphicsProxyWidget();
					m_pVScroll = new QGraphicsProxyWidget();

					m_pHScroll->setParentItem(this);
					m_pVScroll->setParentItem(this);

					m_pHScroll->setWidget(&m_HScrollBar);
					m_pVScroll->setWidget(&m_VScrollBar);
					// отправитель сигнал - приниматель слот
					connect(&m_HScrollBar, &QScrollBar::valueChanged, this, &CQtGraphicsScrollArea::OnHScrollBarChanged);
					connect(&m_VScrollBar, &QScrollBar::valueChanged, this, &CQtGraphicsScrollArea::OnVScrollBarChanged);

					// Исправляем геометрию виджета
					m_CornerWidget.resize(0, 0);

					m_pHScroll->setVisible(false);
					m_pVScroll->setVisible(false);
					m_pCorner->setVisible(false);
				}


				CQtGraphicsScrollArea::~CQtGraphicsScrollArea()
				{
				}


				void CQtGraphicsScrollArea::SizeChanged(QSizeF const &size)
				{
					SetContentSize(size);
				}


				void CQtGraphicsScrollArea::SetContentSize(QSizeF const &qSize)
				{
					m_qContentSize = qSize;
					UpdateScrolls();
				}


				void CQtGraphicsScrollArea::UpdateScrolls()
				{
					auto rc = rect();

					m_pHScroll->setVisible(false);
					m_pVScroll->setVisible(false);
					m_pCorner->setVisible(false);

					// Проверяем, нужны ли скроллы
					if (rc.width() >= m_qContentSize.width() && rc.height() >= m_qContentSize.height())
						return;

					auto rcHScroll = m_pHScroll->rect();
					auto rcVScroll = m_pVScroll->rect();

					if (rc.width() < m_qContentSize.width())
					{
						// Нужен горизонтальный скролл
						m_pHScroll->setVisible(true);
						rc.adjust(0.0, 0.0, 0.0, -rcHScroll.height());

						if (rc.height() < m_qContentSize.height())
						{
							// Горизонтальный скролл слишком высокий - нужны оба
							m_pVScroll->setVisible(true);
							m_pCorner->setVisible(true);
							rc.adjust(0.0, 0.0, -rcVScroll.width(), 0.0);
						}
					}
					else if (rc.height() < m_qContentSize.height())
					{
						// Нужен вертикальный скролл
						m_pVScroll->setVisible(true);
						rc.adjust(0.0, 0.0, -rcVScroll.width(), 0.0);

						if (rc.width() < m_qContentSize.width())
						{
							// Вертикальный скролл слишком широкий - нужны оба
							m_pHScroll->setVisible(true);
							m_pCorner->setVisible(true);
							rc.adjust(0.0, 0.0, 0.0, -rcHScroll.height());
						}
					}

					// Перемещаем
					m_pHScroll->setPos(0.0, rc.height());
					m_pVScroll->setPos(rc.width(), 0.0);
					m_pCorner->setPos(rc.width(), rc.height());

					// Подгоняем размеры
					m_pHScroll->resize(rc.width(), rcHScroll.height());
					m_pVScroll->resize(rcVScroll.width(), rc.height());
					m_pCorner->resize(rcHScroll.height(), rcVScroll.width());

					auto pHScroll = qobject_cast<QScrollBar *> (m_pHScroll->widget());
					auto pVScroll = qobject_cast<QScrollBar *> (m_pVScroll->widget());

					// Настраиваем ползунок
					pHScroll->setMaximum((m_qContentSize.width() > rc.width()) ? m_qContentSize.width() - rc.width() : 0);
					pVScroll->setMaximum((m_qContentSize.height() > rc.height()) ? m_qContentSize.height() - rc.height() : 0);

					pHScroll->setPageStep(rc.width());
					pVScroll->setPageStep(rc.height());
				}


				void CQtGraphicsScrollArea::OnHScrollBarChanged(int value)
				{
					auto pos = m_pRoot->pos();
					pos.setX(-value);
					m_pRoot->setPos(pos);
				}


				void CQtGraphicsScrollArea::OnVScrollBarChanged(int value)
				{
					auto pos = m_pRoot->pos();
					pos.setY(-value);
					m_pRoot->setPos(pos);
				}

				QVariant CQtGraphicsScrollArea::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant & value)
				{
					auto ret = QGraphicsRectItem::itemChange(change, value);

					// Workaround: проблема в дизайнере - сбрасываются флаги при добавлении на сцену
					if (change == GraphicsItemChange::ItemFlagsChange)
					{
						auto flags = value.value<unsigned int>();
						if (!(flags & QGraphicsItem::ItemClipsChildrenToShape))
							ret = QVariant(flags | QGraphicsItem::ItemClipsChildrenToShape);
					}

					return ret;
				}
			}
		}
	}
}