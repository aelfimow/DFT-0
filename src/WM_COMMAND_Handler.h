#ifdef WM_COMMAND_HANDLER_H
#error Already included
#else
#define WM_COMMAND_HANDLER_H

class WndProcParam;

class WM_COMMAND_Handler: public WndProcHandler
{
    public:
        WM_COMMAND_Handler();
        ~WM_COMMAND_Handler();

        LRESULT operator()(const WndProcParam &param) override;

    private:
        const DWORD m_TimerID;

    public:
        WM_COMMAND_Handler(const WM_COMMAND_Handler &instance) = delete;
        WM_COMMAND_Handler(const WM_COMMAND_Handler &&instance) = delete;
        WM_COMMAND_Handler &operator=(const WM_COMMAND_Handler &instance) = delete;
        WM_COMMAND_Handler &operator=(const WM_COMMAND_Handler &&instance) = delete;
};

#endif
