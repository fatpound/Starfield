module;

#include <FatWin32_Namespaces.hpp>

#include <DirectXMath.h>

export module StarField;

import StarField.Entity;
import StarField.View;

import FatPound;

import std;

export namespace starfield
{
    class Game final
    {
    public:
        Game();
        Game(const Game& src) = delete;
        Game(Game&& src) = delete;

        auto operator = (const Game& src) -> Game& = delete;
        auto operator = (Game&& src)      -> Game& = delete;
        ~Game() noexcept = default;


    public:
        auto Go() -> int;


    protected:


    private:
        void UpdateModel_() noexcept;
        void DoFrame_();


    private:
        NAMESPACE_WIN32::Window wnd_;
        NAMESPACE_D2D::Graphics gfx_;

        NAMESPACE_UTIL::AutoTimer timer_;

        Camera camera_;
        CameraController camera_controller_;

        std::vector<std::unique_ptr<entity::Star>> drawables_;

        float totalTime_ = 0.0f;
    };
}