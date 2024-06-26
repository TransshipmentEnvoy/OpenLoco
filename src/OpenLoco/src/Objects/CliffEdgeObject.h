#pragma once

#include "Object.h"
#include "Types.hpp"
#include <span>

namespace OpenLoco
{
    namespace ObjectManager
    {
        struct DependentObjects;
    }
    namespace Gfx
    {
        class DrawingContext;
    }

#pragma pack(push, 1)
    struct CliffEdgeObject
    {
        static constexpr auto kObjectType = ObjectType::cliffEdge;

        StringId name;
        uint32_t image; // 0x02

        // 0x004699FC
        bool validate() const { return true; }
        void load(const LoadedObjectHandle& handle, std::span<const std::byte> data, ObjectManager::DependentObjects*);
        void unload();
        void drawPreviewImage(Gfx::DrawingContext& drawingCtx, const int16_t x, const int16_t y) const;
    };
#pragma pack(pop)
    static_assert(sizeof(CliffEdgeObject) == 0x6);
}
