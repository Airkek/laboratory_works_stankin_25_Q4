#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    {
        Application::Run(gcnew Lab_sem3_01::MyForm());
    }
    return 0;
}