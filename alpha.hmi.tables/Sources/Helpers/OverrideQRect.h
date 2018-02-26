#pragma once
#include "c:\Qt\5.9.3\msvc2015\include\QtWidgets\qgraphicsitem.h"
#include "TableControl.h"
namespace Alpha {
	namespace Hmi {
		namespace Tables {

			class MyQGraphicsRectItem : public QGraphicsRectItem {
				double NumberHorCells, NumberVertCells;
			public:
				void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override {
					//QGraphicsScene *myscene = new QGraphicsScene();
					//QString test = "Table is ready";
					///*TableControl main; 
					//myscene->addItem(main.mas);*/
					//myscene->addLine;
					//myscene->addText(test);
					//myscene->height = myscene->parent.height;
					//myscene->width = myscene->parent.width;


				};
	void SetNumberHorCells(double HorVal) { NumberHorCells = HorVal; };
	void SetNumberVertCells(double VertVal) { NumberVertCells = VertVal; };
	double GetNumberHorCells() { return NumberHorCells; };
	double GetNumberVertCells() { return NumberVertCells; };
};



		};
	};
};




