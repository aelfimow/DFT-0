#ifdef WM_PAINT_HANDLER_H
#error Already included
#else
#define WM_PAINT_HANDLER_H

class WndProcParam;

class WM_PAINT_Handler: public WndProcHandler
{
    public:
        WM_PAINT_Handler();
        ~WM_PAINT_Handler();

        LRESULT operator()(const WndProcParam &param);

    public:
        WM_PAINT_Handler(const WM_PAINT_Handler &instance) = delete;
        WM_PAINT_Handler(const WM_PAINT_Handler &&instance) = delete;
        WM_PAINT_Handler &operator=(const WM_PAINT_Handler &instance) = delete;
        WM_PAINT_Handler &operator=(const WM_PAINT_Handler &&instance) = delete;
};

#endif
