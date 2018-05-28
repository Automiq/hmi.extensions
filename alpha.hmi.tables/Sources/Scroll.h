#pragma once

#include "Helpers\OverrideQRect.h"

namespace Alpha {
	namespace Hmi {
		namespace Tables {
			namespace Scrolls {

				class CQtGraphicsScrollArea
					: public QObject
					, public QGraphicsRectItem
					, public INotificationHandler
				{

				protected:

					QSizeF m_qContentSize;

					QPointer<QGraphicsProxyWidget> m_pHScroll;
					QPointer<QGraphicsProxyWidget> m_pVScroll;
					QPointer<QGraphicsProxyWidget> m_pCorner;
					QScrollBar m_HScrollBar;
					QScrollBar m_VScrollBar;
					QWidget m_CornerWidget;

					QGraphicsItem *m_pRoot;

				public:

					CQtGraphicsScrollArea();
					~CQtGraphicsScrollArea();

					void SizeChanged(QSizeF const &size) override;
					void SetContentSize(QSizeF const &qSize);

					void UpdateScrolls();


				private:

					void OnHScrollBarChanged(int value);
					void OnVScrollBarChanged(int value);

					QVariant itemChange(GraphicsItemChange change, const QVariant & value) override;
				};
			}

		}
	}
}