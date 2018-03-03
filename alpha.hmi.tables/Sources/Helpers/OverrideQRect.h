#pragma once
#include "TableControl.h"

namespace Alpha {
	namespace Hmi {
		namespace Tables {

			class MyQGraphicsRectItem : public QGraphicsRectItem
			{
				uint32_t _NumberHorCells;
				uint32_t _NumberVertCells;

				static const double _defaultCellWidth = 50.0;
				static const double _defaultCellHeight = 20.0;

				QVector<QLine> _lines;

				void _UpdateLines()
				{
					// Обновим количество и размер линий
					/*for (int i = 0; i < _NumberVertCells; i++) {
						for (int j = 0; j < _NumberHorCells; j++) {
							
						}
					}*/

					// Инициируем перерисовку
					update();
				};

			public:

				MyQGraphicsRectItem()
					: _NumberHorCells(100)
					, _NumberVertCells(100)
				{
					setRect(QRectF(0.0, 0.0, 100.0, 100.0));

					_UpdateLines();
				};

				void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override {

					// Отрисуем прямоугольник
					QGraphicsRectItem::paint(painter, option, widget);

					// сохраним состяние художника
					painter->save();

					// рисуем содержимое таблицы

					// рисуем разделительные линии
					painter->drawLines(_lines);

					// восстановим состояние
					painter->restore();
				};

				void SetNumberHorCells(uint32_t HorVal)
				{
					_NumberHorCells = HorVal;

					//_UpdateLines();
				};

				void SetNumberVertCells(uint32_t VertVal)
				{
					_NumberVertCells = VertVal;

					//_UpdateLines();
				};

				uint32_t GetNumberHorCells() const { return _NumberHorCells; };
				uint32_t GetNumberVertCells() const { return _NumberVertCells; };
			};

		};
	};
};




