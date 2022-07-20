#pragma once

#include "ultpch.h"

#include "Ultra/Core.h"
#include "Events/Event.h"

namespace Ultra {
	struct WindowProps
	{
		std::string Titile;
		unsigned int Width;
		unsigned int Height;

		WindowProps(
			const std::string& titile = "Ultra Engine",
			unsigned int width = 1200,
			unsigned int height = 720
		)
			: Titile(titile), Width(width), Height(height)
		{
		}
	};

	class ULT_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attrivutes.
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		
		virtual bool IsRunning() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}