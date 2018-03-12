#pragma once
#include "QtWidgets\qgraphicsitem.h"
#include "QtGui\qpainter.h"


namespace Alpha {
	namespace Hmi {
		namespace Tables {

			

			class MyQGraphicsRectItem : public QGraphicsRectItem
			{
				uint32_t _NumberHorCells;	uint32_t _OldNumberHorCells;
				uint32_t _NumberVertCells;	uint32_t _OldNumberVertCells;
				const double _defaultCellWidth = 50.0;
				const double _defaultCellHeight = 20.0;

				QVector<QLine> _Lines;

				
				/*QVector<QLine> _Xlines;
				QVector<QLine> _Ylines;*/


				/*void addHorLines();
				void addVertLines();
				void retrieveHorLines();
				void retrieveVertLines();*/


			public:

				void _UpdateLines() // ������� ���������� � ������ �����
				{
					_Lines.clear();


					for (int i = 0; i <= _NumberHorCells; i++) {                 // move on X
						_Lines.push_back(QLine(0 + (50 * i), 0, 0 + (50 * i), 20 * _NumberVertCells));
					}
					for (int i = 0; i <= _NumberVertCells; i++) {                // move on Y
						_Lines.push_back(QLine(0, 0 + (20 * i), 50 * _NumberHorCells, 0 + (20 * i)));
					}

					// ���������� �����������
					update(0, 0, _defaultCellWidth*_NumberHorCells, _defaultCellHeight*_NumberVertCells);

				};





				MyQGraphicsRectItem()
					: _NumberHorCells(5)
					, _NumberVertCells(5)
					, _OldNumberHorCells(5)
					, _OldNumberVertCells(5)
				{
					setFlag(QGraphicsItem::ItemClipsChildrenToShape,true);
					setRect(QRectF(0.0, 0.0, _defaultCellWidth*_NumberHorCells, _defaultCellHeight*_NumberVertCells));


						_OldNumberHorCells = _NumberHorCells;
						_OldNumberVertCells = _NumberVertCells;
					
					_UpdateLines();
				};


				class Cell {
					qreal Xpos;
					qreal Ypos;
					Alpha::Binbo::default_string* data;
				public:
					Cell(uint32_t X, uint32_t Y, Alpha::Binbo::default_string& text) {
						Xpos = X;
						Ypos = Y;
						data = new Alpha::Binbo::default_string(text);
					};
					~Cell() {};
					qreal getX() { return Xpos; };
					qreal getY() { return Ypos; };
					Alpha::Binbo::default_string getData() { return *data; };
				};
				std::list<Cell> TableData; // for inner data



				void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override {

					// �������� �������������
					QGraphicsRectItem::paint(painter, option, widget);

					// �������� �������� ���������
					painter->save();

					// ������ ���������� �������

					for (Cell s : TableData) {
						painter->drawText((s.getX()-1)*_defaultCellWidth+2, s.getY()*_defaultCellHeight-2, QString::fromStdString(s.getData()));
					}
					// ������ �������������� �����
					painter->drawLines(_Lines);

					// ����������� ���������
					painter->restore();
				};

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

				uint32_t GetNumberHorCells() const { return _NumberHorCells; };
				uint32_t GetNumberVertCells() const { return _NumberVertCells; };
			};

		};
	};
};



// backup

//if (_NumberHorCells > _OldNumberHorCells && _NumberVertCells > _OldNumberVertCells) {
//
//	_OldNumberHorCells = _NumberHorCells;
//	_OldNumberVertCells = _NumberVertCells;
//
//	for (int i = 0; i <= _NumberHorCells; i++) {                 // move on X
//		_lines.push_back(QLine(0 + (50 * i), 0, 0 + (50 * i), 20 * _NumberVertCells));
//	}
//	for (int i = 0; i <= _NumberVertCells; i++) {                // move on Y
//		_lines.push_back(QLine(0, 0 + (20 * i), 50 * _NumberHorCells, 0 + (20 * i)));
//	}
//}




