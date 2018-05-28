#pragma once
#include "QtWidgets/qgraphicsitem.h"
#include "QtWidgets/qgraphicsscene.h"
#include <QtWidgets/QScrollbar>
#include <QtWidgets/QGraphicsProxyWidget>
#include <QtCore/QPointer>

namespace Alpha {
	namespace Hmi {
		namespace Tables {
			namespace Scrolls {

				class CQtGraphicsFrame : public QObject, public QGraphicsRectItem
				{
					//Q_OBJECT

				protected:

					QSizeF m_qContentSize;

					QPointer<QGraphicsProxyWidget> m_pHScroll;
					QPointer<QGraphicsProxyWidget> m_pVScroll;
					QPointer<QGraphicsProxyWidget> m_pCorner;
					QScrollBar m_HScrollBar;
					QScrollBar m_VScrollBar;
					QWidget m_CornerWidget;

				public:

					CQtGraphicsFrame();
					~CQtGraphicsFrame();

					QRectF& SetContentSize(QSizeF const &qSize, QRectF &bigqSize);
					void DrawScrolls(QRectF &bigqSize);
				private:

					QRectF& UpdateScrolls(QRectF &bigqSize);
					

					private slots:

					void OnHScrollBarChanged(int value);
					void OnVScrollBarChanged(int value);
				};
			}

		}
	}
}