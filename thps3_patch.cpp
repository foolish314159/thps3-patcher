#include "win32-process-wrapper/process.h"

#include <conio.h>

constexpr const char *THPS3_EXE = "THPS3.exe";

constexpr DWORD64 THPS3_251_BYTE_ADDR = 0x004355ad;
constexpr BYTE THPS3_251_PATCH = 0xeb;

constexpr DWORD64 THPS3_BW_MANUAL_ADDR = 0x0049d7be;
constexpr BYTE THPS3_BW_MANUAL_BYTE_COUNT = 15;
constexpr BYTE THPS3_BW_MANUAL_PATCH = 0x90;

struct THPS3 : public Process
{
  public:
    THPS3() : Process(THPS3_EXE)
    {
    }

    void Patch251()
    {
        std::cout << "Patching 251 combo limit..." << std::endl;
        PatchMem(THPS3_251_BYTE_ADDR, THPS3_251_PATCH);
        std::cout << "Patched." << std::endl;
    }

    void PatchBwManual()
    {
        std::cout << "Patching backwards manual..." << std::endl;

        DWORD64 addr = THPS3_BW_MANUAL_ADDR;
        for (int i = 0; i < THPS3_BW_MANUAL_BYTE_COUNT; i++)
        {
            PatchMem(addr++, THPS3_BW_MANUAL_PATCH);
        }

        std::cout << "Patched." << std::endl;
    }
};

int main()
{
    try
    {
        THPS3 thps3;
        thps3.Patch251();
        thps3.PatchBwManual();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Press any key" << std::endl;
    _getch();

    return 0;
}
