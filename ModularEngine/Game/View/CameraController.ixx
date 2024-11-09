module;

#include <FatWin32.hpp>

#include <DirectXMath.h>

#include <d2d1.h>

export module StarField.View.CameraController;

import StarField.View.Camera;

import FatPound;

import std;

export namespace starfield
{
    class CameraController final
    {
    public:
        explicit CameraController(Camera& camera, FATSPACE_UTIL_IO::Mouse& mouse, const FATSPACE_UTIL_IO::Keyboard& kbd) noexcept;

        explicit CameraController() = delete;
        explicit CameraController(const CameraController& src) = delete;
        explicit CameraController(CameraController&& src) = delete;

        auto operator = (const CameraController& src) -> CameraController& = delete;
        auto operator = (CameraController&& src)      -> CameraController& = delete;
        ~CameraController() noexcept = default;


    public:
        void Update(float deltaTime) noexcept;


    protected:


    private:
        Camera& m_camera_;

        FATSPACE_UTIL_IO::Mouse& m_mouse_;
        const FATSPACE_UTIL_IO::Keyboard& m_kbd_;

        ::DirectX::XMFLOAT2 m_last_pos_{ 0.0f, 0.0f };

        bool engaged_{};

        static constexpr auto zoomFactor_ = 1.05f;
        static constexpr auto rotationSpeed_ = ::DirectX::XM_PI / 6.0f;
    };
}