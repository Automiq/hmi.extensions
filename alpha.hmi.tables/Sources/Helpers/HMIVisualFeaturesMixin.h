#pragma once

#include "mixin.h"
#include "ZOrderHelper.h"

////////////////////////////////////////////////////////////////////////////////////////////////
///	@short
///		Примесь, реализующая интерфейс HMIFeatures::IVisual
////////////////////////////////////////////////////////////////////////////////////////////////
template <typename Implementation>
class hmi_features_visual_impl
	:	protected mixin<Implementation>
{
protected:

	// Список разметок (активна только первая)
	std::vector<HMILayout::ILayout *> _layouts;

	// Список элементов, умеющих подстраиваться под разметку
	std::vector<HMILayout::ILayoutItem *> _layoutItems;

	// "Сырой" указатель на родителя
	HMIFeatures::IBase *_rawParent;

	QString _resourceFolder;

public:

	hmi_features_visual_impl()
		:	_rawParent(nullptr)
	{
	}

	// HMIFeatures::IBase interface
	void get_object_ptr_impl(void **object_ptr)
	{
		assert(object_ptr);

		*object_ptr = static_cast<QGraphicsItem *> (to_impl(this));
	}

	void notify_child_added_impl(Alpha::Binbo::i_common *child_ptr)
	{
		assert(child_ptr);

		// Если добавленный элемент умеет подстраиваться под разметку
		auto layoutItem = Alpha::Binbo::foreign_cast<HMILayout::ILayoutItem> (child_ptr);
		if (layoutItem)
		{
			// Добавим его в список
			_layoutItems.push_back(layoutItem);

			// Применим к нему разметку
			if (!_layouts.empty())
				Alpha::auto_throw(_layouts.front()->add_layout_item(layoutItem));
		}
	}

	void notify_child_removed_impl(Alpha::Binbo::i_common *child_ptr)
	{
		assert(child_ptr);

		// Если добавленный элемент умеет подстраиваться под разметку
		auto layoutItem = Alpha::Binbo::foreign_cast<HMILayout::ILayoutItem> (child_ptr);
		if (layoutItem)
		{
			// Уберём его из активной разметки
			if (!_layouts.empty())
				Alpha::auto_throw(_layouts.front()->remove_layout_item(layoutItem));

			// И из списка элементов
			auto itRemove = std::remove(_layoutItems.begin(), _layoutItems.end(), layoutItem);
			_layoutItems.erase(itRemove, _layoutItems.end());
		}
	}

	// Alpha::Om::Native::IRequiresParent interface
	void SetParent_impl(Alpha::Binbo::i_common_ptr const &parentCommon, Alpha::Om::IObjectConstPtr const &parentDefinition)
	{
		auto oldRawParent = _rawParent;
		QGraphicsItem *parent = nullptr;

		// Нужно ли установить нового родителя или сбросить старого
		if (parentCommon)
		{
			// Проверим тип родителя
			auto parentBase = Alpha::Binbo::foreign_cast<HMIFeatures::IBase> (parentCommon);
			if (!parentBase)
				AlphaThrow(Alpha::Error(), nstr(L"Родитель не является графическим объектом HMI"));

			// Получим его нативный указатель
			Alpha::auto_throw(parentBase->get_object_ptr(reinterpret_cast<void **> (&parent)));
			_rawParent = parentBase.get();
		}
		else
			_rawParent = nullptr;

		// Сменим родителя
		to_impl(this)->setNativeParent(parent);

		// Уведомим родителей
		if (oldRawParent)
			Alpha::auto_throw(oldRawParent->notify_child_removed(Alpha::Binbo::foreign_cast_ex<Alpha::Binbo::i_common, HMIFeatures::IBase> (to_impl(this))));
		if (_rawParent)
			Alpha::auto_throw(_rawParent->notify_child_added(Alpha::Binbo::foreign_cast_ex<Alpha::Binbo::i_common, HMIFeatures::IBase> (to_impl(this))));
	}

	bool IsValidParent_impl(Alpha::Binbo::i_common_ptr const &parentCommon, Alpha::Om::IObjectConstPtr const &parentDefinition)
	{
		if (parentCommon)
		{
			// Узнаем тип родителя
			auto parentBase = Alpha::Binbo::foreign_cast<HMIFeatures::IBase> (parentCommon);
			if (!parentBase)
				return false;

			// Попробуем достать его нативный указатель
			QGraphicsItem *parent = nullptr;
			Alpha::auto_throw(parentBase->get_object_ptr(reinterpret_cast<void **> (&parent)));
		}

		// Если родителя нет, или всё прошло успешно - положительный результат
		return true;
	}

	// Alpha::Om::Native::IRequiresResources interface
	void SetResourceFolder_impl(Alpha::Binbo::string_val const &resourceFolder)
	{
		_resourceFolder = QString::fromUtf8(resourceFolder.string, resourceFolder.size);
	}

	// Alpha::Om::Native::ISupportsMove interface
	void MoveBefore_impl(Alpha::Binbo::i_common_ptr const &visualCommon)
	{
		// Приводим к указателю на визуальный элемент
		auto visual = Alpha::Binbo::foreign_cast<HMIFeatures::IVisual> (visualCommon);
		if (!visual)
			AlphaThrow(Alpha::Error(), nstr(L"Аргумент не является графическим объектом HMI"));

		// Обновим Z-order
		z_order_before_impl(visual);
	}

	void MoveAfter_impl(Alpha::Binbo::i_common_ptr const &visualCommon)
	{
		// Приводим к указателю на визуальный элемент
		auto visual = Alpha::Binbo::foreign_cast<HMIFeatures::IVisual> (visualCommon);
		if (!visual)
			AlphaThrow(Alpha::Error(), nstr(L"Аргумент не является графическим объектом HMI"));

		// Обновим Z-order
		z_order_after_impl(visual);
	}

	// HMIFeatures::IVisual interface
	void set_position_impl(const GraphicsPoint &pt)
	{
		to_impl(this)->setPos(QPointF(pt.fX, pt.fY));
	}

	GraphicsPoint get_position_impl()
	{
		auto pos = to_impl(this)->pos();
		return GraphicsPoint(pos.x(), pos.y());
	}

	void set_center_position_impl(const GraphicsPoint &ptCenter)
	{
		to_impl(this)->setCenterPos(QPointF(ptCenter.fX, ptCenter.fY));
	}

	GraphicsPoint get_center_position_impl()
	{
		auto pos = to_impl(this)->centerPos();
		return GraphicsPoint(pos.x(), pos.y());
	}

	void set_visible_impl(bool visible)
	{
		to_impl(this)->setVisible(visible);
	}

	bool get_visible_impl()
	{
		return to_impl(this)->isVisible();
	}

	void z_order_after_impl(HMIFeatures::IVisual_ptr const &item_ptr)
	{
		QGraphicsItem *item = nullptr;
		if (item_ptr)
			Alpha::auto_throw(item_ptr->get_object_ptr(reinterpret_cast<void **> (&item)));

		ZOrderAfter(to_impl(this), item);
	}

	void z_order_before_impl(HMIFeatures::IVisual_ptr const &item_ptr)
	{
		QGraphicsItem *item = nullptr;
		if (item_ptr)
			Alpha::auto_throw(item_ptr->get_object_ptr(reinterpret_cast<void **> (&item)));

		ZOrderBefore(to_impl(this), item);
	}

	void z_order_increase_impl(bool bTopmost)
	{
		ZOrderChange(to_impl(this), true, bTopmost);
	}

	void z_order_decrease_impl(bool bLowest)
	{
		ZOrderChange(to_impl(this), false, bLowest);
	}

	void set_center_rotation_impl(const double &fRotationDegrees)
	{
		to_impl(this)->setRotation(fRotationDegrees);
	}

	double get_center_rotation_impl()
	{
		return to_impl(this)->rotation();
	}

	void add_effect_impl(HMIEffects::IBase *effect_ptr)
	{
		if (!effect_ptr)
			AlphaThrow(Alpha::Error(), nstr(L"Нулевой указатель"));

		///TODO: реализация пока не нужна
		//to_impl(this)->SetEffect(effect_ptr);
	}

	void update_effect_impl(HMIEffects::IBase *effect_ptr)
	{
		if (!effect_ptr)
			AlphaThrow(Alpha::Error(), nstr(L"Нулевой указатель"));

		///TODO: реализация пока не нужна
		//to_impl(this)->UpdateEffect(effect_ptr);
	}

	void remove_effect_impl(HMIEffects::IBase *effect_ptr)
	{
		if (!effect_ptr)
			AlphaThrow(Alpha::Error(), nstr(L"Нулевой указатель"));

		///TODO: реализация пока не нужна
		//to_impl(this)->RemoveEffect(effect_ptr);
	}

	void add_layout_impl(HMILayout::ILayout *layout_ptr)
	{
		if (!layout_ptr)
			AlphaThrow(Alpha::Error(), nstr(L"Нулевой указатель"));

		// Если данная разметка - первая
		if (_layouts.empty())
		{
			// Дадим ей размеры нашего элемента
			auto rc = to_impl(this)->rect();
			Alpha::auto_throw(layout_ptr->update_layout(GraphicsRect(rc.x(), rc.y(), rc.width(), rc.height())));

			// Добавим ей все элементы, которыми можно управлять
			for (auto const &item : _layoutItems)
				Alpha::auto_throw(layout_ptr->add_layout_item(item));
		}

		// Добавим в список разметок
		_layouts.push_back(layout_ptr);
	}

	void remove_layout_impl(HMILayout::ILayout *layout_ptr)
	{
		if (!layout_ptr)
			AlphaThrow(Alpha::Error(), nstr(L"Нулевой указатель"));

		// Первая ли разметка в списке
		bool bFirst = (layout_ptr == _layouts.front());

		// Перенесём её в конец списка
		auto itRemove = std::remove(_layouts.begin(), _layouts.end(), layout_ptr);
		if (itRemove == _layouts.end())
			return;

		// Если данная разметка - первая, уберём из неё все элементы
		if (bFirst)
			Alpha::auto_throw(layout_ptr->remove_all_items());

		// Уберём её из списка
		_layouts.erase(itRemove, _layouts.end());

		// Если есть ещё разметки - добавим все элементы к первой
		if (bFirst && !_layouts.empty())
		{
			for (auto const &item : _layoutItems)
				Alpha::auto_throw(_layouts.front()->add_layout_item(item));
		}
	}

};	//hmi_features_visual_impl
