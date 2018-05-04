#pragma once
#include "stdafx.h"
#include "QtWidgets/qgraphicsitem.h"
#include "QtWidgets/qgraphicsscene.h"
#include <QtWidgets/QScrollbar>
#include <QtWidgets/QGraphicsProxyWidget>

namespace Alpha {
	namespace Hmi {
		namespace Tables {

			class CQtGraphicsFrame : public QObject, public QGraphicsRectItem
			{
				Q_OBJECT

			protected:

				QSizeF m_qContentSize;

//				QPointer<QGraphicsProxyWidget> m_pHScroll;
//				QPointer<QGraphicsProxyWidget> m_pVScroll;
//				QPointer<QGraphicsProxyWidget> m_pCorner;
				QScrollBar m_HScrollBar;
				QScrollBar m_VScrollBar;
				QWidget m_CornerWidget;

			public:

				CQtGraphicsFrame();
				~CQtGraphicsFrame();

				void SetContentSize(QSizeF const &qSize);

			private:

				void UpdateScrolls();

				private slots:

				void OnHScrollBarChanged(int value);
				void OnVScrollBarChanged(int value);
			};

		}
	}
}