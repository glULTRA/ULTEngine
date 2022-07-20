#pragma once

#include "ultpch.h"
#include "Ultra/Core.h"

namespace Ultra {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCatregory {
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; } 

	class ULT_API Event {
	public:
		// properties
		bool handled = false;
	public:
		virtual ~Event() = default;
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); };

		bool IsInCategory(EventCatregory category) 
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher {
	public:
		EventDispatcher(Event& evnt) // Note in C++ 20 we have event as a key so don't name it as an objetc. 
			: m_Event(evnt)
		{

		}

		template<typename T, typename F>
		bool Dispatch(const F& func) {
			if (m_Event.GetEventType == T::GetStaticType()) {
				m_Event.handled != func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}