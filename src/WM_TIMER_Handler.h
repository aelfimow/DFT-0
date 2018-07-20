#ifdef WM_TIMER_HANDLER_H
#error Already included
#else
#define WM_TIMER_HANDLER_H

class WndProcParam;

class WM_TIMER_Handler: public WndProcHandler
{
    public:
        WM_TIMER_Handler();
        ~WM_TIMER_Handler();

        LRESULT operator()(const WndProcParam &param) override;

    public:
        WM_TIMER_Handler(const WM_TIMER_Handler &instance) = delete;
        WM_TIMER_Handler(const WM_TIMER_Handler &&instance) = delete;
        WM_TIMER_Handler &operator=(const WM_TIMER_Handler &instance) = delete;
        WM_TIMER_Handler &operator=(const WM_TIMER_Handler &&instance) = delete;
};

#endif
