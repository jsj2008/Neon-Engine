#pragma once

#include "Core/Config.h"

namespace Neon
{
	namespace Graphics
	{
		enum ShaderType
		{
			Float = 4,
			Float2 = 4 * 2,
			Float3 = 4 * 3,
			Float4 = 4 * 4,
			Int = 4,
			Int2 = 4 * 2,
			Int3 = 4 * 3,
			Int4 = 4 * 4,
			Mat3 = 4 * 3 * 3,
			Mat4 = 4 * 4 * 4,
			Bool = 1
		};
		
		class NEON_API BufferPair
		{
		public:
			BufferPair(ShaderType type, std::string name, bool normalised = false) : m_type(type), m_name(name), m_normalised(normalised) {}

			int GetSize() { return ((int)m_type / 4); }

		public:
			int offset = 0;
			
			ShaderType m_type;
			std::string m_name;
			bool m_normalised = false;
		};
		
		class NEON_API BufferLayout
		{
		public:
			BufferLayout() = default;
			BufferLayout(const std::initializer_list<BufferPair>& layout) { m_bufferLayout = layout; CalculateStride(); }

			int GetStride() { return stride; }
			std::vector<BufferPair>& GetElements() { return m_bufferLayout; }

			std::vector<BufferPair>::iterator Begin() { return m_bufferLayout.begin(); }
			std::vector<BufferPair>::iterator End() { return m_bufferLayout.end(); }
		
		private:
			void CalculateStride()
			{
				int offset = 0;
				for (auto& pair : m_bufferLayout)
				{
					pair.offset = offset;
					offset += pair.GetSize();
					stride += pair.GetSize();
				}
			}
			
		private:
			int stride = 0;
			std::vector<BufferPair> m_bufferLayout;
		};
	}
}