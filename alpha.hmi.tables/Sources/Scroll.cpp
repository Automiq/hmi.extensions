#include "stdafx.h"

#include "Helpers\Scroll.h"

namespace Alpha {
	namespace Hmi {
		namespace Tables {
			namespace Scrolls {
				CQtGraphicsFrame::CQtGraphicsFrame() : m_HScrollBar(Qt::Horizontal), m_VScrollBar(Qt::Vertical)
				{
					// Clip content to frame size
					setFlag(QGraphicsItem::ItemClipsChildrenToShape);

					// ����������� ������� ������� ����
					m_pCorner = new QGraphicsProxyWidget();
					m_pCorner->setParentItem(this);
					m_pCorner->setWidget(&m_CornerWidget);

					// ������ ����������
					m_pHScroll = new QGraphicsProxyWidget();
					m_pVScroll = new QGraphicsProxyWidget();

					m_pHScroll->setParentItem(this);
					m_pVScroll->setParentItem(this);

					m_pHScroll->setWidget(&m_HScrollBar);
					m_pVScroll->setWidget(&m_VScrollBar);
					// ����������� ������ - ����������� ����
					connect(&m_HScrollBar, &QScrollBar::valueChanged, this, &CQtGraphicsFrame::OnHScrollBarChanged);
					connect(&m_VScrollBar, &QScrollBar::valueChanged, this, &CQtGraphicsFrame::OnVScrollBarChanged);

					// ���������� ��������� �������
					m_CornerWidget.resize(0, 0);

					m_pHScroll->setVisible(false);
					m_pVScroll->setVisible(false);
					m_pCorner->setVisible(false);
				}


				CQtGraphicsFrame::~CQtGraphicsFrame()
				{
				}


				QRectF& CQtGraphicsFrame::SetContentSize(QSizeF const &qSize, QRectF &bigqSize)
				{
					m_qContentSize = qSize; // ����� ������� �������
					QRectF& arg = UpdateScrolls(bigqSize);
					return arg;
				}


				QRectF& CQtGraphicsFrame::UpdateScrolls(QRectF &rc)
				{
					//auto rc = qSize; // QRectF ������� �����

					m_pHScroll->setVisible(false);
					m_pVScroll->setVisible(false);
					m_pCorner->setVisible(false);

					// ���������, ����� �� �������
					if (rc.width() >= m_qContentSize.width() && rc.height() >= m_qContentSize.height())
						return rc;     // ���� ����� ������ �������, �������

					auto rcHScroll = m_pHScroll->rect();
					auto rcVScroll = m_pVScroll->rect();  // ����� �������������� ����� �������� 

					if (rc.width() < m_qContentSize.width())
					{
						// ����� �������������� ������
						m_pHScroll->setVisible(true);
						rc.adjust(0.0, 0.0, 0.0, -rcHScroll.height()); // ������ ��������� ��������, ������ ����, ������ ����������� �� ������ ��������������� ������� 

						if (rc.height() < m_qContentSize.height())
						{
							// �������������� ������ ������� ������� - ����� ���, ��� � �������� ���������� ����� ��� ������ � ����� ����
							m_pVScroll->setVisible(true);
							m_pCorner->setVisible(true);
							rc.adjust(0.0, 0.0, -rcVScroll.width(), 0.0);  // ���� ��� �����, ��������� ����� ��� � � ���� � ������ ������ �� ������ ��������
						}
					}
					else if (rc.height() < m_qContentSize.height())
					{
						// ����� ������������ ������
						m_pVScroll->setVisible(true);
						rc.adjust(0.0, 0.0, -rcVScroll.width(), 0.0);

						if (rc.width() < m_qContentSize.width())
						{
							// ������������ ������ ������� ������� - ����� ���
							m_pHScroll->setVisible(true);
							m_pCorner->setVisible(true);
							rc.adjust(0.0, 0.0, 0.0, -rcHScroll.width());
						}
					}
					return rc;
				}
				void CQtGraphicsFrame::DrawScrolls(QRectF &rc){

					auto rcHScroll = m_pHScroll->rect();
					auto rcVScroll = m_pVScroll->rect();  // ����� �������������� ����� �������� 

					// ��������� � ������ ������ (��� ������ �� ���� , X)
					m_pHScroll->setPos(0.0, rc.height());
					m_pVScroll->setPos(rc.width(), 0.0);
					m_pCorner->setPos(rc.width(), rc.height());

					// ��������� �������, ������ ����������, ��������� ��������������� 
					m_pHScroll->resize(rc.width(), rcHScroll.height());
					m_pVScroll->resize(rcVScroll.width(), rc.height());
					m_pCorner->resize(rcHScroll.width(), rcVScroll.height());

					auto pHScroll = qobject_cast<QScrollBar *> (m_pHScroll->widget());  // ��������� Q��������� ������� � ���������
					auto pVScroll = qobject_cast<QScrollBar *> (m_pVScroll->widget());

					// ����������� ��������
					pHScroll->setMaximum((m_qContentSize.width() > rc.width()) ? m_qContentSize.width() - rc.width() : 0); // ������� ����� ������� � ��������, �� ������� �������� ����� ����� ���������� ��������
					pVScroll->setMaximum((m_qContentSize.height() > rc.height()) ? m_qContentSize.height() - rc.height() : 0);

					pHScroll->setPageStep(rc.width());
					pVScroll->setPageStep(rc.height());
				}


				void CQtGraphicsFrame::OnHScrollBarChanged(int value)
				{
				//	/*auto pos = this->pos();
				//	pos.setX(-value);
				//	this->setPos(pos);*/
				}


				void CQtGraphicsFrame::OnVScrollBarChanged(int value)
				{
				//	/*auto pos = this->pos();
				//	pos.setY(-value);
				//	this->setPos(pos);*/
				}
			}
		}
	}
}