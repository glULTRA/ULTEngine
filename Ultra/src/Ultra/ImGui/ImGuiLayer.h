#pragma once

#include "Ultra/Layer.h"

namespace Ultra 
{
	class ULT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();


		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;

	private:
		float m_Time = 0.0f;
	};
}