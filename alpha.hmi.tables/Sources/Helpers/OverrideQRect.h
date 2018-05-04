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

			public:

				void _UpdateLines() // ќбновим количество и размер линий
				{
					_Lines.clear();
					_StrongLines.clear();

					if (_CaptionFlag) {
						_StrongLines.push_back(QLine(_CellsWidth, 0, _CellsWidth, _CellsHeight * _NumberVertCells -3));
						_StrongLines.push_back(QLine(0, 0, 0, _CellsHeight * _NumberVertCells - 3));
						_StrongLines.push_back(QLine(0, _CellsHeight, _CellsWidth * _NumberHorCells - 3, _CellsHeight));
						_StrongLines.push_back(QLine(0, 0, _CellsWidth * _NumberHorCells - 3, 0));
					}

					for (int i = 0; i <= _NumberHorCells; i++) {                 // move on X
						_Lines.push_back(QLine(0 + (_CellsWidth * i), 0, 0 + (_CellsWidth * i), _CellsHeight * _NumberVertCells));
					}
					for (int i = 0; i <= _NumberVertCells; i++) {                // move on Y
						_Lines.push_back(QLine(0, 0 + (_CellsHeight * i), _CellsWidth * _NumberHorCells, 0 + (_CellsHeight * i)));
					}

					// »нициируем перерисовку
					update(0, 0, _CellsWidth*_NumberHorCells, _CellsHeight*_NumberVertCells);

				};





				MyQGraphicsRectItem()
					: _NumberHorCells(5)
					, _NumberVertCells(5)
					, _CellsWidth(_defaultCellWidth)
					, _CellsHeight(_defaultCellHeight)
					, brush(Qt::white)
					, _CaptionFlag(true)
				{
					setFlag(QGraphicsItem::ItemClipsChildrenToShape,true);
					setRect(QRectF(0.0, 0.0, _CellsWidth*_NumberHorCells, _CellsHeight*_NumberVertCells));

					_UpdateLines();
				};


				class Cell {
					
					uint32_t Xpos;
					uint32_t Ypos;
					//QString data;
				public:
					Cell(uint32_t X, uint32_t Y) :  //QString& text
						Xpos(X),
						Ypos(Y)
						//data(text)
					{};
					uint32_t getX() const { return Xpos; };
					uint32_t getY() const { return Ypos; };
					//QString getData() { return data; };
					bool operator < (const Cell &obj) const {  // map требует дл€ внутренней сортировки
						return (Xpos*Xpos+Ypos*Ypos < obj.Xpos*obj.Xpos + obj.Ypos*obj.Ypos);
					};

				};


				//std::list<Cell> TableData; // for inner data
				std::map<Cell,QString> TableData; // for inner data

				void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override {

					// ќтрисуем пр€моугольник
					painter->fillRect(QRectF(0.0, 0.0, _CellsWidth*_NumberHorCells, _CellsHeight*_NumberVertCells),brush);
					QGraphicsRectItem::paint(painter, option, widget);

					// сохраним сост€ние художника
					painter->save();
					painter->setClipRect(boundingRect());

					// рисуем содержимое таблицы

					for (auto it = TableData.begin(); it != TableData.end(); ++it)
					{
						QRectF item(it->first.getX() * _CellsWidth, it->first.getY() * _CellsHeight, _CellsWidth, _CellsHeight);
						QTextOption textOption;
						textOption.setAlignment(Qt::AlignmentFlag::AlignCenter);
						painter->drawText(item, it->second, textOption);
					}

					// рисуем разделительные линии

					painter->drawLines(_Lines);
					QPen pen(Qt::black, 5);	
					painter->setPen(pen);
					painter->drawLines(_StrongLines);

					// восстановим состо€ние
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

				/*void SetBrush(QColor color)
				{
					brush.setColor(color);
				};


				QColor GetBrush() const { return QColor(brush.color); };*/

				uint32_t GetNumberHorCells() const { return _NumberHorCells; };
				uint32_t GetNumberVertCells() const { return _NumberVertCells; };

				double GetCellsWidth() const { return _CellsWidth; };
				double GetCellsHeight() const { return _CellsHeight; };

				bool GetCaption() const { return _CaptionFlag; };
			
			};

		};
	};
};