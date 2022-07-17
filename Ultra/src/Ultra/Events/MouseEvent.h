#pragma once

#include "Event.h"

namespace Ultra {

	// Mouse Moved Event is cursor's movement.
	class ULT_API MouseMovedEvent : public Event 
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() { return m_MouseX; };
		inline float GetY() { return m_MouseY; };

		std::string ToString() {
			std::stringstream ss;
			ss << "MouseMovedEvent(" << GetX() << ", " << GetY() << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseMoved);

	private:
		float m_MouseX;
		float m_MouseY;
	};

	class ULT_API MouseScrolledEvent: public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent(" << m_XOffset << "," << m_YOffset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		float m_XOffset, m_YOffset;
	};

	class ULT_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput | EventCategoryMouseButton);
	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {}

	private:
		int m_Button;
	};

	class ULT_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int mouse)
			: MouseButtonEvent(mouse) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << GetMouseButton();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class ULT_API MouseButtonReleasedEvent : public MouseButtonEvent 
	{
	public:
		MouseButtonReleasedEvent(int mouse)
			: MouseButtonEvent(mouse) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << GetMouseButton();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}