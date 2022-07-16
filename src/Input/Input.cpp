#include "Input.h"

Input *Input::s_Instance = nullptr;

Input::Input()
{
}

Input *Input::GetInstance()
{
    return s_Instance = (s_Instance == nullptr) ? new Input() : s_Instance;
}

Input::~Input()
{
}
