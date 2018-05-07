#pragma once
#include "QtWidgets\qgraphicsitem.h"
#include "QtGui\qpainter.h"
#include "Scroll.h"




namespace Alpha {
	namespace Hmi {
		namespace Tables {

			

			class MyQGraphicsRectItem : public QGraphicsRectItem
			{
				uint32_t _NumberHorCells;	
				uint32_t _NumberVertCells;	

				const double _defaultCellWidth = 50.0;
				const double _defaultCellHeight = 20.0;

				double _CellsWidth;
				double _CellsHeight;

				QVector<QLine> _Lines;
				QVector<QLine> _StrongLines;
				QBrush brush;

				bool _CaptionFlag;
				uint32_t Caption;

			public:

				void _UpdateLines() // Обновим количество и размер линий
				{
					_Lines.clear();
					_StrongLines.clear();

					if (_CaptionFlag) {
						Caption = 1;
						_StrongLines.push_back(QLine(_CellsWidth, 0, _CellsWidth, _CellsHeight * (_NumberVertCells+Caption) -3));
						_StrongLines.push_back(QLine(0, 0, 0, _CellsHeight * (_NumberVertCells+Caption) - 3));
						_StrongLines.push_back(QLine(0, _CellsHeight, _CellsWidth * (_NumberHorCells+Caption) - 3, _CellsHeight));
						_StrongLines.push_back(QLine(0, 0, _CellsWidth * (_NumberHorCells+Caption) - 3, 0));
					} else Caption = 0;

					for (int i = 0; i <= (_NumberHorCells + Caption); i++) {                 // move on X
						_Lines.push_back(QLine(0 + (_CellsWidth * i), 0, 0 + (_CellsWidth * i), _CellsHeight * (_NumberVertCells + Caption)));
					}
					for (int i = 0; i <= (_NumberVertCells + Caption); i++) {                // move on Y
						_Lines.push_back(QLine(0, 0 + (_CellsHeight * i), _CellsWidth * (_NumberHorCells + Caption), 0 + (_CellsHeight * i)));
					}

					// Инициируем перерисовку
					update(0, 0, _CellsWidth*_NumberHorCells, _CellsHeight*_NumberVertCells);

				};





				MyQGraphicsRectItem()
					: _NumberHorCells(5)
					, _NumberVertCells(5)
					, _CellsWidth(_defaultCellWidth)
					, _CellsHeight(_defaultCellHeight)
					, brush(Qt::white)
					, _CaptionFlag(true)
					, Caption(1)
				{
					setFlag(QGraphicsItem::ItemClipsChildrenToShape,true);
					setRect(QRectF(0, 0, _CellsWidth*(_NumberHorCells+Caption), _CellsHeight*(_NumberVertCells+Caption)));
					_UpdateLines();
				};


				class Cell {
					uint32_t Xpos;
					uint32_t Ypos;
				public:
					Cell(uint32_t X, uint32_t Y) :  
						Xpos(X),
						Ypos(Y)
					{};
					uint32_t getX() const { return Xpos; };
					uint32_t getY() const { return Ypos; };
					bool operator < (const Cell &obj) const {
						return (Xpos < obj.Xpos || (Xpos == obj.Xpos && Ypos < obj.Ypos));
					};
				};

				std::map<Cell,QString> TableData; // for inner data
				std::map<uint32_t, QString> CaptionColumnData; 
				std::map<uint32_t, QString> CaptionLineData;

				void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override {

					// проверка на наличие заголовков
					if (_CaptionFlag) Caption = 1;
					else Caption = 0;

					// сохраним состяние художника
					painter->save();
					painter->setClipRect(boundingRect());


					// Отрисуем прямоугольник
					
					painter->fillRect(QRectF(0.0, 0.0, _CellsWidth*(_NumberHorCells+Caption), _CellsHeight*(_NumberVertCells+Caption)), brush);
					QGraphicsRectItem::paint(painter, option, widget);

					// рисуем содержимое таблицы

						for (auto it = TableData.begin(); it != TableData.end(); ++it)
						{
							QRectF item((it->first.getX()+Caption) * _CellsWidth, (it->first.getY()+Caption) * _CellsHeight, _CellsWidth, _CellsHeight);
							QTextOption textOption;
							textOption.setAlignment(Qt::AlignmentFlag::AlignCenter);
							painter->drawText(item, it->second, textOption);
						}

					// рисуем содержимое заголовков

						if (_CaptionFlag) {
							for (auto it = CaptionColumnData.begin(); it != CaptionColumnData.end(); ++it)
							{
								QRectF item((it->first + Caption) * _CellsWidth, 0, _CellsWidth, _CellsHeight);
								QTextOption textOption;
								textOption.setAlignment(Qt::AlignmentFlag::AlignCenter);
								painter->drawText(item, it->second, textOption);
							}
							for (auto it = CaptionLineData.begin(); it != CaptionLineData.end(); ++it)
							{
								QRectF item(0, (it->first + Caption) * _CellsHeight, _CellsWidth, _CellsHeight);
								QTextOption textOption;
								textOption.setAlignment(Qt::AlignmentFlag::AlignCenter);
								painter->drawText(item, it->second, textOption);
							}
						}

					// рисуем разделительные линии

					painter->drawLines(_Lines);
					QPen pen(Qt::black, 5);	
					painter->setPen(pen);
					painter->drawLines(_StrongLines);

					// восстановим состояние
					painter->restore();
				};


					// гетеры и сетеры

				void SetNumberHorCells(uint32_t HorVal)
				{
					_NumberHorCells = HorVal;

					_UpdateLines();
				};

				void SetNumberVertCells(uint32_t VertVal)
				{
					_NumberVertCells = VertVal;

					_UpdateLines();
				};

				void SetCellsWidth(double CellsWidth)
				{
					_CellsWidth = CellsWidth;

					_UpdateLines();
				};

				void SetCellsHeight(double CellsHeight)
				{
					_CellsHeight = CellsHeight;

					_UpdateLines();
				};

				void SetCaption(bool CaptionFlag)
				{
					_CaptionFlag = CaptionFlag;

					_UpdateLines();
				};

				void SetBrushColor( uint32_t const val)
				{
					brush.setColor(QColor::fromRgba(val));
					update();
				};


				uint32_t GetBrushColor() const { return brush.color().rgba(); };

				uint32_t GetNumberHorCells() const { return _NumberHorCells; };
				uint32_t GetNumberVertCells() const { return _NumberVertCells; };

				double GetCellsWidth() const { return _CellsWidth; };
				double GetCellsHeight() const { return _CellsHeight; };

				bool GetCaption() const { return _CaptionFlag; };
			
			};

		};
	};
};